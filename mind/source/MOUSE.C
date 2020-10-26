#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include "mouse.h"

/**************************
MOUSE.c
UPDATER: dengshuumin
FUNCTION: mouse action
ABSTRACT:
		A.mread
		B.newmouse
VERSION: 3.0
***************************/
int MouseX;
int MouseY;
int MouseS; //这些全局变量是可以外用，改变鼠标状态的//S表示鼠标不同形态
int press;
void *buffer; //存鼠标背景
union REGS regs;
int flag = 0; //表示是否画鼠标

void mouseinit() //初始化//jia 只是初始化，保存图形，但是还没画
{
    int retcode;
    int xmin, xmax, ymin, ymax, x_max = 625, y_max = 480;
    int size;

    xmin = 2;
    xmax = x_max - 1;
    ymin = 8;
    ymax = y_max - 2;
    regs.x.ax = 0;
    int86(51, &regs, &regs);
    retcode = regs.x.ax;
    if (retcode == 0)
    {
        printf("Mouse or Mouse Driver Obsent,Please Install!");
        delay(5000);
    }
    else
    {
        regs.x.ax = 7;
        regs.x.cx = xmin;
        regs.x.dx = xmax;
        int86(51, &regs, &regs);
        regs.x.ax = 8;
        regs.x.cx = ymin;
        regs.x.dx = ymax;
        int86(51, &regs, &regs);
    }
    MouseS = 0; //MouseS 可更改鼠标样式 0为默认
    MouseX = 320, MouseY = 240;
    save_bk_mou(320, 240);
    mouse(MouseX, MouseY);
    flag = 1;
}

/*****************************
FUNCTION: mouse
DESCRIPTION: 画不同形态的鼠标
INPUT: x,y
RETURN: 无
******************************/
void mouse(int x, int y)
{

    switch (MouseS)
    {
    case 1: //手势鼠标
    {
        setcolor(WHITE);
        setlinestyle(0, 0, 1);
        line(x - 1, y + 9, x - 1, y + 8);
        line(x, y + 7, x, y + 11);
        line(x + 1, y + 6, x + 1, y + 13);
        line(x + 2, y + 8, x + 2, y + 14);
        line(x + 3, y - 1, x + 3, y + 15);
        arc(x + 4, y - 1, 0, 180, 1);
        line(x + 4, y - 2, x + 4, y + 15);
        line(x + 5, y - 1, x + 5, y + 16);
        arc(x + 6, y + 3, 0, 180, 1);
        line(x + 6, y + 2, x + 6, y + 16);
        line(x + 7, y + 3, x + 7, y + 17);
        arc(x + 8, y + 5, 0, 180, 1);
        line(x + 8, y + 4, x + 8, y + 17);
        line(x + 9, y + 5, x + 9, y + 16);
        arc(x + 10, y + 7, 0, 180, 1);
        line(x + 10, y + 6, x + 10, y + 16);
        line(x + 11, y + 7, x + 11, y + 13);

        setcolor(DARKGRAY);
        line(x - 1, y + 9, x - 1, y + 8);
        line(x - 1, y + 8, x + 1, y + 6);
        line(x + 1, y + 6, x + 3, y + 10);
        line(x + 3, y + 10, x + 3, y - 1);
        arc(x + 4, y - 1, 0, 180, 1);
        line(x + 5, y - 1, x + 5, y + 5);
        arc(x + 6, y + 3, 0, 180, 1);
        line(x + 7, y + 3, x + 7, y + 7);
        arc(x + 8, y + 5, 0, 180, 1);
        line(x + 9, y + 5, x + 9, y + 9);
        arc(x + 10, y + 7, 0, 180, 1);
        line(x + 11, y + 7, x + 11, y + 13);
        arc(x + 7, y + 13, -90, 0, 4);
        line(x + 7, y + 17, x + 3, y + 15);
        line(x + 3, y + 15, x + 1, y + 13);
        line(x + 1, y + 13, x - 1, y + 9);
    }
    break;
    case 2: //光标
    {
        setcolor(DARKGRAY);
        setlinestyle(0, 0, 1);
        line(x + 1, y - 1, x + 9, y - 1);
        line(x + 1, y + 15, x + 9, y + 15);
        line(x + 5, y - 1, x + 5, y + 15);
    }
    break;
    case 3: //十字
    {
        setcolor(WHITE);
        setlinestyle(0, 0, 1);
        line(x - 1, y + 7, x + 11, y + 7);
        line(x + 5, y - 1, x + 5, y + 15);
    }
    break;
    default: //默认鼠标
    {
        setlinestyle(0, 0, 1);
        setcolor(WHITE);
        line(x, y, x, y + 13);
        line(x + 1, y + 1, x + 1, y + 12);
        line(x + 2, y + 2, x + 2, y + 11);
        line(x + 3, y + 3, x + 3, y + 10);
        line(x + 4, y + 4, x + 4, y + 12);
        line(x + 5, y + 5, x + 5, y + 9);
        line(x + 5, y + 11, x + 5, y + 14);
        line(x + 6, y + 6, x + 6, y + 9);
        line(x + 6, y + 13, x + 6, y + 15);
        line(x + 7, y + 7, x + 7, y + 9);
        line(x + 8, y + 8, x + 8, y + 9);
        line(x + 9, y + 9, x + 9, y + 9);
        setcolor(DARKGRAY);
        line(x - 1, y - 1, x - 1, y + 14);
        line(x - 1, y + 14, x + 3, y + 11);
        line(x + 3, y + 11, x + 3, y + 12);
        line(x + 3, y + 12, x + 4, y + 13);
        line(x + 4, y + 13, x + 4, y + 14);
        line(x + 4, y + 14, x + 7, y + 17);
        line(x + 7, y + 17, x + 7, y + 13);
        line(x + 7, y + 13, x + 6, y + 12);
        line(x + 6, y + 12, x + 6, y + 11);
        line(x + 6, y + 11, x + 5, y + 10);
        line(x + 5, y + 10, x + 11, y + 10);
        line(x + 11, y + 10, x - 1, y - 2);
    }
    break;
    }
}

