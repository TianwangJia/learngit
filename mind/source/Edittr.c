/**********************************************
Description:  ����༭��״ͼ���ܼ�����
Function list :  edittr �༭ҳ�湦��
Attention:  
Author:  ����Դ
History:  
***********************************************/

#include "common.h"
#include "Edit.h"
#include "Edittr.h"
#include <graphics.h>

/**************************************************
Name: edittr
Function���༭��״ͼ���湦��
Calls: edit_screen
Called By: operate
Parameter: ��
Return: ��
Author: ����Դ
Others: ��
**************************************************/
void edittr(MINDBOX (*editp)[VERTREE])
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
    drawmind_tr(editp);
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
                addbox_tr(editp, heng, zong);
                setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
                drawmind_tr(editp);
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
                deletebox_tr(editp, heng, zong);
                setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
                drawmind_tr(editp);
                find_flag = 0;
            }
        }
        else if (mouse_press(0, 24, 496, 480) == 1) //ѡҪ�༭�Ŀ�
        {
            find_flag = findbox_tr(editp, &heng, &zong);
            if (find_flag == 1)
            {
                clrmous(MouseX, MouseY);
                delay(25); //��ͼǰ�������꣬��ֹ����

                setlinestyle(SOLID_LINE, 0, 3);
                setcolor(RED);
                setfillstyle(SOLID_FILL, WHITE);
                bar(8 + heng * 80, 34 + zong * 36, 8 + heng * 80 + 64, 34 + zong * 36 + 16);
                rectangle(8 + heng * 80, 34 + zong * 36, 8 + heng * 80 + 64, 34 + zong * 36 + 16);
                edit_mind(8 + heng * 80, 34 + zong * 36, &minput, &editp[heng][zong],BLACK);
                strcpy(minput.str, "");
                minput.cursor = 0;
            }
            setfillstyle(SOLID_FILL, WHITE);
            bar(0, 24, 496, 480);
            drawmind_tr(editp);
            setcolor(RED);
            setlinestyle(0, 0, 3);
			if(find_flag == 1)
			{
				rectangle(8 + heng * 80, 34 + zong * 36, 8 + heng * 80 + 64, 34 + zong * 36 + 16);
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
				color_screen();
				colortemp = BLACK;
				rectangle(504 + 17, 280, 524 + 17, 300);
			}
			else if(mouse_press(524 + 17, 280, 544 + 17, 300) == 1)
			{
				color_screen();
				colortemp = CYAN;
				rectangle(524 + 17, 280, 544 + 17, 300);
			}
			else if(mouse_press(544 + 17, 280, 564 + 17, 300) == 1)
			{
				color_screen();
				colortemp = GREEN;
				rectangle(544 + 17, 280, 564 + 17, 300);
			}
			else if(mouse_press(564 + 17, 280, 584 + 17, 300) == 1)
			{
				color_screen();
				colortemp = BLUE;
				rectangle(564 + 17, 280, 584 + 17, 300);
			}
			else if(mouse_press(584 + 17, 280, 604 + 17, 300) == 1)
			{
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
				drawmind_tr(editp);
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
				drawmind_tr(editp);
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

