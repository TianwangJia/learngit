/**********************************************
Description:  һЩ�ļ��������ߺ����Լ����뺯��
Function list :  daotujud  �жϵ�ͼ�ļ��Ƿ��ظ�
                 newmind   �½�һ����ͼ�ļ�
                 input_mind ���벢��ʾ��Ϣ����
				 newdrt �½�һ��������û���ͼ�ļ����ļ���
Attention:
Author:  ����Դ
History:
***********************************************/
#ifndef _OPERATET_H_
#define _OPERATET_H_

int daotujud(char *account_name, char *mind_name); //�жϵ�ͼ�ļ��Ƿ����

void newmind(char *account_name, char *mind_name, MIND *dt); //�½���ͼ�ļ�����

void input_mind(int x, int y, int size, ENTER *content); //����������Ϣ��ʾ����

void newdrt(char *account_name); //Ϊ���û��½��ļ���

#endif