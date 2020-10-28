/**********************************************
Description:  编辑鱼骨图操作
Function list : findbone 寻找鱼骨
                drawbone 画出当前的鱼骨图
				deletebone 删去某根骨头
				addbone 新增某根骨头
Attention:
Author:  倪启源
History:
***********************************************/

#ifndef _BOXFB_H_
#define _BOXFB_H_

int findbone(FISHINFO *edifish, int *pnum);

void drawbone(FISHINFO *edifish);

void deletebone(FISHINFO *edifish, int pnum);

void addbone(FISHINFO *edifish, int pnum);

#endif // !_BOXFB_H_