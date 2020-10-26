/**********************************************
Description:  ��ɳ�������ṹ�壬�����壬���ų�����ͷ�ļ�
Include:  
Function list :  
Attention:  
Author:  ������������Դ
History:  
***********************************************/

#ifndef _DATA_H_
#define _DATA_H_

#define HORI 6 //�����������
#define VERT 16//�����������
#define VERTREE 12 //��״ͼ������
#define NON 20 //δѡ�п����
#define BONEMAX 8 //�����
#define MAXDATE 25//ʱ�����������

typedef struct //������Ϣ�ṹ��
{
    int x1; //���������
    int y1;
    int x2;
    int y2;
    char length;  //�������󳤶�
    char cursor;  //���λ��
    char flag;    //0���������룬1�����������
    char str[19]; //������ַ�������
} ENTER;

typedef struct //�û������Ϣ
{
    char username[12 + 1]; //�û���
    char password[12 + 1]; //����
    char ID[18 + 1];       //���֤��
} USER;

typedef struct //˼ά��ͼ�ļ���Ϣ
{
    int type;             //˼ά��ͼ�����࣬1Ϊ����˼ά��ͼ��2Ϊ��״ͼ
    char mindname[8 + 1]; //˼ά��ͼ��
} MIND;

typedef struct
{
    int length;      //������󳤶�
    int cursor;      //���λ��
    char str[7 + 1]; //������߸��ַ�

} MINPUT;

typedef struct //˼ά��ͼ����Ϣ
{
	int ste; //���Ƿ���ʹ���� 0Ϊ��ʹ�� 1Ϊʹ��
	char content[8]; //��������
	int textcolor; //������ɫ
	int boxcolor; //����ɫ CYAN, BLACK, GREEN, BLUE, LIGHTGRAY
} MINDBOX; 

typedef struct //���ͼ��ͷ��Ϣ
{
	char content[8]; //��ͷ�ϵ�����
} FISHBONE;

typedef struct //���ͼ�ۺ���Ϣ
{
	FISHBONE bone[BONEMAX]; //��ͷ
	int bonenum; //��ͷ��
} FISHINFO;

typedef struct //ʱ���ᵥԪ��Ϣ
{
    int year;        //��
    int month;       //��
    int day;         //��
    char content[8]; //ʱ���������
} DATEHAPPEN;

typedef struct //ʱ�����ۺ���Ϣ
{
    DATEHAPPEN date[MAXDATE]; //ĳһ�죬�����ݶ�
    int daynum;          //����
} DATEINFO;


#endif // !_DATA_H_
