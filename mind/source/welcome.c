/**********************************************
Description:  完成欢迎界面及其功能
Function list :  welcome    欢迎界面功能
                 welcome_screen    绘制欢迎界面
Attention:
Author: 贾田旺
***********************************************/
#include "common.h"
#include "welcome.h"

/**************************************************
Name: welcome
Function：欢迎界面相关信息与跳转功能
Calls: 无
Called By: main
Parameter： 无
Return: page 页面跳转
Author: 贾田旺
Others: 无
**************************************************/
int welcome(void)
{
    int page = 1;
    int state = 0, pre_state = 0; //表示鼠标状态的相关值
                                  //0 无操作状态 1 退出键 2 注册键 3 登陆键
                                  //4 帮助键
    clrmous(MouseX, MouseY);
    delay(100);
    //mouseinit();
    welcome_screen();
    mouseinit();

    while (page == 1)
    {
        newmouse(&MouseX, &MouseY, &press);
        //退出框
        if (mouse_press(590, 0, 640, 35) == 2) //在退出框且未点击
        {
            pre_state = state;
            state = 1;
            if (pre_state != 1) //防止被重复标亮（只有之前是其它状态才标亮）
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1;
                setcolor(RED);
                setlinestyle(0, 0, 3);
                rectangle(590, 0, 640, 35);
            }
        }
        else if (mouse_press(590, 0, 640, 35) == 1) //在退出框且点击
        {
            page = 0;
        }
        //注册框
        else if (mouse_press(240, 300, 400, 340) == 2) //在注册框未点击
        {
            pre_state = state;
            state = 2;
            if (pre_state != 2) //防止被重复标亮（只有之前是其它状态才标亮）
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1;
                setcolor(LIGHTMAGENTA);
                setlinestyle(0, 0, 1);
                setfillstyle(SOLID_FILL, LIGHTMAGENTA);
                rectangle(240, 300, 400, 340);
                fillellipse(252, 320, 9, 9);
                puthz(275, 310, "用户注册", 24, 32, LIGHTMAGENTA);
                setlinestyle(0, 0, 3);
                line(195, 320, 240, 320);
                setfillstyle(SOLID_FILL, YELLOW);
                fillellipse(120, 320, 75, 26);
                puthz(53, 312, "点击即可加入我们", 16, 17, LIGHTMAGENTA);
            }
        }
        else if (mouse_press(240, 300, 400, 340) == 1) //在注册框且点击
        {
            page = 2;
        }
        //登录框
        else if (mouse_press(240, 350, 400, 390) == 2) //在登录框未点击
        {
            pre_state = state;
            state = 3;
            if (pre_state != 3) //防止被重复标亮（只有之前是其它状态才标亮）
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1;
                setcolor(LIGHTMAGENTA);
                setlinestyle(0, 0, 1);
                setfillstyle(SOLID_FILL, LIGHTMAGENTA);
                rectangle(240, 350, 400, 390);
                fillellipse(252, 370, 9, 9);
                puthz(275, 360, "用户登录", 24, 32, LIGHTMAGENTA);
                setlinestyle(0, 0, 3);
                line(445, 370, 400, 370);
                setfillstyle(SOLID_FILL, YELLOW);
                fillellipse(520, 370, 75, 26);
                puthz(453, 362, "登录即可纵情表达", 16, 17, LIGHTMAGENTA);
            }
        }
        else if (mouse_press(240, 350, 400, 390) == 1)
        {
            page = 3;
        }
        else if (mouse_press(0, 0, 50, 35) == 2) //帮助未点击
        {
            pre_state = state;
            state = 4;
            if (pre_state != 4) //防止被重复标亮（只有之前是其它状态才标亮）
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(RED);
                setlinestyle(0, 0, 3);
                rectangle(0, 0, 50, 35);
            }
        }
        else if (mouse_press(0, 0, 50, 35) == 1) //帮助且点击
        {
            page = 6;
        }
        //无操作状态
        else
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
                puthz(275, 310, "用户注册", 24, 32, WHITE);
                setlinestyle(0, 0, 3);
                line(195, 320, 240, 320);
                setfillstyle(SOLID_FILL, YELLOW);
                fillellipse(120, 320, 75, 26);
                puthz(53, 312, "快来写下你的想法", 16, 17, LIGHTBLUE);
                break;
            case 3:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                setfillstyle(SOLID_FILL, WHITE);
                rectangle(240, 350, 400, 390);
                fillellipse(252, 370, 9, 9);
                puthz(275, 360, "用户登录", 24, 32, WHITE);
                setlinestyle(0, 0, 3);
                line(445, 370, 400, 370);
                setfillstyle(SOLID_FILL, YELLOW);
                fillellipse(520, 370, 75, 26);
                puthz(453, 362, "快来架构你的思维", 16, 17, LIGHTBLUE);
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
Function：画欢迎界面
Calls: 无
Called By: welcome
Parameter：无
Return: 无
Author: 贾田旺
Others: 无
**************************************************/
void welcome_screen(void)
{
    //用于画m字母的数组
    int a[32] = {250, 170, 270, 60, 300, 60, 320, 140, 340, 60, 370, 60, 390, 170, 380, 170, 362, 80, 348, 80, 325, 170, 315, 170, 292, 80,
                 278, 80, 260, 170, 250, 170};

    //背景
    cleardevice();
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(0, 0, 640, 480);

    //退出按钮
    setcolor(WHITE);
    setlinestyle(0, 0, 3);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(590, 0, 640, 35); //退出按钮
    rectangle(590, 0, 640, 35);
    puthz(600, 10, "退出", 12, 18, WHITE);

    //帮助按钮
    bar(0, 0, 50, 35); //退出按钮
    rectangle(0, 0, 50, 35);
    puthz(10, 10, "帮助", 12, 18, WHITE);

    //画M logo
    setfillstyle(SOLID_FILL, YELLOW);
    setlinestyle(0, 0, 1);
    fillellipse(320, 120, 100, 100);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    fillellipse(320, 120, 90, 90);
    setfillstyle(SOLID_FILL, YELLOW);
    fillpoly(16, a);

    //思维导图汉字
    puthz(225, 235, "思维导图", 48, 50, LIGHTBLUE);

    //注册按钮
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(240, 300, 400, 340);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(240, 300, 400, 340);
    puthz(275, 310, "用户注册", 24, 32, WHITE);

    //登录按钮
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(240, 350, 400, 390);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(240, 350, 400, 390);
    puthz(275, 360, "用户登录", 24, 32, WHITE);

    //两个按钮的修饰
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(252, 370, 9, 9);
    fillellipse(252, 320, 9, 9);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(520, 370, 75, 26);
    fillellipse(120, 320, 75, 26);
    puthz(453, 362, "快来架构你的思维", 16, 17, LIGHTBLUE);
    puthz(53, 312, "快来写下你的想法", 16, 17, LIGHTBLUE);
    setcolor(WHITE);
    setlinestyle(0, 0, 3);
    line(445, 370, 400, 370);
    line(195, 320, 240, 320);

    //版权信息
    setcolor(WHITE);
    settextstyle(0, 0, 1);
    outtextxy(260, 470, "Copyright C 2020 HUST-Jiatianwang, Niqiyuan.");
}
