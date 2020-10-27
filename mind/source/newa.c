/**************************************************
Description:完成新建界面及其功能
Function list:   new 新建界面功能
                 pagenew 绘制新建界面
Attention:
Author:倪启源
**************************************************/

#include <common.h>
#include <newa.h>
/**************************************************
Name: new
Function: 新建界面相关信息与跳转功能
Calls:
Called by:main
Parameter: account_name 用户名
           daotu 用于存放指定的思维导图
Return: mstate 新建状态
Others：
**************************************************/
int new (char *account_name, MIND *daotu)
{
	int mstate = 2;				  //表示新建导图状态 2表示仍在页面中 0未新建返回 1表示新建返回
	MIND new_mind = {0, ""};	  //新建思维导图信息暂时存放处
	int state = 0, pre_state = 0; //表示鼠标状态的相关值
								  //0 无操作状态 1 回到空白编辑页按钮
								  //             2 单向导图按钮
								  //             3 树状图按钮
								  //			 4 鱼骨图按钮
								  //  			 5 时间轴按钮
								  // 6 确定框  7 退出框
	ENTER newmindname = {90, 400, 350, 440, 8, 0, 0, ""};
	clrmous(MouseX, MouseY);
	delay(100);
	//mouseinit();
	new_screen();
	mouseinit();

	while (mstate == 2)
	{
		newmouse(&MouseX, &MouseY, &press);

		if (newmindname.flag != 1)
		{
			while (bioskey(1))
			{
				getch();
			}
		}

		input_mind(100, 408, 5, &newmindname);
		//回到编辑页
		if (mouse_press(540, 448, 610, 468) == 2) //在按钮上未点击
		{
			pre_state = state;
			state = 1;
			if (pre_state != 1) //防止被重复标亮（只有之前是其它状态才标亮）
			{
				clrmous(MouseX, MouseY);
				delay(5); //画图前先清除鼠标，防止干扰

				MouseS = 1;
				puthz(540, 448, "返回编辑", 16, 18, RED);
				setlinestyle(SOLID_FILL, 0, 1);
				setcolor(RED);
				line(540, 468, 610, 468);
			}
		}
		else if (mouse_press(540, 448, 610, 468) == 1) //在返回按钮上且点击
		{
			mstate = 0;
		}
		//选择某一个导图模板
		else if (mouse_press(50, 70, 200, 200) == 2) //在单向导图未点击
		{
			pre_state = state;
			state = 2;
			if (pre_state != 2) //防止被重复标亮（只有之前是其它状态才标亮）
			{
				clrmous(MouseX, MouseY);
				delay(5); //画图前先清除鼠标，防止干扰

				MouseS = 1;
			}
		}
		else if (mouse_press(50, 70, 200, 200) == 1) //在单向导图且点击
		{
			puthz(60, 176, "单向思维导图", 16, 18, WHITE); //单向导图
			puthz(230, 176, "树状图", 16, 18, BLACK);	   //树状图
			puthz(400, 176, "鱼骨图", 16, 18, BLACK);	   //鱼骨图
			puthz(60, 326, "时间轴", 16, 18, BLACK);	   //时间轴
			new_mind.type = 1;
		}
		else if (mouse_press(220, 70, 370, 200) == 2) //在树状图未点击
		{
			pre_state = state;
			state = 3;
			if (pre_state != 3) //防止被重复标亮（只有之前是其它状态才标亮）
			{
				clrmous(MouseX, MouseY);
				delay(5); //画图前先清除鼠标，防止干扰

				MouseS = 1;
			}
		}
		else if (mouse_press(220, 70, 370, 200) == 1) //在树状图且点击
		{
			puthz(60, 176, "单向思维导图", 16, 18, BLACK); //单向导图
			puthz(230, 176, "树状图", 16, 18, WHITE);	   //树状图
			puthz(400, 176, "鱼骨图", 16, 18, BLACK);	   //鱼骨图
			puthz(60, 326, "时间轴", 16, 18, BLACK);	   //时间轴
			new_mind.type = 2;
		}
		else if (mouse_press(390, 70, 540, 200) == 2) //在鱼骨图未点击
		{
			pre_state = state;
			state = 4;
			if (pre_state != 4) //防止被重复标亮（只有之前是其它状态才标亮）
			{
				clrmous(MouseX, MouseY);
				delay(5); //画图前先清除鼠标，防止干扰

				MouseS = 1;
			}
		}
		else if (mouse_press(390, 70, 540, 200) == 1) //在鱼骨图且点击
		{
			puthz(60, 176, "单向思维导图", 16, 18, BLACK); //单向导图
			puthz(230, 176, "树状图", 16, 18, BLACK);	   //树状图
			puthz(400, 176, "鱼骨图", 16, 18, WHITE);	   //鱼骨图
			puthz(60, 326, "时间轴", 16, 18, BLACK);	   //时间轴
			new_mind.type = 3;
		}
		else if (mouse_press(50, 220, 200, 350) == 2) //在时间轴未点击
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
		else if (mouse_press(50, 220, 200, 350) == 1) //在时间轴且点击
		{
			puthz(60, 176, "单向思维导图", 16, 18, BLACK); //单向导图
			puthz(230, 176, "树状图", 16, 18, BLACK);	   //树状图
			puthz(400, 176, "鱼骨图", 16, 18, BLACK);	   //鱼骨图
			puthz(60, 326, "时间轴", 16, 18, WHITE);	   //时间轴
			new_mind.type = 4;
		}
		else if (mouse_press(360, 400, 420, 440) == 2) //在确定框未点击
		{
			pre_state = state;
			state = 6;
			if (pre_state != 6) //防止被重复标亮（只有之前是其它状态才标亮）
			{
				clrmous(MouseX, MouseY);
				delay(5); //画图前先清除鼠标，防止干扰

				MouseS = 1;
			}
		}
		else if (mouse_press(360, 400, 420, 440) == 1) //在确定框且点击
		{
			setfillstyle(SOLID_FILL, LIGHTCYAN);
			bar(95, 444, 350, 470);
			//确认是否符合要求
			if (newmindname.str[0] == '\0') //有无？
			{
				puthz(100, 448, "未输入新建文件名", 16, 18, LIGHTGRAY);
			}
			else if (strlen(newmindname.str) >= 9) //溢出？
			{
				puthz(100, 448, "最多八字符", 16, 18, LIGHTGRAY);
			}
			else if (new_mind.type == 0) //种类选了？
			{
				puthz(100, 448, "选个种类吧", 16, 18, LIGHTGRAY);
			}
			else if (daotujud(account_name, newmindname.str)) //重复？
			{
				puthz(100, 448, "文件名已存在", 16, 18, LIGHTGRAY);
			}
			else
			{
				newmind(account_name, newmindname.str, &new_mind);
				*daotu = new_mind;
				mstate = 1;
			}
		}
		else if (mouse_press(430, 448, 464, 468) == 2)
		{
			pre_state = state;
			state = 7;
			if (pre_state != 7) //防止被重复标亮（只有之前是其它状态才标亮）
			{
				clrmous(MouseX, MouseY);
				delay(5); //画图前先清除鼠标，防止干扰

				MouseS = 1;
				puthz(430, 448, "退出", 16, 18, RED);
				setlinestyle(SOLID_FILL, 0, 1);
				setcolor(RED);
				line(430, 448, 464, 468);
			}
		}
		else if (mouse_press(430, 448, 464, 468) == 1) //退出框
		{
			closegraph(); //关闭画图
			delay(100);	  //可解决重启动时鼠标状态不稳定，但有学长反应容易崩溃，慎用
			exit(0);	  //退出程序
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
				puthz(540, 448, "返回编辑", 16, 18, BLUE);
				setlinestyle(SOLID_FILL, 0, 1);
				setcolor(BLUE);
				line(540, 468, 610, 468);
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				MouseS = 0;
				break;
			case 7:
				MouseS = 0;
				puthz(430, 448, "退出", 16, 18, BLUE);
				setlinestyle(SOLID_FILL, 0, 1);
				setcolor(BLUE);
				line(430, 448, 464, 468);
				break;
			}
		}
	}
	return mstate;
}

