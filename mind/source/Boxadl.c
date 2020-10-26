/**********************************************
Description:  ˼ά��ͼɾ����
Function list :  
		  
Attention:
Author:  ����Դ
History:
***********************************************/

#include "common.h"
#include "Boxadl.h"

/**************************************************
Name: deletebox
Function��ɾ���������е��ӽڵ�һ��ɾ������������ڵ��������е���
Calls: 
Called By: edit.c
Parameter: editp Ҫ�����ĵ�ͼ
           ho ˮƽλ��
		   ve ��ֱλ��
Return: ��
Author: ����Դ
Others: �ж�ɾ���������
        �ȱ������У�������ֵĵ�һ�������Լ�����state=1
		�����state=0
		����һ�п�ʼ�����������һ���ں������ڱ���֮ǰ
		state=1ȫ��������ve
		state=0ȫ��������ve+1
		�����һ��������ڱ���
		state=1ȫ��������ve
		state=0ȫ��������ve������ֻ�Ӻ�����ho��ʼ�ƶ�
		�����һ������ڱ���֮��
		������һ��ѭ��
		����޿�
		state=1���ve�п�ʼ������
		state=0���ve+1�п�ʼ�������Լ�ve��ho���Ժ������
**************************************************/
void deletebox(MINDBOX (*editp)[16], int ho, int ve)
{
	int benhang; //����������ʹ�õı���
	int i, j; //���ݱ���
	int movei, movej; //�ƶ��򹤾߱���
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