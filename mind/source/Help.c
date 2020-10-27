/**********************************************
Description:  ��������
Function list :  help   �������湦��
                 help_screen  ���ư�������
                 help_page1 ��һҳ
                 help_page2 �ڶ�ҳ
                 help_page3 ����ҳ
                 help_page4 ����ҳ
Attention:  
Author:  ������
History:  
***********************************************/
#include "common.h"
#include "help.h"

/**************************************************
Name: help
Function����ɰ������湦��
Calls: help_screen
Called By: main
Parameter: ��
Return: page ҳ����ת
Author: ������
Others: δ���
**************************************************/
int help()
{
    int index = 1; //��ʾ��ҳ���� Ŀǰ��Χ1~4
    int click = 0; //��ʾ������Ƿ�����Ч��� 0δ��� 1���
    int page = 6;
    int a[2][8] = {{640 - 8 - 4,
                    16,
                    640 - 8 - 4 - 22,
                    4,
                    640 - 8 - 4 - 22,
                    28,
                    640 - 8 - 4,
                    16},
                   {640 - 8 - 30 - 8 - 4 - 22,
                    16,
                    640 - 8 - 30 - 8 - 4,
                    4,
                    640 - 8 - 30 - 8 - 4,
                    28,
                    640 - 8 - 30 - 8 - 4 - 22,
                    16}};         //���Ʒ�������� �ң���
    int state = 0, pre_state = 0; //��ʾ���״̬�����ֵ��δ�����
                                  // 0 �޲���״̬ 1 ���ؼ�
    clrmous(MouseX, MouseY);
    delay(100);
    help_page1(a);
    mouseinit();
    //newmouse(&MouseX, &MouseY, &press); ������newmouse���������

    while (page == 6)
    {
        newmouse(&MouseX, &MouseY, &press);

        if (mouse_press(8, 2, 8 + 48 + 8, 30) == 2) //���ؼ���δ���
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
                rectangle(8, 2, 8 + 48 + 8, 30);
            }
        }
        else if (mouse_press(8, 2, 8 + 48 + 8, 30) == 1)
        {
            page = 1;
        }
        else if (mouse_press(640 - 8 - 30 - 8 - 30, 2, 640 - 8 - 30 - 8, 30) == 2) //������δ���
        {
            pre_state = state;
            state = 2;

            if (pre_state != 2) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(LIGHTRED);
                rectangle(640 - 8 - 30 - 8 - 30, 2, 640 - 8 - 30 - 8, 30);
                setfillstyle(SOLID_FILL, LIGHTRED);
                fillpoly(4, a[1]);
            }
        }
        else if (mouse_press(640 - 8 - 30 - 8 - 30, 2, 640 - 8 - 30 - 8, 30) == 1 && index > 1) //��������ҵ��
        {
            click = 1;
            index -= 1;

            clrmous(MouseX, MouseY);
            delay(100);
        }
        else if (mouse_press(640 - 8 - 30, 2, 640 - 8, 30) == 2) //������δ���
        {
            pre_state = state;
            state = 3;

            if (pre_state != 3) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(LIGHTRED);
                rectangle(640 - 8 - 30, 2, 640 - 8, 30);
                setfillstyle(SOLID_FILL, LIGHTRED);
                fillpoly(4, a[0]);
            }
        }
        else if (mouse_press(640 - 8 - 30, 2, 640 - 8, 30) == 1 && index < 4) //��������ҵ��
        {
            click = 1;
            index += 1;

            clrmous(MouseX, MouseY);
            delay(100);
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
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(8, 2, 8 + 48 + 8, 30);
                break;
            case 2:
                MouseS = 0;
                setcolor(WHITE);
                rectangle(640 - 8 - 30 - 8 - 30, 2, 640 - 8 - 30 - 8, 30);
                setfillstyle(SOLID_FILL, WHITE);
                fillpoly(4, a[1]);
                break;
            case 3:
                MouseS = 0;
                setcolor(WHITE);
                rectangle(640 - 8 - 30, 2, 640 - 8, 30);
                setfillstyle(SOLID_FILL, WHITE);
                fillpoly(4, a[0]);
                break;
            }
        }

        if (click == 1)
        {
            click = 0;
            switch (index)
            {
            case 1:
                help_page1(a);
                break;
            case 2:
                help_page2(a);
                break;
            case 3:
                help_page3(a);
                break;
            case 4:
                help_page4(a);
                break;
            }
        }
    }

    return page;
}

