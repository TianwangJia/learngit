/**********************************************
Description:  帮助界面
Function list :  help   帮助界面功能
                 help_screen  绘制帮助界面
                 help_page1 第一页
                 help_page2 第二页
                 help_page3 第三页
                 help_page4 第四页
Attention:  
Author:  贾田旺
History:  
***********************************************/
#include "common.h"
#include "help.h"

/**************************************************
Name: help
Function：完成帮助界面功能
Calls: help_screen
Called By: main
Parameter: 无
Return: page 页面跳转
Author: 贾田旺
Others: 未完成
**************************************************/
int help()
{
    int index = 1; //表示翻页索引 目前范围1~4
    int click = 0; //表示方向键是否曾有效点击 0未点击 1点击
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
                    16}};         //绘制方向键数组 右，左
    int state = 0, pre_state = 0; //表示鼠标状态的相关值（未点击）
                                  // 0 无操作状态 1 返回键
    clrmous(MouseX, MouseY);
    delay(100);
    help_page1(a);
    mouseinit();
    //newmouse(&MouseX, &MouseY, &press); 可以用newmouse不会跳鼠标

    while (page == 6)
    {
        newmouse(&MouseX, &MouseY, &press);

        if (mouse_press(8, 2, 8 + 48 + 8, 30) == 2) //返回键且未点击
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
                rectangle(8, 2, 8 + 48 + 8, 30);
            }
        }
        else if (mouse_press(8, 2, 8 + 48 + 8, 30) == 1)
        {
            page = 1;
        }
        else if (mouse_press(640 - 8 - 30 - 8 - 30, 2, 640 - 8 - 30 - 8, 30) == 2) //方向左未点击
        {
            pre_state = state;
            state = 2;

            if (pre_state != 2) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(LIGHTRED);
                rectangle(640 - 8 - 30 - 8 - 30, 2, 640 - 8 - 30 - 8, 30);
                setfillstyle(SOLID_FILL, LIGHTRED);
                fillpoly(4, a[1]);
            }
        }
        else if (mouse_press(640 - 8 - 30 - 8 - 30, 2, 640 - 8 - 30 - 8, 30) == 1 && index > 1) //方向键左且点击
        {
            click = 1;
            index -= 1;

            clrmous(MouseX, MouseY);
            delay(100);
        }
        else if (mouse_press(640 - 8 - 30, 2, 640 - 8, 30) == 2) //方向右未点击
        {
            pre_state = state;
            state = 3;

            if (pre_state != 3) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(LIGHTRED);
                rectangle(640 - 8 - 30, 2, 640 - 8, 30);
                setfillstyle(SOLID_FILL, LIGHTRED);
                fillpoly(4, a[0]);
            }
        }
        else if (mouse_press(640 - 8 - 30, 2, 640 - 8, 30) == 1 && index < 4) //方向键右且点击
        {
            click = 1;
            index += 1;

            clrmous(MouseX, MouseY);
            delay(100);
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
Function：绘制帮助界面
Calls: 无
Called By: help
Parameter: a 绘制方向键数组
Return: 无
Author: 贾田旺
Others: 无
**************************************************/
void help_screen(int (*a)[8])
{
    cleardevice();
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, 640, 480); //背景

    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(0, 0, 640, 32);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(640 - 8 - 30, 2, 640 - 8, 30);
    bar(640 - 8 - 30 - 8 - 30, 2, 640 - 8 - 30 - 8, 30);
    bar(8, 2, 8 + 48 + 8, 30); //返回键
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillpoly(4, a[0]);
    fillpoly(4, a[1]); //方向键

    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(8, 2, 8 + 48 + 8, 30);
    rectangle(640 - 8 - 30, 2, 640 - 8, 30);
    rectangle(640 - 8 - 30 - 8 - 30, 2, 640 - 8 - 30 - 8, 30);

    puthz(297, 4, "帮助", 24, 32, BLACK);
    puthz(8 + 4, 4, "返回", 24, 24, WHITE);
}

