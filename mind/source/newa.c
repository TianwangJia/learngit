/**************************************************
Description:����½����漰�书��
Function list:   new �½����湦��
                 pagenew �����½�����
Attention:
Author:����Դ
**************************************************/

#include <common.h>
#include <newa.h>
/**************************************************
Name: new
Function: �½����������Ϣ����ת����
Calls:
Called by:main
Parameter: account_name �û���
           daotu ���ڴ��ָ����˼ά��ͼ
Return: mstate �½�״̬
Others��
**************************************************/
int new (char *account_name, MIND *daotu)
{
	int mstate = 2;				  //��ʾ�½���ͼ״̬ 2��ʾ����ҳ���� 0δ�½����� 1��ʾ�½�����
	MIND new_mind = {0, ""};	  //�½�˼ά��ͼ��Ϣ��ʱ��Ŵ�
	int state = 0, pre_state = 0; //��ʾ���״̬�����ֵ
								  //0 �޲���״̬ 1 �ص��հױ༭ҳ��ť
								  //             2 ����ͼ��ť
								  //             3 ��״ͼ��ť
								  //			 4 ���ͼ��ť
								  //  			 5 ʱ���ᰴť
								  // 6 ȷ����  7 �˳���
	ENTER newmindname = {90, 400, 350, 440, 8, 0, 0, ""};
	clrmous(MouseX, MouseY);
	delay(100);
	//mouseinit();
	new_screen();
	mouseinit();

	while (mstate == 2)
	{
		newmouse(&MouseX, &MouseY, &press);

		input_mind(100, 408, 5, &newmindname);
		//�ص��༭ҳ
		if (mouse_press(540, 448, 610, 468) == 2) //�ڰ�ť��δ���
		{
			pre_state = state;
			state = 1;
			if (pre_state != 1) //��ֹ���ظ�������ֻ��֮ǰ������״̬�ű�����
			{
				clrmous(MouseX, MouseY);
				delay(5); //��ͼǰ�������꣬��ֹ����

				MouseS = 1;
				puthz(540, 448, "���ر༭", 16, 18, RED);
				setlinestyle(SOLID_FILL, 0, 1);
				setcolor(RED);
				line(540, 468, 610, 468);
			}
		}
		else if (mouse_press(540, 448, 610, 468) == 1) //�ڷ��ذ�ť���ҵ��
		{
			mstate = 0;
		}
		//ѡ��ĳһ����ͼģ��
		else if (mouse_press(50, 70, 200, 200) == 2) //�ڵ���ͼδ���
		{
			pre_state = state;
			state = 2;
			if (pre_state != 2) //��ֹ���ظ�������ֻ��֮ǰ������״̬�ű�����
			{
				clrmous(MouseX, MouseY);
				delay(5); //��ͼǰ�������꣬��ֹ����

				MouseS = 1;
			}
		}
		else if (mouse_press(50, 70, 200, 200) == 1) //�ڵ���ͼ�ҵ��
		{
			puthz(60, 176, "����˼ά��ͼ", 16, 18, WHITE); //����ͼ
			puthz(230, 176, "��״ͼ", 16, 18, BLACK);	   //��״ͼ
			puthz(400, 176, "���ͼ", 16, 18, BLACK);	   //���ͼ
			puthz(60, 326, "ʱ����", 16, 18, BLACK);	   //ʱ����
			new_mind.type = 1;
		}
		else if (mouse_press(220, 70, 370, 200) == 2) //����״ͼδ���
		{
			pre_state = state;
			state = 3;
			if (pre_state != 3) //��ֹ���ظ�������ֻ��֮ǰ������״̬�ű�����
			{
				clrmous(MouseX, MouseY);
				delay(5); //��ͼǰ�������꣬��ֹ����

				MouseS = 1;
			}
		}
		else if (mouse_press(220, 70, 370, 200) == 1) //����״ͼ�ҵ��
		{
			puthz(60, 176, "����˼ά��ͼ", 16, 18, BLACK); //����ͼ
			puthz(230, 176, "��״ͼ", 16, 18, WHITE);	   //��״ͼ
			puthz(400, 176, "���ͼ", 16, 18, BLACK);	   //���ͼ
			puthz(60, 326, "ʱ����", 16, 18, BLACK);	   //ʱ����
			new_mind.type = 2;
		}
		else if (mouse_press(390, 70, 540, 200) == 2) //�����ͼδ���
		{
			pre_state = state;
			state = 4;
			if (pre_state != 4) //��ֹ���ظ�������ֻ��֮ǰ������״̬�ű�����
			{
				clrmous(MouseX, MouseY);
				delay(5); //��ͼǰ�������꣬��ֹ����

				MouseS = 1;
			}
		}
		else if (mouse_press(390, 70, 540, 200) == 1) //�����ͼ�ҵ��
		{
			puthz(60, 176, "����˼ά��ͼ", 16, 18, BLACK); //����ͼ
			puthz(230, 176, "��״ͼ", 16, 18, BLACK);	   //��״ͼ
			puthz(400, 176, "���ͼ", 16, 18, WHITE);	   //���ͼ
			puthz(60, 326, "ʱ����", 16, 18, BLACK);	   //ʱ����
			new_mind.type = 3;
		}
		else if (mouse_press(50, 220, 200, 350) == 2) //��ʱ����δ���
		{
			pre_state = state;
			state = 5;
			if (pre_state != 5) //��ֹ���ظ�������ֻ��֮ǰ������״̬�ű�����
			{
				clrmous(MouseX, MouseY);
				delay(5); //��ͼǰ�������꣬��ֹ����

				MouseS = 1;
			}
		}
		else if (mouse_press(50, 220, 200, 350) == 1) //��ʱ�����ҵ��
		{
			puthz(60, 176, "����˼ά��ͼ", 16, 18, BLACK); //����ͼ
			puthz(230, 176, "��״ͼ", 16, 18, BLACK);	   //��״ͼ
			puthz(400, 176, "���ͼ", 16, 18, BLACK);	   //���ͼ
			puthz(60, 326, "ʱ����", 16, 18, WHITE);	   //ʱ����
			new_mind.type = 4;
		}
		else if (mouse_press(360, 400, 420, 440) == 2) //��ȷ����δ���
		{
			pre_state = state;
			state = 6;
			if (pre_state != 6) //��ֹ���ظ�������ֻ��֮ǰ������״̬�ű�����
			{
				clrmous(MouseX, MouseY);
				delay(5); //��ͼǰ�������꣬��ֹ����

				MouseS = 1;
			}
		}
		else if (mouse_press(360, 400, 420, 440) == 1) //��ȷ�����ҵ��
		{
			setfillstyle(SOLID_FILL, LIGHTCYAN);
			bar(95, 444, 350, 470);
			//ȷ���Ƿ����Ҫ��
			if (newmindname.str[0] == '\0') //���ޣ�
			{
				puthz(100, 448, "δ�����½��ļ���", 16, 18, LIGHTGRAY);
			}
			else if (strlen(newmindname.str) >= 9) //�����
			{
				puthz(100, 448, "�����ַ�", 16, 18, LIGHTGRAY);
			}
			else if (new_mind.type == 0) //����ѡ�ˣ�
			{
				puthz(100, 448, "ѡ�������", 16, 18, LIGHTGRAY);
			}
			else if (daotujud(account_name, newmindname.str)) //�ظ���
			{
				puthz(100, 448, "�ļ����Ѵ���", 16, 18, LIGHTGRAY);
			}
			else
			{
				newmind(account_name, newmindname.str, &new_mind);
				*daotu = new_mind;
				mstate = 1;
			}
		}
		else if (mouse_press(430, 448, 464, 468) == 2)
		{
			pre_state = state;
			state = 7;
			if (pre_state != 7) //��ֹ���ظ�������ֻ��֮ǰ������״̬�ű�����
			{
				clrmous(MouseX, MouseY);
				delay(5); //��ͼǰ�������꣬��ֹ����

				MouseS = 1;
				puthz(430, 448, "�˳�", 16, 18, RED);
				setlinestyle(SOLID_FILL, 0, 1);
				setcolor(RED);
				line(430, 448, 464, 468);
			}
		}
		else if (mouse_press(430, 448, 464, 468) == 1) //�˳���
		{
			closegraph(); //�رջ�ͼ
			delay(100);	  //�ɽ��������ʱ���״̬���ȶ�������ѧ����Ӧ���ױ���������
			exit(0);	  //�˳�����
		}
		else //�޲���״̬
		{
			pre_state = state;
			state = 0;
		}
		//���״̬�����ı䣬��֮ǰ�����޲���״̬����������������
		if (pre_state != state && pre_state != 0)
		{
			clrmous(MouseX, MouseY);
			delay(5);

			switch (pre_state)
			{
			case 1:
				MouseS = 0;
				puthz(540, 448, "���ر༭", 16, 18, BLUE);
				setlinestyle(SOLID_FILL, 0, 1);
				setcolor(BLUE);
				line(540, 468, 610, 468);
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				MouseS = 0;
				break;
			case 7:
				MouseS = 0;
				puthz(430, 448, "�˳�", 16, 18, BLUE);
				setlinestyle(SOLID_FILL, 0, 1);
				setcolor(BLUE);
				line(430, 448, 464, 468);
				break;
			}
		}
	}
	return mstate;
}

