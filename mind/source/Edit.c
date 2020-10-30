/**********************************************
Description:  ����༭˼ά��ͼ���ܼ�����
Function list :  edit �༭ҳ�湦��
                edit_screen ���Ʊ༭ҳ��
				color_screen ���Ƶ�ɫ�����
Attention:  
Author:  ����Դ
History:  
***********************************************/

#include "common.h"
#include "Edit.h"

/**************************************************
Name: edit
Function���༭���湦��
Calls: edit_screen
       findbox
	   drawmind
	   addbox
	   deletebox
	   edit_mind
Called By: operate
Parameter: editp
Return: ��
Author: ����Դ
Others: ��
**************************************************/
void edit(MINDBOX (*editp)[VERT])
{
    int e_state = 1;              //��ʾ�Ƿ���editҳ���� 1Ϊ���� 0Ϊ��ת    ����ҳ����ת
    int state = 0, pre_state = 0; //��ʾ���״̬�����ֵ��δ�����
                                  // 0 �޲���״̬
                                  // 1 ��ɼ� 2 ������ 3 ɾ���� 4 �����
    int heng, zong;
    MINPUT minput = {7, 0, ""};
    int find_flag = 0; //��ʾ�Ƿ��ҵ���
	int colortemp = WHITE; //�ݴ浱ǰѡ�е���ɫ û��ѡ��ʱ����ΪWHITE
    clrmous(MouseX, MouseY);
    delay(100);
    edit_screen();
	color_screen();
    drawmind(editp);
    mouseinit();

    while (e_state == 1)
    {
        newmouse(&MouseX, &MouseY, &press);

        while (bioskey(1))
        {
            getch();
        }

        if (mouse_press(640 - 42, 0, 640, 24) == 2) //�����δ��� δ�������
        {
            pre_state = state;
            state = 1;

            if (pre_state != 1) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(RED);
                setlinestyle(0, 0, 1);
                rectangle(640 - 42, 0, 640, 24);
            }
        }
        else if (mouse_press(640 - 42, 0, 640, 24) == 1) //����ҵ��
        {
            e_state = 0;
            delay(100);
        }
        else if (mouse_press(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24) == 2) //������δ���
        {
            pre_state = state;
            state = 2;

            if (pre_state != 2) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(RED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24);
            }
        }
        else if (mouse_press(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24) == 1) //�����ҵ��
        {
            if (heng < HORI && find_flag == 1)
            {
                addbox(editp, heng, zong);
                setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
                drawmind(editp);
                find_flag = 0;
            }
        }
        else if (mouse_press(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24) == 2) //ɾ����δ���
        {
            pre_state = state;
            state = 3;

            if (pre_state != 3) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(RED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24);
            }
        }
        else if (mouse_press(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24) == 1) //ɾ���ҵ��
        {
            if (find_flag && (heng + zong) != 0)
            {
                deletebox(editp, heng, zong);
                setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
                drawmind(editp);
                find_flag = 0;
            }
        }
        else if (mouse_press(0, 24, 496, 480) == 1) //ѡҪ�༭�Ŀ�
        {
            find_flag = findbox(editp, &heng, &zong);
            if (find_flag == 1)
            {
                clrmous(MouseX, MouseY);
                delay(25); //��ͼǰ�������꣬��ֹ����

                setlinestyle(SOLID_LINE, 0, 3);
                setcolor(RED);
                setfillstyle(SOLID_FILL, WHITE);
                bar(8 + heng * 80, 28 + zong * 24, 8 + heng * 80 + 64, 28 + zong * 24 + 16);
                rectangle(8 + heng * 80, 28 + zong * 24, 8 + heng * 80 + 64, 28 + zong * 24 + 16);
                edit_mind(8 + heng * 80, 28 + zong * 24, &minput, &editp[heng][zong],BLACK);
                strcpy(minput.str, "");
                minput.cursor = 0;
            }
            setfillstyle(SOLID_FILL, WHITE);
            bar(0, 24, 496, 480);
            drawmind(editp);
            setcolor(RED);
            setlinestyle(0, 0, 3);
			if(find_flag == 1)
			{
				rectangle(8 + heng * 80, 28 + zong * 24, 8 + heng * 80 + 64, 28 + zong * 24 + 16);
			}
        }
		else if(mouse_press(504 + 17, 280, 604 + 17, 300) == 2) //����ɫ��δ���
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
		else if(mouse_press(504 + 17, 280, 604 + 17, 300) == 1) //����ɫ���ҵ��
		{
			setfillstyle(SOLID_FILL, LIGHTCYAN);
			bar(504 + 17 - 2, 280 - 2, 604 + 17 + 2, 300 + 2);
			setcolor(RED);
			setlinestyle(0, 0, 1);
			if(mouse_press(504 + 17, 280, 524 + 17, 300) == 1)
			{
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                color_screen();
				colortemp = BLACK;
				rectangle(504 + 17, 280, 524 + 17, 300);
			}
			else if(mouse_press(524 + 17, 280, 544 + 17, 300) == 1)
			{
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                color_screen();
				colortemp = CYAN;
				rectangle(524 + 17, 280, 544 + 17, 300);
			}
			else if(mouse_press(544 + 17, 280, 564 + 17, 300) == 1)
			{
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                color_screen();
				colortemp = GREEN;
				rectangle(544 + 17, 280, 564 + 17, 300);
			}
			else if(mouse_press(564 + 17, 280, 584 + 17, 300) == 1)
			{
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                color_screen();
				colortemp = BLUE;
				rectangle(564 + 17, 280, 584 + 17, 300);
			}
			else if(mouse_press(584 + 17, 280, 604 + 17, 300) == 1)
			{
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                color_screen();
				colortemp = LIGHTGRAY;
				rectangle(584 + 17, 280, 604 + 17, 300);
			}
		}
		else if(mouse_press(496 + 25, 248, 496 + 25 + 42, 272) == 2) //��ɫδ���
		{
			pre_state = state;
            state = 6;

            if (pre_state != 6) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(RED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25, 248, 496 + 25 + 42, 272);
            }
		}
		else if(mouse_press(496 + 25, 248, 496 + 25 + 42, 272) == 1) //��ɫ�ҵ��
		{
			if(find_flag == 1 && colortemp != WHITE)
			{
				editp[heng][zong].textcolor = colortemp;
				setfillstyle(SOLID_FILL, LIGHTCYAN);
			    bar(504 + 17 - 2, 280 - 2, 604 + 17 + 2, 300 + 2);
				color_screen();
				colortemp = WHITE;
				
				setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
				drawmind(editp);
                find_flag = 0;
			}
		}
		else if(mouse_press(496 + 25 + 42 + 10, 248, 496 + 25 + 42 + 10 + 42, 272) == 2) //��ɫδ���
		{
			pre_state = state;
            state = 7;

            if (pre_state != 7) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(RED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25 + 42 + 10, 248, 496 + 25 + 42 + 10 + 42, 272);
            }
		}
		else if(mouse_press(496 + 25 + 42 + 10, 248, 496 + 25 + 42 + 10 + 42, 272) == 1) //��ɫ�ҵ��
		{
			if(find_flag == 1 && colortemp != WHITE)
			{
				editp[heng][zong].boxcolor = colortemp;
				setfillstyle(SOLID_FILL, LIGHTCYAN);
			    bar(504 + 17 - 2, 280 - 2, 604 + 17 + 2, 300 + 2);
				color_screen();
				colortemp = WHITE;
				
				setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
				drawmind(editp);
                find_flag = 0;
			}
		}
        else //�޲���״̬
        {
            pre_state = state;
            state = 0;
        }

        if (pre_state != state && pre_state != 0)
        {
            clrmous(MouseX, MouseY);
            delay(5);

            switch (pre_state)
            {
            case 1:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(640 - 42, 0, 640, 24);
                break;
            case 2:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24);
                break;
            case 3:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24);
                break;
            case 4:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25, 24 + 8 + 24 + 8, 496 + 25 + 42, 24 + 8 + 24 + 8 + 24);
				break;
			case 5:
			    MouseS = 0;
				break;
			case 6:
			    MouseS = 0;
				setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25, 248, 496 + 25 + 42, 272);
				break;
			case 7:
			    MouseS = 0;
				setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25 + 42 + 10, 248, 496 + 25 + 42 + 10 + 42, 272);
				break;
            }
        }
    }
}

