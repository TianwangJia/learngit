/**********************************************
Description: 编辑时间轴功能及界面
Function list :  edidate 编辑页面功能
				 edidate_screen 绘制编辑页面
Attention:  
Author:  倪启源
History:  
***********************************************/

#include "common.h"
#include "Edidate.h"

/**************************************************
Name: edidate
Function：编辑时间轴界面功能
Calls: edidate_screen
       finddate
	   drawdate
	   deletedate
	   rank_time
	   judge_time
Called By: operate
Parameter: edidate 待编辑时间轴的信息
Return: 无
Author: 倪启源
Others: 无
**************************************************/
void edidate(DATEINFO *edidate)
{
    int e_state = 1;              //表示是否在edit页面内 1为仍在 0为跳转    控制页面跳转
    int state = 0, pre_state = 0; //表示鼠标状态的相关值（未点击）
                                  // 0 无操作状态
                                  // 1 完成键 2 新增键 3 删除键 4 保存键
    int rankdate;                 //存储rankdate下标
    ENTER newdateyear = {496 + 25 + 20, 24 + 8 + 24 + 24, 600 + 20, 24 + 8 + 24 + 24 + 20, 4, 0, 0, ""};
    ENTER newdatemonth = {496 + 25 + 20, 24 + 8 + 24 + 24 + 40, 600 + 20, 24 + 8 + 24 + 24 + 60, 2, 0, 0, ""};
    ENTER newdateday = {496 + 25 + 20, 24 + 8 + 24 + 24 + 80, 600 + 20, 24 + 8 + 24 + 24 + 100, 2, 0, 0, ""};
    ENTER newdatehappen = {496 + 8 + 20, 24 + 8 + 24 + 24 + 160 + 100, 496 + 8 + 90 + 20, 24 + 8 + 24 + 24 + 160 + 20 + 100, 7, 0, 0, ""};
    DATEHAPPEN tempsave;
    int find_flag = 0; //表示是否找到框
    clrmous(MouseX, MouseY);
    delay(100);
    edidate_screen();
    drawdate(edidate);
    mouseinit();

    while (e_state == 1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if (newdateyear.flag != 1 && newdatemonth.flag != 1 && newdateday.flag != 1 && newdatehappen.flag != 1)
        {
            while (bioskey(1))
            {
                getch();
            }
        } //FIXME

        input_info(525 + 20, 24 + 8 + 24 + 24 + 2, 5, 1, &newdateyear);
        input_info(525 + 20, 24 + 8 + 24 + 24 + 40 + 2, 5, 1, &newdatemonth);
        input_info(525 + 20, 24 + 8 + 24 + 24 + 80 + 2, 5, 1, &newdateday);
        input_info(510 + 20, 24 + 8 + 24 + 24 + 160 + 2 + 100, 5, 1, &newdatehappen);
        if (mouse_press(640 - 42, 0, 640, 24) == 2) //完成且未点击 未制作点击
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
                rectangle(640 - 42, 0, 640, 24);
            }
        }
        else if (mouse_press(640 - 42, 0, 640, 24) == 1) //完成且点击
        {
            e_state = 0;
            delay(100);
        }
        else if (mouse_press(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24) == 2) //新增且未点击
        {
            pre_state = state;
            state = 2;

            if (pre_state != 2) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(RED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24);
            }
        }
        else if (mouse_press(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24) == 1) //新增且点击
        {
            setfillstyle(SOLID_FILL, LIGHTCYAN);
            tempsave.year = atoi(newdateyear.str);
            tempsave.month = atoi(newdatemonth.str);
            tempsave.day = atoi(newdateday.str);
            strcpy(tempsave.content, newdatehappen.str);
            if (judge_time(tempsave) && tempsave.content[0] != '\0')
            {
                rank_time(edidate, tempsave);
                strcpy(newdateyear.str, "");
                strcpy(newdatemonth.str, "");
                strcpy(newdateday.str, "");
                strcpy(newdatehappen.str, "");
                newdateyear.cursor = 0;
                newdatemonth.cursor = 0;
                newdateday.cursor = 0;
                newdatehappen.cursor = 0;
                edidate_screen();
                drawdate(edidate);
            }
            else if (judge_time(tempsave) == 0 && (newdateyear.cursor != 0 || newdatemonth.cursor != 0 || newdateday.cursor != 0)) //输入了日期但不合法
            {
                bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 100 + 10, 496 + 25 + 20 + 80, 24 + 8 + 24 + 24 + 100 + 10 + 20);
                bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10, 496 + 25 + 20 + 80, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10 + 20);
                puthz(496 + 25 + 20, 24 + 8 + 24 + 24 + 100 + 10, "日期非法", 16, 16, DARKGRAY);
            }
            else if ((newdateyear.cursor != 0 || newdatemonth.cursor != 0 || newdateday.cursor != 0) && newdatehappen.cursor == 0) //输入了日期合法文字没输入
            {
                bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 100 + 10, 496 + 25 + 20 + 80, 24 + 8 + 24 + 24 + 100 + 10 + 20);
                bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10, 496 + 25 + 20 + 80, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10 + 20);
                puthz(496 + 25 + 20, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10, "未输入文字", 16, 16, DARKGRAY);
            }
            else if (!(newdateyear.cursor != 0 || newdatemonth.cursor != 0 || newdateday.cursor != 0) && newdatehappen.cursor != 0) //没输入日期输了文字
            {
                bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 100 + 10, 496 + 25 + 20 + 80, 24 + 8 + 24 + 24 + 100 + 10 + 20);
                bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10, 496 + 25 + 20 + 80, 24 + 8 + 24 + 24 + 160 + 20 + 100 + 10 + 20);
                puthz(496 + 25 + 20, 24 + 8 + 24 + 24 + 100 + 10, "未输入日期", 16, 16, DARKGRAY);
            }
        }
        else if (mouse_press(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24) == 2) //删除且未点击
        {
            pre_state = state;
            state = 3;

            if (pre_state != 3) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(RED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24);
            }
        }
        else if (mouse_press(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24) == 1) //删除且点击
        {
            if (find_flag == 1)
            {
                deletedate(edidate, rankdate);
                edidate_screen();
                drawdate(edidate);
                find_flag = 0;
            }
        }
        else if (mouse_press(0, 24, 496, 480) == 1) //选要编辑的框
        {
            edidate_screen();
            drawdate(edidate);
            find_flag = finddate(edidate, &rankdate);
        }
        else //无操作状态
        {
            pre_state = state;
            state = 0;
        }

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
                rectangle(640 - 42, 0, 640, 24);
                break;
            case 2:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24);
                break;
            case 3:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24);
                break;
            case 4:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25, 24 + 8 + 24 + 8, 496 + 25 + 42, 24 + 8 + 24 + 8 + 24);
            }
        }
    }
}

