/**********************************************
Description:  登录页面及相关功能
Function list :  log    登录函数
                log_screen  绘制登录页面   
Attention:
Author: 贾田旺
History: 1 完成绘制及跳转  2  完成登录功能 
***********************************************/

#include "common.h"
#include "Log.h"

/**************************************************
Name: log
Function：登录函数
Calls: input_info
       judge_samename
       right_key
Called By: main
Parameter: account_name  用户名 登录后用来保存与用户相关的文件
Return: page 页面跳转
Author: 贾田旺
Others: 无
**************************************************/
int log(char *account_name)
{
    int page = 3;
    int state = 0, pre_state = 0; //表示鼠标状态的相关值（未点击）
                                  // 0 无操作状态 1 退出按钮 2 返回按钮 3 登录按钮
                                  // 4 忘记密码按钮 5 两个输入白框
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
            page = 1;
        }
        else if (mouse_press(262, 258, 262 + 120, 258 + 40) == 2) //登录按钮且未点击
        {
            pre_state = state;
            state = 3;

            if (pre_state != 3) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(WHITE);
                setlinestyle(0, 0, 3);
                rectangle(262, 258, 262 + 120, 258 + 40);
            }
        }
        else if (mouse_press(262, 258, 262 + 120, 258 + 40) == 1) //登录按钮且点击
        {
            //清除提示信息
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            bar(96 + 448 - 16 * 6, 128 + 32 + 4, 96 + 448, 128 + 32 + 4 + 16);
            bar(96 + 448 - 16 * 5, 188 + 32 + 4, 96 + 448, 188 + 32 + 4 + 16);

            //确认是否输入完全
            if (username.str[0] == '\0')
            {
                puthz(96 + 448 - 16 * 6, 128 + 32 + 4, "未输入用户名", 16, 16, RED);
            }
            else if (password.str[0] == '\0')
            {
                puthz(98 + 488 - 16 * 5, 188 + 32 + 4, "未输入密码", 16, 16, RED);
            }

            //判断用户名是否存在
            else if (!judge_samename(username.str))
            {
                puthz(96 + 448 - 16 * 6, 128 + 32 + 4, "用户名不存在", 16, 16, RED);
            }

            //判断密码是否正确
            else if (!right_key(username.str, password.str))
            {
                puthz(96 + 448 - 16 * 4, 188 + 32 + 4, "密码错误", 16, 16, RED);
            }

            //登陆成功，用参数保存用户名，进入到编辑主页面
            else
            {
				strcpy(account_name, username.str);
                page = 5;
            }
        }

        else if (mouse_press(430, 328, 430 + 128, 328 + 40) == 2) //忘记密码按钮且未点击
        {
            pre_state = state;
            state = 4;

            if (pre_state != 4) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(WHITE);
                setlinestyle(0, 0, 3);
                rectangle(430, 328, 430 + 128, 328 + 40);
            }
        }
        else if (mouse_press(430, 328, 430 + 128, 328 + 40) == 1) //忘记密码按钮且点击
        {
            page = 4;
        }
        else if (mouse_press(96 + 128, 128, 96 + 448, 128 + 32) == 2 || mouse_press(96 + 128, 188, 96 + 448, 188 + 32) == 2) //两个输入白框且未点击 还未制作点击状态
        {
            pre_state = state;
            state = 5;

            if (pre_state != 5) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 2; //光标
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
Function：绘制登陆页面
Calls: 无
Called By: log
Parameter: 无
Return: 无
Author: 贾田旺
Others: 无
**************************************************/
void log_screen()
{
    cleardevice();
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(0, 0, 640, 480);

    //退出程序的按钮
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

    //返回按钮
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
    bar(96, 128, 96 + 128, 128 + 32);
    puthz(96 + 4, 128 + 4, "用户名", 24, 48, WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(96 + 128, 128, 96 + 448, 128 + 32);

    //密码框
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    bar(96, 188, 96 + 128, 188 + 32);
    puthz(96 + 20, 188 + 4, "密码", 24, 64, WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(96 + 128, 188, 96 + 448, 188 + 32);

    //登录框
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    setlinestyle(0, 0, 1);
    setcolor(WHITE);
    bar(262, 258, 262 + 120, 258 + 40);
    rectangle(262, 258, 262 + 120, 258 + 40);
    puthz(262 + 20, 258 + 8, "登录", 24, 56, WHITE);

    //忘记密码框
    setfillstyle(SOLID_FILL, DARKGRAY);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    setlinestyle(0, 0, 1);
    setcolor(WHITE);
    bar(430, 328, 430 + 128, 328 + 40);
    rectangle(430, 328, 430 + 128, 328 + 40);
    puthz(430 + 4, 328 + 8, "忘记密码", 24, 32, LIGHTRED);
}