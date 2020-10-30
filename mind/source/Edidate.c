/**********************************************
Description: �༭ʱ���Ṧ�ܼ�����
Function list :  edidate �༭ҳ�湦��
				 edidate_screen ���Ʊ༭ҳ��
Attention:  
Author:  ����Դ
History:  
***********************************************/

#include "common.h"
#include "Edidate.h"

/**************************************************
Name: edidate
Function���༭ʱ������湦��
Calls: edidate_screen
       finddate
	   drawdate
	   deletedate
	   rank_time
	   judge_time
Called By: operate
Parameter: edidate ���༭ʱ�������Ϣ
Return: ��
Author: ����Դ
Others: ��
**************************************************/
void edidate(DATEINFO *edidate)
{
    int e_state = 1;              //��ʾ�Ƿ���editҳ���� 1Ϊ���� 0Ϊ��ת    ����ҳ����ת
    int state = 0, pre_state = 0; //��ʾ���״̬�����ֵ��δ�����
                                  // 0 �޲���״̬
                                  // 1 ��ɼ� 2 ������ 3 ɾ���� 4 �����
    int rankdate;                 //�洢rankdate�±�
    ENTER newdateyear = {496 + 25 + 20, 24 + 8 + 24 + 24, 600 + 20, 24 + 8 + 24 + 24 + 20, 4, 0, 0, ""};
    ENTER newdatemonth = {496 + 25 + 20, 24 + 8 + 24 + 24 + 40, 600 + 20, 24 + 8 + 24 + 24 + 60, 2, 0, 0, ""};
    ENTER newdateday = {496 + 25 + 20, 24 + 8 + 24 + 24 + 80, 600 + 20, 24 + 8 + 24 + 24 + 100, 2, 0, 0, ""};
    ENTER newdatehappen = {496 + 8 + 20, 24 + 8 + 24 + 24 + 160 + 100, 496 + 8 + 90 + 20, 24 + 8 + 24 + 24 + 160 + 20 + 100, 7, 0, 0, ""};
    DATEHAPPEN tempsave;
    int find_flag = 0; //��ʾ�Ƿ��ҵ���
    clrmous(MouseX, MouseY);
    delay(100);
    edidate_screen();
    drawdate(edidate);
    mouseinit();

    while (e_state == 1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if (newdateyear.flag != 1 && newdatemonth.flag != 1 && newdateday.flag != 1 && newdatehappen.flag != 1)
        {
            while (bioskey(1))
            {
                getch();
            }
        } //FIXME

        input_info(525 + 20, 24 + 8 + 24 + 24 + 2, 5, 1, &newdateyear);
        input_info(525 + 20, 24 + 8 + 24 + 24 + 40 + 2, 5, 1, &newdatemonth);
        input_info(525 + 20, 24 + 8 + 24 + 24 + 80 + 2, 5, 1, &newdateday);
        input_info(510 + 20, 24 + 8 + 24 + 24 + 160 + 2 + 100, 5, 1, &newdatehappen);
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
            setfillstyle(SOLID_FILL, LIGHTCYAN);
            tempsave.year = atoi(newdateyear.str);
            tempsave.month = atoi(newdatemonth.str);
            tempsave.day = atoi(newdateday.str);
            strcpy(tempsave.content, newdatehappen.str);
            if (judge_time(tempsave) && tempsave.content[0] != '\0')
            {
                rank_time(edidate, tempsave);
                strcpy(newdateyear.str, "");
                strcpy(newdatemonth.str, "");
                strcpy(newdateday.str, "");
                strcpy(newdatehappen.str, "");
                newdateyear.cursor = 0;
                newdatemonth.cursor = 0;
                newdateday.cursor = 0;
                newdatehappen.cursor = 0;
                edidate_screen();
                drawdate(edidate);
            }
            else if (judge_time(tempsave) == 0 && (newdateyear.cursor != 0 || newdatemonth.cursor != 0 || newdateday.cursor != 0)) //���������ڵ����Ϸ�
            {
                bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 100 + 10, 496 + 25 + 20 + 80, 24 + 8 + 24 + 24 + 100 + 10 + 20);
                bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10, 496 + 25 + 20 + 80, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10 + 20);
                puthz(496 + 25 + 20, 24 + 8 + 24 + 24 + 100 + 10, "���ڷǷ�", 16, 16, DARKGRAY);
            }
            else if ((newdateyear.cursor != 0 || newdatemonth.cursor != 0 || newdateday.cursor != 0) && newdatehappen.cursor == 0) //���������ںϷ�����û����
            {
                bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 100 + 10, 496 + 25 + 20 + 80, 24 + 8 + 24 + 24 + 100 + 10 + 20);
                bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10, 496 + 25 + 20 + 80, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10 + 20);
                puthz(496 + 25 + 20, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10, "δ��������", 16, 16, DARKGRAY);
            }
            else if (!(newdateyear.cursor != 0 || newdatemonth.cursor != 0 || newdateday.cursor != 0) && newdatehappen.cursor != 0) //û����������������
            {
                bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 100 + 10, 496 + 25 + 20 + 80, 24 + 8 + 24 + 24 + 100 + 10 + 20);
                bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10, 496 + 25 + 20 + 80, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10 + 20);
                puthz(496 + 25 + 20, 24 + 8 + 24 + 24 + 100 + 10, "δ��������", 16, 16, DARKGRAY);
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
            if (find_flag == 1)
            {
                deletedate(edidate, rankdate);
                setfillstyle(SOLID_FILL, WHITE);
			    bar(0, 24, 496, 480);
                drawdate(edidate);
                find_flag = 0;
            }
        }
        else if (mouse_press(0, 24, 496, 480) == 1) //ѡҪ�༭�Ŀ�
        {
            setfillstyle(SOLID_FILL, WHITE);
			bar(0, 24, 496, 480);
            drawdate(edidate);
            find_flag = finddate(edidate, &rankdate);
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

/**************************************************
Name: edidate_screen
Function�����Ʊ༭����
Calls: ��
Called By: edidate
Parameter: ��
Return: ��
Author: ����Դ
Others: ��
**************************************************/
void edidate_screen(void)
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
    bar(640 - 42, 0, 640, 24);
    puthz(640 - 42 + 4, 0 + 4, "���", 16, 18, LIGHTRED);

    setlinestyle(0, 0, 1);
    setcolor(WHITE);
    rectangle(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24);
    rectangle(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24);
    rectangle(640 - 42, 0, 640, 24);

    //�������
    setfillstyle(SOLID_FILL, WHITE);
    bar(496 + 25 + 20, 24 + 8 + 24 + 24, 600 + 20, 24 + 8 + 24 + 24 + 20);                                 //��
    bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 40, 600 + 20, 24 + 8 + 24 + 24 + 60);                            //��
    bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 80, 600 + 20, 24 + 8 + 24 + 24 + 100);                           //��
    bar(496 + 8 + 20, 24 + 8 + 24 + 24 + 160 + 100, 496 + 8 + 90 + 20, 24 + 8 + 24 + 24 + 160 + 20 + 100); //�������ֿ�
    //�����ֿ�
    setfillstyle(SOLID_FILL, BLUE);
    bar(496 + 5 + 20, 24 + 8 + 24 + 24, 496 + 25 + 20, 24 + 8 + 24 + 24 + 20); //��
    setfillstyle(SOLID_FILL, GREEN);
    bar(496 + 5 + 20, 24 + 8 + 24 + 24 + 40, 496 + 25 + 20, 24 + 8 + 24 + 24 + 60); //��
    setfillstyle(SOLID_FILL, RED);
    bar(496 + 5 + 20, 24 + 8 + 24 + 24 + 80, 496 + 25 + 20, 24 + 8 + 24 + 24 + 100); //��
    //���
    //setlinestyle(SOLID_LINE, 0, 1);
    //setcolor(BLACK);
    //rectangle(496 + 5, 24 + 8 + 24 + 24, 600, 24 + 8 + 24 + 24 + 20); //��
    //rectangle(496 + 5, 24 + 8 + 24 + 24 + 40, 600, 24 + 8 + 24 + 24 + 60); //��
    //rectangle(496 + 5, 24 + 8 + 24 + 24 + 80, 600, 24 + 8 + 24 + 24 + 100); //��
    //rectangle(496 + 8, 24 + 8 + 24 + 24 + 160, 496 + 8 + 90, 24 + 8 + 24 + 24 + 160 + 20); //�������ֿ�
    //����
    puthz(496 + 5 + 2 + 20, 24 + 8 + 24 + 24 + 2, "��", 16, 0, YELLOW);
    puthz(496 + 5 + 2 + 20, 24 + 8 + 24 + 24 + 40 + 2, "��", 16, 0, YELLOW);
    puthz(496 + 5 + 2 + 20, 24 + 8 + 24 + 24 + 80 + 2, "��", 16, 0, YELLOW);
    puthz(496 + 8 + 20, 24 + 8 + 24 + 24 + 140 + 100, "����", 16, 16, BLACK);
}



