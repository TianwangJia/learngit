/**********************************************
Description:  树状图删框函数
Function list :  deletebox_tr 删除，将所有的子节点一并删除，并对其余节点的坐标进行调整
Attention:
Author:  倪启源
History:
***********************************************/

#include "common.h"
#include "Boxtrdl.h"

/**************************************************
Name: deletebox_tr
Function：删除，将所有的子节点一并删除，并对其余节点的坐标进行调整
Calls: movebox
       vanbox
Called By: edit
Parameter: editp 要画出的导图
           ho 水平位置
		   ve 竖直位置
Return: 无
Author: 倪启源
Others: 具体思路可参考单向思维导图
**************************************************/
void deletebox_tr(MINDBOX (*editp)[VERTREE], int ho, int ve)
{
	int benlie; //遍历本列所使用的变量
	int i, j; //横纵遍历
	int movei, movej; //移动框工具变量
	for(benlie = 0; benlie < ve; benlie ++)
	{
		if(editp[ho][benlie].ste == 1)
		{
			break;
		}
	}
	
	if(ho == HORI - 1)
	{
		for(movej = ve; movej < VERTREE; movej ++)
		{
			vanbox(&editp[ho][movej]);
		}
		return;
	}
	for(i = ho + 1; i < HORI; i ++)//boxa姊妹情况
	{
		for(j = 0; j < VERTREE; j ++)
		{
			if(editp[i][j].ste == 1)
			{
				break;
			}
		}
		
		if(j < ve)
		{
			if(benlie == ve)
			{
				for(movej = ve; movej < VERTREE; movej ++)
				{
					vanbox(&editp[ho][movej]);
				}
				if(i > ho + 1)
				{
					for(movei = ho + 1; movei < i; movei ++)
					{
						for(movej = 0; movej < VERTREE; movej ++)
						{
							vanbox(&editp[movei][movej]);
						}
					}
				}
				for(movei = i; movei < HORI; movei ++)
				{
					for(movej = 0; movej < VERTREE; movej ++)
					{
						movebox(&editp[ho + movei - i][movej], &editp[movei][movej]);
					}
				}
			}
			else
			{
				for(movej = ve; movej < VERTREE; movej ++)
				{
					vanbox(&editp[ho][movej]);
				}
				if(i > ho + 1)
				{
					for(movei = ho + 1; movei < i; movei ++)
					{
						for(movej = 0; movej < VERTREE; movej ++)
						{
							vanbox(&editp[movei][movej]);
						}
					}
					for(movei = i; movei < HORI; movei ++)
				    {
						for(movej = 0; movej < VERTREE; movej ++)
					    {
							movebox(&editp[ho + movei - i + 1][movej], &editp[movei][movej]);
					    }
				    }
				}
			}
			break;
		}
		else if(j == ve)
		{
			if(benlie == ve)
			{
				for(movej = ve; movej < VERTREE; movej ++)
				{
					vanbox(&editp[ho][movej]);
				}
				if(i > ho + 1)
				{
					for(movei = ho + 1; movei < i; movei ++)
					{
						for(movej = 0; movej < VERTREE; movej ++)
						{
							vanbox(&editp[movei][movej]);
						}
					}
				}
				for(movei = i; movei < HORI; movei ++)
				{
					for(movej = 0; movej < VERTREE; movej ++)
					{
						movebox(&editp[ho + movei - i][movej], &editp[movei][movej]);
					}
				}
			}
			else
			{
				for(movej = ve; movej < VERTREE; movej ++)
				{
					movebox(&editp[ho][movej], &editp[i][movej]);
				}
				if(i > ho + 1)
				{
					for(movei = ho + 1; movei < i; movei ++)
					{
						for(movej = 0; movej < VERTREE; movej ++)
						{
							vanbox(&editp[movei][movej]);
						}
					}
				}
				for(movei = i + 1; movei < HORI; movei ++)
				{
					for(movej = 0; movej < VERTREE; movej ++)
					{
						movebox(&editp[ho + movei - i][movej], &editp[movei][movej]);
					}
				}
			}
			break;
		}
		else if(j < VERTREE && j > ve)
		{
			continue;
		}
		else
		{
			if(benlie == ve)
			{
				for(movej = ve; movej < VERTREE; movej ++)
				{
					vanbox(&editp[ho][movej]);
				}
				for(movei = ho + 1; movei < HORI; movei ++)
				{
					for(movej = 0; movej < VERTREE; movej ++)
					{
						vanbox(&editp[movei][movej]);
					}
				}
			}
			else
			{
				for(movej = ve; movej < VERTREE; movej ++)
				{
					vanbox(&editp[ho][movej]);
				}
				for(movei = ho + 1; movei < HORI; movei ++)
				{
					for(movej = 0; movej < VERTREE; movej ++)
					{
						vanbox(&editp[movei][movej]);
					}
				}
			}
			break;
		}
	}
	if(i == HORI)
	{
		for(movej = ve; movej < VERTREE; movej ++)
		{
			vanbox(&editp[ho][movej]);
		}
		if(ho + 1 < HORI)
		{
			for(movei = ho + 1; movei < HORI; movei ++)
			{
				for(movej = 0; movej < VERTREE; movej ++)
				{
					vanbox(&editp[movei][movej]);
				}
			}
		}
	}
}