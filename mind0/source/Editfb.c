/**********************************************
Description:  ����༭˼ά��ͼ���ܼ�����
Function list :  edit �༭ҳ�湦��
                 edit_screen ���Ʊ༭ҳ��
Attention:  
Author:  ������
History:  
***********************************************/

#include "common.h"
#include "Editfb.h"
#include <graphics.h>

/**************************************************
Name: editfb
Function���༭���湦��
Calls: edit_screen
Called By: operate
Parameter: δ��
Return: δ��
Author: ������
Others: δ���
**************************************************/
void editfb(FISHINFO *editp)
{
	int e_state = 1;              //��ʾ�Ƿ���editҳ���� 1Ϊ���� 0Ϊ��ת    ����ҳ����ת
    int state = 0, pre_state = 0; //��ʾ���״̬�����ֵ��δ�����
                                  // 0 �޲���״̬
                                  // 1 ��ɼ� 2 ������ 3 ɾ���� 4 �����
    int rankbone; //�洢rankbone�±�
    MINPUT minput = {7, 0, ""};
	int find_flag = 0; //��ʾ�Ƿ��ҵ���
    clrmous(MouseX, MouseY);
    delay(100);
    edit_screen();
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	bar(496 + 25 - 1, 248 - 1, 496 + 25 + 42 + 10 + 42 + 1, 272 + 1); //��ס������ť
	drawbone(editp);
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
            if (find_flag == 1 && editp -> bonenum < BONEMAX)
            {
                addbone(editp, rankbone);
                setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
                drawbone(editp);
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
            if (find_flag == 1 && editp -> bonenum > 1)
            {
                deletebone(editp, rankbone);
                setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
                drawbone(editp);
                find_flag = 0;
            }
        }
        else if (mouse_press(0, 24, 496, 480) == 1) //ѡҪ�༭�Ŀ� 
        {
            find_flag = findbone(editp, &rankbone);
            if (find_flag == 1)
            {
                clrmous(MouseX, MouseY);
                delay(25); //��ͼǰ�������꣬��ֹ����

                setlinestyle(SOLID_LINE, 0, 3);
                setcolor(RED);
                setfillstyle(SOLID_FILL, WHITE);
                bar(248 - 114 + 164 * (rankbone % 2), 80 + 24 + rankbone * 40, 248 - 50 + 164 * (rankbone % 2), 80 + 40 + rankbone * 40);
                line(248, 80 + 20 + rankbone * 40, 248 - 50 + 100 * (rankbone % 2), 80 + 40 + rankbone * 40);
			    rectangle(248 - 114 + 164 * (rankbone % 2), 80 + 24 + rankbone * 40, 248 - 50 + 164 * (rankbone % 2), 80 + 40 + rankbone * 40);
                edit_yugu(248 - 114 + 164 * (rankbone % 2), 80 + 24 + rankbone * 40, &minput, editp->bone[rankbone].content,BLACK);
                strcpy(minput.str, "");
                minput.cursor = 0;
            }
            setfillstyle(SOLID_FILL, WHITE);
            bar(0, 24, 496, 480);
            drawbone(editp);
            setcolor(RED);
            setlinestyle(0, 0, 3);
			if(find_flag == 1)
            {
				line(248, 80 + 20 + rankbone * 40, 248 - 50 + 100 * (rankbone % 2), 80 + 40 + rankbone * 40);
			    rectangle(248 - 114 + 164 * (rankbone % 2), 80 + 24 + rankbone * 40, 248 - 50 + 164 * (rankbone % 2), 80 + 40 + rankbone * 40);
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
            }
        }
    }
}