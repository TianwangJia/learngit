/**********************************************
Description:  �򿪽��漰����
Function list :  opena   ��ɴ򿪹���
                 open_screen  ���ƴ򿪽���
Attention:  
Author:  ������
History:  
***********************************************/

#include "common.h"
#include "Opena.h"

/**************************************************
Name: opena
Function����ɴ򿪹���
Calls:  input_mind
        findmind
Called By: operate
Parameter: account_name �˻���
           daotu_info  ˼ά��ͼ��Ϣ
Return: mstate ��״̬
Author: ������
Others: 
**************************************************/
int opena(char *account_name, MIND *daotu_info)
{
    int mstate = 2;               //��ʾ�򿪵�ͼ״̬ 2��ʾ����ҳ���� 0δ�򿪷��� 1��ʾ�򿪷���
    int state = 0, pre_state = 0; //��ʾ���״̬�����ֵ
                                  // 0 �޲���״̬ 1 ȡ����ť 2 ����׿� 3 �򿪰�ť
    ENTER mindname = {120 + 128, 100 + 128, 120 + 128 + 144, 100 + 128 + 32, 8, 0, 0, ""};

    clrmous(MouseX, MouseY);
    delay(100);
    open_screen();
    mouseinit();

    while (mstate == 2)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mindname.flag!=1)
        {
            while(bioskey(1))
            {
                getch();
            }
        }

        input_mind(120 + 128 + 4, 100 + 128 + 4, 7, &mindname);

        if (mouse_press(120 + 80 + 80 + 80, 100 + 192, 120 + 80 + 80 + 80 + 80, 100 + 192 + 32) == 2) //ȡ������δ���
        {
            pre_state = state;
            state = 1;

            if (pre_state != 1) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(120 + 80 + 80 + 80, 100 + 192, 120 + 80 + 80 + 80 + 80, 100 + 192 + 32);
            }
        }
        else if (mouse_press(120 + 80 + 80 + 80, 100 + 192, 120 + 80 + 80 + 80 + 80, 100 + 192 + 32) == 1) //ȡ�����ҵ��
        {
            mstate = 0;
        }
        else if (mouse_press(120 + 128, 100 + 128, 120 + 128 + 144, 100 + 128 + 32) == 2) //�������δ���
        {
            pre_state = state;
            state = 2;

            if (pre_state != 2) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 2; //���
            }
        }
        else if (mouse_press(120 + 80, 100 + 192, 120 + 80 + 80, 100 + 192 + 32) == 2) //�򿪼���δ���
        {
            pre_state = state;
            state = 3;

            if (pre_state != 3) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(120 + 80, 100 + 192, 120 + 80 + 80, 100 + 192 + 32);
            }
        }
        else if (mouse_press(120 + 80, 100 + 192, 120 + 80 + 80, 100 + 192 + 32) == 1) //�򿪼��ҵ��
        {
            //�����ʾ��Ϣ
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            bar(120 + 128, 100 + 128 + 32 + 2, 120 + 128 + 16 * 8, 100 + 128 + 32 + 2 + 16);

            //ȷ���Ƿ�������ȫ
            if (mindname.str[0] == '\0')
            {
                puthz(120 + 128, 100 + 128 + 32 + 2, "δ����˼ά��ͼ��", 16, 16, RED);
            }

            //�ж�˼ά��ͼ�Ƿ����
            else if (!daotujud(account_name, mindname.str))
            {
                puthz(120 + 128, 100 + 128 + 32 + 2, "��˼ά��ͼ������", 16, 16, RED);
            }
            else
            {
				(*daotu_info).type = findmind(account_name, mindname.str).type;
				strcpy((*daotu_info).mindname, findmind(account_name, mindname.str).mindname);
				mstate = 1;
            }
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
                rectangle(120 + 80 + 80 + 80, 100 + 192, 120 + 80 + 80 + 80 + 80, 100 + 192 + 32);
                break;
            case 2:
                MouseS = 0;
                break;
            case 3:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(120 + 80, 100 + 192, 120 + 80 + 80, 100 + 192 + 32);
            }
        }
    }
    return mstate;
}

/**************************************************
Name: open_screen
Function�����ƴ򿪽���
Calls: ��
Called By: open
Parameter: ��
Return: ��
Author: ������
Others: ��
**************************************************/
void open_screen(void)
{
    //����
    cleardevice();
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(0, 0, 640, 480);

    //����
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(120, 100, 120 + 400, 100 + 280);
    setcolor(WHITE);
    setlinestyle(3, 0, 1); //�����ۺ���
    rectangle(120, 100, 120 + 400, 100 + 280);
    setlinestyle(1, 0, 3); //������
    rectangle(120 + 2, 100 + 2, 120 + 400 - 2, 100 + 280 - 2);

    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(120 + 100, 100 + 28 + 40, 120 + 100 + 24 * 8 + 8, 100 + 28 + 40 + 24 + 8);
    setlinestyle(0, 0, 1); //�����ۺ���
    rectangle(120 + 100, 100 + 28 + 40, 120 + 100 + 24 * 8 + 8, 100 + 28 + 40 + 24 + 8);
    puthz(120 + 104, 100 + 32 + 40, "������˼ά��ͼ��", 24, 24, WHITE);

    //�����
    setfillstyle(SOLID_FILL, WHITE);
    bar(120 + 128, 100 + 128, 120 + 128 + 144, 100 + 128 + 32);

    //�򿪼�
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(120 + 80, 100 + 192, 120 + 80 + 80, 100 + 192 + 32);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(120 + 80, 100 + 192, 120 + 80 + 80, 100 + 192 + 32);
    puthz(120 + 80 + 8, 100 + 192 + 4, "��", 24, 40, WHITE);

    //ȡ����
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(120 + 80 + 80 + 80, 100 + 192, 120 + 80 + 80 + 80 + 80, 100 + 192 + 32);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(120 + 80 + 80 + 80, 100 + 192, 120 + 80 + 80 + 80 + 80, 100 + 192 + 32);
    puthz(120 + 80 + 80 + 80 + 8, 100 + 192 + 4, "ȡ��", 24, 40, WHITE);
}