/**************************************************
Name: help_screen
Function�����ư�������
Calls: ��
Called By: help
Parameter: a ���Ʒ��������
Return: ��
Author: ������
Others: ��
**************************************************/
void help_screen(int (*a)[8])
{
    cleardevice();
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, 640, 480); //����

    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(0, 0, 640, 32);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(640 - 8 - 30, 2, 640 - 8, 30);
    bar(640 - 8 - 30 - 8 - 30, 2, 640 - 8 - 30 - 8, 30);
    bar(8, 2, 8 + 48 + 8, 30); //���ؼ�
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillpoly(4, a[0]);
    fillpoly(4, a[1]); //�����

    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(8, 2, 8 + 48 + 8, 30);
    rectangle(640 - 8 - 30, 2, 640 - 8, 30);
    rectangle(640 - 8 - 30 - 8 - 30, 2, 640 - 8 - 30 - 8, 30);

    puthz(297, 4, "����", 24, 32, BLACK);
    puthz(8 + 4, 4, "����", 24, 24, WHITE);
}

/**************************************************
Name: help_page2
Function������ҳ���һҳ
Calls: ��
Called By: help
Parameter: a ���Ʒ��������
Return: ��
Author: ������
Others: 
**************************************************/
void help_page1(int (*a)[8])
{
    cleardevice();
    help_screen(a);

    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(1, HORIZ_DIR, 2);
    setcolor(BLACK);
    outtextxy(432, 0, "Page 1");
    puthz(0, 46, "�û����ڻ�ӭ����������²���", 16, 16, BLACK); //��46��ʼ���Ϊ6
    puthz(14 * 16, 46 + 22 * 1, "ע�᣺", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 1, "��Ҫ�û��������֤�ţ����루���ٰ�λ��", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 2, "��¼��", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 2, "ʹ����ע����û�����������е�¼", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 3, "�޸����룺", 16, 16, RED);
    puthz(19 * 16, 46 + 22 * 3, "ʹ����ע����û������Ӧ���֤���޸�����", 16, 16, BLACK);
    puthz(0, 46 + 22 * 6, "��¼", 16, 16, RED);
    puthz(16 * 2, 46 + 22 * 6, "����뵼ͼ����ҳ��", 16, 16, BLACK);
    setcolor(RED);
    setlinestyle(0, 0, 1);
    rectangle(0, 46 + 22 * 6, 16 * 2, 46 + 22 * 6 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 1, 14 * 16 + 16 * 2, 46 + 22 * 1 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 2, 14 * 16 + 16 * 2, 46 + 22 * 2 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 3, 14 * 16 + 16 * 4, 46 + 22 * 3 + 16 * 1);
}