/**************************************************
Name: edit_screen
Function�����Ʊ༭����
Calls: ��
Called By: edit
           edittr
		   editfb
Parameter: ��
Return: ��
Author: ����Դ
Others: ��
**************************************************/
void edit_screen(void)
{
    //����
    cleardevice();
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, 496, 480);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(496, 0, 640, 480);
    bar(0, 0, 496, 24);
    setcolor(WHITE);
    setlinestyle(0, 0, 3);
    line(496, 0, 496, 480);
    line(496, 240, 640, 240);

    //����
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24);
    puthz(496 + 25 + 4, 24 + 8 + 4, "����", 16, 18, WHITE);
    bar(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24);
    puthz(496 + 25 + 42 + 10 + 4, 24 + 8 + 4, "ɾ��", 16, 18, WHITE);
	bar(496 + 25, 248, 496 + 25 + 42, 272);
	puthz(496 + 25 + 4, 248 + 4, "��ɫ", 16, 18, WHITE);
	bar(496 + 25 + 42 + 10, 248, 496 + 25 + 42 + 10 + 42, 272);
	puthz(496 + 25 + 42 + 10 + 4, 248 + 4, "��ɫ", 16, 18, WHITE);
    bar(640 - 42, 0, 640, 24);
    puthz(640 - 42 + 4, 0 + 4, "���", 16, 18, LIGHTRED);

    setlinestyle(0, 0, 1);
    setcolor(WHITE);
    rectangle(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24);
    rectangle(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24);
	rectangle(496 + 25, 248, 496 + 25 + 42, 272);
	rectangle(496 + 25 + 42 + 10, 248, 496 + 25 + 42 + 10 + 42, 272);
    rectangle(640 - 42, 0, 640, 24);
}

/**************************************************
Name: color_screen
Function�����Ƶ�ɫ�����
Calls: ��
Called By: edit
           edittr
Parameter: ��
Return: ��
Author: ����Դ
Others: ��
**************************************************/
void color_screen(void)
{
	//����ɫ��
	setcolor(BLACK);
	setlinestyle(0, 0, 1);
	rectangle(504 + 17 - 1, 280 - 1, 604 + 17 + 1, 300 + 1);
	setfillstyle(SOLID_FILL, BLACK);
	bar(504 + 17, 280, 524 + 17, 300);
	setfillstyle(SOLID_FILL, CYAN);
	bar(524 + 17, 280, 544 + 17, 300);
	setfillstyle(SOLID_FILL, GREEN);
	bar(544 + 17, 280, 564 + 17, 300);
	setfillstyle(SOLID_FILL, BLUE);
	bar(564 + 17, 280, 584 + 17, 300);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(584 + 17, 280, 604 + 17, 300);
}