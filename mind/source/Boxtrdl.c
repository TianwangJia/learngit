/**********************************************
Description:  思维导图删框函数
Function list :  
		  
Attention:
Author:  倪启源
History:
***********************************************/

#include "common.h"
#include "Boxtrdl.h"

/**************************************************
Name: deletebox
Function：删除，将所有的子节点一并删除，并对其余节点的坐标进行调整
Calls: 
Called By: edit.c
Parameter: editp 要画出的导图
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
			editp[ho][movej].ste = 0;
			strcpy(editp[ho][movej].content, "");
			editp[ho][movej].boxcolor = BLACK;
			editp[ho][movej].textcolor = BLACK;
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
					editp[ho][movej].ste = 0;
					strcpy(editp[ho][movej].content, "");
					editp[ho][movej].boxcolor = BLACK;
					editp[ho][movej].textcolor = BLACK;
				}
				if(i > ho + 1)
				{
					for(movei = ho + 1; movei < i; movei ++)
					{
						for(movej = 0; movej < VERTREE; movej ++)
						{
							editp[movei][movej].ste = 0;
					        strcpy(editp[movei][movej].content, "");
							editp[movei][movej].boxcolor = BLACK;
							editp[movei][movej].textcolor = BLACK;
						}
					}
				}
				for(movei = i; movei < HORI; movei ++)
				{
					for(movej = 0; movej < VERTREE; movej ++)
					{
						editp[ho + movei - i][movej].ste = editp[movei][movej].ste;
						editp[ho + movei - i][movej].boxcolor = editp[movei][movej].boxcolor;
						editp[ho + movei - i][movej].textcolor = editp[movei][movej].textcolor;
						editp[movei][movej].ste = 0;
						editp[movei][movej].boxcolor = BLACK;
						editp[movei][movej].textcolor = BLACK;
						strcpy(editp[ho + movei - i][movej].content, editp[movei][movej].content);
						strcpy(editp[movei][movej].content,"");
					}
				}
			}
			else
			{
				for(movej = ve; movej < VERTREE; movej ++)
				{
					editp[ho][movej].ste = 0;
					strcpy(editp[ho][movej].content, "");
					editp[ho][movej].boxcolor = BLACK;
					editp[ho][movej].textcolor = BLACK;
				}
				if(i > ho + 1)
				{
					for(movei = ho + 1; movei < i; movei ++)
					{
						for(movej = 0; movej < VERTREE; movej ++)
						{
							editp[movei][movej].ste = 0;
					        strcpy(editp[movei][movej].content, "");
							editp[movei][movej].boxcolor = BLACK;
							editp[movei][movej].textcolor = BLACK;
						}
					}
					for(movei = i; movei < HORI; movei ++)
				    {
						for(movej = 0; movej < VERTREE; movej ++)
					    {
							editp[ho + movei - i + 1][movej].ste = editp[movei][movej].ste;
							editp[ho + movei - i + 1][movej].boxcolor = editp[movei][movej].boxcolor;
							editp[ho + movei - i + 1][movej].textcolor = editp[movei][movej].textcolor;
						    editp[movei][movej].ste = 0;
							editp[movei][movej].boxcolor = BLACK;
							editp[movei][movej].textcolor = BLACK;
							strcpy(editp[ho + movei - i + 1][movej].content, editp[movei][movej].content);
						    strcpy(editp[movei][movej].content,"");
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
					editp[ho][movej].ste = 0;
					strcpy(editp[ho][movej].content, "");
					editp[ho][movej].boxcolor = BLACK;
					editp[ho][movej].textcolor = BLACK;
				}
				if(i > ho + 1)
				{
					for(movei = ho + 1; movei < i; movei ++)
					{
						for(movej = 0; movej < VERTREE; movej ++)
						{
							editp[movei][movej].ste = 0;
					        strcpy(editp[movei][movej].content, "");
							editp[movei][movej].boxcolor = BLACK;
							editp[movei][movej].textcolor = BLACK;
						}
					}
				}
				for(movei = i; movei < HORI; movei ++)
				{
					for(movej = 0; movej < VERTREE; movej ++)
					{
						editp[ho + movei - i][movej].ste = editp[movei][movej].ste;
						editp[ho + movei - i][movej].boxcolor = editp[movei][movej].boxcolor;
						editp[ho + movei - i][movej].textcolor = editp[movei][movej].textcolor;
						editp[movei][movej].ste = 0;
						editp[movei][movej].boxcolor = BLACK;
						editp[movei][movej].textcolor = BLACK;
						strcpy(editp[ho + movei - i][movej].content, editp[movei][movej].content);
						strcpy(editp[movei][movej].content,"");
					}
				}
			}
			else
			{
				for(movej = ve; movej < VERTREE; movej ++)
				{
					editp[ho][movej].ste = editp[i][movej].ste;
					editp[ho][movej].boxcolor = editp[i][movej].boxcolor;
					editp[ho][movej].textcolor = editp[i][movej].textcolor;
					editp[i][movej].ste = 0;
					editp[i][movej].boxcolor = BLACK;
					editp[i][movej].textcolor = BLACK;
					strcpy(editp[ho][movej].content, editp[i][movej].content);
				    strcpy(editp[i][movej].content,"");
				}
				if(i > ho + 1)
				{
					for(movei = ho + 1; movei < i; movei ++)
					{
						for(movej = 0; movej < VERTREE; movej ++)
						{
							editp[movei][movej].ste = 0;
					        strcpy(editp[movei][movej].content, "");
							editp[movei][movej].boxcolor = BLACK;
							editp[movei][movej].textcolor = BLACK;
						}
					}
				}
				for(movei = i + 1; movei < HORI; movei ++)
				{
					for(movej = 0; movej < VERTREE; movej ++)
					{
						editp[ho + movei - i][movej].ste = editp[movei][movej].ste;
						editp[ho + movei - i][movej].boxcolor = editp[movei][movej].boxcolor;
						editp[ho + movei - i][movej].textcolor = editp[movei][movej].textcolor;
						editp[movei][movej].ste = 0;
						editp[movei][movej].boxcolor = BLACK;
						editp[movei][movej].textcolor = BLACK;
						strcpy(editp[ho + movei - i][movej].content, editp[movei][movej].content);
						strcpy(editp[movei][movej].content,"");
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
					editp[ho][movej].ste = 0;
					strcpy(editp[ho][movej].content, "");
					editp[ho][movej].boxcolor = BLACK;
					editp[ho][movej].textcolor = BLACK;
				}
				for(movei = ho + 1; movei < HORI; movei ++)
				{
					for(movej = 0; movej < VERTREE; movej ++)
					{
						editp[movei][movej].ste = 0;
						strcpy(editp[movei][movej].content,"");
						editp[movei][movej].boxcolor = BLACK;
						editp[movei][movej].textcolor = BLACK;
					}
				}
			}
			else
			{
				for(movej = ve; movej < VERTREE; movej ++)
				{
					editp[ho][movej].ste = 0;
					strcpy(editp[ho][movej].content, "");
					editp[ho][movej].boxcolor = BLACK;
					editp[ho][movej].boxcolor = BLACK;
				}
				for(movei = ho + 1; movei < HORI; movei ++)
				{
					for(movej = 0; movej < VERTREE; movej ++)
					{
						editp[movei][movej].ste = 0;
						strcpy(editp[movei][movej].content, "");
						editp[movei][movej].boxcolor = BLACK;
						editp[movei][movej].textcolor = BLACK;
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
			editp[ho][movej].ste = 0;
			strcpy(editp[ho][movej].content, "");
			editp[ho][movej].boxcolor = BLACK;
			editp[ho][movej].textcolor = BLACK;
		}
		if(ho + 1 < HORI)
		{
			for(movei = ho + 1; movei < HORI; movei ++)
			{
				for(movej = 0; movej < VERTREE; movej ++)
				{
					editp[movei][movej].ste = 0;
					strcpy(editp[movei][movej].content, "");
					editp[movei][movej].boxcolor = BLACK;
					editp[movei][movej].textcolor = BLACK;
				}
			}
		}
	}
}