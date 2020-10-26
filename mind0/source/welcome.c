/**********************************************
Description:  ��ɻ�ӭ���漰�书��
Function list :  welcome    ��ӭ���湦��
                 welcome_screen    ���ƻ�ӭ����
Attention:
Author: ������
***********************************************/
#include "common.h"
#include "welcome.h"

/**************************************************
Name: welcome
Function����ӭ���������Ϣ����ת����
Calls: ��
Called By: main
Parameter�� ��
Return: page ҳ����ת
Author: ������
Others: ��
**************************************************/
int welcome()
{
    int page = 1;
    int state = 0, pre_state = 0; //��ʾ���״̬�����ֵ
                                  //0 �޲���״̬ 1 �˳��� 2 ע��� 3 ��½��
                                  //4 ������
    clrmous(MouseX, MouseY);
    delay(100);
    //mouseinit();
    welcome_screen();
    mouseinit();

    while (page == 1)
    {
        newmouse(&MouseX, &MouseY, &press);
        //�˳���
        if (mouse_press(590, 0, 640, 35) == 2) //���˳�����δ���
        {
            pre_state = state;
            state = 1;
            if (pre_state != 1) //��ֹ���ظ�������ֻ��֮ǰ������״̬�ű�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1;
                setcolor(RED);
                setlinestyle(0, 0, 3);
                rectangle(590, 0, 640, 35);
            }
        }
        else if (mouse_press(590, 0, 640, 35) == 1) //���˳����ҵ��
        {
            page = 0;
        }
        //ע���
        else if (mouse_press(240, 300, 400, 340) == 2) //��ע���δ���
        {
            pre_state = state;
            state = 2;
            if (pre_state != 2) //��ֹ���ظ�������ֻ��֮ǰ������״̬�ű�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1;
                setcolor(LIGHTMAGENTA);
                setlinestyle(0, 0, 1);
                setfillstyle(SOLID_FILL, LIGHTMAGENTA);
                rectangle(240, 300, 400, 340);
                fillellipse(252, 320, 9, 9);
                puthz(275, 310, "�û�ע��", 24, 32, LIGHTMAGENTA);
                setlinestyle(0, 0, 3);
                line(195, 320, 240, 320);
                setfillstyle(SOLID_FILL, YELLOW);
                fillellipse(120, 320, 75, 26);
                puthz(53, 312, "������ɼ�������", 16, 17, LIGHTMAGENTA);
            }
        }
        else if (mouse_press(240, 300, 400, 340) == 1) //��ע����ҵ��
        {
            page = 2;
        }
        //��¼��
        else if (mouse_press(240, 350, 400, 390) == 2) //�ڵ�¼��δ���
        {
            pre_state = state;
            state = 3;
            if (pre_state != 3) //��ֹ���ظ�������ֻ��֮ǰ������״̬�ű�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1;
                setcolor(LIGHTMAGENTA);
                setlinestyle(0, 0, 1);
                setfillstyle(SOLID_FILL, LIGHTMAGENTA);
                rectangle(240, 350, 400, 390);
                fillellipse(252, 370, 9, 9);
                puthz(275, 360, "�û���¼", 24, 32, LIGHTMAGENTA);
                setlinestyle(0, 0, 3);
                line(445, 370, 400, 370);
                setfillstyle(SOLID_FILL, YELLOW);
                fillellipse(520, 370, 75, 26);
                puthz(453, 362, "��¼����������", 16, 17, LIGHTMAGENTA);
            }
        }
        else if (mouse_press(240, 350, 400, 390) == 1)
        {
            page = 3;
        }
        else if (mouse_press(0, 0, 50, 35) == 2) //����δ���
        {
            pre_state = state;
            state = 4;
            if (pre_state != 4) //��ֹ���ظ�������ֻ��֮ǰ������״̬�ű�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(RED);
                setlinestyle(0, 0, 3);
                rectangle(0, 0, 50, 35);
            }
        }
        else if (mouse_press(0, 0, 50, 35) == 1) //�����ҵ��
        {
            page = 6;
        }
        //�޲���״̬
        else
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
                setlinestyle(0, 0, 3);
                rectangle(590, 0, 640, 35);
                break;
            case 2:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                setfillstyle(SOLID_FILL, WHITE);
                rectangle(240, 300, 400, 340);
                fillellipse(252, 320, 9, 9);
                puthz(275, 310, "�û�ע��", 24, 32, WHITE);
                setlinestyle(0, 0, 3);
                line(195, 320, 240, 320);
                setfillstyle(SOLID_FILL, YELLOW);
                fillellipse(120, 320, 75, 26);
                puthz(53, 312, "����д������뷨", 16, 17, LIGHTBLUE);
                break;
            case 3:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                setfillstyle(SOLID_FILL, WHITE);
                rectangle(240, 350, 400, 390);
                fillellipse(252, 370, 9, 9);
                puthz(275, 360, "�û���¼", 24, 32, WHITE);
                setlinestyle(0, 0, 3);
                line(445, 370, 400, 370);
                setfillstyle(SOLID_FILL, YELLOW);
                fillellipse(520, 370, 75, 26);
                puthz(453, 362, "�����ܹ����˼ά", 16, 17, LIGHTBLUE);
                break;
            case 4:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 3);
                rectangle(0, 0, 50, 35);
            }
        }
    }

    return page;
}

