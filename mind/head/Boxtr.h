/**********************************************
Description:  编辑树状图操作（查、画、增）函数集
Function list :  findbox_tr 寻找树状图的框
                 drawmind_tr 画出当前的树状图
				 addbox_tr 新增，新增树状图一个子节点
Attention:
Author:  倪启源
History:
***********************************************/

#ifndef _BOXTR_H_
#define _BOXTR_H_

int findbox_tr(MINDBOX (*editp)[VERTREE], int *ho, int *ve);

void drawmind_tr(MINDBOX (*editp)[VERTREE]);

//void deletebox_tr(MINDBOX (*editp)[VERTREE], int ho, int ve);

void addbox_tr(MINDBOX (*editp)[VERTREE], int ho, int ve);

#endif // !_BOXTR_H_



