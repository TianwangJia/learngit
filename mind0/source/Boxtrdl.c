/**********************************************
Description:  ˼ά��ͼɾ����
Function list :  
		  
Attention:
Author:  ����Դ
History:
***********************************************/

#include "common.h"
#include "Boxtrdl.h"

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
void deletebox_tr(MINDBOX (*editp)[VERTREE], int ho, int ve)
{
	int benlie; //����������ʹ�õı���
	int i, j; //���ݱ���
	int movei, movej; //�ƶ��򹤾߱���
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
	for(i = ho + 1; i < HORI; i ++)//boxa������
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