/**************************************************
Name: welcome_screen
Function������ӭ����
Calls: ��
Called By: welcome
Parameter����
Return: ��
Author: ������
Others: ��
**************************************************/
void welcome_screen()
{
    //���ڻ�m��ĸ������
    int a[32] = {250, 170, 270, 60, 300, 60, 320, 140, 340, 60, 370, 60, 390, 170, 380, 170, 362, 80, 348, 80, 325, 170, 315, 170, 292, 80,
                 278, 80, 260, 170, 250, 170};

    //����
    cleardevice();
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(0, 0, 640, 480);

    //�˳���ť
    setcolor(WHITE);
    setlinestyle(0, 0, 3);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(590, 0, 640, 35); //�˳���ť
    rectangle(590, 0, 640, 35);
    puthz(600, 10, "�˳�", 12, 18, WHITE);

    //������ť
    bar(0, 0, 50, 35); //�˳���ť
    rectangle(0, 0, 50, 35);
    puthz(10, 10, "����", 12, 18, WHITE);

    //��M logo
    setfillstyle(SOLID_FILL, YELLOW);
    setlinestyle(0, 0, 1);
    fillellipse(320, 120, 100, 100);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    fillellipse(320, 120, 90, 90);
    setfillstyle(SOLID_FILL, YELLOW);
    fillpoly(16, a);

    //˼ά��ͼ����
    puthz(225, 235, "˼ά��ͼ", 48, 50, LIGHTBLUE);

    //ע�ᰴť
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(240, 300, 400, 340);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(240, 300, 400, 340);
    puthz(275, 310, "�û�ע��", 24, 32, WHITE);

    //��¼��ť
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(240, 350, 400, 390);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(240, 350, 400, 390);
    puthz(275, 360, "�û���¼", 24, 32, WHITE);

    //������ť������
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(252, 370, 9, 9);
    fillellipse(252, 320, 9, 9);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(520, 370, 75, 26);
    fillellipse(120, 320, 75, 26);
    puthz(453, 362, "�����ܹ����˼ά", 16, 17, LIGHTBLUE);
    puthz(53, 312, "����д������뷨", 16, 17, LIGHTBLUE);
    setcolor(WHITE);
    setlinestyle(0, 0, 3);
    line(445, 370, 400, 370);
    line(195, 320, 240, 320);

    //��Ȩ��Ϣ
    setcolor(WHITE);
    settextstyle(0, 0, 1);
    outtextxy(260, 470, "Copyright C 2020 HUST-Jiatianwang, Niqiyuan.");
}