/*void mou_pos(int *nx,int *ny,int*nbuttons)//更改鼠标位置
{
	int x0=*nx,y0=*ny;

	mread(nx,ny,nbuttons);
	clrmous(x0,y0);
	save_bk_mou(*nx,*ny);
	drawmous(*nx,*ny);
}

void mread(int *nx,int *ny,int*nbuttons)//改坐标不画
{
	int x0=*nx,y0=*ny,buttons0=*nbuttons;
	int xnew,ynew,buttonsnew;

	do{
	regs.x.ax=3;
	int86(51,&regs,&regs);
	buttonsnew=regs.x.bx;
	delay(10);
	regs.x.ax=3;
	int86(51,&regs,&regs);
	if(regs.x.bx==buttonsnew)
		*nbuttons=regs.x.bx;
	else
		*nbuttons=buttons0;
	xnew=regs.x.cx;
	ynew=regs.x.dx;
	}while(xnew==x0&&ynew==y0&&*nbuttons==0);
	*nx=xnew;
	*ny=ynew;
}
*/

/***************************************
FUNCTION: mread
DESCRIPTION: 获取新的寄存器信息
INPUT: nx,ny,nbuttons
RETURN: 无
****************************************/
void mread(int *nx, int *ny, int *nbuttons) //jia 获取新的鼠标位置
{
    regs.x.ax = 3;
    int86(51, &regs, &regs);
    *nx = regs.x.cx;
    *ny = regs.x.dx;
    *nbuttons = regs.x.bx; //jia 这里已经随时更新的鼠标的press
}

/*******************************************
FUNCTION: newmouse
DESCRIPTION: 鼠标状态发生变化则更新鼠标
INPUT: nx,ny,nbuttons
RETURN: 无
********************************************/
void newmouse(int *nx, int *ny, int *nbuttons) //jia *nx,*ny 传入当前信息，靠mread读取状态后再更新*nx，*ny，*nbuttons代表按键状态
{
    int xn, yn, buttonsn;
    int x0 = *nx, y0 = *ny, buttons0 = *nbuttons;
    mread(&xn, &yn, &buttonsn);
    *nx = xn;
    *ny = yn;
    *nbuttons = buttonsn; //jia 这三行与原状态传递值
    if (buttons0 == *nbuttons)
        *nbuttons = 0; //使得能连续按键
    if (xn == x0 && yn == y0 && buttonsn == buttons0)
        return;      //鼠标状态不变则直接返回S
    clrmous(x0, y0); //说明鼠标状态发生了改变
    save_bk_mou(*nx, *ny);
    drawmous(*nx, *ny);
}

void save_bk_mou(int nx, int ny) //存鼠标背景//jia 为了在鼠标闪烁的时候显现
{
    int size;

    size = imagesize(nx - 1, ny - 2, nx + 11, ny + 17);
    buffer = malloc(size);
    if (buffer != NULL)
        getimage(nx - 1, ny - 2, nx + 11, ny + 17, buffer); //buffer全局变量一次存储一个鼠标背景
    else
        printf("Error");
}

void clrmous(int nx, int ny) //清除鼠标
{
    if (flag == 1) //jia flag=1 代表已画鼠标
    {
        setwritemode(XOR_PUT); //jia XOR_PUT 画图异或模式 这样画同样的图会清除原图
        mouse(nx, ny);
        putimage(nx - 1, ny - 2, buffer, COPY_PUT); //jia 清除原图
        free(buffer);
        flag = 0;
        setwritemode(COPY_PUT); //jia 再设置为原样模式
    }
}
void drawmous(int nx, int ny)
{
    if (flag == 0)
    {
        setwritemode(COPY_PUT);
        mouse(nx, ny); //jia 原样画鼠标
        flag = 1;
    }
}

//如果在框中点击，则返回1；在框中未点击，则返回2；不在框中则返回0
int mouse_press(int x1, int y1, int x2, int y2)
{
    //在框中点击，则返回1
    if (MouseX > x1 && MouseX < x2 && MouseY > y1 && MouseY < y2 && press == 1)
    {
        return 1;
    }

    //在框中未点击，则返回2
    else if (MouseX > x1 && MouseX < x2 && MouseY > y1 && MouseY < y2 && press == 0)
    {
        return 2;
    }

    //在框中点击右键，则返回3
    else if (MouseX > x1 && MouseX < x2 && MouseY > y1 && MouseY < y2 && press == 2)
    {
        return 3;
    }

    else
    {
        return 0;
    }
}
