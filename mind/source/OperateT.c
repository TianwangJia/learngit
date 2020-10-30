/**********************************************
Description:  编辑页面及附属页面所用工具函数
Function list :  daotujud  判断导图文件是否重复
                 newmind   新建一个导图文件
                 input_mind 输入并显示信息函数
				 newdrt 新建一个存放新用户导图文件的文件夹
Attention:
Author:  倪启源
History:
***********************************************/

#include "common.h"
#include "operateT.h"

/**************************************************
Name: daotujud
Function：判断导图文件是否重复
Calls:无
Called By: new Open.c
Parameter：account_name 用户名
           mind_name 待新建的思维导图文件名
Return: 标识，1为重复，0未重复
Author: 倪启源
Others:无
**************************************************/

int daotujud(char *account_name, char *mind_name)
{
    FILE *fp;
    MIND *mind = NULL;
    int flag = 0;       //返回导图文件是否存在标志,1存在，0不存在
    int num;            //用户所拥有的导图文件个数
    int i;              //计数用
    char place[25 + 1]; //存放用户所拥有的文件的信息索引
    sprintf(place, ".\\UserInfo\\%s.dat", account_name);

    if ((fp = fopen(place, "rb")) == NULL) //打开失败，异常退出
    {
        closegraph();
        printf("\nFile UserInfo opening error.(from daotujud_open)\n");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    num = ftell(fp) / sizeof(MIND); //得到导图数量
    if (num == 0)                   //无导图
    {
        flag = 0;
        return flag;
    }
    mind = (MIND *)malloc(sizeof(MIND)); 
	if (mind== NULL) //分配内存失败，退出程序
    {
        closegraph();
        printf("\nMemory location failed.(from daotujud_malloc)\n");
        delay(3000);
        exit(1);
    }
    for (i = 0; i < num; i++)
    {
        fseek(fp, i * sizeof(MIND), SEEK_SET);
        fread(mind, sizeof(MIND), 1, fp);

        if (!strcmp(mind->mindname, mind_name))
        {
            flag = 1;
            break;
        }
    }

    free(mind);
    mind = NULL;
    if (fclose(fp) != 0) //关闭文件错误
    {
        closegraph();
        printf("\nFile UserInfo closed error.(from daotujud_close)\n");
        delay(3000);
        exit(1);
    }
    return flag;
}

/**************************************************
Name: newmind
Function：给对应用户新建一个思维导图的文件
Calls:无
Called By: new
Parameter: account_name 用户名 新建后将文献信息存储到对应用户名的文件中
           mind_name 新建的思维导图文件名
		   dt 暂时存放思维导图信息的结构
Return: 无
Author: 倪启源
Others: 无
**************************************************/
void newmind(char *account_name, char *mind_name, MIND *dt) //函数类型待定！
{
    FILE *fp;
	int i,j; //框计数变量
    MINDBOX new_boxes[HORI][VERT];
	MINDBOX new_boxestr[HORI][VERTREE];
	FISHINFO new_fishbone;
	DATEINFO new_dates;
    char filename[32+ 1];   //思维导图位置索引
    char filename_1[25 + 1]; //对应用户拥有的导图信息文件索引
	for(i = 0; i < HORI; i ++)
	{
		for(j = 0; j < VERT; j ++)
		{
			new_boxes[i][j].ste = 0;
			strcpy(new_boxes[i][j].content, "");
			new_boxes[i][j].boxcolor = BLACK;
			new_boxes[i][j].textcolor = BLACK;
		}
	}
	for(i = 0; i < HORI; i ++)
	{
		for(j = 0; j < VERTREE; j ++)
		{
			new_boxestr[i][j].ste = 0;
			strcpy(new_boxestr[i][j].content, "");
			new_boxestr[i][j].boxcolor = BLACK;
			new_boxestr[i][j].textcolor = BLACK;
		}
	}
	for(i = 0; i < BONEMAX; i ++)
	{
		strcpy(new_fishbone.bone[i].content,"");
	}

    strcpy(dt->mindname, mind_name); //将名字置入信息暂存区
    sprintf(filename, ".\\daotu\\%s\\%s.dat", account_name, mind_name);

    if ((fp = fopen(filename, "wb+")) == NULL) //新建一个导图文件
    {
        //打开失败，异常退出
        closegraph();
        printf("\nFile opening error.(from newmind_1)\n");
        delay(3000);
        exit(1);
    }
	
	switch(dt->type)
	{
		case 1: //初始化单向思维导图并保存
		new_boxes[0][0].ste = 1;
		strcpy(new_boxes[0][0].content,"");
		new_boxes[0][0].textcolor = BLACK;
		new_boxes[0][0].boxcolor = BLACK;
		
		new_boxes[1][0].ste = 1;
		strcpy(new_boxes[1][0].content,"");
		new_boxes[1][0].textcolor = BLACK;
		new_boxes[1][0].boxcolor = BLACK;
		
		new_boxes[1][1].ste = 1;
		strcpy(new_boxes[1][1].content,"");
		new_boxes[1][1].textcolor = BLACK;
		new_boxes[1][1].boxcolor = BLACK;
		
		new_boxes[1][2].ste = 1;
		strcpy(new_boxes[1][2].content,"");
		new_boxes[1][2].textcolor = BLACK;
		new_boxes[1][2].boxcolor = BLACK;
		
		fseek(fp, 0, 0);
	    fwrite(&(new_boxes[0][0]), sizeof(MINDBOX), HORI * VERT, fp);
		break;
		
		case 2: //初始化树状图并保存
		new_boxestr[0][0].ste = 1;
		strcpy(new_boxestr[0][0].content,"");
		new_boxestr[0][0].textcolor = BLACK;
		new_boxestr[0][0].boxcolor = BLACK;
		
		new_boxestr[0][1].ste = 1;
		strcpy(new_boxestr[0][1].content,"");
		new_boxestr[0][1].textcolor = BLACK;
		new_boxestr[0][1].boxcolor = BLACK;
		
		new_boxestr[1][1].ste = 1;
		strcpy(new_boxestr[1][1].content,"");
		new_boxestr[1][1].textcolor = BLACK;
		new_boxestr[1][1].boxcolor = BLACK;
		
		new_boxestr[2][1].ste = 1;
		strcpy(new_boxestr[2][1].content,"");
		new_boxestr[2][1].textcolor = BLACK;
		new_boxestr[2][1].boxcolor = BLACK;
		
		fseek(fp, 0, 0);
	    fwrite(&(new_boxestr[0][0]), sizeof(MINDBOX), HORI * VERT, fp);
		break;
		
		case 3: //初始化鱼骨图并保存
		new_fishbone.bonenum = 3;
		
		fseek(fp, 0, 0);
		fwrite(&new_fishbone, sizeof(FISHINFO), 1, fp);
		break;
		
		case 4: //初始化时间轴并保存
		new_dates.daynum = 0;
		
		fseek(fp, 0, 0);
		fwrite(&new_dates, sizeof(DATEINFO), 1, fp);
		break;
	}

    if (fclose(fp) != 0) //关闭文件错误
    {
        closegraph();
        printf("closed error.");
        delay(3000);
        exit(1);
    }

    sprintf(filename_1, ".\\UserInfo\\%s.dat", account_name);

    if ((fp = fopen(filename_1, "ab")) == NULL) //打开用户文件
    {
        //打开失败，异常退出
        closegraph();
        printf("\nFile opening error.(from newmind_2)\n");
        delay(3000);
        exit(1);
    }

    fwrite(dt, sizeof(MIND), 1, fp);

    if (fclose(fp) != 0) //关闭文件错误
    {
        closegraph();
        printf("closed error.");
        delay(3000);
        exit(1);
    }
}

/**************************************************
Name: input_mind
Function：键盘输入显示函数（输入新的思维导图）
Calls: 无
Called By: new Open.c
Parameter: x  输入位置左边界
           y  输入位置上边界
           size  字符大小
           content  输入信息的结构体，详见data.h
Return: 无
Author: 倪启源
Others: 无
**************************************************/
void input_mind(int x, int y, int size, ENTER *content) //将信息输入到content中，并显示在屏幕上
{
    char tmp;
    int i;
    if (press == 1)
    {
        if (mouse_press(content->x1, content->y1, content->x2, content->y2) == 1) //在输入框内点击
        {
            content->flag = 1;
            clrmous(MouseX, MouseY);

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

            setcolor(DARKGRAY);
            clrmous(MouseX, MouseY);
            delay(5); 
            outtextxy(x, y, content->str);
            line(x + (content->cursor) * (2 * size - 2) + 3, y, x + (content->cursor) * (2 * size - 2) + 3, y + 2 * (2 * size - 2));
        }
    }
}

/**************************************************
Name: newdrt
Function：新建一个存放新用户导图文件的文件夹
Calls: 无
Called By: sign_up
Parameter: account_name 用户名
Return: 无
Author: 倪启源
Others: 无
**************************************************/
void newdrt(char *account_name)
{
    char indexer[15 + 1]; //新建的文件夹索引
    sprintf(indexer, ".\\daotu\\%s", account_name);
	if (mkdir(indexer) != 0) //新建失败，异常退出
    {
        closegraph();
        printf("fail(from newdrt)");
        delay(3000);
        exit(1);
    }
}
    