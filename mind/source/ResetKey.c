/**********************************************
Description:  �����������ҳ�漰��ع���
Function list :  reset_key    �������뺯��
                 reset_key_screen    ������������ҳ��
Attention:
Author: ������
History: 1 ���ҳ����Ƽ���ת 2 ��ɾ����������빦��
***********************************************/

#include "common.h"
#include "ResetKey.h"

/**************************************************
Name: reset_key
Function���������뺯��
Calls:  reset_key_screen
        input_info
        judge_samename
        right_ID
        judge_password
        rewrite_key
Called By: main
Parameter: ��
Return: page ҳ����ת
Author: ������
Others: ��
**************************************************/
int reset_key(void)
{
    int page = 4;
    int state = 0, pre_state = 0;                                    //��ʾ���״̬�����ֵ
                                                                     // 0 �޲���״̬ 1 �˳���ť 2 ���ذ�ť 3 �ĸ�����׿�
                                                                     // 4 ȷ����ť
    ENTER username = {96 + 128, 96, 96 + 448, 96 + 32, 8, 0, 0, ""}; //ENTERΪ������Ϣ�ṹ�壬���data.h
    ENTER ID = {96 + 128, 160, 96 + 448, 160 + 32, 18, 0, 0, ""};
    ENTER password1 = {96 + 128, 224, 96 + 448, 224 + 32, 12, 0, 0, ""};
    ENTER password2 = {96 + 128, 288, 96 + 448, 288 + 32, 12, 0, 0, ""};

    clrmous(MouseX, MouseY);
    delay(100);
    reset_key_screen();
    mouseinit();

    while (page == 4)
    {
        newmouse(&MouseX, &MouseY, &press);

        if (username.flag != 1 && ID.flag != 1 && password1.flag != 1 && password2.flag != 1)
        {
            while (bioskey(1))
            {
                getch();
            }
        }

        input_info(96 + 128 + 4, 96 + 4, 7, 1, &username);
        input_info(96 + 128 + 4, 160 + 4, 7, 1, &ID);
        input_info(96 + 128 + 4, 224 + 4, 7, 0, &password1);
        input_info(96 + 128 + 4, 288 + 4, 7, 0, &password2);

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
            page = 3;
        }
        else if (mouse_press(96 + 128, 96, 96 + 448, 96 + 32) == 2 || mouse_press(96 + 128, 160, 96 + 448, 160 + 32) == 2 ||
                 mouse_press(96 + 128, 224, 96 + 448, 224 + 32) == 2 || mouse_press(96 + 128, 288, 96 + 448, 288 + 32) == 2)
        //�ĸ�����׿� ��δ���
        {
            pre_state = state;
            state = 3;
            if (pre_state != 3) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 2; //���
            }
        }
        else if (mouse_press(256, 352, 256 + 128, 352 + 48) == 2) //ȷ����ť��δ���
        {
            pre_state = state;
            state = 4;

            if (pre_state != 4) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                bar(264, 352, 264 + 120, 352 + 40);
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(268, 356, 268 + 112, 356 + 32);
                puthz(264 + 20, 352 + 8, "ȷ��", 24, 56, WHITE);
            }
        }
        else if (mouse_press(256, 352, 256 + 128, 352 + 48) == 1) //ȷ����ť�ҵ��
        {
            //�����ʾ��Ϣ
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            bar(96 + 448 - 16 * 6, 96 + 32 + 4, 96 + 448, 96 + 32 + 4 + 16);
            bar(96 + 448 - 16 * 7, 160 + 32 + 4, 96 + 448, 160 + 32 + 4 + 16);
            bar(96 + 448 - 16 * 9, 224 + 32 + 4, 96 + 448, 224 + 32 + 4 + 16);
            bar(96 + 448 - 16 * 9, 288 + 32 + 4, 96 + 448, 288 + 32 + 4 + 16);

            //ȷ���Ƿ�������ȫ
            if (username.str[0] == '\0')
            {
                puthz(96 + 448 - 16 * 6, 96 + 32 + 4, "δ�����û���", 16, 16, RED);
            }
            else if (ID.str[0] == '\0')
            {
                puthz(96 + 448 - 16 * 7, 160 + 32 + 4, "δ�������֤��", 16, 16, RED);
            }
            else if (password1.str[0] == '\0')
            {
                puthz(96 + 448 - 16 * 5, 224 + 32 + 4, "δ��������", 16, 16, RED);
            }
            else if (password2.str[0] == '\0')
            {
                puthz(96 + 448 - 16 * 6, 288 + 32 + 4, "δȷ������", 16, 16, RED);
            }

            //�ж��Ƿ�����û���
            else if (!judge_samename(username.str))
            {
                puthz(96 + 448 - 16 * 6, 96 + 32 + 4, "�û���������", 16, 16, RED);
            }

            //�ж����֤���Ƿ���ȷ
            else if (!right_ID(username.str, ID.str))
            {
                puthz(96 + 448 - 16 * 6, 160 + 32 + 4, "���֤�Ŵ���", 16, 16, RED);
            }

            //�ж������Ƿ����Ҫ��
            else if (!judge_password(password1.str))
            {
                puthz(96 + 448 - 16 * 9, 224 + 32 + 4, "���볤������Ϊ��λ", 16, 16, RED);
            }

            //�ж��������������Ƿ���ͬ
            else if (strcmp(password1.str, password2.str))
            {
                puthz(96 + 448 - 16 * 9, 288 + 32 + 4, "�����������벻һ��", 16, 16, RED);
            }

            else //�����ɹ�д�������룬���ص�¼ҳ��
            {
                rewrite_key(username.str, password1.str);
                page = 3;
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
                break;
            case 4:
                MouseS = 0;
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(264, 352, 264 + 120, 352 + 40);
                puthz(264 + 20, 352 + 8, "ȷ��", 24, 56, WHITE);
                break;
            }
        }
    }
    return page;
}

/**************************************************
Name: reset_key_screen
Function����������ҳ��
Calls: ��
Called By: reset_key
Parameter: ��
Return: ��
Author: ������
Others: ��
**************************************************/
void reset_key_screen(void)
{
    cleardevice();
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(0, 0, 640, 480);

    //�˳�����İ�ť
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
    bar(96, 96, 96 + 128, 96 + 32);
    puthz(96 + 4, 96 + 4, "�û���", 24, 48, WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(96 + 128, 96, 96 + 448, 96 + 32);

    //���֤�ſ�
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    bar(96, 160, 96 + 128, 160 + 32);
    puthz(96 + 4, 160 + 4, "���֤��", 24, 32, WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(96 + 128, 160, 96 + 448, 160 + 32);

    //�������
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    bar(96, 224, 96 + 128, 224 + 32);
    puthz(96 + 4, 224 + 4, "������", 24, 48, WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(96 + 128, 224, 96 + 448, 224 + 32);

    //ȷ�������
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    bar(96, 288, 96 + 128, 288 + 32);
    puthz(96 + 4, 288 + 4, "ȷ������", 24, 32, WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(96 + 128, 288, 96 + 448, 288 + 32);

    //ȷ����ť
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(264, 352, 264 + 120, 352 + 40);
    puthz(264 + 20, 352 + 8, "ȷ��", 24, 56, WHITE);
}
