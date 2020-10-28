/**********************************************
Description:  思维导图删框函数 基础函数（移动框，清空框）
Function list :  deletebox 删除，将所有的子节点一并删除，并对其余节点的坐标进行调整
                 movebox 移动信息函数
				 vanbox 置空信息函数
Attention:
Author:  倪启源
History:
***********************************************/

#include "common.h"
#include "Boxadl.h"

/**************************************************
Name: deletebox
Function：删除，将所有的子节点一并删除，并对其余节点的坐标进行调整
Calls: movebox
       vanbox
Called By: edit 
Parameter: editp 当前的存储思维导图的数组
           ho 水平位置
		   ve 竖直位置
Return: 无
Author: 倪启源
Others: 判断删除的情况：
        先遍历本行，如果出现的第一个框是自己，记state=1
		否则记state=0
		从下一行开始遍历，如果第一框在横坐标在本框之前
		state=1全体上移至ve
		state=0全体上移至ve+1
		如果第一框坐标等于本框
		state=1全体上移至ve
		state=0全体上移至ve，本行只从横坐标ho开始移动
		如果第一框出现在本框之后
		继续下一轮循环
		如果无框
		state=1清空ve行开始的所有
		state=0清空ve+1行开始的所有以及ve行ho及以后的所有
**************************************************/
void deletebox(MINDBOX (*editp)[VERT], int ho, int ve)
{
	int benhang; //遍历本行所使用的变量
	int i, j; //横纵遍历
	int movei, movej; //移动框工具变量
	for(benhang = 0; benhang < ho; benhang ++)
	{
		if(editp[benhang][ve].ste == 1)
		{
			break;
		}
	}
	
	if(ve == VERT - 1)
	{
		for(movei = ho; movei < HORI; movei ++)
		{
			vanbox(&editp[movei][ve]);
		}
		return;
	}
	for(j = ve + 1; j < VERT; j ++) 
	{
		for(i = 0; i < HORI; i ++)
		{
			if(editp[i][j].ste == 1)
			{
				break;
			}
		}
		
		if(i < ho)
		{
			if(benhang == ho)
			{
				for(movei = ho; movei < HORI; movei ++)
				{
					vanbox(&editp[movei][ve]);
				}
				if(j > ve + 1)
				{
					for(movej = ve + 1; movej < j; movej ++)
					{
						for(movei = 0; movei < HORI; movei ++)
						{
							vanbox(&editp[movei][movej]);
						}
					}
				}
				for(movej = j; movej < VERT; movej ++)
				{
					for(movei = 0; movei < HORI; movei ++)
					{
						movebox(&editp[movei][ve + movej - j], &editp[movei][movej]);
					}
				}
			}
			else
			{
				for(movei = ho; movei < HORI; movei ++)
				{
					vanbox(&editp[movei][ve]);
				}
				if(j > ve + 1) 
				{
					for(movej = ve + 1; movej < j; movej ++)
					{
						for(movei = 0; movei < HORI; movei ++)
						{
							vanbox(&editp[movei][movej]);
						}
					}
					for(movej = j; movej < VERT; movej ++)
				    {
						for(movei = 0; movei < HORI; movei ++)
					    {
							movebox(&editp[movei][ve + movej - j + 1], &editp[movei][movej]);
					    }
				    }
				}
			}
			break;
		}
		else if(i == ho)
		{
			if(benhang == ho)
			{
				for(movei = ho; movei < HORI; movei ++)
				{
					vanbox(&editp[movei][ve]);
				}
				if(j > ve + 1)
				{
					for(movej = ve + 1; movej < j; movej ++)
					{
						for(movei = 0; movei < HORI; movei ++)
						{
							vanbox(&editp[movei][movej]);
						}
					}
				}
				for(movej = j; movej < VERT; movej ++)
				{
					for(movei = 0; movei < HORI; movei ++)
					{
						movebox(&editp[movei][ve + movej - j], &editp[movei][movej]);
					}
				}
			}
			else
			{
				for(movei = ho; movei < HORI; movei ++)
				{
					movebox(&editp[movei][ve], &editp[movei][j]);
				}
				if(j > ve + 1)
				{
					for(movej = ve + 1; movej < j; movej ++)
					{
						for(movei = 0; movei < HORI; movei ++)
						{
							vanbox(&editp[movei][movej]);
						}
					}
				}
				for(movej = j + 1; movej < VERT; movej ++)
				{
					for(movei = 0; movei < HORI; movei ++)
					{
						movebox(&editp[movei][ve + movej - j], &editp[movei][movej]);
					}
				}
			}
			break;
		}
		else if(i < HORI && i > ho)
		{
			continue;
		}
		else
		{
			if(benhang == ho)
			{
				for(movei = ho; movei < HORI; movei ++)
				{
					vanbox(&editp[movei][ve]);
				}
				for(movej = ve + 1; movej < VERT; movej ++)
				{
					for(movei = 0; movei < HORI; movei ++)
					{
						vanbox(&editp[movei][movej]);
					}
				}
			}
			else
			{
				for(movei = ho; movei < HORI; movei ++)
				{
					vanbox(&editp[movei][ve]);
				}
				for(movej = ve + 1; movej < VERT; movej ++)
				{
					for(movei = 0; movei < HORI; movei ++)
					{
						vanbox(&editp[movei][movej]);
					}
				}
			}
			break;
		}
	}
	if(j == VERT)
	{
		for(movei = ho; movei < HORI; movei ++)
		{
			vanbox(&editp[movei][ve]);
		}
		if(ve + 1 < VERT)
		{
			for(movej = ve + 1; movej < VERT; movej ++)
			{
				for(movei = 0; movei < HORI; movei ++)
				{
					vanbox(&editp[movei][movej]);
				}
			}
		}
	}
}

/**************************************************
Name: movebox
Function：移动信息函数
Calls: 
Called By: Boxa.c Boxadl.c Boxtr.c Boxtrdl.c
Parameter: former 接收数据的单元
           latter 释放数据的单元
Return: 无
Author: 倪启源
Others: 
**************************************************/
void movebox(MINDBOX *former, MINDBOX *latter)
{
	former -> ste = latter -> ste;
	former -> boxcolor = latter -> boxcolor;
	former -> textcolor =latter -> textcolor;
	latter -> ste = 0;
	latter -> boxcolor = BLACK;
	latter -> textcolor = BLACK;
	strcpy(former -> content, latter -> content);
	strcpy(latter -> content,"");
}

/**************************************************
Name: vanbox
Function：置空信息函数
Calls: 
Called By: Boxa.c Boxadl.c Boxtr.c Boxtrdl.c
Parameter: clrbox 清除数据的单元
Return: 无
Author: 倪启源
Others: 
**************************************************/
void vanbox(MINDBOX *clrbox)
{
	clrbox -> ste = 0;
	strcpy(clrbox -> content, "");
	clrbox -> boxcolor = BLACK;
	clrbox -> textcolor = BLACK;
}