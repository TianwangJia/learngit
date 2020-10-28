/**********************************************
Description:  一些文件操作工具函数以及输入函数
Function list :  daotujud  判断导图文件是否重复
                 newmind   新建一个导图文件
                 input_mind 输入并显示信息函数
				 newdrt 新建一个存放新用户导图文件的文件夹
Attention:
Author:  倪启源
History:
***********************************************/
#ifndef _OPERATET_H_
#define _OPERATET_H_

int daotujud(char *account_name, char *mind_name); //判断导图文件是否存在

void newmind(char *account_name, char *mind_name, MIND *dt); //新建导图文件函数

void input_mind(int x, int y, int size, ENTER *content); //键盘输入信息显示函数

void newdrt(char *account_name); //为新用户新建文件夹

#endif