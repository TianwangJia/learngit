/**********************************************
Description:  帮助界面头文件
Include:  无
Function list :  help 帮助界面功能
                 help_screen 绘制帮助界面
                 help_page1 帮助页1
                 help_page2 帮助页2
                 help_page3 帮助页3
                 help_page4 帮助页4
Attention:  
Author:  贾田旺，倪启源
History:  
*******************************************/
#ifndef _HELP_H_
#define _HELP_H_

int help(); //帮助界面功能

void help_screen(int (*a)[8]);//绘制帮助界面

void help_page1(int (*a)[8]);//帮助页1

void help_page2(int (*a)[8]); //帮助页2

void help_page3(int (*a)[8]); //帮助页3

void help_page4(int (*a)[8]); //帮助页4

#endif