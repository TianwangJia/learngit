/**********************************************
Description:  编辑时间轴操作（找，画，删）函数集
Function list : finddate 寻找时间
                drawdate 画出当前的时间轴
		        deletedate 删去某个时间
Attention:
Author:  倪启源
History:
***********************************************/

#include "common.h"
#include "Boxdate.h"

/**************************************************
Name: finddate
Function：寻找时间
Calls: drawdate
Called By: edidate
Parameter: edidate 受选择的时间轴
           pdatenum 位置
Author: 倪启源
return flag 是否找到框
Others: 无
**************************************************/
int finddate(DATEINFO *edidate, int *pdatenum)
{
	int i = 0; //计数变量
	int flag = 0; //flag代表是否选中了所点击的区域
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
Function：画出当前的时间轴
Calls: 无
Called By: edidate finddate
Parameter: edidate 要画出的时间轴
Return: 无
Author: 倪启源
Others: 无
**************************************************/
void drawdate(DATEINFO *edidate)
{
	int i = 0; //计数变量
	char year[5]; //年暂存
	char month[3]; //月暂存
	char day[3]; //日暂存
	strcpy(year, "");
	strcpy(month, "");
	strcpy(day, "");
	setlinestyle(SOLID_LINE, 0, 3); //所有线都是如此
	while(i < edidate -> daynum) //画框
	{
		setcolor(BLACK);
		settextstyle(SMALL_FONT, HORIZ_DIR, 5);
		itoa(edidate -> date[i].year, year, 10);
		itoa(edidate -> date[i].month, month, 10);
        itoa(edidate -> date[i].day, day, 10);
		switch((i / 5) % 2) //画框,线
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
Function：删去某个时间
Calls: 无
Called By: edidate
Parameter: edidate 时间轴
           pdatenum 位置
Return: 无
Author: 倪启源
Others: 无
**************************************************/
void deletedate(DATEINFO *edidate, int pdatenum)
{
	int i = pdatenum; //计数变量
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