/**************************************************
Name: edidate_screen
Function：绘制编辑界面
Calls: 无
Called By: edidate
Parameter: 无
Return: 无
Author: 倪启源
Others: 无
**************************************************/
void edidate_screen(void)
{
    //背景
    cleardevice();
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, 496, 480);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(496, 0, 640, 480);
    bar(0, 0, 496, 24);
    setcolor(WHITE);
    setlinestyle(0, 0, 3);
    line(496, 0, 496, 480);
    line(496, 240, 640, 240);

    //画框
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24);
    puthz(496 + 25 + 4, 24 + 8 + 4, "新增", 16, 18, WHITE);
    bar(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24);
    puthz(496 + 25 + 42 + 10 + 4, 24 + 8 + 4, "删除", 16, 18, WHITE);
    bar(640 - 42, 0, 640, 24);
    puthz(640 - 42 + 4, 0 + 4, "完成", 16, 18, LIGHTRED);

    setlinestyle(0, 0, 1);
    setcolor(WHITE);
    rectangle(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24);
    rectangle(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24);
    rectangle(640 - 42, 0, 640, 24);

    //画输入框
    setfillstyle(SOLID_FILL, WHITE);
    bar(496 + 25 + 20, 24 + 8 + 24 + 24, 600 + 20, 24 + 8 + 24 + 24 + 20);                                 //年
    bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 40, 600 + 20, 24 + 8 + 24 + 24 + 60);                            //月
    bar(496 + 25 + 20, 24 + 8 + 24 + 24 + 80, 600 + 20, 24 + 8 + 24 + 24 + 100);                           //日
    bar(496 + 8 + 20, 24 + 8 + 24 + 24 + 160 + 100, 496 + 8 + 90 + 20, 24 + 8 + 24 + 24 + 160 + 20 + 100); //输入文字框
    //画文字框
    setfillstyle(SOLID_FILL, BLUE);
    bar(496 + 5 + 20, 24 + 8 + 24 + 24, 496 + 25 + 20, 24 + 8 + 24 + 24 + 20); //年
    setfillstyle(SOLID_FILL, GREEN);
    bar(496 + 5 + 20, 24 + 8 + 24 + 24 + 40, 496 + 25 + 20, 24 + 8 + 24 + 24 + 60); //月
    setfillstyle(SOLID_FILL, RED);
    bar(496 + 5 + 20, 24 + 8 + 24 + 24 + 80, 496 + 25 + 20, 24 + 8 + 24 + 24 + 100); //日
    //描框
    //setlinestyle(SOLID_LINE, 0, 1);
    //setcolor(BLACK);
    //rectangle(496 + 5, 24 + 8 + 24 + 24, 600, 24 + 8 + 24 + 24 + 20); //年
    //rectangle(496 + 5, 24 + 8 + 24 + 24 + 40, 600, 24 + 8 + 24 + 24 + 60); //月
    //rectangle(496 + 5, 24 + 8 + 24 + 24 + 80, 600, 24 + 8 + 24 + 24 + 100); //日
    //rectangle(496 + 8, 24 + 8 + 24 + 24 + 160, 496 + 8 + 90, 24 + 8 + 24 + 24 + 160 + 20); //输入文字框
    //文字
    puthz(496 + 5 + 2 + 20, 24 + 8 + 24 + 24 + 2, "年", 16, 0, YELLOW);
    puthz(496 + 5 + 2 + 20, 24 + 8 + 24 + 24 + 40 + 2, "月", 16, 0, YELLOW);
    puthz(496 + 5 + 2 + 20, 24 + 8 + 24 + 24 + 80 + 2, "日", 16, 0, YELLOW);
    puthz(496 + 8 + 20, 24 + 8 + 24 + 24 + 140 + 100, "内容", 16, 16, BLACK);
}



