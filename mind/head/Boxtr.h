/**********************************************
Description:  ±à¼­Ò³Ãæ¿òÍ¼²Ù×÷Ê÷×´Í¼º¯Êý¼¯
Include:  
Function list :  
Attention:  ÎÞ
Author:  ¼ÖÌïÍú£¬ÄßÆôÔ´
History:  
***********************************************/
#ifndef _BOXTR_H_
#define _BOXTR_H_

int findbox_tr(MINDBOX (*editp)[VERTREE], int *ho, int *ve);

void drawmind_tr(MINDBOX (*editp)[VERTREE]);

//void deletebox_tr(MINDBOX (*editp)[VERTREE], int ho, int ve);

void addbox_tr(MINDBOX (*editp)[VERTREE], int ho, int ve);

#endif // !_BOXTR_H_



