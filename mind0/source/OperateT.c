/**********************************************
Description:  �༭ҳ�漰����ҳ�����ù��ߺ���
Function list :  daotujud  �жϵ�ͼ�ļ��Ƿ��ظ�
                 newmind   �½�һ����ͼ�ļ�
                 input_mind ���벢��ʾ��Ϣ����
                 findmind  �ҵ��û��е�MIND�ṹ��
                 delete_mind ɾ���û��ļ��е�ָ��MIND�ṹ�壬��ɾ����Ӧ�ĵ�ͼ�ļ�
Attention:
Author:  ������������Դ
History:
***********************************************/

#include "common.h"
#include "operateT.h"

/**************************************************
Name: daotujud
Function���жϵ�ͼ�ļ��Ƿ��ظ�
Calls:
Called By: new Open.c
Parameter��account_name �û���
           mind_name ���½���˼ά��ͼ�ļ���
Return: ��ʶ��1Ϊ�ظ���0δ�ظ�
Author: ����Դ
Others:
**************************************************/

int daotujud(char *account_name, char *mind_name)
{
    FILE *fp;
    MIND *mind = NULL;
    int flag = 0;       //���ص�ͼ�ļ��Ƿ���ڱ�־,1���ڣ�0������
    int num;            //�û���ӵ�еĵ�ͼ�ļ�����
    int i;              //������
    char place[25 + 1]; //����û���ӵ�е��ļ�����Ϣ����
    sprintf(place, ".\\UserInfo\\%s.dat", account_name);

    if ((fp = fopen(place, "rb")) == NULL) //��ʧ�ܣ��쳣�˳�
    {
        closegraph();
        printf("\nFile UserInfo opening error.(from daotujud_open)\n");
        delay(3000);
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    num = ftell(fp) / sizeof(MIND); //�õ���ͼ����
    if (num == 0)                   //�޵�ͼ
    {
        flag = 0;
        return flag;
    }
    if ((mind = (MIND *)malloc(sizeof(MIND)) == NULL)) //�����ڴ�ʧ�ܣ��˳�����
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
    if (fclose(fp) != 0) //�ر��ļ�����
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
Function������Ӧ�û��½�һ��˼ά��ͼ���ļ�
Calls:
Called By: new
Parameter��type �½���˼ά��ͼ�������ʶ��
           account_name �û��� �½���������Ϣ�洢����Ӧ�û������ļ���
           mind_name �½���˼ά��ͼ�ļ���
		   dt ��ʱ���˼ά��ͼ��Ϣ�Ľṹ
Return: ��
Author: ����Դ
Others:
**************************************************/
void newmind(char *account_name, char *mind_name, MIND *dt) //�������ʹ�����
{
    FILE *fp;
	int i,j; //���������
    MINDBOX new_boxes[HORI][VERT];
	MINDBOX new_boxestr[HORI][VERTREE];
	FISHINFO new_fishbone;
	DATEINFO new_dates;
    char filename[32+ 1];   //˼ά��ͼλ������
    char filename_1[25 + 1]; //��Ӧ�û�ӵ�еĵ�ͼ��Ϣ�ļ�����
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
			new_boxes[i][j].boxcolor = BLACK;
			new_boxes[i][j].textcolor = BLACK;
		}
	}
	for(i = 0; i < BONEMAX; i ++)
	{
		strcpy(new_fishbone.bone[i].content,"");
	}

    strcpy(dt->mindname, mind_name); //������������Ϣ�ݴ���
    sprintf(filename, ".\\daotu\\%s\\%s.dat", account_name, mind_name);

    if ((fp = fopen(filename, "wb+")) == NULL) //�½�һ����ͼ�ļ�
    {
        //��ʧ�ܣ��쳣�˳�
        closegraph();
        printf("\nFile opening error.(from newmind_1)\n");
        delay(3000);
        exit(1);
    }
	
	switch(dt->type)
	{
		case 1: //��ʼ������˼ά��ͼ������
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
		
		case 2: //��ʼ����״ͼ������
		new_boxestr[0][0].ste = 1;
		strcpy(new_boxestr[0][0].content,"");
		new_boxes[0][0].textcolor = BLACK;
		new_boxes[0][0].boxcolor = BLACK;
		
		new_boxestr[0][1].ste = 1;
		strcpy(new_boxestr[0][1].content,"");
		new_boxes[0][1].textcolor = BLACK;
		new_boxes[0][1].boxcolor = BLACK;
		
		new_boxestr[1][1].ste = 1;
		strcpy(new_boxestr[1][1].content,"");
		new_boxes[1][1].textcolor = BLACK;
		new_boxes[1][1].boxcolor = BLACK;
		
		new_boxestr[2][1].ste = 1;
		strcpy(new_boxestr[2][1].content,"");
		new_boxes[2][1].textcolor = BLACK;
		new_boxes[2][1].boxcolor = BLACK;
		
		fseek(fp, 0, 0);
	    fwrite(&(new_boxestr[0][0]), sizeof(MINDBOX), HORI * VERT, fp);
		break;
		
		case 3: //��ʼ�����ͼ������
		new_fishbone.bonenum = 3;
		
		fseek(fp, 0, 0);
		fwrite(&new_fishbone, sizeof(FISHINFO), 1, fp);
		break;
		
		case 4: //��ʼ��ʱ���Ტ����
		new_dates.daynum = 0;
		
		fseek(fp, 0, 0);
		fwrite(&new_dates, sizeof(DATEINFO), 1, fp);
		break;
	}

    if (fclose(fp) != 0) //�ر��ļ�����
    {
        closegraph();
        printf("closed error.");
        delay(3000);
        exit(1);
    }

    sprintf(filename_1, ".\\UserInfo\\%s.dat", account_name);

    if ((fp = fopen(filename_1, "ab")) == NULL) //���û��ļ�
    {
        //��ʧ�ܣ��쳣�˳�
        closegraph();
        printf("\nFile opening error.(from newmind_2)\n");
        delay(3000);
        exit(1);
    }

    fwrite(dt, sizeof(MIND), 1, fp);

    if (fclose(fp) != 0) //�ر��ļ�����
    {
        closegraph();
        printf("closed error.");
        delay(3000);
        exit(1);
    }
}

