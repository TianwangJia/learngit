#include "common.h"
#include "main.h"

void main(void)
{
    int page = 1;
    char account_name[8+1] = ""; //用户名
    int graphdriver = VGA;
    int graphmode = VGAHI;
    initgraph(&graphdriver, &graphmode, "C:\\BORLANDC\\BGI");
    mouseinit();
    while (1)
    {
        switch (page)
        {
        case 1: //首页，欢迎界面
            page = welcome();
            break;
        case 2: //注册界面
            page = sign_up();
            break;
        case 3: //登录界面
            page = log(account_name);
            break;
        case 4: //重置密码页面
            page = reset_key();
            break;
        case 5: //编辑主页面
			page = operate(account_name);
            break;
        case 6:
            page = help();
            break;
        case 0:           //退出程序
            closegraph(); //关闭画图
            delay(1000);   //可解决重启动时鼠标状态不稳定，但有学长反应容易崩溃，慎用
            exit(0);      //退出程序
        }
    }
}