/**********************************************
Description:  编辑时间轴操作（找，画，删）函数集
Function list : finddate 寻找时间
                drawdate 画出当前的时间轴
		        deletedate 删去某个时间
Attention:
Author:  倪启源
History:
***********************************************/

#ifndef _BOXDATE_H_
#define _BOXDATE_H_

int finddate(DATEINFO *edidate, int *pdatenum);

void drawdate(DATEINFO *edidate);

void deletedate(DATEINFO *edidate, int pdatenum);

#endif // !_BOXDATE_H_