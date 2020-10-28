/**********************************************
Description:  思维导图删框函数 基础函数（移动框，清空框）
Function list :  deletebox 删除，将所有的子节点一并删除，并对其余节点的坐标进行调整
                 movebox 移动信息函数
				 vanbox 置空信息函数
Attention:
Author:  倪启源
History:
***********************************************/

#ifndef _BOXADL_H_
#define _BOXADL_H_

void deletebox(MINDBOX (*editp)[16], int ho, int ve);

void movebox(MINDBOX *former, MINDBOX *latter);

void vanbox(MINDBOX *clrbox);

#endif // !_BOXADL_H_