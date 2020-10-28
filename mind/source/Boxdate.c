/**********************************************
Description:  �༭ʱ����������ң�����ɾ��������
Function list : finddate Ѱ��ʱ��
                drawdate ������ǰ��ʱ����
		        deletedate ɾȥĳ��ʱ��
Attention:
Author:  ����Դ
History:
***********************************************/

#include "common.h"
#include "Boxdate.h"

/**************************************************
Name: finddate
Function��Ѱ��ʱ��
Calls: drawdate
Called By: edidate
Parameter: edidate ��ѡ���ʱ����
           pdatenum λ��
Author: ����Դ
return flag �Ƿ��ҵ���
Others: ��
**************************************************/
int finddate(DATEINFO *edidate, int *pdatenum)
{
	int i = 0; //��������
	int flag = 0; //flag�����Ƿ�ѡ���������������
	while(i < edidate -> daynum)
	{
		switch((i / 5) % 2)
		{
			case 0:
			if(mouse_press(56 + 80 * (i % 5), 48 + 24 + (i / 5) * 80, 56 + 80 * (i % 5) + 64, 48 + 24 + (i / 5) * 80 + 64) == 1)
			{
				*pdatenum = i;
				setfillstyle(SOLID_FILL, WHITE);
		        bar(0, 24, 496, 480);
			    drawdate(edidate);
				setcolor(RED);
				setlinestyle(SOLID_LINE, 0, 3);
				rectangle(56 + 80 * (i % 5), 48 + 24 + (i / 5) * 80, 56 + 80 * (i % 5) + 64, 48 + 24 + (i / 5) * 80 + 64);
				flag = 1;
				break;
			}
			break;
			case 1:
			if(mouse_press(496 - 56 - 64 - 80 * (i % 5), 48 + 24 + (i / 5) * 80, 496 - 56 - 80 * (i % 5), 48 + 24 + (i / 5) * 80 + 64) == 1)
			{
				*pdatenum = i;
				setfillstyle(SOLID_FILL, WHITE);
		        bar(0, 24, 496, 480);
			    drawdate(edidate);
				setcolor(RED);
				setlinestyle(SOLID_LINE, 0, 3);
				rectangle(496 - 56 - 64 - 80 * (i % 5), 48 + 24 + (i / 5) * 80, 496 - 56 - 80 * (i % 5), 48 + 24 + (i / 5) * 80 + 64);
				flag = 1;
				break;
			}
			break;
		}
		if(flag == 1)
		{
			break;
		}
		i ++;
	}
	return flag;
}

