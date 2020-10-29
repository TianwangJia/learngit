/**********************************************
Description: 登录注册所需工具函数，操作界面所需部分工具函数
Function list :  input_info 键盘输入显示函数
                 judge_samename 检查用户名是否已存在函数
                 judge_ID 检查身份证号格式是否符合要求
                 judge_password 检查密码是否符合要求
                 write_info 将账户用户名，身份证号，密码写入账户文件
                 new_file 为新注册的用户建立一个文件保存其账户信息
                 right_ID 判断身份证号是否正确
                 rewrite_key 写入新密码
                 right_key 判断密码是否正确
                 findmind 根据传入的用户名与思维导图名找到用户中的MIND结构体
                 delete_mind 删除用户文件中的指定MIND结构体,并删除对应的导图文件
Attention:
Author： 贾田旺
History:
***********************************************/

#include "common.h"
#include "EnterT.h"

/**************************************************
Name: input_info
Function：键盘输入显示函数
Calls: 无
Called By: Signup
           Log
           ResetKey
Parameter: x  输入位置左边界
           y  输入位置上边界
           size  字符大小
	       mode  输入模式，1为可见信息如用户名、身份证号，0为不可见信息如密码
           content  输入信息的结构体，详见data.h
Return: 无
Author: 贾田旺
Others: 无
**************************************************/
void input_info(int x, int y, int size, int mode, ENTER *content) //将信息输入到content中，并显示在屏幕上
{
    char tmp;
    int i;
    if (press == 1)
    {
        if (mouse_press(content->x1, content->y1, content->x2, content->y2) == 1) //在输入框内点击
        {
            content->flag = 1;
            clrmous(MouseX, MouseY);
            delay(5); //FIXME

            setcolor(RED);
            setlinestyle(0, 0, 1);
            rectangle(content->x1, content->y1, content->x2, content->y2);
            setcolor(DARKGRAY);
            line(x + (content->cursor) * (2 * size - 2) + 3, y, x + (content->cursor) * (2 * size - 2) + 3, y + 2 * (2 * size - 2));
        }
        else //在输入框外点击
        {
            content->flag = 0;
            clrmous(MouseX, MouseY);
            delay(5); //FIXME

            setcolor(WHITE);
            setlinestyle(0, 0, 1);
            rectangle(content->x1, content->y1, content->x2, content->y2);
            line(x + (content->cursor) * (2 * size - 2) + 3, y, x + (content->cursor) * (2 * size - 2) + 3, y + 2 * (2 * size - 2));
        }
    }

    if (content->flag == 1) //flag为1时表示可以接收键盘输入
    {
        if (kbhit())
        {
            tmp = getch();

            if (tmp >= '!' && tmp <= '~') //输入一个字符
            {
                if (content->cursor < content->length) //不能超过最大长度
                {
                    (content->str)[content->cursor] = tmp;
                    (content->str)[content->cursor + 1] = '\0';
                    (content->cursor)++;
                }
            }
            else if (tmp == '\b') //删除字符
            {
                if (content->cursor > 0)
                {
                    (content->str)[content->cursor - 1] = '\0';
                    (content->cursor)--;
                }
            }

            setcolor(DARKGRAY);
            setlinestyle(0, 0, 1);
            setfillstyle(SOLID_FILL, WHITE);
            settextjustify(LEFT_TEXT, TOP_TEXT);
            settextstyle(SMALL_FONT, HORIZ_DIR, size);
            bar(content->x1 + 2, content->y1 + 2, content->x2 - 2, content->y2 - 2); //每一步显示之前先用背景色覆盖掉原来信息

            if (mode == 1) //显示字符串并划线
            {
                setcolor(DARKGRAY);
                clrmous(MouseX, MouseY);
                delay(5); //FIXME
                outtextxy(x, y, content->str);
                line(x + (content->cursor) * (2 * size - 2) + 3, y, x + (content->cursor) * (2 * size - 2) + 3, y + 2 * (2 * size - 2));
            }
            else //显示*
            {
                setcolor(DARKGRAY);
                for (i = 0; i < content->cursor; i++)
                {
                    clrmous(MouseX, MouseY);
                    delay(5); //FIXME
                    outtextxy(x + i * (2 * size - 2), y, "*");
                }
                line(x + (content->cursor) * (2 * size - 2) + 3, y, x + (content->cursor) * (2 * size - 2) + 3, y + 2 * (2 * size - 2));
            }
        }
    }
}

