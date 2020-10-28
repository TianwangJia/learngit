/**********************************************
Description:  ��״ͼɾ����
Function list :  deletebox_tr ɾ���������е��ӽڵ�һ��ɾ������������ڵ��������е���
Attention:
Author:  ����Դ
History:
***********************************************/

#include "common.h"
#include "Boxtrdl.h"

/**************************************************
Name: deletebox_tr
Function��ɾ���������е��ӽڵ�һ��ɾ������������ڵ��������е���
Calls: movebox
       vanbox
Called By: edit
Parameter: editp Ҫ�����ĵ�ͼ
           ho ˮƽλ��
		   ve ��ֱλ��
Return: ��
Author: ����Դ
Others: ����˼·�ɲο�����˼ά��ͼ
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