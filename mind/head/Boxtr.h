/**********************************************
Description:  �༭��״ͼ�������顢��������������
Function list :  findbox_tr Ѱ����״ͼ�Ŀ�
                 drawmind_tr ������ǰ����״ͼ
				 addbox_tr ������������״ͼһ���ӽڵ�
Attention:
Author:  ����Դ
History:
***********************************************/

#ifndef _BOXTR_H_
#define _BOXTR_H_

int findbox_tr(MINDBOX (*editp)[VERTREE], int *ho, int *ve);

void drawmind_tr(MINDBOX (*editp)[VERTREE]);

//void deletebox_tr(MINDBOX (*editp)[VERTREE], int ho, int ve);

void addbox_tr(MINDBOX (*editp)[VERTREE], int ho, int ve);

#endif // !_BOXTR_H_



