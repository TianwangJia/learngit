/**********************************************
Description: ��¼ע�����蹤�ߺ����������������貿�ֹ��ߺ���
Function list :  input_info ����������ʾ����
                 judge_samename ����û����Ƿ��Ѵ��ں���
                 judge_ID ������֤�Ÿ�ʽ�Ƿ����Ҫ��
                 judge_password ��������Ƿ����Ҫ��
                 write_info ���˻��û��������֤�ţ�����д���˻��ļ�
                 new_file Ϊ��ע����û�����һ���ļ��������˻���Ϣ
                 right_ID �ж����֤���Ƿ���ȷ
                 rewrite_key д��������
                 right_key �ж������Ƿ���ȷ
                 findmind ���ݴ�����û�����˼ά��ͼ���ҵ��û��е�MIND�ṹ��
                 delete_mind ɾ���û��ļ��е�ָ��MIND�ṹ��,��ɾ����Ӧ�ĵ�ͼ�ļ�
Attention:
Author�� ������
History:
***********************************************/

#include "common.h"
#include "EnterT.h"

/**************************************************
Name: input_info
Function������������ʾ����
Calls: ��
Called By: Signup
           Log
           ResetKey
Parameter: x  ����λ����߽�
           y  ����λ���ϱ߽�
           size  �ַ���С
	       mode  ����ģʽ��1Ϊ�ɼ���Ϣ���û��������֤�ţ�0Ϊ���ɼ���Ϣ������
           content  ������Ϣ�Ľṹ�壬���data.h
Return: ��
Author: ������
Others: ��
**************************************************/
void input_info(int x, int y, int size, int mode, ENTER *content) //����Ϣ���뵽content�У�����ʾ����Ļ��
{
    char tmp;
    int i;
    if (press == 1)
    {
        if (mouse_press(content->x1, content->y1, content->x2, content->y2) == 1) //��������ڵ��
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
        else //�����������
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

    if (content->flag == 1) //flagΪ1ʱ��ʾ���Խ��ռ�������
    {
        if (kbhit())
        {
            tmp = getch();

            if (tmp >= '!' && tmp <= '~') //����һ���ַ�
            {
                if (content->cursor < content->length) //���ܳ�����󳤶�
                {
                    (content->str)[content->cursor] = tmp;
                    (content->str)[content->cursor + 1] = '\0';
                    (content->cursor)++;
                }
            }
            else if (tmp == '\b') //ɾ���ַ�
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
            bar(content->x1 + 2, content->y1 + 2, content->x2 - 2, content->y2 - 2); //ÿһ����ʾ֮ǰ���ñ���ɫ���ǵ�ԭ����Ϣ

            if (mode == 1) //��ʾ�ַ���������
            {
                setcolor(DARKGRAY);
                clrmous(MouseX, MouseY);
                delay(5); //FIXME
                outtextxy(x, y, content->str);
                line(x + (content->cursor) * (2 * size - 2) + 3, y, x + (content->cursor) * (2 * size - 2) + 3, y + 2 * (2 * size - 2));
            }
            else //��ʾ*
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
Function������û����Ƿ��Ѵ���
Calls: ��
Called By: Signup
           Log
           ResetKey
Parameter: name �û���
Return: flag  0��ʾ�����ڣ�1��ʾ����
Author: ������
Others: ��
**************************************************/
int judge_samename(char *name)
{
    FILE *fp;
    USER *user = NULL;
    int flag = 0; //���ص��Ƿ���ڱ�־
    int num;      //�ļ��û�����
    int i;
    if ((fp = fopen(".\\UserInfo\\UserInfo.dat", "rb")) == NULL) //��ʧ�ܣ��쳣�˳�
    {
        closegraph();
        printf("\nFile UserInfo opening error.(from judge_samename)\n");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    num = ftell(fp) / sizeof(USER); //�õ��û�����
    if (num == 0)
    {
        flag = 0;
        return flag;
    }
    user = (USER *)malloc(sizeof(USER));
    if (user == NULL) //�����ڴ�ʧ�ܣ��˳�����
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
    if (fclose(fp) != 0) //�ر��ļ�����
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
Function��������֤���Ƿ����Ҫ��
Calls: ��
Called By: Signup
           ResetKey
Parameter: card ���֤��
Return: flag  0��ʾ����1��ʾ��ȷ
Author: ������
Others: ��
**************************************************/
int judge_ID(char *card)
{
    int i;
    int flag = 1; //��ʾ���֤���Ƿ����Ҫ��
    if (strlen(card) != 18)
    {
        flag = 0;
        return flag;
    }
    for (i = 0; i < 18; i++)
    {
        if ((i < 17) && (card[i] < '0' || card[i] > '9')) //���ڳ����һλ֮����ַ������ַ��������
        {
            flag = 0;
            break;
        }
        if ((i == 17) && (card[i] < '0' || card[i] > '9') && (card[i] != 'x' && card[i] != 'X')) //�������һλ���ֲ���x��X�ķ������ַ��������
        {
            flag = 0;
            break;
        }
    }

	return flag;
}

/**************************************************
Name: judge_password
Function���ж������Ƿ����Ҫ��
Calls: ��
Called By: Signup
           ResetKey
Parameter: password ����
Return: 1 ����Ҫ��  0 ������Ҫ��
Author: ������
Others: ��
**************************************************/
int judge_password(char *password)
{
    if (strlen(password) < 8) //����С��8λ������Ҫ��
        return 0;
    else
        return 1;
}

/**************************************************
Name: write_info
Function�����˻��û��������֤�ţ�����д���˻��ļ�
Calls: ��
Called By: Signup
           ResetKey
Parameter: name �û���
           card ���֤��
           password ����
Return: ��
Author: ������
Others: ��
**************************************************/
void write_info(char *name, char *card, char *password)
{
    FILE *fp;
    USER *user;
    int i;

    if ((fp = fopen(".\\UserInfo\\UserInfo.dat", "ab+")) == NULL) //�Զ�д׷�ӷ�ʽ��
    {
        //��ʧ�ܣ��쳣�˳�
        closegraph();
        printf("\nFile UserInfo opening error.(from write_info)\n");
        delay(3000);
        exit(1);
    }
    user = (USER *)malloc(sizeof(USER));
    if (user == NULL) //�����ڴ�ʧ�ܣ��˳�����
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
    if (fclose(fp) != 0) //�ر��ļ�����
    {
        closegraph();
        printf("\nFile UserInfo closed error.(from write_info)\n");
        delay(3000);
        exit(1);
    }
}

/**************************************************
Name: new_file
Function��Ϊ��ע����û�����һ���ļ��������˻���Ϣ
Calls: ��
Called By: Signup
Parameter: name ���û�����
Return: ��
Author: ������
Others: ��
**************************************************/
void new_file(char *name)
{
    FILE *fp;
    char filename[25 + 1]; //���û��ļ���

    sprintf(filename, ".\\UserInfo\\%s.dat", name);
    if ((fp = fopen(filename, "wb+")) == NULL) //Ϊ��д����һ���µĶ������ļ���
    {
        //��ʧ�ܣ��쳣�˳�
        closegraph();
        printf("\nFile opening error.(from new_file)\n");
        delay(3000);
        exit(1);
    }
    if (fclose(fp) != 0) //�ر��ļ�����
    {
        closegraph();
        printf("\nFile closed error.(from new_file)\n");
        delay(3000);
        exit(1);
    }
}

/**************************************************
Name: right_ID
Function���ж����֤���Ƿ���ȷ
Calls: ��
Called By: ResetKey
Parameter: name �û���
            card �û���������֤��
Return: flag  1 ��ʾ��ȷ  2 ��ʾ����
Author: ������
Others: ��
**************************************************/
int right_ID(char *name, char *card)
{
    FILE *fp;
    USER *user;
    int flag = 1;     //��ʾ���֤���Ƿ���ȷ
    int i, num, j, k; //�ļ��û�����

    if ((fp = fopen(".\\UserInfo\\UserInfo.dat", "rb")) == NULL) //��ֻ����ʽ��
    {
        //��ʧ�ܣ��˳�����
        closegraph();
        printf("\nFile UserInfo opening error.(from rihgt_ID)\n");
        delay(3000);
        exit(1);
    }
    user = (USER *)malloc(sizeof(USER));
    if (user == NULL) //�����ڴ�ʧ�ܣ��˳�����
    {
        closegraph();
        printf("\nMemory location failed.(from right_ID)\n");
        delay(3000);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    num = ftell(fp) / sizeof(USER); //�õ��û�����

    for (i = 0; i < num; i++)
    {
        fseek(fp, i * sizeof(USER), SEEK_SET);
        fread(user, sizeof(USER), 1, fp);

        if (strcmp(user->username, name) == 0)
        {
            break;
        }
    }
    if (strcmp(user->ID, card) == 0) //����������֤�����ļ��ڲ���ͬ
    {
        flag = 1;
    }
    else if (strcmp(user->ID, card) != 0)
    {
        flag = 0;
    }

    free(user);
    user = NULL;
    if (fclose(fp) != 0) //�ر��ļ�����
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
Function��д��������
Calls: ��
Called By: ResetKey
Parameter: name �û���
           newkey ������
Return: ��
Author: ������
Others: ��
**************************************************/
void rewrite_key(char *name, char *newkey)
{
    FILE *fp;
    USER *user;
    int i, num; //�ļ��û�����

    if ((fp = fopen(".\\UserInfo\\UserInfo.dat", "rb+")) == NULL) //�Զ�д��ʽ��
    {
        //��ʧ�ܣ��˳�����
        closegraph();
        printf("\nFile UserInfo opening error.(from rewrite_key)\n");
        delay(3000);
        exit(1);
    }
    user = (USER *)malloc(sizeof(USER));
    if (user == NULL) //�����ڴ�ʧ�ܣ��˳�����
    {
        closegraph();
        printf("\nMemory location failed.(from rewrite_key)\n");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    num = ftell(fp) / sizeof(USER); //�õ��û�����

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
    if (fclose(fp) != 0) //�ر��ļ�����
    {
        closegraph();
        printf("\nFile UserInfo closed error.(from rewite_key)\n");
        delay(3000);
        exit(1);
    }
}

/**************************************************
Name: right_key
Function���ж������Ƿ���ȷ
Calls: ��
Called By: Log
Parameter: name �û���
           password  �û���������
Return: flag 1 ��ʾ��ȷ 0 ��ʾ����
Author: ������
Others: ��
**************************************************/
int right_key(char *name, char *password)
{
    FILE *fp;
    USER *user;
    int flag = 1;
    int i, num; //�ļ��û�����

    if ((fp = fopen(".\\UserInfo\\UserInfo.dat", "rb")) == NULL) //��ֻ����ʽ��
    {
        //��ʧ�ܣ��˳�����
        closegraph();
        printf("\nFile UserInfo opening error.(from right_key)\n");
        delay(3000);
        exit(1);
    }
    user = (USER *)malloc(sizeof(USER));
    if (user == NULL) //�����ڴ�ʧ�ܣ��˳�����
    {
        closegraph();
        printf("\nMemory location failed.(from right_key)\n");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    num = ftell(fp) / sizeof(USER); //�õ��û�����

    for (i = 0; i < num; i++)
    {
        fseek(fp, i * sizeof(USER), SEEK_SET);
        fread(user, sizeof(USER), 1, fp);

        if (!strcmp(user->username, name))
        {
            break;
        }
    }
    if (strcmp(user->password, password) != 0) //���벻���
    {
        flag = 0;
    }
    else if (strcmp(user->password, password) == 0) //�������
    {
        flag = 1;
    }

    free(user);
    user = NULL;
    if (fclose(fp) != 0) //�ر��ļ�����
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
Function�����ݴ�����û�����˼ά��ͼ���ҵ��û��е�MIND�ṹ��
Calls: ��
Called By: Open.c
Parameter: account_name �˻���
           mindname ˼ά��ͼ��
Return: MIND �ṹ��
Author: ������
Others:
**************************************************/
MIND findmind(char *account_name, char *mindname)
{
    FILE *fp;
    MIND mind1;
    int num;            //�û���ӵ�еĵ�ͼ�ļ�����
    int i;              //������
    char place[25 + 1]; //����û���ӵ�е��ļ�����Ϣ����
    sprintf(place, ".\\UserInfo\\%s.dat", account_name);

    if ((fp = fopen(place, "rb")) == NULL) //��ʧ�ܣ��쳣�˳�
    {
        closegraph();
        printf("\nFile UserInfo opening error.(from findmind)\n");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    num = ftell(fp) / sizeof(MIND); //�õ���ͼ����

    for (i = 0; i < num; i++)
    {
        fseek(fp, i * sizeof(MIND), SEEK_SET);
        fread(&mind1, sizeof(MIND), 1, fp);

        if (!strcmp(mind1.mindname, mindname))
        {
            break;
        }
    }

    if (fclose(fp) != 0) //�ر��ļ�����
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
Function��ɾ���û��ļ��е�ָ��MIND�ṹ��,��ɾ����Ӧ�ĵ�ͼ�ļ�
Calls: ��
Called By: edit.c
Parameter: account_name �˻���
           mindname ��ͼ��
Return: ��
Author: ������
Others: ��
**************************************************/
void delete_mind(char *account_name, char *mindname)
{
    FILE *fp, *ftmp;
    MIND *mind1;
    int i, num;                                         //�������û�ӵ�е�ͼ����
    char place_user[25 + 1];                            //����û��ļ�����Ϣ����
    char place_tp[24 + 1] = ".\\UserInfo\\tmp_dmd.dat"; //��ʱ
    char place_daotu[32 + 1];                           //��ͼ�ļ�����
    sprintf(place_user, ".\\UserInfo\\%s.dat", account_name);
    sprintf(place_daotu, ".\\daotu\\%s\\%s.dat", account_name, mindname);

    if ((fp = fopen(place_user, "rb")) == NULL) //��ʧ�ܣ��쳣�˳�
    {
        closegraph();
        printf("\nFile UserInfo opening error.(from delete_mind1)\n");
        delay(3000);
        exit(1);
    }
    if ((ftmp = fopen(place_tp, "wb+")) == NULL) //��ʧ�ܣ��쳣�˳�
    {
        closegraph();
        printf("\nFile UserInfo opening error.(from delete_mind2)\n");
        delay(3000);
        exit(1);
    }
    mind1 = (MIND *)malloc(sizeof(MIND));
    if (mind1 == NULL) //�����ڴ�ʧ�ܣ��˳�����
    {
        closegraph();
        printf("\nMemory location failed.(from delete_mind)\n");
        delay(3000);
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    num = ftell(fp) / sizeof(MIND); //�õ���ͼ����

    for (i = 0; i < num; i++)
    {
        fseek(fp, i * sizeof(MIND), SEEK_SET);
        fread(mind1, sizeof(MIND), 1, fp);

        if (strcmp(mind1->mindname, mindname)) //�����Ҫɾ���ĵ�ͼMIND��ͬ
        {
            fwrite(mind1, sizeof(MIND), 1, ftmp);
        }
    }

    if (fclose(fp) != 0) //�ر��ļ�����
    {
        closegraph();
        printf("\nFile UserInfo closed error.(from delete_mind1)\n");
        delay(3000);
        exit(1);
    }
    if (fclose(ftmp) != 0) //�ر��ļ�����
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
