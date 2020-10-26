/**********************************************
Description:  ��¼ҳ�漰��ع���
Function list :  log    ��¼����
                log_screen  ���Ƶ�¼ҳ��   
Attention:
Author: ������
History: 1 ��ɻ��Ƽ���ת  2  ��ɵ�¼���� 
***********************************************/

#include "common.h"
#include "Log.h"

/**************************************************
Name: log
Function����¼����
Calls: input_info
       judge_samename
       right_key
Called By: main
Parameter: account_name  �û��� ��¼�������������û���ص��ļ�
Return: page ҳ����ת
Author: ������
Others: ��
**************************************************/
int log(char *account_name)
{
    int page = 3;
    int state = 0, pre_state = 0; //��ʾ���״̬�����ֵ��δ�����
                                  // 0 �޲���״̬ 1 �˳���ť 2 ���ذ�ť 3 ��¼��ť
                                  // 4 �������밴ť 5 ��������׿�
    ENTER username = {96 + 128, 128, 96 + 448, 128 + 32, 8, 0, 0, ""};
    ENTER password = {96 + 128, 188, 96 + 448, 188 + 32, 12, 0, 0, ""};
    clrmous(MouseX, MouseY);
    delay(100);
    log_screen();
    mouseinit();

    while (page == 3)
    {
        newmouse(&MouseX, &MouseY, &press);

        if (username.flag != 1 && password.flag != 1)
        {
            while (bioskey(1))
            {
                getch();
            }
        }

        input_info(96 + 128 + 4, 128 + 4, 7, 1, &username);
        input_info(96 + 128 + 4, 188 + 4, 7, 0, &password);

        if (mouse_press(608, 0, 640, 32) == 2) //�˳�����δ���
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
                rectangle(608, 0, 640, 32);
                setlinestyle(0, 0, 3);
                line(616, 8, 632, 24);
                line(616, 24, 632, 8);
            }
        }
        else if (mouse_press(608, 0, 640, 32) == 1) //�˳����ҵ��
        {
            page = 0;
        }
        else if (mouse_press(0, 0, 32, 32) == 2) //���ؿ���δ���
        {
            pre_state = state;
            state = 2;

            if (pre_state != 2) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(RED);
                rectangle(0, 0, 32, 32);
            }
        }
        else if (mouse_press(0, 0, 32, 32) == 1) //���ؿ��ҵ��
        {
            page = 1;
        }
        else if (mouse_press(262, 258, 262 + 120, 258 + 40) == 2) //��¼��ť��δ���
        {
            pre_state = state;
            state = 3;

            if (pre_state != 3) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(WHITE);
                setlinestyle(0, 0, 3);
                rectangle(262, 258, 262 + 120, 258 + 40);
            }
        }
        else if (mouse_press(262, 258, 262 + 120, 258 + 40) == 1) //��¼��ť�ҵ��
        {
            //�����ʾ��Ϣ
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            bar(96 + 448 - 16 * 6, 128 + 32 + 4, 96 + 448, 128 + 32 + 4 + 16);
            bar(96 + 448 - 16 * 5, 188 + 32 + 4, 96 + 448, 188 + 32 + 4 + 16);

            //ȷ���Ƿ�������ȫ
            if (username.str[0] == '\0')
            {
                puthz(96 + 448 - 16 * 6, 128 + 32 + 4, "δ�����û���", 16, 16, RED);
            }
            else if (password.str[0] == '\0')
            {
                puthz(98 + 488 - 16 * 5, 188 + 32 + 4, "δ��������", 16, 16, RED);
            }

            //�ж��û����Ƿ����
            else if (!judge_samename(username.str))
            {
                puthz(96 + 448 - 16 * 6, 128 + 32 + 4, "�û���������", 16, 16, RED);
            }

            //�ж������Ƿ���ȷ
            else if (!right_key(username.str, password.str))
            {
                puthz(96 + 448 - 16 * 4, 188 + 32 + 4, "�������", 16, 16, RED);
            }

            //��½�ɹ����ò��������û��������뵽�༭��ҳ��
            else
            {
				strcpy(account_name, username.str);
                page = 5;
            }
        }

        else if (mouse_press(430, 328, 430 + 128, 328 + 40) == 2) //�������밴ť��δ���
        {
            pre_state = state;
            state = 4;

            if (pre_state != 4) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(WHITE);
                setlinestyle(0, 0, 3);
                rectangle(430, 328, 430 + 128, 328 + 40);
            }
        }
        else if (mouse_press(430, 328, 430 + 128, 328 + 40) == 1) //�������밴ť�ҵ��
        {
            page = 4;
        }
        else if (mouse_press(96 + 128, 128, 96 + 448, 128 + 32) == 2 || mouse_press(96 + 128, 188, 96 + 448, 188 + 32) == 2) //��������׿���δ��� ��δ�������״̬
        {
            pre_state = state;
            state = 5;

            if (pre_state != 5) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 2; //���
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
                rectangle(608, 0, 640, 32);
                setlinestyle(0, 0, 3);
                line(616, 8, 632, 24);
                line(616, 24, 632, 8);
                break;
            case 2:
                MouseS = 0;
                setcolor(WHITE);
                rectangle(0, 0, 32, 32);
                break;
            case 3:
                MouseS = 0;
                setcolor(LIGHTGRAY);
                setlinestyle(0, 0, 3);
                rectangle(262, 258, 262 + 120, 258 + 40);
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(262, 258, 262 + 120, 258 + 40);
                break;
            case 4:
                MouseS = 0;
                setcolor(LIGHTGRAY);
                setlinestyle(0, 0, 3);
                rectangle(430, 328, 430 + 128, 328 + 40);
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(430, 328, 430 + 128, 328 + 40);
                break;
            case 5:
                MouseS = 0;
                break;
            }
        }
    }
    return page;
}