/**************************************************
Name: new_screen
Function�����½�����
Calls: 
Called By: new
Parameter��
Return: 
Others: 
**************************************************/
void new_screen()
{
	int i, j; //���������
	int head[8] = {465, 75, 440, 95, 490, 95, 465, 75};
	int tail[8] = {465, 145, 440, 165, 490, 165, 465, 145};

	//����
	cleardevice();
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	bar(0, 0, 640, 480);

	//���ر༭���ص��հױ༭ҳ��ť
	settextjustify(LEFT_TEXT, TOP_TEXT);
	puthz(540, 448, "���ر༭", 16, 18, BLUE);
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(BLUE);
	line(540, 468, 610, 468);

	//ѡ��һ����ʼ��
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setcolor(LIGHTGRAY);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	bar(0, 0, 640, 60);
	puthz(30, 30, "ѡ��һ����ʼ��", 24, 30, BLACK);

	//˼ά��ͼģ������
	//��ͼ��
	setfillstyle(SOLID_FILL, WHITE);
	bar(50, 70, 200, 170);	//����ͼ
	bar(220, 70, 370, 170); //��״ͼ
	bar(390, 70, 540, 170); //���ͼ
	bar(50, 220, 200, 320); //ʱ����
	//���ƿ�
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(50, 170, 200, 200);	 //����ͼ
	bar(220, 170, 370, 200); //��״ͼ
	bar(390, 170, 540, 200); //���ͼ
	bar(50, 320, 200, 350);	 //ʱ����
	//����
	settextjustify(LEFT_TEXT, TOP_TEXT);
	puthz(60, 176, "����˼ά��ͼ", 16, 18, BLACK); //����ͼ
	puthz(230, 176, "��״ͼ", 16, 18, BLACK);	   //��״ͼ
	puthz(400, 176, "���ͼ", 16, 18, BLACK);	   //���ͼ
	puthz(60, 326, "ʱ����", 16, 18, BLACK);	   //ʱ����

	//ͼ��
	//�򲿷�
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	setcolor(LIGHTGREEN);
	setlinestyle(0, 0, 1);
	bar(60, 110, 110, 130); //����ͼ
	for (i = 0; i < 3; i++)
	{
		bar(140, 80 + i * 30, 190, 100 + i * 30);
	}
	bar(270, 80, 320, 100); //��״ͼ
	for (i = 0; i < 3; i++)
	{
		bar(235 + i * 45, 120, 265 + i * 45, 140);
	}
	for (i = 0; i < 3; i++) //ʱ����
	{
		bar(50 + 10 + i * 50, 250, 50 + 10 + 30 + i * 50, 290);
		for (j = 0; j < 3; j++)
		{
			setcolor(BLACK);
			line(50 + 10 + i * 50, 260 + j * 10, 50 + 10 + 30 + i * 50, 260 + j * 10);
		}
	}
	//���ͼ
	fillpoly(4, head);
	fillpoly(4, tail);

	//���߲���
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, 0, 2);
	for (i = 0; i < 3; i++) //����ͼ
	{
		line(110, 120, 140, 90 + i * 30);
	}
	for (i = 0; i < 3; i++) //��״ͼ
	{
		line(295, 100, 250 + i * 45, 120);
	}
	for (i = 0; i < 2; i++) //ʱ����
	{
		line(50 + 10 + 30 + i * 50, 270, 50 + 10 + 30 + 20 + i * 50, 270);
	}
	//���ͼ
	line(465, 95, 465, 145);
	line(465, 105, 450, 120);
	line(450, 120, 425, 120);
	line(465, 120, 480, 135);
	line(480, 135, 505, 135);

	//�˳���ť
	settextjustify(LEFT_TEXT, TOP_TEXT);
	puthz(430, 448, "�˳�", 16, 18, BLUE);
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(BLUE);
	line(430, 468, 464, 468);

	//���뵼ͼ�ļ����ֿ�
	setlinestyle(SOLID_LINE, 0, 5);
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, BLUE);
	bar(10, 400, 90, 440);
	rectangle(10, 400, 90, 440);
	puthz(20, 408, "��ͼ��", 16, 20, YELLOW);
	setfillstyle(SOLID_FILL, WHITE);
	bar(90, 400, 350, 440); //�����
	setfillstyle(SOLID_FILL, RED);
	bar(360, 400, 420, 440);
	puthz(370, 408, "ȷ��", 16, 30, YELLOW);
}
