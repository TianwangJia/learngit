/**********************************************
Description:  �༭ҳ���ͼ����������ɾ���飩������
Function list :  
		  
Attention:
Author:  ������������Դ
History:
***********************************************/

#include "common.h"
#include "Boxtr.h"

/**************************************************
Name: findbox
Function��Ѱ�ҿ�
Calls: 
Called By: edittr.c
Parameter: editp ��ѡ�������
           ho ˮƽλ��
		   ve ��ֱλ��
Author: ����Դ
return flag �Ƿ��ҵ���
Others: 
**************************************************/
int findbox_tr(MINDBOX (*editp)[VERTREE], int *ho, int *ve)
{
	int i,j; //��������
	int flag = 0; //flag�����Ƿ�ѡ�����������������ѡ���ˣ����Ϊ1������Ϊ0
	for(i = 0; i < HORI; i ++)
	{
		for(j = 0; j < VERTREE; j ++)
		{
			if(mouse_press(8 + i * 80, 34 + j * 36, 8 + i * 80 + 64, 34 + j * 36 + 16) == 1)
			{
				if(editp[i][j].ste == 1)
				{
					*ho = i;
					*ve = j;
					setfillstyle(SOLID_FILL, WHITE);
					bar(0, 24, 496, 480);
					drawmind_tr(editp);
					setcolor(RED);
					setlinestyle(SOLID_LINE, 0, 3);
					rectangle(8 + i * 80, 34 + j * 36, 8 + i * 80 + 64, 34 + j * 36 + 16);
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
Function��������ǰ�ĵ�ͼ
Calls: 
Called By: operate.c
Parameter: editp Ҫ�����ĵ�ͼ
Return: 
Author: ����Դ
Others: 
**************************************************/
void drawmind_tr(MINDBOX (*editp)[VERTREE])
{
	int i, j; //��������
	int k; //���ݼ�������
	setlinestyle(SOLID_LINE, 0, 3);
	setfillstyle(SOLID_FILL, WHITE);
	for(i = 0; i < HORI; i ++)
	{
		for(j = 0; j < VERTREE; j ++)
		{
			if(editp[i][j].ste == 1)
			{
				setcolor(editp[i][j].boxcolor);
				rectangle(8 + i * 80, 34 + j * 36, 8 + i * 80 + 64, 34 + j * 36 + 16);
				bar(8 + i * 80, 34 + j * 36, 8 + i * 80 + 64, 34 + j * 36 + 16);
				//settextjustify(LEFT_TEXT, TOP_TEXT);
				setcolor(editp[i][j].textcolor);
		        settextstyle(SMALL_FONT, HORIZ_DIR, 5);
		        outtextxy(8 + i * 80 + 6 , 34 + j * 36, editp[i][j].content);
				if(i != 0 || j != 0)
				{
					k = i;
					while(editp[k][j - 1].ste == 0)
					{
						k --;
					}
					setcolor(BLACK);
					line(8 + k * 80 + 32, 34 + (j - 1) * 36 + 16, 8 + i * 80 + 32, 34 + j * 36);
				}
			}
		}
	}
}

/**************************************************
Name: addbox
Function������������һ���ӽڵ�
Calls: 
Called By: edit.c
Parameter: editp Ҫ�����ĵ�ͼ
           ho ˮƽλ��
		   ve ��ֱλ��
Return: ��
Author: ����Դ
Others: �ж������������Ҫ���Է�Ϊ���������
        1��ѡ�еĿ��hoֵΪ5�����ʱ�����������addbox�޷�Ӧ
		���ж��ں�������֮ǰ��ɣ�
		2��ѡ�еĿ�hoֵС��5
		��1������ÿ�ho��ve��֮��ģ�ho+1��ve����steֵ����0��
		 ��ֱ������������򼴿�
		��2����������ve+1��ʼ������ÿһ�д����ұ߿�ʼ���������
		������ho+1��Ȼste=0����ֱ�Ӵ���һ�п�ʼ������������һ��
		����һ�еĺ�����ho+1������һ����
		������ste=1����������жϸ��еĺ�����ho������ste=1
		a.ste=1������һ�еĺ�����ho+1��Ϊ�����Ŀ�
		b.ste=0����ʼ������һ��
		ע�⣨2�����һ��Ҫ�ȼ�鿴��������VERT-1������ste=1�Ŀ�
		���У���ִ���κβ������޷������У���
**************************************************/
void addbox_tr(MINDBOX (*editp)[VERTREE], int ho, int ve) //����΢��bug����de
{
	int i, j, k; //��������
	int movei, movej; //�ƶ���������
	int check; //������һ���Ƿ��Ѿ���Ԫ�� ��check=HORI��
	           //�����һ��û�п�
	int states; //����޸ķ�ʽ�洢����
	int flag = 0;
	if(ve == VERTREE - 1)
	{
		return;
	}
	
	for(check = 0; check < VERTREE; check ++)
	{
		if(editp[HORI - 1][ve].ste == 1)
		{
			break;
		}
	}
	
	if(editp[ho][ve + 1].ste == 0)
	{
		editp[ho][ve + 1].ste = 1;
	}
	else
	{
		for(i = ho + 1; i < HORI; i ++)
		{
			for(j = VERTREE - 1; j > ve; j --)
			{
				if(editp[i][j].ste == 1 && j > ve)
				{
					break;
				}
			}
			
			if(j == ve || editp[i][ve].ste == 1) //�����Ŀ��ڣ�ho+1��j����
			{
				if(check == VERTREE)
				{
					for(movei = HORI - 2; movei >= i; movei --)
					{
						for(movej = 0; movej < VERTREE; movej ++)
						{
							editp[movei + 1][movej].ste = editp[movei][movej].ste;
							editp[movei + 1][movej].boxcolor = editp[movei][movej].boxcolor;
							editp[movei + 1][movej].textcolor = editp[movei][movej].textcolor;
							editp[movei][movej].ste = 0;
							editp[movei][movej].boxcolor = BLACK;
							editp[movei][movej].textcolor = BLACK;
							strcpy(editp[movei + 1][movej].content, editp[movei][movej].content);
							strcpy(editp[movei][movej].content, "");
						}
					}
					editp[i][ve + 1].ste = 1;
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