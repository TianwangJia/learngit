/**********************************************
Description:  ��������ͷ�ļ�
Include:  ��
Function list :  help �������湦��
                 help_screen ���ư�������
                 help_page1 ����ҳ1
                 help_page2 ����ҳ2
                 help_page3 ����ҳ3
                 help_page4 ����ҳ4
Attention:  
Author:  ������
History:  
*******************************************/
#ifndef _HELP_H_
#define _HELP_H_

int help(void); //�������湦��

void help_screen(int (*a)[8]);//���ư�������

void help_page1(int (*a)[8]);//����ҳ1

void help_page2(int (*a)[8]); //����ҳ2

void help_page3(int (*a)[8]); //����ҳ3

void help_page4(int (*a)[8]); //����ҳ4

#endif