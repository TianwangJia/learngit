/**********************************************
Description:  �༭ҳ�漰����ҳ�����ù��ߺ���
Include:  
Function list :  daotujud �жϵ�ͼ�ļ��Ƿ����
                 newmind  �½���ͼ�ļ�
                 input_newmind ����������Ϣ��ʾ����
                 findmind �ҵ��û��е�MIND�ṹ��
                 delete_mind ɾ���û��ļ��е�ָ��MIND�ṹ�壬��ɾ����Ӧ�ĵ�ͼ�ļ�
Attention:  
Author:  ������������Դ
History:  
***********************************************/
#ifndef _OPERATET_H_
#define _OPERATET_H_

int daotujud(char *account_name, char *mind_name); //�жϵ�ͼ�ļ��Ƿ����

void newmind(char *account_name, char *mind_name, MIND *dt); //�½���ͼ�ļ�����

void input_newmind(int x, int y, int size, ENTER *content); //����������Ϣ��ʾ����

MIND findmind(char *account_name, char *mindname); //�ҵ��û��е�MIND�ṹ��

void delete_mind(char *account_name, char *mindname); //ɾ���û��ļ��е�ָ��MIND�ṹ��,��ɾ����Ӧ�ĵ�ͼ�ļ�

#endif