/**********************************************
Description:  �༭ҳ���ͼ�������顢��������������
Function list :  findbox Ѱ�ҵ���˼ά��ͼ�Ŀ�
                 drawmind ������ǰ�ĵ���˼ά��ͼ
		         addbox ��������������˼ά��ͼ��һ���ӽڵ�
Attention:
Author:  ����Դ
History:
***********************************************/

#ifndef _BOXA_H_
#define _BOXA_H_

int findbox(MINDBOX (*editp)[VERT], int *ho, int *ve);

void drawmind(MINDBOX (*editp)[VERT]);

//void deletebox(MINDBOX (*editp)[VERT], int ho, int ve); 

void addbox(MINDBOX (*editp)[VERT], int ho, int ve);

#endif // !_BOXA_H_