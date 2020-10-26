/**********************************************
Description:  ±à¼­Ò³Ãæ¿òÍ¼²Ù×÷Ê÷×´Í¼º¯Êý¼¯
Include:  
Function list :  
Attention:  ÎÞ
Author:  ¼ÖÌïÍú£¬ÄßÆôÔ´
History:  
***********************************************/
#ifndef _BOXA_H_
#define _BOXA_H_

int findbox(MINDBOX (*editp)[VERT], int *ho, int *ve);

void drawmind(MINDBOX (*editp)[VERT]);

//void deletebox(MINDBOX (*editp)[VERT], int ho, int ve); 

void addbox(MINDBOX (*editp)[VERT], int ho, int ve);

#endif // !_BOXA_H_