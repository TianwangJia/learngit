/**********************************************
Description: ˼ά��ͼ�༭ҳ�沿�ֹ��ߺ���ͷ�ļ�
Include:  ��
Function list : edit_mind ˼ά��ͼ�����ı��༭����
                judge_time �жϴ���ʱ���Ƿ���ȷ
                rank_time Ϊʱ���������ʱ���������
                edit_yugu �༭���ͼ�ı�
Attention:
Author��������
History:
***********************************************/

#ifndef _EDIT_T_H_
#define _EDIR_T_H_

void edit_mind(int x, int y, MINPUT *message, MINDBOX *mind, int color); //˼ά��ͼ�����ı��༭����

int judge_time(DATEHAPPEN time); //�жϴ���ʱ���Ƿ���ȷ

void edit_yugu(int x, int y, MINPUT *info, FISHBONE *bone, int color); //Ϊʱ���������ʱ���������

int rank_time(DATEINFO *timeline, DATEHAPPEN time); //�༭���ͼ�ı�

#endif // !_EDIT_T_H
