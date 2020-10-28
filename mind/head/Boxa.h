/**********************************************
Description:  编辑页面框图操作（查、画、增）函数集
Function list :  findbox 寻找单向思维导图的框
                 drawmind 画出当前的单向思维导图
		         addbox 新增，新增单向思维导图的一个子节点
Attention:
Author:  倪启源
History:
***********************************************/

#ifndef _BOXA_H_
#define _BOXA_H_

int findbox(MINDBOX (*editp)[VERT], int *ho, int *ve);

void drawmind(MINDBOX (*editp)[VERT]);

//void deletebox(MINDBOX (*editp)[VERT], int ho, int ve); 

void addbox(MINDBOX (*editp)[VERT], int ho, int ve);

#endif // !_BOXA_H_