/**********************************************
Description:  编辑页面框图操作（增、删、查）函数集
Function list :  
		  
Attention:
Author:  贾田旺，倪启源
History:
***********************************************/

#include "common.h"
#include "Boxa.h"

/**************************************************
Name: findbox
Function：寻找框
Calls: 
Called By: edit.c
Parameter: editp 受选择的数组
           ho 水平位置
		   ve 竖直位置
Author: 倪启源
return flag 是否找到框
Others: 
**************************************************/
int findbox(MINDBOX (*editp)[VERT], int *ho, int *ve)
{
	int i,j; //计数变量
	int flag = 0; 
	for(i = 0; i < HORI; i ++)
	{
		for(j = 0; j < VERT; j ++)
		{
			if(mouse_press(8 + i * 80, 28 + j * 24, 8 + i * 80 + 64, 28 + j * 24 + 16) == 1)
			{
				if(editp[i][j].ste == 1)
				{
					*ho = i;
					*ve = j;
					setfillstyle(SOLID_FILL, WHITE);
					bar(0, 24, 496, 480);
					drawmind(editp);
					setcolor(RED);
					setlinestyle(SOLID_LINE, 0, 3);
					rectangle(8 + i * 80, 28 + j * 24, 8 + i * 80 + 64, 28 + j * 24 + 16);
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
Name: drawmind
Function：画出当前的导图
Calls: 
Called By: operate.c
Parameter: editp 要画出的导图
Return: 
Author: 倪启源
Others: 
**************************************************/
void drawmind(MINDBOX (*editp)[16])
{
	int i, j; //计数变量
	int k; //上溯计数变量

	setlinestyle(SOLID_LINE, 0, 3);
	setfillstyle(SOLID_FILL, WHITE);
	for(i = 0; i < HORI; i ++)
	{
		for(j = 0; j < VERT; j ++)
		{
			if(editp[i][j].ste == 1)
			{
				setcolor(editp[i][j].boxcolor);
				rectangle(8 + i * 80, 28 + j * 24, 8 + i * 80 + 64, 28 + j * 24 + 16);
				bar(8 + i * 80, 28 + j * 24, 8 + i * 80 + 64, 28 + j * 24 + 16);
				//settextjustify(LEFT_TEXT, TOP_TEXT);
				setcolor(editp[i][j].textcolor);
		        settextstyle(SMALL_FONT, HORIZ_DIR, 5);
		        outtextxy(8 + i * 80 + 6 , 28 + j * 24, editp[i][j].content);
				if(i != 0 || j != 0)
				{
					k = j;
					while(editp[i - 1][k].ste == 0)
					{
						k --;
					}
					setcolor(BLACK);
					line(8 + (i - 1) * 80 + 64, 28 + k * 24 + 8, 8 + i * 80, 28 + j * 24 + 8);
				}
			}
		}
	}
}

/**************************************************
Name: addbox
Function：新增，新增一个子节点
Calls: 
Called By: edit.c
Parameter: editp 要画出的导图
           ho 水平位置
		   ve 竖直位置
Return: 无
Author: 倪启源
Others: 判断新增的情况主要可以分为三种情况：
        1，选中的框的ho值为5，这个时候会溢出，点击addbox无反应
		（判断在函数调用之前完成）
		2，选中的框ho值小于5
		（1）如果该框（ho，ve）之后的（ho+1，ve）的ste值等于0，
		 则直接新增在这个框即可
		（2）从纵坐标ve+1开始遍历，每一行从最右边开始遍历，如果
		遍历到ho+1仍然ste=0，则直接从这一行开始的所有行下移一行
		在这一行的横坐标ho+1处新增一个框。
		若遇到ste=1的情况，则判断该行的横坐标ho处有无ste=1
		a.ste=1，则这一行的横坐标ho+1处为新增的框
		b.ste=0，开始遍历下一行
		注意（2）情况一定要先检查看看纵坐标VERT-1处有无ste=1的框，
		若有，则不执行任何操作（无法新增行！）
**************************************************/
void addbox(MINDBOX (*editp)[16], int ho, int ve) //还有微量bug，待de
{
	int i, j, k; //计数变量
	int movei, movej; //移动计数变量
	int check; //检测最后一排是否已经有元素 若check=HORI，
	           //则最后一行没有框
	int states; //框的修改方式存储变量
	int flag = 0;
	if(ho == HORI - 1)
	{
		return;
	}
	
	for(check = 0; check < HORI; check ++)
	{
		if(editp[check][VERT - 1].ste == 1)
		{
			break;
		}
	}
	
	if(editp[ho + 1][ve].ste == 0)
	{
		editp[ho + 1][ve].ste = 1;
	}
	else
	{
		for(j = ve + 1; j < VERT; j ++)
		{
			for(i = HORI - 1; i > ho; i --)
			{
				if(editp[i][j].ste == 1 && i > ho)
				{
					break;
				}
			}
			
			if(i == ho || editp[ho][j].ste == 1) //新增的框在（ho+1，j）处
			{
				if(check == HORI)
				{
					for(movej = VERT - 2; movej >= j; movej --)
					{
						for(movei = 0; movei < HORI; movei ++)
						{
							editp[movei][movej + 1].ste = editp[movei][movej].ste;
							editp[movei][movej + 1].boxcolor = editp[movei][movej].boxcolor;
							editp[movei][movej + 1].textcolor = editp[movei][movej].textcolor;
							editp[movei][movej].ste = 0;
							editp[movei][movej].boxcolor = BLACK;
							editp[movei][movej].textcolor = BLACK;
							strcpy(editp[movei][movej + 1].content, editp[movei][movej].content);
							strcpy(editp[movei][movej].content, "");
						}
					}
					editp[ho + 1][j].ste = 1;
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