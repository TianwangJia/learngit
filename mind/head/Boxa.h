/**********************************************
Description:  �༭ҳ���ͼ������״ͼ������
Include:  
Function list :  
Attention:  ��
Author:  ������������Դ
History:  
***********************************************/
#ifndef _BOXA_H_
#define _BOXA_H_

int findbox(MINDBOX (*editp)[VERT], int *ho, int *ve);

void drawmind(MINDBOX (*editp)[VERT]);

//void deletebox(MINDBOX (*editp)[VERT], int ho, int ve); 

void addbox(MINDBOX (*editp)[VERT], int ho, int ve);

#endif // !_BOXA_H_