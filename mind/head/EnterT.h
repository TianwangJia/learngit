/**********************************************
Description: ��¼ע�����蹤�ߺ��������ֲ������湤�ߺ�����ͷ�ļ�
Include:  ��
Function list :  input_info ����������ʾ����
                 judge_samename ����û����Ƿ��Ѵ��ں���
                 judge_ID ������֤���Ƿ����Ҫ��
                 judge_password ��������Ƿ����Ҫ��
                 write_info ���˻��û��������֤�ţ�����д���˻��ļ�
                 new_file Ϊ��ע����û�����һ���ļ��������˻���Ϣ
                 right_ID �ж����֤���Ƿ���ȷ
                 rewrite_key д��������
                 right_key  �ж������Ƿ���ȷ
                 findmind   �ҵ��û��е�MIND�ṹ��
                 delete_mind  ɾ���û��ļ��е�ָ��MIND�ṹ��,��ɾ����Ӧ�ĵ�ͼ�ļ�
Attention:
Author��������
History:
***********************************************/

#ifndef _ENTERT_H_
#define _ENTERT_H_

void input_info(int x, int y, int size, int mode, ENTER *content); //����������ʾ����

int judge_samename(char *name); //����û����Ƿ��Ѵ��ں���

int judge_ID(char *card); //������֤���Ƿ����Ҫ��

int judge_password(char *password); //��������Ƿ����Ҫ��

void write_info(char *name, char *card, char *password); //���˻��û��������֤�ţ�����д���˻��ļ�

void new_file(char *name); //Ϊ��ע����û�����һ���ļ��������˻���Ϣ

int right_ID(char *name, char *card); //�ж����֤���Ƿ���ȷ

void rewrite_key(char *name, char *newkey); //д��������

int right_key(char *name, char *password); //�ж������Ƿ���ȷ

MIND findmind(char *account_name, char *mindname); //�ҵ��û��е�MIND�ṹ��

void delete_mind(char *account_name, char *mindname); //ɾ���û��ļ��е�ָ��MIND�ṹ��,��ɾ����Ӧ�ĵ�ͼ�ļ�

#endif // !_ENTERT_H_
