/**********************************************
Description:  �༭���ͼ����
Function list : findbone Ѱ�����
                drawbone ������ǰ�����ͼ
				deletebone ɾȥĳ����ͷ
				addbone ����ĳ����ͷ
Attention:
Author:  ����Դ
History:
***********************************************/

#ifndef _BOXFB_H_
#define _BOXFB_H_

int findbone(FISHINFO *edifish, int *pnum);

void drawbone(FISHINFO *edifish);

void deletebone(FISHINFO *edifish, int pnum);

void addbone(FISHINFO *edifish, int pnum);

#endif // !_BOXFB_H_