/**********************************************
Description:  �༭ʱ����������ң�����ɾ��������
Function list : finddate Ѱ��ʱ��
                drawdate ������ǰ��ʱ����
		        deletedate ɾȥĳ��ʱ��
Attention:
Author:  ����Դ
History:
***********************************************/

#ifndef _BOXDATE_H_
#define _BOXDATE_H_

int finddate(DATEINFO *edidate, int *pdatenum);

void drawdate(DATEINFO *edidate);

void deletedate(DATEINFO *edidate, int pdatenum);

#endif // !_BOXDATE_H_