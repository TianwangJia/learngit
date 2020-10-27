/**********************************************
Description:  编辑页面及附属页面所用工具函数
Include:  
Function list :  daotujud 判断导图文件是否存在
                 newmind  新建导图文件
                 input_newmind 键盘输入信息显示函数
                 newdrt 为新用户新建文件夹
Author:  倪启源
History:  
***********************************************/
#ifndef _OPERATET_H_
#define _OPERATET_H_

int daotujud(char *account_name, char *mind_name); //判断导图文件是否存在

void newmind(char *account_name, char *mind_name, MIND *dt); //新建导图文件函数

void input_newmind(int x, int y, int size, ENTER *content); //键盘输入信息显示函数

void newdrt(char *account_name); //为新用户新建文件夹

#endif