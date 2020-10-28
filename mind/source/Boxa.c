/**********************************************
Description:  �༭ҳ���ͼ�������顢��������������
Function list :  findbox Ѱ�ҵ���˼ά��ͼ�Ŀ�
                 drawmind ������ǰ�ĵ���˼ά��ͼ
		         addbox ��������������˼ά��ͼ��һ���ӽڵ�
Attention:
Author:  ����Դ
History:
***********************************************/

#include "common.h"
#include "Boxa.h"

/**************************************************
Name: findbox
Function��Ѱ�ҵ���˼ά��ͼ�Ŀ�
Calls: drawmind
Called By: edit
Parameter: editp ��ѡ�������
           ho ˮƽλ��
		   ve ��ֱλ��
Return��flag �Ƿ��ҵ���
Author: ����Դ
Others: ��
**************************************************/
int findbox(MINDBOX (*editp)[VERT], int *ho, int *ve)
{
	int i,j; //��������
	int flag = 0; 
	for(i = 0; i < HORI; i ++)
	{
		for(j = 0; j < VERT; j ++)
		{
			if(mouse_press(8 + i * 80, 28 + j * 24, 8 + i * 80 + 64, 28 + j * 24 + 16) == 1)
			{
				if(editp[i][j].ste == 1)
				{
					*ho = i;
					*ve = j;
					setfillstyle(SOLID_FILL, WHITE);
					bar(0, 24, 496, 480);
					drawmind(editp);
					setcolor(RED);
					setlinestyle(SOLID_LINE, 0, 3);
					rectangle(8 + i * 80, 28 + j * 24, 8 + i * 80 + 64, 28 + j * 24 + 16);
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
Function��������ǰ�ĵ���˼ά��ͼ
Calls: ��
Called By: edit
Parameter: editp ��ǰ�Ĵ洢˼ά��ͼ������
Return����
Author: ����Դ
Others: ��
**************************************************/
void drawmind(MINDBOX (*editp)[VERT])
{
	int i, j; //��������
	int k; //���ݼ�������

	setlinestyle(SOLID_LINE, 0, 3);
	setfillstyle(SOLID_FILL, WHITE);
	for(i = 0; i < HORI; i ++)
	{
		for(j = 0; j < VERT; j ++)
		{
			if(editp[i][j].ste == 1)
			{
				setcolor(editp[i][j].boxcolor);
				rectangle(8 + i * 80, 28 + j * 24, 8 + i * 80 + 64, 28 + j * 24 + 16);
				bar(8 + i * 80, 28 + j * 24, 8 + i * 80 + 64, 28 + j * 24 + 16);
				//settextjustify(LEFT_TEXT, TOP_TEXT);
				setcolor(editp[i][j].textcolor);
		        settextstyle(SMALL_FONT, HORIZ_DIR, 5);
		        outtextxy(8 + i * 80 + 6 , 28 + j * 24, editp[i][j].content);
				if(i != 0 || j != 0)
				{
					k = j;
					while(editp[i - 1][k].ste == 0)
					{
						k --;
					}
					setcolor(BLACK);
					line(8 + (i - 1) * 80 + 64, 28 + k * 24 + 8, 8 + i * 80, 28 + j * 24 + 8);
				}
			}
		}
	}
}

/**************************************************
Name: addbox
Function����������������˼ά��ͼ��һ���ӽڵ�
Calls: movebox
Called By: edit
Parameter: editp ��ǰ�Ĵ洢˼ά��ͼ������
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
void addbox(MINDBOX (*editp)[VERT], int ho, int ve) //����΢��bug����de
{
	int i, j, k; //��������
	int movei, movej; //�ƶ���������
	int check; //������һ���Ƿ��Ѿ���Ԫ�� ��check=HORI��
	           //�����һ��û�п�
	//int states; //����޸ķ�ʽ�洢����
	int flag = 0;
	if(ho == HORI - 1)
	{
		return;
	}
	
	for(check = 0; check < HORI; check ++)
	{
		if(editp[check][VERT - 1].ste == 1)
		{
			break;
		}
	}
	
	if(editp[ho + 1][ve].ste == 0)
	{
		editp[ho + 1][ve].ste = 1;
	}
	else
	{
		for(j = ve + 1; j < VERT; j ++)
		{
			for(i = HORI - 1; i > ho; i --)
			{
				if(editp[i][j].ste == 1 && i > ho)
				{
					break;
				}
			}
			
			if(i == ho || editp[ho][j].ste == 1) //�����Ŀ��ڣ�ho+1��j����
			{
				if(check == HORI)
				{
					for(movej = VERT - 2; movej >= j; movej --)
					{
						for(movei = 0; movei < HORI; movei ++)
						{
							movebox(&editp[movei][movej + 1], &editp[movei][movej]);
						}
					}
					editp[ho + 1][j].ste = 1;
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