/**************************************************
Name: help_page2
Function：帮助页面第一页
Calls: 无
Called By: help
Parameter: a 绘制方向键数组
Return: 无
Author: 贾田旺
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
    puthz(0, 46, "用户可在欢迎界面进行以下操作", 16, 16, BLACK); //从46开始间隔为6
    puthz(14 * 16, 46 + 22 * 1, "注册：", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 1, "需要用户名，身份证号，密码（最少八位）", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 2, "登录：", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 2, "使用已注册的用户名和密码进行登录", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 3, "修改密码：", 16, 16, RED);
    puthz(19 * 16, 46 + 22 * 3, "使用已注册的用户名与对应身份证号修改密码", 16, 16, BLACK);
    puthz(0, 46 + 22 * 6, "登录", 16, 16, RED);
    puthz(16 * 2, 46 + 22 * 6, "后进入导图操作页面", 16, 16, BLACK);
    setcolor(RED);
    setlinestyle(0, 0, 1);
    rectangle(0, 46 + 22 * 6, 16 * 2, 46 + 22 * 6 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 1, 14 * 16 + 16 * 2, 46 + 22 * 1 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 2, 14 * 16 + 16 * 2, 46 + 22 * 2 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 3, 14 * 16 + 16 * 4, 46 + 22 * 3 + 16 * 1);
}

/**************************************************
Name: help_page2
Function：帮助页面第二页
Calls: 无
Called By: help
Parameter: a 绘制方向键数组
Return: 无
Author: 贾田旺
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
    puthz(0, 46, "用户可在操作界面进行以下操作", 16, 16, BLACK); //从46开始间隔为6
    puthz(14 * 16, 46 + 22 * 1, "新建：", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 1, "新建一个导图（名字不可重复），可选类型有四种", 16, 16, BLACK);
    puthz(17 * 16, 46 + 22 * 2, "单向导图，树状图，时间轴，鱼骨图", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 3, "打开：", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 3, "输入名称可打开已存在导图文件", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 4, "关闭：", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 4, "关闭当前导图文件，并显示初始页面", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 5, "删除：", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 5, "关闭当前导图文件，显示初始页面并删除对应导图", 16, 16, BLACK);
    puthz(17 * 16, 46 + 22 * 6, "文件", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 7, "编辑：", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 7, "（已打开导图文件）对导图框内容进行编辑子操作", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 8, "保存：", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 8, "对更改进行保存", 16, 16, BLACK);
    puthz(0, 46 + 22 * 11, "点击", 16, 16, BLACK);
    puthz(2 * 16, 46 + 22 * 11, "编辑", 16, 16, RED);
    puthz(4 * 16, 46 + 22 * 11, "后进入编辑界面", 16, 16, BLACK);
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
Function：帮助页面第三页
Calls: 无
Called By: help
Parameter: a 绘制方向键数组
Return: 无
Author: 贾田旺
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
    puthz(0, 46, "用户可在编辑界面进行以下操作", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 1, "选中：", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 1, "点击存在的思维导图框进行选中，标红", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 2, "编辑文本：", 16, 16, RED);
    puthz(19 * 16, 46 + 22 * 2, "标红框后立刻进入文本编辑状态，按下", 16, 16, BLACK);
    puthz(19 * 16 + 17 * 16, 46 + 22 * 2, "回车", 16, 16, RED);
    puthz(21 * 16 + 17 * 16, 46 + 22 * 2, "退", 16, 16, BLACK);
    puthz(19 * 16, 46 + 22 * 3, "出状态", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 4, "新建：", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 4, "标红后新建子框", 16, 16, BLACK);
    puthz(14 * 16, 46 + 22 * 5, "删除：", 16, 16, RED);
    puthz(17 * 16, 46 + 22 * 5, "删除标红框及子框，界面调整", 16, 16, BLACK);
    puthz(0, 46 + 22 * 8, "点击", 16, 16, BLACK);
    puthz(2 * 16, 46 + 22 * 8, "完成", 16, 16, RED);
    puthz(4 * 16, 46 + 22 * 8, "后退回操作页面", 16, 16, BLACK);
    setcolor(RED);
    setlinestyle(0, 0, 1);
    rectangle(19 * 16 + 17 * 16, 46 + 22 * 2, 38 * 16, 46 + 22 * 2 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 4, 14 * 16 + 2 * 16, 46 + 22 * 4 + 16 * 1);
    rectangle(14 * 16, 46 + 22 * 5, 14 * 16 + 2 * 16, 46 + 22 * 5 + 16 * 1);
    rectangle(2 * 16, 46 + 22 * 8, 2 * 16 + 2 * 16, 46 + 22 * 8 + 16 * 1);
}

/**************************************************
Name: help_page4
Function：帮助页面第四页
Calls: 无
Called By: help
Parameter: a 绘制方向键数组
Return: 无
Author: 贾田旺
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
    puthz(0, 46, "新建导图文件界面", 16, 16, BLACK);
    puthz(8 * 16, 46 + 1 * 16, "用户可选中导图类型，输入导图名进行新建", 16, 16, BLACK);
    puthz(8 * 16, 46 + 2 * 16, "也可退出程序，返回操作界面", 16, 16, BLACK);
    puthz(0, 46 + 4 * 16, "打开导图文件界面", 16, 16, BLACK);
    puthz(8 * 16, 46 + 5 * 16, "输入导图名，点击确定打开", 16, 16, BLACK);
    puthz(8 * 16, 46 + 6 * 16, "点击取消，返回操作界面", 16, 16, BLACK);
}
