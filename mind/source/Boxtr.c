/**********************************************
Description:  编辑树状图操作（查、画、增）函数集
Function list :  findbox_tr 寻找树状图的框
                 drawmind_tr 画出当前的树状图
				 addbox_tr 新增，新增树状图一个子节点
Attention:
Author:  倪启源
History:
***********************************************/

#include "common.h"
#include "Boxtr.h"

/**************************************************
Name: findbox_tr
Function：寻找树状图的框
Calls: drawmind_tr
Called By: edittr
Parameter: editp 受选择的数组
           ho 水平位置
		   ve 竖直位置
Return：flag 是否找到框
Author: 倪启源
Others: 无
**************************************************/
int findbox_tr(MINDBOX (*editp)[VERTREE], int *ho, int *ve)
{
	int i,j; //计数变量
	int flag = 0; //flag代表是否选中了所点击的区域，若选中了，则变为1，否则为0
	for(i = 0; i < HORI; i ++)
	{
		for(j = 0; j < VERTREE; j ++)
		{
			if(mouse_press(8 + i * 80, 34 + j * 36, 8 + i * 80 + 64, 34 + j * 36 + 16) == 1)
			{
				if(editp[i][j].ste == 1)
				{
					*ho = i;
					*ve = j;
					setfillstyle(SOLID_FILL, WHITE);
					bar(0, 24, 496, 480);
					drawmind_tr(editp);
					setcolor(RED);
					setlinestyle(SOLID_LINE, 0, 3);
					rectangle(8 + i * 80, 34 + j * 36, 8 + i * 80 + 64, 34 + j * 36 + 16);
					flag = 1;
				}
				break;
			}
		}
		if(flag == 1)
		{
			break;
		}
	}

	return flag;
}

/**************************************************
Name: drawmind_tr
Function：画出当前的树状图
Calls: 无
Called By: edittr
Parameter: editp 当前的存储树状图的数组
Return: 无
Author: 倪启源
Others: 无
**************************************************/
void drawmind_tr(MINDBOX (*editp)[VERTREE])
{
	int i, j; //计数变量
	int k; //上溯计数变量
	setlinestyle(SOLID_LINE, 0, 3);
	setfillstyle(SOLID_FILL, WHITE);
	for(i = 0; i < HORI; i ++)
	{
		for(j = 0; j < VERTREE; j ++)
		{
			if(editp[i][j].ste == 1)
			{
				setcolor(editp[i][j].boxcolor);
				rectangle(8 + i * 80, 34 + j * 36, 8 + i * 80 + 64, 34 + j * 36 + 16);
				bar(8 + i * 80, 34 + j * 36, 8 + i * 80 + 64, 34 + j * 36 + 16);
				//settextjustify(LEFT_TEXT, TOP_TEXT);
				setcolor(editp[i][j].textcolor);
		        settextstyle(SMALL_FONT, HORIZ_DIR, 5);
		        outtextxy(8 + i * 80 + 6 , 34 + j * 36, editp[i][j].content);
				if(i != 0 || j != 0)
				{
					k = i;
					while(editp[k][j - 1].ste == 0)
					{
						k --;
					}
					setcolor(BLACK);
					line(8 + k * 80 + 32, 34 + (j - 1) * 36 + 16, 8 + i * 80 + 32, 34 + j * 36);
				}
			}
		}
	}
}

/**************************************************
Name: addbox_tr
Function：新增，新增树状图一个子节点
Calls: movebox
Called By: edit.c
Parameter: editp 要画出的导图
           ho 水平位置
		   ve 竖直位置
Return: 无
Author: 倪启源
Others: 具体思路可参考单向思维导图
**************************************************/
void addbox_tr(MINDBOX (*editp)[VERTREE], int ho, int ve) //还有微量bug，待de
{
	int i, j, k; //计数变量
	int movei, movej; //移动计数变量
	int check; //检测最后一排是否已经有元素 若check=HORI，
	           //则最后一行没有框
	int states; //框的修改方式存储变量
	int flag = 0;
	if(ve == VERTREE - 1)
	{
		return;
	}
	
	for(check = 0; check < VERTREE; check ++)
	{
		if(editp[HORI - 1][ve].ste == 1)
		{
			break;
		}
	}
	
	if(editp[ho][ve + 1].ste == 0)
	{
		editp[ho][ve + 1].ste = 1;
	}
	else
	{
		for(i = ho + 1; i < HORI; i ++)
		{
			for(j = VERTREE - 1; j > ve; j --)
			{
				if(editp[i][j].ste == 1 && j > ve)
				{
					break;
				}
			}
			
			if(j == ve || editp[i][ve].ste == 1) //新增的框在（ho+1，j）处
			{
				if(check == VERTREE)
				{
					for(movei = HORI - 2; movei >= i; movei --)
					{
						for(movej = 0; movej < VERTREE; movej ++)
						{
							movebox(&editp[movei + 1][movej], &editp[movei][movej]);
						}
					}
					editp[i][ve + 1].ste = 1;
				}
				flag = 1;
			}
			if(flag == 1)
			{
				break;
			}
		}
	}
}