/**************************************************
Name: judge_samename
Function：检查用户名是否已存在
Calls: 无
Called By: Signup
           Log
           ResetKey
Parameter: name 用户名
Return: flag  0表示不存在，1表示存在
Author: 贾田旺
Others: 无
**************************************************/
int judge_samename(char *name)
{
    FILE *fp;
    USER *user = NULL;
    int flag = 0; //返回的是否存在标志
    int num;      //文件用户个数
    int i;
    if ((fp = fopen(".\\UserInfo\\UserInfo.dat", "rb")) == NULL) //打开失败，异常退出
    {
        closegraph();
        printf("\nFile UserInfo opening error.(from judge_samename)\n");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    num = ftell(fp) / sizeof(USER); //得到用户数量
    if (num == 0)
    {
        flag = 0;
        return flag;
    }
    user = (USER *)malloc(sizeof(USER));
    if (user == NULL) //分配内存失败，退出程序
    {
        closegraph();
        printf("\nMemory location failed.(from juse_samename)\n");
        delay(3000);
        exit(1);
    }
    for (i = 0; i < num; i++)
    {
        fseek(fp, i * sizeof(USER), SEEK_SET);
        fread(user, sizeof(USER), 1, fp);

        if (!strcmp(user->username, name))
        {
            flag = 1;
            break;
        }
    }

    free(user);
    user = NULL;
    if (fclose(fp) != 0) //关闭文件错误
    {
        closegraph();
        printf("\nFile UserInfo closed error.(from judge_samename)\n");
        delay(3000);
        exit(1);
    }
    return flag;
}

/**************************************************
Name: judge_ID
Function：检查身份证号是否符合要求
Calls: 无
Called By: Signup
           ResetKey
Parameter: card 身份证号
Return: flag  0表示错误，1表示正确
Author: 贾田旺
Others: 无
**************************************************/
int judge_ID(char *card)
{
    int i;
    int flag = 1; //表示身份证号是否符合要求
    if (strlen(card) != 18)
    {
        flag = 0;
        return flag;
    }
    for (i = 0; i < 18; i++)
    {
        if ((i < 17) && (card[i] < '0' || card[i] > '9')) //若在除最后一位之外出现非数字字符，则错误
        {
            flag = 0;
            break;
        }
        if ((i == 17) && (card[i] < '0' || card[i] > '9') && (card[i] != 'x' && card[i] != 'X')) //若在最后一位出现不是x或X的非数字字符，则错误
        {
            flag = 0;
            break;
        }
    }

	return flag;
}

/**************************************************
Name: judge_password
Function：判断密码是否符合要求
Calls: 无
Called By: Signup
           ResetKey
Parameter: password 密码
Return: 1 符合要求  0 不符合要求
Author: 贾田旺
Others: 无
**************************************************/
int judge_password(char *password)
{
    if (strlen(password) < 8) //密码小于8位不符合要求
        return 0;
    else
        return 1;
}

/**************************************************
Name: write_info
Function：将账户用户名，身份证号，密码写入账户文件
Calls: 无
Called By: Signup
           ResetKey
Parameter: name 用户名
           card 身份证号
           password 密码
Return: 无
Author: 贾田旺
Others: 无
**************************************************/
void write_info(char *name, char *card, char *password)
{
    FILE *fp;
    USER *user;
    int i;

    if ((fp = fopen(".\\UserInfo\\UserInfo.dat", "ab+")) == NULL) //以读写追加方式打开
    {
        //打开失败，异常退出
        closegraph();
        printf("\nFile UserInfo opening error.(from write_info)\n");
        delay(3000);
        exit(1);
    }
    user = (USER *)malloc(sizeof(USER));
    if (user == NULL) //分配内存失败，退出程序
    {
        closegraph();
        printf("\nMemory location failed.(from write_info)\n");
        delay(3000);
        exit(1);
    }
    strcpy(user->username, name);
    strcpy(user->ID, card);
    strcpy(user->password, password);
    fwrite(user, sizeof(USER), 1, fp);

    free(user);
    user = NULL;
    if (fclose(fp) != 0) //关闭文件错误
    {
        closegraph();
        printf("\nFile UserInfo closed error.(from write_info)\n");
        delay(3000);
        exit(1);
    }
}

/**************************************************
Name: new_file
Function：为新注册的用户建立一个文件保存其账户信息
Calls: 无
Called By: Signup
Parameter: name 新用户姓名
Return: 无
Author: 贾田旺
Others: 无
**************************************************/
void new_file(char *name)
{
    FILE *fp;
    char filename[25 + 1]; //新用户文件名

    sprintf(filename, ".\\UserInfo\\%s.dat", name);
    if ((fp = fopen(filename, "wb+")) == NULL) //为读写建立一个新的二进制文件。
    {
        //打开失败，异常退出
        closegraph();
        printf("\nFile opening error.(from new_file)\n");
        delay(3000);
        exit(1);
    }
    if (fclose(fp) != 0) //关闭文件错误
    {
        closegraph();
        printf("\nFile closed error.(from new_file)\n");
        delay(3000);
        exit(1);
    }
}

/**************************************************
Name: right_ID
Function：判断身份证号是否正确
Calls: 无
Called By: ResetKey
Parameter: name 用户名
           card 用户输入的身份证号
Return: flag  1 表示正确  2 表示错误
Author: 贾田旺
Others: 无
**************************************************/
int right_ID(char *name, char *card)
{
    FILE *fp;
    USER *user;
    int flag = 1;     //表示身份证号是否正确
    int i, num, j, k; //文件用户个数

    if ((fp = fopen(".\\UserInfo\\UserInfo.dat", "rb")) == NULL) //以只读方式打开
    {
        //打开失败，退出程序
        closegraph();
        printf("\nFile UserInfo opening error.(from rihgt_ID)\n");
        delay(3000);
        exit(1);
    }
    user = (USER *)malloc(sizeof(USER));
    if (user == NULL) //分配内存失败，退出程序
    {
        closegraph();
        printf("\nMemory location failed.(from right_ID)\n");
        delay(3000);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    num = ftell(fp) / sizeof(USER); //得到用户数量

    for (i = 0; i < num; i++)
    {
        fseek(fp, i * sizeof(USER), SEEK_SET);
        fread(user, sizeof(USER), 1, fp);

        if (strcmp(user->username, name) == 0)
        {
            break;
        }
    }
    if (strcmp(user->ID, card) == 0) //如果输入身份证号与文件内部相同
    {
        flag = 1;
    }
    else if (strcmp(user->ID, card) != 0)
    {
        flag = 0;
    }

    free(user);
    user = NULL;
    if (fclose(fp) != 0) //关闭文件错误
    {
        closegraph();
        printf("\nFile UserInfo closed error.(from right_ID)\n");
        delay(3000);
        exit(1);
    }

    return flag;
}

/**************************************************
Name: rewrite_key
Function：写入新密码
Calls: 无
Called By: ResetKey
Parameter: name 用户名
           newkey 新密码
Return: 无
Author: 贾田旺
Others: 无
**************************************************/
void rewrite_key(char *name, char *newkey)
{
    FILE *fp;
    USER *user;
    int i, num; //文件用户个数

    if ((fp = fopen(".\\UserInfo\\UserInfo.dat", "rb+")) == NULL) //以读写方式打开
    {
        //打开失败，退出程序
        closegraph();
        printf("\nFile UserInfo opening error.(from rewrite_key)\n");
        delay(3000);
        exit(1);
    }
    user = (USER *)malloc(sizeof(USER));
    if (user == NULL) //分配内存失败，退出程序
    {
        closegraph();
        printf("\nMemory location failed.(from rewrite_key)\n");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    num = ftell(fp) / sizeof(USER); //得到用户数量

    for (i = 0; i < num; i++)
    {
        fseek(fp, i * sizeof(USER), SEEK_SET);
        fread(user, sizeof(USER), 1, fp);

        if (!strcmp(user->username, name))
        {
            break;
        }
    }
    strcpy(user->password, newkey);
    fseek(fp, i * sizeof(USER), SEEK_SET);
    fwrite(user, sizeof(USER), 1, fp);

    free(user);
    user = NULL;
    if (fclose(fp) != 0) //关闭文件错误
    {
        closegraph();
        printf("\nFile UserInfo closed error.(from rewite_key)\n");
        delay(3000);
        exit(1);
    }
}

/**************************************************
Name: right_key
Function：判断密码是否正确
Calls: 无
Called By: Log
Parameter: name 用户名
           password  用户输入密码
Return: flag 1 表示正确 0 表示错误
Author: 贾田旺
Others: 无
**************************************************/
int right_key(char *name, char *password)
{
    FILE *fp;
    USER *user;
    int flag = 1;
    int i, num; //文件用户个数

    if ((fp = fopen(".\\UserInfo\\UserInfo.dat", "rb")) == NULL) //以只读方式打开
    {
        //打开失败，退出程序
        closegraph();
        printf("\nFile UserInfo opening error.(from right_key)\n");
        delay(3000);
        exit(1);
    }
    user = (USER *)malloc(sizeof(USER));
    if (user == NULL) //分配内存失败，退出程序
    {
        closegraph();
        printf("\nMemory location failed.(from right_key)\n");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    num = ftell(fp) / sizeof(USER); //得到用户数量

    for (i = 0; i < num; i++)
    {
        fseek(fp, i * sizeof(USER), SEEK_SET);
        fread(user, sizeof(USER), 1, fp);

        if (!strcmp(user->username, name))
        {
            break;
        }
    }
    if (strcmp(user->password, password) != 0) //密码不相符
    {
        flag = 0;
    }
    else if (strcmp(user->password, password) == 0) //密码相符
    {
        flag = 1;
    }

    free(user);
    user = NULL;
    if (fclose(fp) != 0) //关闭文件错误
    {
        closegraph();
        printf("\nFile UserInfo closed error.(from right_key)\n");
        delay(3000);
        exit(1);
    }
    return flag;
}

/**************************************************
Name: findmind
Function：根据传入的用户名与思维导图名找到用户中的MIND结构体
Calls: 无
Called By: Open.c
Parameter: account_name 账户名
           mindname 思维导图名
Return: MIND 结构体
Author: 贾田旺
Others:
**************************************************/
MIND findmind(char *account_name, char *mindname)
{
    FILE *fp;
    MIND mind1;
    int num;            //用户所拥有的导图文件个数
    int i;              //计数用
    char place[25 + 1]; //存放用户所拥有的文件的信息索引
    sprintf(place, ".\\UserInfo\\%s.dat", account_name);

    if ((fp = fopen(place, "rb")) == NULL) //打开失败，异常退出
    {
        closegraph();
        printf("\nFile UserInfo opening error.(from findmind)\n");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    num = ftell(fp) / sizeof(MIND); //得到导图数量

    for (i = 0; i < num; i++)
    {
        fseek(fp, i * sizeof(MIND), SEEK_SET);
        fread(&mind1, sizeof(MIND), 1, fp);

        if (!strcmp(mind1.mindname, mindname))
        {
            break;
        }
    }

    if (fclose(fp) != 0) //关闭文件错误
    {
        closegraph();
        printf("\nFile UserInfo closed error.(from findmind)\n");
        delay(3000);
        exit(1);
    }

    return mind1;
}

/**************************************************
Name: delete_mind
Function：删除用户文件中的指定MIND结构体,并删除对应的导图文件
Calls: 无
Called By: edit.c
Parameter: account_name 账户名
           mindname 导图名
Return: 无
Author: 贾田旺
Others: 无
**************************************************/
void delete_mind(char *account_name, char *mindname)
{
    FILE *fp, *ftmp;
    MIND *mind1;
    int i, num;                                         //计数，用户拥有导图个数
    char place_user[25 + 1];                            //存放用户文件的信息索引
    char place_tp[24 + 1] = ".\\UserInfo\\tmp_dmd.dat"; //暂时
    char place_daotu[32 + 1];                           //导图文件索引
    sprintf(place_user, ".\\UserInfo\\%s.dat", account_name);
    sprintf(place_daotu, ".\\daotu\\%s\\%s.dat", account_name, mindname);

    if ((fp = fopen(place_user, "rb")) == NULL) //打开失败，异常退出
    {
        closegraph();
        printf("\nFile UserInfo opening error.(from delete_mind1)\n");
        delay(3000);
        exit(1);
    }
    if ((ftmp = fopen(place_tp, "wb+")) == NULL) //打开失败，异常退出
    {
        closegraph();
        printf("\nFile UserInfo opening error.(from delete_mind2)\n");
        delay(3000);
        exit(1);
    }
    mind1 = (MIND *)malloc(sizeof(MIND));
    if (mind1 == NULL) //分配内存失败，退出程序
    {
        closegraph();
        printf("\nMemory location failed.(from delete_mind)\n");
        delay(3000);
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    num = ftell(fp) / sizeof(MIND); //得到导图数量

    for (i = 0; i < num; i++)
    {
        fseek(fp, i * sizeof(MIND), SEEK_SET);
        fread(mind1, sizeof(MIND), 1, fp);

        if (strcmp(mind1->mindname, mindname)) //如果和要删除的导图MIND不同
        {
            fwrite(mind1, sizeof(MIND), 1, ftmp);
        }
    }

    if (fclose(fp) != 0) //关闭文件错误
    {
        closegraph();
        printf("\nFile UserInfo closed error.(from delete_mind1)\n");
        delay(3000);
        exit(1);
    }
    if (fclose(ftmp) != 0) //关闭文件错误
    {
        closegraph();
        printf("\nFile UserInfo closed error.(from delete_mind2)\n");
        delay(3000);
        exit(1);
    }
    free(mind1);
    mind1 = NULL;

    remove(place_user);
    rename(place_tp, place_user);
    remove(place_daotu);
}
