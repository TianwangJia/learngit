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
Function���ƶ���Ϣ����
Calls: 
Called By: Boxa.c Boxadl.c Boxtr.c Boxtrdl.c
Parameter: former �������ݵĵ�Ԫ
           latter �ͷ����ݵĵ�Ԫ
Return: ��
Author: ����Դ
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
Function���ÿ���Ϣ����
Calls: 
Called By: Boxa.c Boxadl.c Boxtr.c Boxtrdl.c
Parameter: clrbox ������ݵĵ�Ԫ
Return: ��
Author: ����Դ
Others: 
**************************************************/
void vanbox(MINDBOX *clrbox)
{
	clrbox -> ste = 0;
	strcpy(clrbox -> content, "");
	clrbox -> boxcolor = BLACK;
	clrbox -> textcolor = BLACK;
}