/**************************************************
Name: new_screen
Function：画新建界面
Calls: 
Called By: new
Parameter：
Return: 
Others: 
**************************************************/
void new_screen()
{
	int i, j; //画框计数用
	int head[8] = {465, 75, 440, 95, 490, 95, 465, 75};
	int tail[8] = {465, 145, 440, 165, 490, 165, 465, 145};

	//背景
	cleardevice();
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	bar(0, 0, 640, 480);

	//返回编辑，回到空白编辑页按钮
	settextjustify(LEFT_TEXT, TOP_TEXT);
	puthz(540, 448, "返回编辑", 16, 18, BLUE);
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(BLUE);
	line(540, 468, 610, 468);

	//选择一个开始吧
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setcolor(LIGHTGRAY);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	bar(0, 0, 640, 60);
	puthz(30, 30, "选择一个开始吧", 24, 30, BLACK);

	//思维导图模板种类
	//置图框
	setfillstyle(SOLID_FILL, WHITE);
	bar(50, 70, 200, 170);	//单向导图
	bar(220, 70, 370, 170); //树状图
	bar(390, 70, 540, 170); //鱼骨图
	bar(50, 220, 200, 320); //时间轴
	//名称框
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(50, 170, 200, 200);	 //单向导图
	bar(220, 170, 370, 200); //树状图
	bar(390, 170, 540, 200); //鱼骨图
	bar(50, 320, 200, 350);	 //时间轴
	//名称
	settextjustify(LEFT_TEXT, TOP_TEXT);
	puthz(60, 176, "单向思维导图", 16, 18, BLACK); //单向导图
	puthz(230, 176, "树状图", 16, 18, BLACK);	   //树状图
	puthz(400, 176, "鱼骨图", 16, 18, BLACK);	   //鱼骨图
	puthz(60, 326, "时间轴", 16, 18, BLACK);	   //时间轴

	//图样
	//框部分
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	setcolor(LIGHTGREEN);
	setlinestyle(0, 0, 1);
	bar(60, 110, 110, 130); //单向导图
	for (i = 0; i < 3; i++)
	{
		bar(140, 80 + i * 30, 190, 100 + i * 30);
	}
	bar(270, 80, 320, 100); //树状图
	for (i = 0; i < 3; i++)
	{
		bar(235 + i * 45, 120, 265 + i * 45, 140);
	}
	for (i = 0; i < 3; i++) //时间轴
	{
		bar(50 + 10 + i * 50, 250, 50 + 10 + 30 + i * 50, 290);
		for (j = 0; j < 3; j++)
		{
			setcolor(BLACK);
			line(50 + 10 + i * 50, 260 + j * 10, 50 + 10 + 30 + i * 50, 260 + j * 10);
		}
	}
	//鱼骨图
	fillpoly(4, head);
	fillpoly(4, tail);

	//连线部分
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, 0, 2);
	for (i = 0; i < 3; i++) //单向导图
	{
		line(110, 120, 140, 90 + i * 30);
	}
	for (i = 0; i < 3; i++) //树状图
	{
		line(295, 100, 250 + i * 45, 120);
	}
	for (i = 0; i < 2; i++) //时间轴
	{
		line(50 + 10 + 30 + i * 50, 270, 50 + 10 + 30 + 20 + i * 50, 270);
	}
	//鱼骨图
	line(465, 95, 465, 145);
	line(465, 105, 450, 120);
	line(450, 120, 425, 120);
	line(465, 120, 480, 135);
	line(480, 135, 505, 135);

	//退出按钮
	settextjustify(LEFT_TEXT, TOP_TEXT);
	puthz(430, 448, "退出", 16, 18, BLUE);
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(BLUE);
	line(430, 468, 464, 468);

	//输入导图文件名字框
	setlinestyle(SOLID_LINE, 0, 5);
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, BLUE);
	bar(10, 400, 90, 440);
	rectangle(10, 400, 90, 440);
	puthz(20, 408, "导图名", 16, 20, YELLOW);
	setfillstyle(SOLID_FILL, WHITE);
	bar(90, 400, 350, 440); //输入框
	setfillstyle(SOLID_FILL, RED);
	bar(360, 400, 420, 440);
	puthz(370, 408, "确定", 16, 30, YELLOW);
}
