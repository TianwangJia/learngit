/**********************************************
Description:  具体编辑思维导图功能及界面
Function list : edit 编辑页面功能
                edit_screen 绘制编辑页面
				color_screen 绘制调色板界面
Attention:  
Author:  倪启源
History:  
***********************************************/

#ifndef _EDIT_H_
#define _EDIT_H_

void edit(MINDBOX (*editp)[VERT]); //编辑页面功能

void edit_screen(void); //绘制编辑页面

void color_screen(void); //画调色板

#endif