/**************************************************
Name: drawdate
Function��������ǰ��ʱ����
Calls: ��
Called By: edidate finddate
Parameter: edidate Ҫ������ʱ����
Return: ��
Author: ����Դ
Others: ��
**************************************************/
void drawdate(DATEINFO *edidate)
{
	int i = 0; //��������
	char year[5]; //���ݴ�
	char month[3]; //���ݴ�
	char day[3]; //���ݴ�
	strcpy(year, "");
	strcpy(month, "");
	strcpy(day, "");
	setlinestyle(SOLID_LINE, 0, 3); //�����߶������
	while(i < edidate -> daynum) //����
	{
		setcolor(BLACK);
		settextstyle(SMALL_FONT, HORIZ_DIR, 5);
		itoa(edidate -> date[i].year, year, 10);
		itoa(edidate -> date[i].month, month, 10);
        itoa(edidate -> date[i].day, day, 10);
		switch((i / 5) % 2) //����,��
		{
			case 0:
			setcolor(BLUE);
			outtextxy(56 + 80 * (i % 5) + 6, 48 + 24 + (i / 5) * 80, year);
			setcolor(GREEN);
			outtextxy(56 + 80 * (i % 5) + 6, 48 + 24 + (i / 5) * 80 + 16, month);
			setcolor(RED);
			outtextxy(56 + 80 * (i % 5) + 6, 48 + 24 + (i / 5) * 80 + 32, day);
			setcolor(BLACK);
			outtextxy(56 + 80 * (i % 5) + 6, 48 + 24 + (i / 5) * 80 + 48, edidate -> date[i].content);
			setcolor(DARKGRAY);
			rectangle(56 + 80 * (i % 5), 48 + 24 + (i / 5) * 80, 56 + 80 * (i % 5) + 64, 48 + 24 + (i / 5) * 80 + 64);
			setcolor(LIGHTGRAY);
			line(56 + 80 * (i % 5), 48 + 24 + (i / 5) * 80 + 16, 56 + 80 * (i % 5) + 64, 48 + 24 + (i / 5) * 80 + 16);
			line(56 + 80 * (i % 5), 48 + 24 + (i / 5) * 80 + 32, 56 + 80 * (i % 5) + 64, 48 + 24 + (i / 5) * 80 + 32);
			line(56 + 80 * (i % 5), 48 + 24 + (i / 5) * 80 + 48, 56 + 80 * (i % 5) + 64, 48 + 24 + (i / 5) * 80 + 48);
			setcolor(BROWN);
			if(i % 5 == 4 && i != edidate -> daynum - 1)
			{
				line(56 + 80 * (i % 5) + 32, 48 + 24 + (i / 5) * 80 + 64, 56 + 80 * (i % 5) + 32, 48 + 24 + (i / 5) * 80 + 64 + 16);
			}
			else if(i != edidate -> daynum - 1)
			{
				line(56 + 80 * (i % 5) + 64, 48 + 24 + (i / 5) * 80 + 32, 56 + 80 * (i % 5) + 64 + 16, 48 + 24 + (i / 5) * 80 + 32);
			}
			break;
			case 1:
			setcolor(BLUE);
			outtextxy(496 - 56 - 64 - 80 * (i % 5) + 6, 48 + 24 + (i / 5) * 80, year);
			setcolor(GREEN);
			outtextxy(496 - 56 - 64 - 80 * (i % 5) + 6, 48 + 24 + (i / 5) * 80 + 16, month);
			setcolor(RED);
			outtextxy(496 - 56 - 64 - 80 * (i % 5) + 6, 48 + 24 + (i / 5) * 80 + 32, day);
			setcolor(BLACK);
			outtextxy(496 - 56 - 64 - 80 * (i % 5) + 6, 48 + 24 + (i / 5) * 80 + 48, edidate -> date[i].content);
			setcolor(DARKGRAY);
			rectangle(496 - 56 - 64 - 80 * (i % 5), 48 + 24 + (i / 5) * 80, 496 - 56 - 80 * (i % 5), 48 + 24 + (i / 5) * 80 + 64);
			setcolor(LIGHTGRAY);
			line(496 - 56 - 64 - 80 * (i % 5), 48 + 24 + (i / 5) * 80 + 16, 496 - 56 - 80 * (i % 5), 48 + 24 + (i / 5) * 80 + 16);
			line(496 - 56 - 64 - 80 * (i % 5), 48 + 24 + (i / 5) * 80 + 32, 496 - 56 - 80 * (i % 5), 48 + 24 + (i / 5) * 80 + 32);
			line(496 - 56 - 64 - 80 * (i % 5), 48 + 24 + (i / 5) * 80 + 48, 496 - 56 - 80 * (i % 5), 48 + 24 + (i / 5) * 80 + 48);
			setcolor(BROWN);
			if(i % 5 == 4 && i != edidate -> daynum - 1)
			{
				line(496 - 56 - 80 * (i % 5) - 32, 48 + 24 + (i / 5) * 80 + 64, 496 - 56 - 80 * (i % 5) - 32, 48 + 24 + (i / 5) * 80 + 64 + 16);
			}
			else if(i != edidate -> daynum - 1)
			{
				line(496 - 56 - 64 - 80 * (i % 5) - 16, 48 + 24 + (i / 5) * 80 + 32 ,496 - 56 - 64 - 80 * (i % 5), 48 + 24 + (i / 5) * 80 + 32);
			}
			break;
		}
		strcpy(year, "");
	    strcpy(month, "");
	    strcpy(day, "");
		i ++;
	}
}

/**************************************************
Name: deletedate
Function��ɾȥĳ��ʱ��
Calls: ��
Called By: edidate
Parameter: edidate ʱ����
           pdatenum λ��
Return: ��
Author: ����Դ
Others: ��
**************************************************/
void deletedate(DATEINFO *edidate, int pdatenum)
{
	int i = pdatenum; //��������
	while(i < edidate -> daynum - 1)
	{
		edidate -> date[i].year = edidate -> date[i + 1].year;
		edidate -> date[i].month = edidate -> date[i + 1].month;
		edidate -> date[i].day = edidate -> date[i + 1].day;
		strcpy(edidate -> date[i].content, edidate -> date[i + 1].content);
		i ++;
	}
	edidate -> daynum --;
}