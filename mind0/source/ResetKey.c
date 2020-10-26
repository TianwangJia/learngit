/**********************************************
Description:  完成重置密码页面及相关功能
Function list :  reset_key    重置密码函数
                 reset_key_screen    绘制重置密码页面
Attention:
Author: 贾田旺
History: 1 完成页面绘制及跳转 2 完成具体重置密码功能
***********************************************/

#include "common.h"
#include "ResetKey.h"

/**************************************************
Name: reset_key
Function：重置密码函数
Calls:  reset_key_screen
        input_info
        judge_samename
        right_ID
        judge_password
        rewrite_key
Called By: main
Parameter: 无
Return: page 页面跳转
Author: 贾田旺
Others: 无
**************************************************/
int reset_key()
{
    int page = 4;
    int state = 0, pre_state = 0;                                    //表示鼠标状态的相关值
                                                                     // 0 无操作状态 1 退出按钮 2 返回按钮 3 四个输入白框
                                                                     // 4 确定按钮
    ENTER username = {96 + 128, 96, 96 + 448, 96 + 32, 8, 0, 0, ""}; //ENTER为输入信息结构体，详见data.h
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

        if (mouse_press(608, 0, 640, 32) == 2) //退出框且未点击
        {
            pre_state = state;
            state = 1;

            if (pre_state != 1) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(RED);
                setlinestyle(0, 0, 1);
                rectangle(608, 0, 640, 32);
                setlinestyle(0, 0, 3);
                line(616, 8, 632, 24);
                line(616, 24, 632, 8);
            }
        }
        else if (mouse_press(608, 0, 640, 32) == 1) //退出框且点击
        {
            page = 0;
        }
        else if (mouse_press(0, 0, 32, 32) == 2) //返回框且未点击
        {
            pre_state = state;
            state = 2;

            if (pre_state != 2) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(RED);
                rectangle(0, 0, 32, 32);
            }
        }
        else if (mouse_press(0, 0, 32, 32) == 1) //返回框且点击
        {
            page = 3;
        }
        else if (mouse_press(96 + 128, 96, 96 + 448, 96 + 32) == 2 || mouse_press(96 + 128, 160, 96 + 448, 160 + 32) == 2 ||
                 mouse_press(96 + 128, 224, 96 + 448, 224 + 32) == 2 || mouse_press(96 + 128, 288, 96 + 448, 288 + 32) == 2)
        //四个输入白框 且未点击
        {
            pre_state = state;
            state = 3;
            if (pre_state != 3) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 2; //光标
            }
        }
        else if (mouse_press(256, 352, 256 + 128, 352 + 48) == 2) //确定按钮且未点击
        {
            pre_state = state;
            state = 4;

            if (pre_state != 4) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                bar(264, 352, 264 + 120, 352 + 40);
                setfillstyle(SOLID_FILL, DARKGRAY);
                bar(268, 356, 268 + 112, 356 + 32);
                puthz(264 + 20, 352 + 8, "确定", 24, 56, WHITE);
            }
        }
        else if (mouse_press(256, 352, 256 + 128, 352 + 48) == 1) //确定按钮且点击
        {
            //清除提示信息
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            bar(96 + 448 - 16 * 6, 96 + 32 + 4, 96 + 448, 96 + 32 + 4 + 16);
            bar(96 + 448 - 16 * 7, 160 + 32 + 4, 96 + 448, 160 + 32 + 4 + 16);
            bar(96 + 448 - 16 * 9, 224 + 32 + 4, 96 + 448, 224 + 32 + 4 + 16);
            bar(96 + 448 - 16 * 9, 288 + 32 + 4, 96 + 448, 288 + 32 + 4 + 16);

            //确认是否输入完全
            if (username.str[0] == '\0')
            {
                puthz(96 + 448 - 16 * 6, 96 + 32 + 4, "未输入用户名", 16, 16, RED);
            }
            else if (ID.str[0] == '\0')
            {
                puthz(96 + 448 - 16 * 7, 160 + 32 + 4, "未输入身份证号", 16, 16, RED);
            }
            else if (password1.str[0] == '\0')
            {
                puthz(96 + 448 - 16 * 5, 224 + 32 + 4, "未输入密码", 16, 16, RED);
            }
            else if (password2.str[0] == '\0')
            {
                puthz(96 + 448 - 16 * 6, 288 + 32 + 4, "未确认密码", 16, 16, RED);
            }

            //判断是否存在用户名
            else if (!judge_samename(username.str))
            {
                puthz(96 + 448 - 16 * 6, 96 + 32 + 4, "用户名不存在", 16, 16, RED);
            }

            //判断身份证号是否正确
            else if (!right_ID(username.str, ID.str))
            {
                puthz(96 + 448 - 16 * 6, 160 + 32 + 4, "身份证号错误", 16, 16, RED);
            }

            //判断密码是否符合要求
            else if (!judge_password(password1.str))
            {
                puthz(96 + 448 - 16 * 9, 224 + 32 + 4, "密码长度至少为八位", 16, 16, RED);
            }

            //判断两次输入密码是否相同
            else if (strcmp(password1.str, password2.str))
            {
                puthz(96 + 448 - 16 * 9, 288 + 32 + 4, "两次输入密码不一致", 16, 16, RED);
            }

            else //操作成功写入新密码，返回登录页面
            {
                rewrite_key(username.str, password1.str);
                page = 3;
            }
        }

        else //无操作状态
        {
            pre_state = state;
            state = 0;
        }
        //如果状态发生改变，且之前不是无操作状态，则可能需清除标亮
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
                puthz(264 + 20, 352 + 8, "确定", 24, 56, WHITE);
                break;
            }
        }
    }
    return page;
}

/**************************************************
Name: reset_key_screen
Function：绘制重置页面
Calls: 无
Called By: reset_key
Parameter: 无
Return: 无
Author: 贾田旺
Others: 无
**************************************************/
void reset_key_screen()
{
    cleardevice();
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(0, 0, 640, 480);

    //退出程序的按钮
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(608, 0, 640, 32);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(608, 0, 640, 32);
    setlinestyle(0, 0, 3);
    line(616, 8, 632, 24);
    line(616, 24, 632, 8);

    //返回按钮
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(0, 0, 32, 32);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(0, 0, 32, 32);
    setlinestyle(0, 0, 3);
    line(24, 4, 8, 16);
    line(8, 16, 24, 28);

    //背景
    setlinestyle(0, 0, 3);
    setcolor(WHITE);
    rectangle(56, 64, 582, 416);
    setlinestyle(0, 0, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(56, 64, 582, 416);

    //用户名框
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    bar(96, 96, 96 + 128, 96 + 32);
    puthz(96 + 4, 96 + 4, "用户名", 24, 48, WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(96 + 128, 96, 96 + 448, 96 + 32);

    //身份证号框
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    bar(96, 160, 96 + 128, 160 + 32);
    puthz(96 + 4, 160 + 4, "身份证号", 24, 32, WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(96 + 128, 160, 96 + 448, 160 + 32);

    //新密码框
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    bar(96, 224, 96 + 128, 224 + 32);
    puthz(96 + 4, 224 + 4, "新密码", 24, 48, WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(96 + 128, 224, 96 + 448, 224 + 32);

    //确认密码框
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    bar(96, 288, 96 + 128, 288 + 32);
    puthz(96 + 4, 288 + 4, "确认密码", 24, 32, WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(96 + 128, 288, 96 + 448, 288 + 32);

    //确定按钮
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(264, 352, 264 + 120, 352 + 40);
    puthz(264 + 20, 352 + 8, "确定", 24, 56, WHITE);
}
