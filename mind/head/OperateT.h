/**********************************************
Description:  �༭ҳ�漰����ҳ�����ù��ߺ���
Include:  
Function list :  daotujud �жϵ�ͼ�ļ��Ƿ����
                 newmind  �½���ͼ�ļ�
                 input_newmind ����������Ϣ��ʾ����
                 newdrt Ϊ���û��½��ļ���
Author:  ����Դ
History:  
***********************************************/
#ifndef _OPERATET_H_
#define _OPERATET_H_

int daotujud(char *account_name, char *mind_name); //�жϵ�ͼ�ļ��Ƿ����

void newmind(char *account_name, char *mind_name, MIND *dt); //�½���ͼ�ļ�����

void input_newmind(int x, int y, int size, ENTER *content); //����������Ϣ��ʾ����

void newdrt(char *account_name); //Ϊ���û��½��ļ���

#endif