/**************************************************
Name: help_page2
Function������ҳ��ڶ�ҳ
Calls: ��
Called By: help
Parameter: a ���Ʒ��������
Return: ��
Author: ������
Others: 
**************************************************/
void help_page2(int (*a)[8])
{
    cleardevice();
    help_screen(a);

    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(1, HORIZ_DIR, 2);
    setcolor(BLACK);
    outtextxy(432, 0, "Page 2");
    puthz(0, 46, "�û����ڲ�������������²���", 16, 16, BLACK); //��46��ʼ���Ϊ6
    puthz(14 * 16, 46 + 22 * 1, "�½���", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 1, "�½�һ����ͼ�����ֲ����ظ�������ѡ����������", 16, 16, BLACK);
    puthz(17 * 16, 46 + 22 * 2, "����ͼ����״ͼ��ʱ���ᣬ���ͼ", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 3, "�򿪣�", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 3, "�������ƿɴ��Ѵ��ڵ�ͼ�ļ�", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 4, "�رգ�", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 4, "�رյ�ǰ��ͼ�ļ�������ʾ��ʼҳ��", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 5, "ɾ����", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 5, "�رյ�ǰ��ͼ�ļ�����ʾ��ʼҳ�沢ɾ����Ӧ��ͼ", 16, 16, BLACK);
    puthz(17 * 16, 46 + 22 * 6, "�ļ�", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 7, "�༭��", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 7, "���Ѵ򿪵�ͼ�ļ����Ե�ͼ�����ݽ��б༭�Ӳ���", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 8, "���棺", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 8, "�Ը��Ľ��б���", 16, 16, BLACK);
    puthz(0, 46 + 22 * 11, "���", 16, 16, BLACK);
    puthz(2 * 16, 46 + 22 * 11, "�༭", 16, 16, RED);
    puthz(4 * 16, 46 + 22 * 11, "�����༭����", 16, 16, BLACK);
    setcolor(RED);
    setlinestyle(0, 0, 1);
    rectangle(14 * 16, 46 + 22 * 1, 14 * 16 + 2 * 16, 46 + 22 * 1 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 5, 14 * 16 + 2 * 16, 46 + 22 * 5 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 3, 14 * 16 + 2 * 16, 46 + 22 * 3 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 4, 14 * 16 + 2 * 16, 46 + 22 * 4 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 7, 14 * 16 + 2 * 16, 46 + 22 * 7 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 8, 14 * 16 + 2 * 16, 46 + 22 * 8 + 16 * 1);
    rectangle(2 * 16, 46 + 22 * 11, 2 * 16 + 2 * 16, 46 + 22 * 11 + 16 * 1);
}

