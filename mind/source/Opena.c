/**********************************************
Description:  打开界面及功能
Function list :  opena   完成打开功能
                 open_screen  绘制打开界面
Attention:  
Author:  贾田旺
History:  
***********************************************/

#include "common.h"
#include "Opena.h"

/**************************************************
Name: opena
Function：完成打开功能
Calls: 
Called By: edit.c
Parameter: account_name 账户名
           daotu_info  思维导图信息
Return: mstate 打开状态
Author: 贾田旺
Others: 
**************************************************/
int opena(char *account_name, MIND *daotu_info)
{
    int mstate = 2;               //表示打开导图状态 2表示仍在页面中 0未打开返回 1表示打开返回
    int state = 0, pre_state = 0; //表示鼠标状态的相关值
                                  // 0 无操作状态 1 取消按钮 2 输入白框 3 打开按钮
    ENTER mindname = {120 + 128, 100 + 128, 120 + 128 + 144, 100 + 128 + 32, 8, 0, 0, ""};

    clrmous(MouseX, MouseY);
    delay(100);
    open_screen();
    mouseinit();

    while (mstate == 2)
    {
        newmouse(&MouseX, &MouseY, &press);

        input_mind(120 + 128 + 4, 100 + 128 + 4, 7, &mindname);

        if (mouse_press(120 + 80 + 80 + 80, 100 + 192, 120 + 80 + 80 + 80 + 80, 100 + 192 + 32) == 2) //取消键且未点击
        {
            pre_state = state;
            state = 1;

            if (pre_state != 1) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(120 + 80 + 80 + 80, 100 + 192, 120 + 80 + 80 + 80 + 80, 100 + 192 + 32);
            }
        }
        else if (mouse_press(120 + 80 + 80 + 80, 100 + 192, 120 + 80 + 80 + 80 + 80, 100 + 192 + 32) == 1) //取消键且点击
        {
            mstate = 0;
        }
        else if (mouse_press(120 + 128, 100 + 128, 120 + 128 + 144, 100 + 128 + 32) == 2) //输入框且未点击
        {
            pre_state = state;
            state = 2;

            if (pre_state != 2) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 2; //光标
            }
        }
        else if (mouse_press(120 + 80, 100 + 192, 120 + 80 + 80, 100 + 192 + 32) == 2) //打开键且未点击
        {
            pre_state = state;
            state = 3;

            if (pre_state != 3) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(120 + 80, 100 + 192, 120 + 80 + 80, 100 + 192 + 32);
            }
        }
        else if (mouse_press(120 + 80, 100 + 192, 120 + 80 + 80, 100 + 192 + 32) == 1) //打开键且点击
        {
            //清除提示信息
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            bar(120 + 128, 100 + 128 + 32 + 2, 120 + 128 + 16 * 8, 100 + 128 + 32 + 2 + 16);

            //确认是否输入完全
            if (mindname.str[0] == '\0')
            {
                puthz(120 + 128, 100 + 128 + 32 + 2, "未输入思维导图名", 16, 16, RED);
            }

            //判断思维导图是否存在
            else if (!daotujud(account_name, mindname.str))
            {
                puthz(120 + 128, 100 + 128 + 32 + 2, "该思维导图不存在", 16, 16, RED);
            }
            else
            {
				(*daotu_info).type = findmind(account_name, mindname.str).type;
				strcpy((*daotu_info).mindname, findmind(account_name, mindname.str).mindname);
				mstate = 1;
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
Function：绘制打开界面
Calls: 无
Called By: open
Parameter: 无
Return: 无
Author: 贾田旺
Others: 无
**************************************************/
void open_screen()
{
    //背景
    cleardevice();
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(0, 0, 640, 480);

    //画框
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(120, 100, 120 + 400, 100 + 280);
    setcolor(WHITE);
    setlinestyle(3, 0, 1); //画破折号线
    rectangle(120, 100, 120 + 400, 100 + 280);
    setlinestyle(1, 0, 3); //画虚线
    rectangle(120 + 2, 100 + 2, 120 + 400 - 2, 100 + 280 - 2);

    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(120 + 100, 100 + 28 + 40, 120 + 100 + 24 * 8 + 8, 100 + 28 + 40 + 24 + 8);
    setlinestyle(0, 0, 1); //画破折号线
    rectangle(120 + 100, 100 + 28 + 40, 120 + 100 + 24 * 8 + 8, 100 + 28 + 40 + 24 + 8);
    puthz(120 + 104, 100 + 32 + 40, "请输入思维导图名", 24, 24, WHITE);

    //输入框
    setfillstyle(SOLID_FILL, WHITE);
    bar(120 + 128, 100 + 128, 120 + 128 + 144, 100 + 128 + 32);

    //打开键
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(120 + 80, 100 + 192, 120 + 80 + 80, 100 + 192 + 32);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(120 + 80, 100 + 192, 120 + 80 + 80, 100 + 192 + 32);
    puthz(120 + 80 + 8, 100 + 192 + 4, "打开", 24, 40, WHITE);

    //取消键
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(120 + 80 + 80 + 80, 100 + 192, 120 + 80 + 80 + 80 + 80, 100 + 192 + 32);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(120 + 80 + 80 + 80, 100 + 192, 120 + 80 + 80 + 80 + 80, 100 + 192 + 32);
    puthz(120 + 80 + 80 + 80 + 8, 100 + 192 + 4, "取消", 24, 40, WHITE);
}