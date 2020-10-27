
/**********************************************
Description:  完成编辑主页面及相关功能
Function list :  operate   操作思维导图功能
                 operate_screen  绘制操作页面
Attention:  
Author:  贾田旺
History:  
***********************************************/

#include "common.h"
#include "operate.h"

/**************************************************
Name: operate
Function：编辑思维导图功能
Calls:  drawmind 
        drawmind_tr
        drawbone
        drawdate
        new
        operate_screen
        opena
        delete_mind
Called By: main
Parameter: account_name 
Return: page 页面跳转
Author: 贾田旺
Others: 无
**************************************************/
int operate(char *account_name)
{
    MIND daotu_info = {0, ""}; //导图信息
	char temdt[30 + 1]; //当前思维导图文件位置索引
	FILE *fp; //存放当前打开的文件指针
	int open_ste; //存放打开状态
	MINDBOX oper_temp[HORI][VERT];
	MINDBOX oper_temptr[HORI][VERTREE];
	FISHINFO oper_fish;
	DATEINFO oper_date;
    int page = 5;
    int state = 0, pre_state = 0; //表示鼠标状态的相关值（未点击）
                                  // 0 无操作状态 1 退出程序按钮 2 返回欢迎界面按钮
                                  //方向键 3 上 4 下 5 左 6 右
                                  // 7 新建  8 打开  9 关闭  10 删除
                                  // 11 帮助 12 编辑
    clrmous(MouseX, MouseY);
    delay(100);
    operate_screen();
    mouseinit();

    while (page == 5)
    {
        newmouse(&MouseX, &MouseY, &press);

        if (mouse_press(616, 0, 640, 24) == 2) //退出框且未点击
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
                rectangle(616, 0, 640, 24);
                setlinestyle(0, 0, 3);
                line(624, 4, 632, 20);
                line(624, 20, 632, 4);
            }
        }
        else if (mouse_press(616, 0, 640, 24) == 1) //退出框且点击
        {
            page = 0;
        }
        else if (mouse_press(496, 0, 496 + 24, 24) == 2) //返回登录界面框且未点击
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
                rectangle(496, 0, 496 + 24, 24);
            }
        }
        else if (mouse_press(496, 0, 496 + 24, 24) == 1) //返回登录界面框且点击
        {
            page = 1;
        }
        else if (mouse_press(496 + 24 + 12, 40, 496 + 24 + 12 + 72, 40 + 32) == 2) //新建未点击
        {
            pre_state = state;
            state = 7;
            if (pre_state != 7) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 40, 496 + 24 + 12 + 72, 40 + 32);
            }
        }
        else if (mouse_press(496 + 24 + 12, 40, 496 + 24 + 12 + 72, 40 + 32) == 1) //新建点击
        {
			clrmous(MouseX, MouseY);
            delay(5);
            if((new(account_name, &daotu_info) == 1)||daotu_info.type != 0)
			{
				operate_screen();
                puthz(16, 4, "导图名：", 16, 16, BLACK);
                settextjustify(LEFT_TEXT, TOP_TEXT);
                settextstyle(SMALL_FONT, HORIZ_DIR, 7);
                setcolor(BLACK);
                outtextxy(96, 0, daotu_info.mindname);
                setfillstyle(SOLID_FILL, WHITE);
                bar(0, 24, 496, 480);
				
				if(fp != NULL)
				{
					fclose(fp);
				}
				sprintf(temdt, ".\\daotu\\%s\\%s.dat", account_name,daotu_info.mindname);//写在另一个函数里面
				if((fp = fopen(temdt,"rb+")) == NULL)//打开失败，异常退出
				{
					closegraph();
                    printf("\nFile mind opening error.(from new_in_edit)\n");
                    delay(3000);
                    exit(1);
				}
				
				switch(daotu_info.type)
				{
					case 1:
					fseek(fp, 0, 0);
		            fread(&(oper_temp[0][0]), sizeof(MINDBOX), HORI * VERT, fp);
					drawmind(oper_temp);
					break;
					case 2:
					fseek(fp, 0, 0);
		            fread(&(oper_temptr[0][0]), sizeof(MINDBOX), HORI * VERTREE, fp);
					drawmind_tr(oper_temptr);
					break;
					case 3:
					fseek(fp, 0, 0);
					fread(&(oper_fish), sizeof(FISHINFO), 1, fp);
					drawbone(&oper_fish);
					break;
					case 4:
					fseek(fp, 0, 0);
					fread(&(oper_date), sizeof(DATEINFO), 1, fp);
					drawdate(&oper_date);
					break;
				}
			}
			else
			{
				operate_screen();
			}
        }
        else if (mouse_press(496 + 24 + 12, 72 + 8, 496 + 24 + 12 + 72, 72 + 8 + 32) == 2) //打开且未点击
        {
            pre_state = state;
            state = 8;
            if (pre_state != 8) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 72 + 8, 496 + 24 + 12 + 72, 72 + 8 + 32);
            }
        }
        else if (mouse_press(496 + 24 + 12, 72 + 8, 496 + 24 + 12 + 72, 72 + 8 + 32) == 1) //打开且点击
        {
            //opena(account_name, &daotu_info);

            clrmous(MouseX, MouseY);
            delay(5);
			open_ste = opena(account_name, &daotu_info);
            if (daotu_info.type != 0)
            {
                operate_screen();
                puthz(16, 4, "导图名：", 16, 16, BLACK);	
                settextjustify(LEFT_TEXT, TOP_TEXT);
                settextstyle(SMALL_FONT, HORIZ_DIR, 7);
                setcolor(BLACK);
                outtextxy(96, 0, daotu_info.mindname);
                setfillstyle(SOLID_FILL, WHITE);
                bar(0, 24, 496, 480);
			}
            else
            {
                operate_screen();
            }

            if(open_ste == 1)
			{
				if(fp != NULL)
				{
					fclose(fp);
				}
				sprintf(temdt, ".\\daotu\\%s\\%s.dat", account_name, daotu_info.mindname);
			    if((fp = fopen(temdt,"rb+")) == NULL)//打开失败，异常退出
			    {
					closegraph();
                    printf("\nFile mind opening error.(from open_in_edit)\n");
                    delay(3000);
                    exit(1);
			    }
			}
			
			switch(daotu_info.type)
			{
				case 1:
				fseek(fp, 0, 0);
		        fread(&(oper_temp[0][0]), sizeof(MINDBOX), HORI * VERT, fp);
				drawmind(oper_temp);
				break;
				case 2:
				fseek(fp, 0, 0);
		        fread(&(oper_temptr[0][0]), sizeof(MINDBOX), HORI * VERTREE, fp);
				drawmind_tr(oper_temptr);
				break;
				case 3:
			    fseek(fp, 0, 0);
				fread(&(oper_fish), sizeof(FISHINFO), 1, fp);
				drawbone(&oper_fish);
				break;
				case 4:
				fseek(fp, 0, 0);
				fread(&(oper_date), sizeof(DATEINFO), 1, fp);
				drawdate(&oper_date);
				break;
			}
        }
        else if (mouse_press(496 + 24 + 12, 112 + 8, 496 + 24 + 12 + 72, 112 + 8 + 32) == 2) //关闭且未点击
        {
            pre_state = state;
            state = 9;
            if (pre_state != 9) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 112 + 8, 496 + 24 + 12 + 72, 112 + 8 + 32);
            }
        }
        else if (mouse_press(496 + 24 + 12, 112 + 8, 496 + 24 + 12 + 72, 112 + 8 + 32) == 1) //关闭且点击
        {
			daotu_info.type = 0;
			strcpy(daotu_info.mindname, ""); //清除信息
			if(fp != NULL)
			{
                fclose(fp);
			}
			
			clrmous(MouseX, MouseY);
            delay(5);

            operate_screen();
        }
        else if (mouse_press(496 + 24 + 12, 152 + 8, 496 + 24 + 12 + 72, 152 + 8 + 32) == 2) //删除且未点击
        {
            pre_state = state;
            state = 10;
            if (pre_state != 10) //防止被重复标亮
            {
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 152 + 8, 496 + 24 + 12 + 72, 152 + 8 + 32);
            }
        }
        else if (mouse_press(496 + 24 + 12, 152 + 8, 496 + 24 + 12 + 72, 152 + 8 + 32) == 1) //删除且点击
        {
            delete_mind(account_name, daotu_info.mindname); //删除操作
            daotu_info.type = 0;
            strcpy(daotu_info.mindname, ""); //清除MIND结构体信息
			
			clrmous(MouseX, MouseY);
            delay(5);

            operate_screen();
        }
		else if (mouse_press(496 + 24 + 12, 192 + 8, 496 + 24 + 12 + 72, 192 + 8 + 32) == 2) //编辑未点击
		{
			pre_state = state;
			state = 12;
			if(pre_state != 12)//防止被重复标亮
			{
				clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

                MouseS = 1; //手势鼠标
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 192 + 8, 496 + 24 + 12 + 72, 192 + 8 + 32);
			}
		}
		else if(mouse_press(496 + 24 + 12, 192 + 8, 496 + 24 + 12 + 72, 192 + 8 + 32) == 1) //编辑且点击
		{
			if(fp != NULL)
			{
				switch(daotu_info.type)
				{
					case 1:
					edit(oper_temp);
					break;
					case 2:
					edittr(oper_temptr);
					break;
					case 3:
					editfb(&oper_fish);
					break;
					case 4:
					edidate(&oper_date);
					break;
				}
                
                clrmous(MouseX, MouseY);
                delay(5); //画图前先清除鼠标，防止干扰

				operate_screen();
				if(daotu_info.type != 0)
				{
					puthz(16, 4, "导图名：", 16, 16, BLACK);
                    settextjustify(LEFT_TEXT, TOP_TEXT);
                    settextstyle(SMALL_FONT, HORIZ_DIR, 7);
                    setcolor(BLACK);
                    outtextxy(96, 0, daotu_info.mindname);
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(0, 24, 496, 480);
				}
				
				switch(daotu_info.type)
				{
					case 1:
					drawmind(oper_temp);
					break;
					case 2:
					drawmind_tr(oper_temptr);
					break;
					case 3:
					drawbone(&oper_fish);
					break;
					case 4:
					drawdate(&oper_date);
					break;
				}
				
			}
		}
		else if(mouse_press(496 + 24 + 12, 232 + 8, 496 + 24 + 12 + 72, 232 + 8 + 32) == 2) //保存未点击
		{
			pre_state = state;
			state = 13;
			if(pre_state != 13)//防止被重复标亮
			{
				clrmous(MouseX, MouseY);
				delay(5); //画图前先清除鼠标，防止干扰
				
				MouseS = 1; //手势鼠标
				setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 232 + 8, 496 + 24 + 12 + 72, 232 + 8 + 32);
			}
		}
		else if(mouse_press(496 + 24 + 12, 232 + 8, 496 + 24 + 12 + 72, 232 + 8 + 32) == 1) //保存已点击
		{
			if(fp != NULL)
			{
				switch(daotu_info.type)
				{
					case 1:
					fseek(fp, 0, 0);
	                fwrite(&(oper_temp[0][0]), sizeof(MINDBOX), HORI * VERT, fp);
					break;
					case 2:
					fseek(fp, 0, 0);
	                fwrite(&(oper_temptr[0][0]), sizeof(MINDBOX), HORI * VERTREE, fp);
					break;
					case 3:
					fseek(fp, 0, 0);
					fwrite(&oper_fish, sizeof(FISHINFO), 1, fp);
					break;
					case 4:
					fseek(fp, 0, 0);
					fwrite(&oper_date, sizeof(DATEINFO), 1, fp);
					break;
				}
				
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
                rectangle(616, 0, 640, 24);
                setlinestyle(0, 0, 3);
                line(624, 4, 632, 20);
                line(624, 20, 632, 4);
                break;
            case 2:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496, 0, 496 + 24, 24);
                break;
            case 7:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 40, 496 + 24 + 12 + 72, 40 + 32);
                break;
            case 8:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 72 + 8, 496 + 24 + 12 + 72, 72 + 8 + 32);
                break;
            case 9:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 112 + 8, 496 + 24 + 12 + 72, 112 + 8 + 32);
                break;
            case 10:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 152 + 8, 496 + 24 + 12 + 72, 152 + 8 + 32);
                break;
            case 11:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 20, 0, 496 + 24 + 20 + 56, 0 + 24);
				break;
			case 12:
			    MouseS = 0;
				setcolor(WHITE);
				setlinestyle(0, 0, 1);
				rectangle(496 + 24 + 12, 192 + 8, 496 + 24 + 12 + 72, 192 + 8 + 32);
			case 13:
			    MouseS = 0;
				setcolor(WHITE);
				setlinestyle(0, 0, 1);
				rectangle(496 + 24 + 12, 232 + 8, 496 + 24 + 12 + 72, 232 + 8 + 32);
            }
        }
    }
    return page;
}