/**************************************************
Name: help_page3
Function������ҳ�����ҳ
Calls: ��
Called By: help
Parameter: a ���Ʒ��������
Return: ��
Author: ������
Others: 
**************************************************/
void help_page3(int (*a)[8])
{
    cleardevice();
    help_screen(a);

    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(1, HORIZ_DIR, 2);
    setcolor(BLACK);
    outtextxy(432, 0, "Page 3");
    puthz(0, 46, "�û����ڵ���˼ά��ͼ����״ͼ�����ͼ�༭����������²�����", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 1, "ѡ�У�", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 1, "������ڵ�˼ά��ͼ�����ѡ�У����", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 2, "�༭�ı���", 16, 16, RED);
    puthz(19 * 16, 46 + 22 * 2, "��������̽����ı��༭״̬������", 16, 16, BLACK);
    puthz(19 * 16 + 17 * 16, 46 + 22 * 2, "�س�", 16, 16, RED);
    puthz(21 * 16 + 17 * 16, 46 + 22 * 2, "��", 16, 16, BLACK);
    puthz(19 * 16, 46 + 22 * 3, "��״̬", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 4, "�½���", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 4, "�����½��ӿ�", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 5, "ɾ����", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 5, "ɾ�������ӿ򣬽������", 16, 16, BLACK);

    puthz(0, 46 + 22 * 8, "����˼ά��ͼ����״ͼ�ɸı��ɫ����ɫ��", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 9, "ѡ�п�������״̬�������ɫ��ѡ��", 16, 16, BLACK);
    puthz(14 * 16 + 18 * 16, 46 + 22 * 9, "��ɫ", 16, 16, RED);
    puthz(14 * 16 + 20 * 16, 46 + 22 * 9, "��", 16, 16, BLACK);
    puthz(14 * 16 + 21 * 16, 46 + 22 * 9, "��ɫ", 16, 16, RED);
    puthz(14 * 16 + 23 * 16, 46 + 22 * 9, "����", 16, 16, BLACK);
    puthz(0, 46 + 22 * 10, "�û���ʱ����༭����ɽ������²�����", 16, 16, BLACK);
    setcolor(RED);
    puthz(14 * 16, 46 + 22 * 11, "������ȷ��ʽ������ʱ�估���ݵ��������", 16, 16, BLACK); //���̺��
    puthz(14 * 16 + 19 * 16, 46 + 22 * 11, "����", 16, 16, RED);
    puthz(14 * 16 + 21 * 16, 46 + 22 * 11, "ʱ�����", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 12, "ѡ�е�ͼ�������״̬�����", 16, 16, BLACK);
    puthz(14 * 16 + 14 * 16, 46 + 22 * 12, "ɾ��", 16, 16, RED);
    puthz(14 * 16 + 16 * 16, 46 + 22 * 12, "��Ӧ��", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 13, "��ͼ��", 16, 16, BLACK);
    puthz(14 * 16 + 3 * 16, 46 + 22 * 13, "��ɫ", 16, 16, BLUE);
    puthz(14 * 16 + 5 * 16, 46 + 22 * 13, "��Ӧ��ݣ�", 16, 16, BLACK);
    puthz(14 * 16 + 10 * 16, 46 + 22 * 13, "��ɫ", 16, 16, GREEN);
    puthz(14 * 16 + 12 * 16, 46 + 22 * 13, "��Ӧ�·ݣ�", 16, 16, BLACK);
    puthz(14 * 16 + 17 * 16, 46 + 22 * 13, "��ɫ", 16, 16, RED);
    puthz(14 * 16 + 19 * 16, 46 + 22 * 13, "��Ӧ��", 16, 16, BLACK);
    puthz(0, 46 + 22 * 16, "���", 16, 16, BLACK);
    puthz(2 * 16, 46 + 22 * 16, "���", 16, 16, RED);
    puthz(4 * 16, 46 + 22 * 16, "���˳��༭ҳ��", 16, 16, BLACK);

    setlinestyle(0, 0, 1);
    rectangle(19 * 16 + 17 * 16, 46 + 22 * 2, 38 * 16, 46 + 22 * 2 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 4, 14 * 16 + 2 * 16, 46 + 22 * 4 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 5, 14 * 16 + 2 * 16, 46 + 22 * 5 + 16 * 1);
    rectangle(2 * 16, 46 + 22 * 16, 2 * 16 + 2 * 16, 46 + 22 * 16 + 16 * 1);
    rectangle(14 * 16 + 18 * 16, 46 + 22 * 9, 14 * 16 + 20 * 16, 46 + 22 * 9 + 16);
    rectangle(14 * 16 + 21 * 16, 46 + 22 * 9, 14 * 16 + 23 * 16, 46 + 22 * 9 + 16);
    rectangle(14 * 16 + 19 * 16, 46 + 22 * 11, 14 * 16 + 21 * 16, 46 + 22 * 11 + 16);
    rectangle(14 * 16 + 14 * 16, 46 + 22 * 12, 14 * 16 + 16 * 16, 46 + 22 * 12 + 16);
}

/**************************************************
Name: help_page4
Function������ҳ�����ҳ
Calls: ��
Called By: help
Parameter: a ���Ʒ��������
Return: ��
Author: ������
Others: 
**************************************************/
void help_page4(int (*a)[8])
{
    cleardevice();
    help_screen(a);

    settextjustify(LEFT_TEXT, TOP_TEXT);
    settextstyle(1, HORIZ_DIR, 2);
    setcolor(BLACK);
    outtextxy(432, 0, "Page 4");
    puthz(0, 46, "�½���ͼ�ļ�����", 16, 16, BLACK);
    puthz(8 * 16, 46 + 1 * 16, "�û���ѡ�е�ͼ���ͣ����뵼ͼ�������½�", 16, 16, BLACK);
    puthz(8 * 16, 46 + 2 * 16, "Ҳ���˳����򣬷��ز�������", 16, 16, BLACK);
    puthz(0, 46 + 4 * 16, "�򿪵�ͼ�ļ�����", 16, 16, BLACK);
    puthz(8 * 16, 46 + 5 * 16, "���뵼ͼ�������ȷ����", 16, 16, BLACK);
    puthz(8 * 16, 46 + 6 * 16, "���ȡ�������ز�������", 16, 16, BLACK);
}
