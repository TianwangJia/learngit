/**********************************************
Description:  具体编辑思维导图功能及界面
Function list :  edit 编辑页面功能
                edit_screen 绘制编辑页面
Attention:  
Author:  贾田旺
History:  
***********************************************/

#include "common.h"
#include "Edit.h"
#include <graphics.h>

/**************************************************
Name: edit
Function：编辑界面功能
Calls: edit_screen
Called By: operate
Parameter: 未定
Return: 未定
Author: 贾田旺
Others: 未完成
**************************************************/
void edit(MINDBOX (*editp)[VERT])
{
    int e_state = 1;              //表示是否在edit页面内 1为仍在 0为跳转    控制页面跳转
    int state = 0, pre_state = 0; //表示鼠标状态的相关值（未点击）
                                  // 0 无操作状态
                                  // 1 完成键 2 新增键 3 删除键 4 保存键
    int heng, zong;
    MINPUT minput = {7, 0, ""};
    int find_flag = 0; //表示是否找到框
	int colortemp = WHITE; //暂存当前选中的颜色 没有选择时，置为WHITE
    clrmous(MouseX, MouseY);
    delay(100);
    edit_screen();
	color_screen();
    drawmind(editp);
    mouseinit();

    while (e_state == 1)
    {
        newmouse(&MouseX, &MouseY, &press);

        while (bioskey(1))
        {
            getch();
        }

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
            if (heng < HORI && find_flag == 1)
            {
                addbox(editp, heng, zong);
                setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
                drawmind(editp);
                find_flag = 0;
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
            if (find_flag && (heng + zong) != 0)
            {
                deletebox(editp, heng, zong);
                setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
                drawmind(editp);
                find_flag = 0;
            }
        }
        else if (mouse_press(0, 24, 496, 480) == 1) //选要编辑的框
        {
            find_flag = findbox(editp, &heng, &zong);
            if (find_flag == 1)
            {
                clrmous(MouseX, MouseY);
                delay(25); //画图前先清除鼠标，防止干扰

                setlinestyle(SOLID_LINE, 0, 3);
                setcolor(RED);
                setfillstyle(SOLID_FILL, WHITE);
                bar(8 + heng * 80, 28 + zong * 24, 8 + heng * 80 + 64, 28 + zong * 24 + 16);
                rectangle(8 + heng * 80, 28 + zong * 24, 8 + heng * 80 + 64, 28 + zong * 24 + 16);
                edit_mind(8 + heng * 80, 28 + zong * 24, &minput, &editp[heng][zong],BLACK);
                strcpy(minput.str, "");
                minput.cursor = 0;
            }
            setfillstyle(SOLID_FILL, WHITE);
            bar(0, 24, 496, 480);
            drawmind(editp);
            setcolor(RED);
            setlinestyle(0, 0, 3);
			if(find_flag == 1)
			{
				rectangle(8 + heng * 80, 28 + zong * 24, 8 + heng * 80 + 64, 28 + zong * 24 + 16);
			}
        }
		else if(mouse_press(504 + 17, 280, 604 + 17, 300) == 2) //在颜色框未点击
		{
			pre_state = state;
			state = 5;
			if (pre_state != 5) //防止被重复标亮（只有之前是其它状态才标亮）
			{
				clrmous(MouseX, MouseY);
				delay(5); //画图前先清除鼠标，防止干扰

				MouseS = 1;
			}
		}
		else if(mouse_press(504 + 17, 280, 604 + 17, 300) == 1) //在颜色框且点击
		{
			setfillstyle(SOLID_FILL, LIGHTCYAN);
			bar(504 + 17 - 2, 280 - 2, 604 + 17 + 2, 300 + 2);
			setcolor(RED);
			setlinestyle(0, 0, 1);
			if(mouse_press(504 + 17, 280, 524 + 17, 300) == 1)
			{
				color_screen();
				colortemp = BLACK;
				rectangle(504 + 17, 280, 524 + 17, 300);
			}
			else if(mouse_press(524 + 17, 280, 544 + 17, 300) == 1)
			{
				color_screen();
				colortemp = CYAN;
				rectangle(524 + 17, 280, 544 + 17, 300);
			}
			else if(mouse_press(544 + 17, 280, 564 + 17, 300) == 1)
			{
				color_screen();
				colortemp = GREEN;
				rectangle(544 + 17, 280, 564 + 17, 300);
			}
			else if(mouse_press(564 + 17, 280, 584 + 17, 300) == 1)
			{
				color_screen();
				colortemp = BLUE;
				rectangle(564 + 17, 280, 584 + 17, 300);
			}
			else if(mouse_press(584 + 17, 280, 604 + 17, 300) == 1)
			{
				color_screen();
				colortemp = LIGHTGRAY;
				rectangle(584 + 17, 280, 604 + 17, 300);
			}
		}
		else if(mouse_press(496 + 25, 248, 496 + 25 + 42, 272) == 2) //字色未点击
		{
			pre_state = state;
            state = 6;

            if (pre_state != 6) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(RED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25, 248, 496 + 25 + 42, 272);
            }
		}
		else if(mouse_press(496 + 25, 248, 496 + 25 + 42, 272) == 1) //字色且点击
		{
			if(find_flag == 1 && colortemp != WHITE)
			{
				editp[heng][zong].textcolor = colortemp;
				setfillstyle(SOLID_FILL, LIGHTCYAN);
			    bar(504 + 17 - 2, 280 - 2, 604 + 17 + 2, 300 + 2);
				color_screen();
				colortemp = WHITE;
				
				setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
				drawmind(editp);
                find_flag = 0;
			}
		}
		else if(mouse_press(496 + 25 + 42 + 10, 248, 496 + 25 + 42 + 10 + 42, 272) == 2) //框色未点击
		{
			pre_state = state;
            state = 7;

            if (pre_state != 7) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(RED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25 + 42 + 10, 248, 496 + 25 + 42 + 10 + 42, 272);
            }
		}
		else if(mouse_press(496 + 25 + 42 + 10, 248, 496 + 25 + 42 + 10 + 42, 272) == 1) //框色且点击
		{
			if(find_flag == 1 && colortemp != WHITE)
			{
				editp[heng][zong].boxcolor = colortemp;
				setfillstyle(SOLID_FILL, LIGHTCYAN);
			    bar(504 + 17 - 2, 280 - 2, 604 + 17 + 2, 300 + 2);
				color_screen();
				colortemp = WHITE;
				
				setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
				drawmind(editp);
                find_flag = 0;
			}
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
				break;
			case 5:
			    MouseS = 0;
				break;
			case 6:
			    MouseS = 0;
				setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25, 248, 496 + 25 + 42, 272);
				break;
			case 7:
			    MouseS = 0;
				setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 25 + 42 + 10, 248, 496 + 25 + 42 + 10 + 42, 272);
				break;
            }
        }
    }
}

