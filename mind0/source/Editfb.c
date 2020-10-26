/**********************************************
Description:  具体编辑思维导图功能及界面
Function list :  edit 编辑页面功能
                 edit_screen 绘制编辑页面
Attention:  
Author:  贾田旺
History:  
***********************************************/

#include "common.h"
#include "Editfb.h"
#include <graphics.h>

/**************************************************
Name: editfb
Function：编辑界面功能
Calls: edit_screen
Called By: operate
Parameter: 未定
Return: 未定
Author: 贾田旺
Others: 未完成
**************************************************/
void editfb(FISHINFO *editp)
{
	int e_state = 1;              //表示是否在edit页面内 1为仍在 0为跳转    控制页面跳转
    int state = 0, pre_state = 0; //表示鼠标状态的相关值（未点击）
                                  // 0 无操作状态
                                  // 1 完成键 2 新增键 3 删除键 4 保存键
    int rankbone; //存储rankbone下标
    MINPUT minput = {7, 0, ""};
	int find_flag = 0; //表示是否找到框
    clrmous(MouseX, MouseY);
    delay(100);
    edit_screen();
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	bar(496 + 25 - 1, 248 - 1, 496 + 25 + 42 + 10 + 42 + 1, 272 + 1); //盖住两个按钮
	drawbone(editp);
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
            if (find_flag == 1 && editp -> bonenum < BONEMAX)
            {
                addbone(editp, rankbone);
                setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
                drawbone(editp);
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
            if (find_flag == 1 && editp -> bonenum > 1)
            {
                deletebone(editp, rankbone);
                setfillstyle(SOLID_FILL, WHITE);
				bar(0, 24, 496, 480);
                drawbone(editp);
                find_flag = 0;
            }
        }
        else if (mouse_press(0, 24, 496, 480) == 1) //选要编辑的框 
        {
            find_flag = findbone(editp, &rankbone);
            if (find_flag == 1)
            {
                clrmous(MouseX, MouseY);
                delay(25); //画图前先清除鼠标，防止干扰

                setlinestyle(SOLID_LINE, 0, 3);
                setcolor(RED);
                setfillstyle(SOLID_FILL, WHITE);
                bar(248 - 114 + 164 * (rankbone % 2), 80 + 24 + rankbone * 40, 248 - 50 + 164 * (rankbone % 2), 80 + 40 + rankbone * 40);
                line(248, 80 + 20 + rankbone * 40, 248 - 50 + 100 * (rankbone % 2), 80 + 40 + rankbone * 40);
			    rectangle(248 - 114 + 164 * (rankbone % 2), 80 + 24 + rankbone * 40, 248 - 50 + 164 * (rankbone % 2), 80 + 40 + rankbone * 40);
                edit_yugu(248 - 114 + 164 * (rankbone % 2), 80 + 24 + rankbone * 40, &minput, editp->bone[rankbone].content,BLACK);
                strcpy(minput.str, "");
                minput.cursor = 0;
            }
            setfillstyle(SOLID_FILL, WHITE);
            bar(0, 24, 496, 480);
            drawbone(editp);
            setcolor(RED);
            setlinestyle(0, 0, 3);
			if(find_flag == 1)
            {
				line(248, 80 + 20 + rankbone * 40, 248 - 50 + 100 * (rankbone % 2), 80 + 40 + rankbone * 40);
			    rectangle(248 - 114 + 164 * (rankbone % 2), 80 + 24 + rankbone * 40, 248 - 50 + 164 * (rankbone % 2), 80 + 40 + rankbone * 40);
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
            }
        }
    }
}