/**************************************************
Name: log_screen
Function�����Ƶ�½ҳ��
Calls: ��
Called By: log
Parameter: ��
Return: ��
Author: ������
Others: ��
**************************************************/
void log_screen()
{
    cleardevice();
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(0, 0, 640, 480);

    //�˳�����İ�ť
    setlinestyle(0, 0, 1);
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(608, 0, 640, 32);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(608, 0, 640, 32);
    setlinestyle(0, 0, 3);
    line(616, 8, 632, 24);
    line(616, 24, 632, 8);

    //���ذ�ť
    setlinestyle(0, 0, 1);
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(0, 0, 32, 32);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(0, 0, 32, 32);
    setlinestyle(0, 0, 3);
    line(24, 4, 8, 16);
    line(8, 16, 24, 28);

    //����
    setlinestyle(0, 0, 3);
    setcolor(WHITE);
    rectangle(56, 64, 582, 416);
    setlinestyle(0, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(56, 64, 582, 416);

    //�û�����
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    bar(96, 128, 96 + 128, 128 + 32);
    puthz(96 + 4, 128 + 4, "�û���", 24, 48, WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(96 + 128, 128, 96 + 448, 128 + 32);

    //�����
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    bar(96, 188, 96 + 128, 188 + 32);
    puthz(96 + 20, 188 + 4, "����", 24, 64, WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(96 + 128, 188, 96 + 448, 188 + 32);

    //��¼��
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    setlinestyle(0, 0, 1);
    setcolor(WHITE);
    bar(262, 258, 262 + 120, 258 + 40);
    rectangle(262, 258, 262 + 120, 258 + 40);
    puthz(262 + 20, 258 + 8, "��¼", 24, 56, WHITE);

    //���������
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    setlinestyle(0, 0, 1);
    setcolor(WHITE);
    bar(430, 328, 430 + 128, 328 + 40);
    rectangle(430, 328, 430 + 128, 328 + 40);
    puthz(430 + 4, 328 + 8, "��������", 24, 32, LIGHTRED);
}