/**************************************************
Name: edit_screen
Function：绘制编辑界面
Calls: 无
Called By: edit
Parameter: 未定
Return: 无
Author: 贾田旺
Others: 
**************************************************/
void edit_screen()
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
	bar(496 + 25, 248, 496 + 25 + 42, 272);
	puthz(496 + 25 + 4, 248 + 4, "字色", 16, 18, WHITE);
	bar(496 + 25 + 42 + 10, 248, 496 + 25 + 42 + 10 + 42, 272);
	puthz(496 + 25 + 42 + 10 + 4, 248 + 4, "框色", 16, 18, WHITE);
    bar(640 - 42, 0, 640, 24);
    puthz(640 - 42 + 4, 0 + 4, "完成", 16, 18, LIGHTRED);

    setlinestyle(0, 0, 1);
    setcolor(WHITE);
    rectangle(496 + 25, 24 + 8, 496 + 25 + 42, 24 + 8 + 24);
    rectangle(496 + 25 + 42 + 10, 24 + 8, 496 + 25 + 42 + 10 + 42, 24 + 8 + 24);
	rectangle(496 + 25, 248, 496 + 25 + 42, 272);
	rectangle(496 + 25 + 42 + 10, 248, 496 + 25 + 42 + 10 + 42, 272);
    rectangle(640 - 42, 0, 640, 24);
}

/**************************************************
Name: color_screen
Function：绘制调色板界面
Calls: 无
Called By: 
Parameter: 未定
Return: 无
Author: 倪启源
Others: 
**************************************************/
void color_screen()
{
	//画调色板
	setcolor(BLACK);
	setlinestyle(0, 0, 1);
	rectangle(504 + 17 - 1, 280 - 1, 604 + 17 + 1, 300 + 1);
	setfillstyle(SOLID_FILL, BLACK);
	bar(504 + 17, 280, 524 + 17, 300);
	setfillstyle(SOLID_FILL, CYAN);
	bar(524 + 17, 280, 544 + 17, 300);
	setfillstyle(SOLID_FILL, GREEN);
	bar(544 + 17, 280, 564 + 17, 300);
	setfillstyle(SOLID_FILL, BLUE);
	bar(564 + 17, 280, 584 + 17, 300);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(584 + 17, 280, 604 + 17, 300);
}