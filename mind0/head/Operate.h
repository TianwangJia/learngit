/**********************************************
Description:  编辑函数及页面头文件
Include:  newa.h 
          opena.h
		  edit.h
Function list :  operate 编辑思维导图功能
                 operate_screen 绘制编辑页面
Attention:  无
Author:  贾田旺,倪启源
History:  无
***********************************************/
#ifndef _OPERATE_H_
#define _OPERATE_H_

#include "newa.h"
#include "Opena.h"
#include "Edit.h"
#include "Boxa.h"
#include "Boxdate.h"
#include "Boxfb.h"
#include "Boxtr.h"
#include "Edidate.h"
#include "Edit.h"
#include "EditT.h"
#include "Edittr.h"
#include "Edittr.h"

int operate(char *account_name); //编辑思维导图功能
void operate_screen(); //绘制编辑页面

#endif // !_OPERATE_H_