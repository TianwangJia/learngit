/**********************************************
Description:  �༭���ͼ����
Function list : findbone Ѱ�����
                drawbone ������ǰ�����ͼ
				deletebone ɾȥĳ����ͷ
				addbone ����ĳ����ͷ
Attention:
Author:  ����Դ
History:
***********************************************/

#include "common.h"
#include "Boxfb.h"

/**************************************************
Name: findbone
Function��Ѱ�����
Calls: drawbone
Called By: editfb
Parameter: edifish ��ѡ�������
           pnum ���λ��
Author: ����Դ
return flag �Ƿ��ҵ���
Others: ��
**************************************************/
int findbone(FISHINFO *edifish, int *pnum)
{
	int i = 0; //��������
	int flag = 0; //flag�����Ƿ�flag�����Ƿ�ѡ�����������������ѡ���ˣ����Ϊ1������Ϊ0
	while(i < edifish -> bonenum)
	{
		if(mouse_press(248 - 114 + 164 * (i % 2), 80 + 24 + i * 40, 248 - 50 + 164 * (i % 2), 80 + 40 + i * 40) == 1)
		{
			*pnum = i;
			setfillstyle(SOLID_FILL, WHITE);
		    bar(0, 24, 496, 480);
			drawbone(edifish);
			setcolor(RED);
			setlinestyle(SOLID_LINE, 0, 3);
			line(248, 80 + 20 + i * 40, 248 - 50 + 100 * (i % 2), 80 + 40 + i * 40);
			rectangle(248 - 114 + 164 * (i % 2), 80 + 24 + i * 40, 248 - 50 + 164 * (i % 2), 80 + 40 + i * 40);
			flag = 1;
			break;
		}
		i ++;
	}
	return flag;
}

/**************************************************
Name: drawbone
Function��������ǰ�����ͼ
Calls: ��
Called By: editfb findbone
Parameter: editp Ҫ���������ͼ
Return: ��
Author: ����Դ
Others: ��
**************************************************/
void drawbone(FISHINFO *edifish)
{
	int i = 0; //��������
	int headoffish[12] = //��ͷ����
	{
		248 - 10, 30, 248 - 40, 80, 248 + 40, 80, 248 + 10, 30, 248, 50, 248 - 10, 30
	};
	int tailoffish[8];
	tailoffish[0] = 248;
	tailoffish[2] = 248 - 30;
	tailoffish[4] = 248 + 30;
	tailoffish[6] = 248;
	tailoffish[1] = (edifish -> bonenum) * 40 + 80;
	tailoffish[3] = (edifish -> bonenum) * 40 + 80 + 60;
	tailoffish[5] = (edifish -> bonenum) * 40 + 80 + 60;
	tailoffish[7] = (edifish -> bonenum) * 40 + 80;
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(LIGHTGRAY);
	fillpoly(6, headoffish);
	fillpoly(4, tailoffish);
	line(248, 80, 248, (edifish -> bonenum) * 40 + 80);
	setfillstyle(SOLID_FILL, WHITE);
	fillellipse(248, 65, 10, 10);
	while(i < edifish -> bonenum)
	{
		setcolor(BLACK);
		settextstyle(SMALL_FONT, HORIZ_DIR, 5);
		outtextxy(248 - 114 + 164 * (i % 2) + 6, 80 + 24 + i * 40, edifish->bone[i].content);
		setcolor(LIGHTGRAY);
		line(248, 80 + 20 + i * 40, 248 - 50 + 100 * (i % 2), 80 + 40 + i * 40);
		line(248 - 114 + 228 * (i % 2) ,80 + 40 + i * 40, 248 - 50 + 100 * (i % 2), 80 + 40 + i * 40);
		i ++;
	}
}

/**************************************************
Name: deletebone
Function��ɾȥĳ����ͷ
Calls: ��
Called By: editfb
Parameter: edifish ���ͼ
           pnum ���λ��
Return: ��
Author: ����Դ
Others: ��
**************************************************/
void deletebone(FISHINFO *edifish, int pnum)
{
	int i = pnum; //��������
	while(i < edifish -> bonenum - 1)
	{
		strcpy(edifish -> bone[i].content, edifish -> bone[i + 1].content);
		i ++;
	}
	strcpy(edifish -> bone[i].content, "");
	edifish -> bonenum --;
}

/**************************************************
Name: addbone
Function: ����ĳ����ͷ
Calls: ��
Called By: editfb
Parameter: edifish ���ͼ
           pnum ���λ��
Return: ��
Author: ����Դ
Others: ��
**************************************************/
void addbone(FISHINFO *edifish, int pnum)
{
	int i = edifish -> bonenum;
	while(i > pnum + 1)
	{
		strcpy(edifish -> bone[i].content, edifish -> bone[i - 1].content);
		i --;
	}
	strcpy(edifish -> bone[i].content, "");
	edifish -> bonenum ++;
}