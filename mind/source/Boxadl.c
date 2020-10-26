/**********************************************
Description:  思维导图删框函数
Function list :  
		  
Attention:
Author:  倪启源
History:
***********************************************/

#include "common.h"
#include "Boxadl.h"

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
void deletebox(MINDBOX (*editp)[16], int ho, int ve)
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
			editp[movei][ve].ste = 0;
			strcpy(editp[movei][ve].content, "");
			editp[movei][ve].boxcolor = BLACK;
			editp[movei][ve].textcolor = BLACK;
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
					editp[movei][ve].ste = 0;
					strcpy(editp[movei][ve].content, "");
					editp[movei][ve].boxcolor = BLACK;
			        editp[movei][ve].textcolor = BLACK;
				}
				if(j > ve + 1)
				{
					for(movej = ve + 1; movej < j; movej ++)
					{
						for(movei = 0; movei < HORI; movei ++)
						{
							editp[movei][movej].ste = 0;
					        strcpy(editp[movei][movej].content, "");
							editp[movei][movej].boxcolor = BLACK;
							editp[movei][movej].textcolor = BLACK;
						}
					}
				}
				for(movej = j; movej < VERT; movej ++)
				{
					for(movei = 0; movei < HORI; movei ++)
					{
						editp[movei][ve + movej - j].ste = editp[movei][movej].ste;
						editp[movei][ve + movej - j].boxcolor = editp[movei][movej].boxcolor;
						editp[movei][ve + movej - j].textcolor = editp[movei][movej].textcolor;
                        editp[movei][movej].ste = 0;
						editp[movei][movej].boxcolor = BLACK;
						editp[movei][movej].textcolor = BLACK;
						strcpy(editp[movei][ve + movej - j].content, editp[movei][movej].content);
						strcpy(editp[movei][movej].content,"");
					}
				}
			}
			else
			{
				for(movei = ho; movei < HORI; movei ++)
				{
					editp[movei][ve].ste = 0;
					strcpy(editp[movei][ve].content, "");
					editp[movei][ve].boxcolor = BLACK;
					editp[movei][ve].textcolor = BLACK;
				}
				if(j > ve + 1) 
				{
					for(movej = ve + 1; movej < j; movej ++)
					{
						for(movei = 0; movei < HORI; movei ++)
						{
							editp[movei][movej].ste = 0;
					        strcpy(editp[movei][movej].content, "");
							editp[movei][movej].boxcolor = BLACK;
							editp[movei][movej].textcolor = BLACK;
						}
					}
					for(movej = j; movej < VERT; movej ++)
				    {
						for(movei = 0; movei < HORI; movei ++)
					    {
							editp[movei][ve + movej - j + 1].ste = editp[movei][movej].ste;
							editp[movei][ve + movej - j + 1].boxcolor = editp[movei][movej].boxcolor;
							editp[movei][ve + movej - j + 1].textcolor = editp[movei][movej].textcolor;
						    editp[movei][movej].ste = 0;
							editp[movei][movej].boxcolor = BLACK;
							editp[movei][movej].textcolor = BLACK;
						    strcpy(editp[movei][ve + movej - j + 1].content, editp[movei][movej].content);
						    strcpy(editp[movei][movej].content,"");
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
					editp[movei][ve].ste = 0;
					strcpy(editp[movei][ve].content, "");
					editp[movei][ve].boxcolor = BLACK;
					editp[movei][ve].textcolor = BLACK;
				}
				if(j > ve + 1)
				{
					for(movej = ve + 1; movej < j; movej ++)
					{
						for(movei = 0; movei < HORI; movei ++)
						{
							editp[movei][movej].ste = 0;
					        strcpy(editp[movei][movej].content, "");
							editp[movei][movej].boxcolor = BLACK;
							editp[movei][movej].textcolor = BLACK;
						}
					}
				}
				for(movej = j; movej < VERT; movej ++)
				{
					for(movei = 0; movei < HORI; movei ++)
					{
						editp[movei][ve + movej - j].ste = editp[movei][movej].ste;
						editp[movei][ve + movej - j].boxcolor = editp[movei][movej].boxcolor;
						editp[movei][ve + movej - j].textcolor = editp[movei][movej].textcolor;
						editp[movei][movej].ste = 0;
						editp[movei][movej].boxcolor = BLACK;
						editp[movei][movej].textcolor = BLACK;
						strcpy(editp[movei][ve + movej - j].content, editp[movei][movej].content);
						strcpy(editp[movei][movej].content,"");
					}
				}
			}
			else
			{
				for(movei = ho; movei < HORI; movei ++)
				{
					editp[movei][ve].ste = editp[movei][j].ste;
					editp[movei][ve].boxcolor = editp[movei][j].boxcolor;
					editp[movei][ve].textcolor = editp[movei][j].textcolor;
					editp[movei][j].ste = 0;
					editp[movei][j].boxcolor = BLACK;
					editp[movei][j].textcolor = BLACK;
					strcpy(editp[movei][ve].content, editp[movei][j].content);
				    strcpy(editp[movei][j].content,"");
				}
				if(j > ve + 1)
				{
					for(movej = ve + 1; movej < j; movej ++)
					{
						for(movei = 0; movei < HORI; movei ++)
						{
							editp[movei][movej].ste = 0;
					        strcpy(editp[movei][movej].content, "");
							editp[movei][movej].boxcolor = BLACK;
							editp[movei][movej].textcolor = BLACK;
						}
					}
				}
				for(movej = j + 1; movej < VERT; movej ++)
				{
					for(movei = 0; movei < HORI; movei ++)
					{
						editp[movei][ve + movej - j].ste = editp[movei][movej].ste;
						editp[movei][ve + movej - j].boxcolor = editp[movei][movej].boxcolor;
						editp[movei][ve + movej - j].textcolor = editp[movei][movej].textcolor;
						editp[movei][movej].ste = 0;
						editp[movei][movej].boxcolor = BLACK;
						editp[movei][movej].textcolor = BLACK;
						strcpy(editp[movei][ve + movej - j].content, editp[movei][movej].content);
						strcpy(editp[movei][movej].content,"");
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
					editp[movei][ve].ste = 0;
					strcpy(editp[movei][ve].content, "");
					editp[movei][ve].boxcolor = BLACK;
					editp[movei][ve].textcolor = BLACK;
				}
				for(movej = ve + 1; movej < VERT; movej ++)
				{
					for(movei = 0; movei < HORI; movei ++)
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
				for(movei = ho; movei < HORI; movei ++)
				{
					editp[movei][ve].ste = 0;
					strcpy(editp[movei][ve].content, "");
					editp[movei][ve].ste = BLACK;
					editp[movei][ve].ste = BLACK;
				}
				for(movej = ve + 1; movej < VERT; movej ++)
				{
					for(movei = 0; movei < HORI; movei ++)
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
	if(j == VERT)
	{
		for(movei = ho; movei < HORI; movei ++)
		{
			editp[movei][ve].ste = 0;
			strcpy(editp[movei][ve].content, "");
			editp[movei][ve].boxcolor = BLACK;
			editp[movei][ve].textcolor = BLACK;
		}
		if(ve + 1 < VERT)
		{
			for(movej = ve + 1; movej < VERT; movej ++)
			{
				for(movei = 0; movei < HORI; movei ++)
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