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
			vanbox(&editp[ho][movej]);
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