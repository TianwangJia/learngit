/**********************************************
Description:  树状图删框函数
Function list :  deletebox_tr 删除，将所有的子节点一并删除，并对其余节点的坐标进行调整
Attention:
Author:  倪启源
History:
***********************************************/

#ifndef _BOXTRDL_H_
#define _BOXTRDL_H_

void deletebox_tr(MINDBOX (*editp)[VERTREE], int ho, int ve);

#endif // !_BOXTRDL_H_