/**************************************************
Name: operate_screen
Function：绘制编辑页面
Calls: 无
Called By: operate
Parameter: a 储存方向键形状数组
Return: 无
Author: 贾田旺
Others: 无
**************************************************/
void operate_screen()
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

    //退出程序的按钮
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(616, 0, 640, 24);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(616, 0, 640, 24);
    setlinestyle(0, 0, 3);
    line(624, 4, 632, 20);
    line(624, 20, 632, 4);

    //退出登录的按钮
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(496, 0, 496 + 24, 24);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(496, 0, 496 + 24, 24);
    setlinestyle(0, 0, 3);
    line(496 + 16, 4, 496 + 8, 12);
    line(496 + 8, 12, 496 + 16, 20);

    //功能按钮
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(496 + 24 + 12, 40, 496 + 24 + 12 + 72, 40 + 32);
    bar(496 + 24 + 12, 72 + 8, 496 + 24 + 12 + 72, 72 + 8 + 32);
    bar(496 + 24 + 12, 112 + 8, 496 + 24 + 12 + 72, 112 + 8 + 32);
    bar(496 + 24 + 12, 152 + 8, 496 + 24 + 12 + 72, 152 + 8 + 32);
    bar(496 + 24 + 12, 192 + 8, 496 + 24 + 12 + 72, 192 + 8 + 32);
	bar(496 + 24 + 12, 232 + 8, 496 + 24 + 12 + 72, 232 + 8 + 32);
	
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(496 + 24 + 12, 40, 496 + 24 + 12 + 72, 40 + 32);
    rectangle(496 + 24 + 12, 72 + 8, 496 + 24 + 12 + 72, 72 + 8 + 32);
    rectangle(496 + 24 + 12, 112 + 8, 496 + 24 + 12 + 72, 112 + 8 + 32);
    rectangle(496 + 24 + 12, 152 + 8, 496 + 24 + 12 + 72, 152 + 8 + 32);
    rectangle(496 + 24 + 12, 192 + 8, 496 + 24 + 12 + 72, 192 + 8 + 32);
	rectangle(496 + 24 + 12, 232 + 8, 496 + 24 + 12 + 72, 232 + 8 + 32);
	
    puthz(496 + 24 + 12 + 8, 40 + 4, "新建", 24, 32, WHITE);
    puthz(496 + 24 + 12 + 8, 72 + 8 + 4, "打开", 24, 32, WHITE);
    puthz(496 + 24 + 12 + 8, 112 + 8 + 4, "关闭", 24, 32, WHITE);
    puthz(496 + 24 + 12 + 8, 152 + 8 + 4, "删除", 24, 32, WHITE);
    puthz(496 + 24 + 12 + 8, 192 + 8 + 4, "编辑", 24, 32, WHITE);
	puthz(496 + 24 + 12 + 8, 232 + 8 + 4, "保存", 24, 32, WHITE);

    //底字
    puthz(152, 216, "欢迎来到思维导图", 24, 24, LIGHTGRAY);
}