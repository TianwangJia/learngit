/**********************************************
Description: 登录注册所需工具函数及部分操作界面工具函数的头文件
Include:  无
Function list :  input_info 键盘输入显示函数
                 judge_samename 检查用户名是否已存在函数
                 judge_ID 检查身份证号是否符合要求
                 judge_password 检查密码是否符合要求
                 write_info 将账户用户名，身份证号，密码写入账户文件
                 new_file 为新注册的用户建立一个文件保存其账户信息
                 right_ID 判断身份证号是否正确
                 rewrite_key 写入新密码
                 right_key  判断密码是否正确
                 findmind   找到用户中的MIND结构体
                 delete_mind  删除用户文件中的指定MIND结构体,并删除对应的导图文件
Attention:
Author：贾田旺
History:
***********************************************/

#ifndef _ENTERT_H_
#define _ENTERT_H_

void input_info(int x, int y, int size, int mode, ENTER *content); //键盘输入显示函数

int judge_samename(char *name); //检查用户名是否已存在函数

int judge_ID(char *card); //检查身份证号是否符合要求

int judge_password(char *password); //检查密码是否符合要求

void write_info(char *name, char *card, char *password); //将账户用户名，身份证号，密码写入账户文件

void new_file(char *name); //为新注册的用户建立一个文件保存其账户信息

int right_ID(char *name, char *card); //判断身份证号是否正确

void rewrite(char *name, char *newkey); //写入新密码

int right_key(char *name, char *password); //判断密码是否正确

MIND findmind(char *account_name, char *mindname); //找到用户中的MIND结构体

void delete_mind(char *account_name, char *mindname); //删除用户文件中的指定MIND结构体,并删除对应的导图文件

#endif // !_ENTERT_H_