/**************************************************
Name: input_mind
Function������������ʾ�����������µ�˼ά��ͼ��
Calls: ��
Called By: new Open.c
Parameter: x  ����λ����߽�
           y  ����λ���ϱ߽�
           size  �ַ���С
           content  ������Ϣ�Ľṹ�壬���data.h
Return: ��
Author: ����Դ
Others: ��
**************************************************/
void input_mind(int x, int y, int size, ENTER *content) //����Ϣ���뵽content�У�����ʾ����Ļ��
{
    char tmp;
    int i;
    if (press == 1)
    {
        if (mouse_press(content->x1, content->y1, content->x2, content->y2) == 1) //��������ڵ��
        {
            content->flag = 1;
            clrmous(MouseX, MouseY);

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

            setcolor(DARKGRAY);
            outtextxy(x, y, content->str);
            line(x + (content->cursor) * (2 * size - 2) + 3, y, x + (content->cursor) * (2 * size - 2) + 3, y + 2 * (2 * size - 2));
        }
    }
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
    int i, num;                                      //�������û�ӵ�е�ͼ����
    char place_user[25 + 1];                         //����û��ļ�����Ϣ����
    char place_tp[24 + 1] = ".\\UserInfo\\tmp_dmd.dat"; //��ʱ
    char place_daotu[32 + 1];                        //��ͼ�ļ�����
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
    if (mind1==NULL )//�����ڴ�ʧ�ܣ��˳�����
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









	
	
	
	
	