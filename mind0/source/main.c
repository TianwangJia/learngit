#include "common.h"
#include "main.h"

void main(void)
{
    int page = 1;
    char account_name[8+1] = ""; //�û���
    int graphdriver = VGA;
    int graphmode = VGAHI;
    initgraph(&graphdriver, &graphmode, "C:\\BORLANDC\\BGI");
    mouseinit();
    while (1)
    {
        switch (page)
        {
        case 1: //��ҳ����ӭ����
            page = welcome();
            break;
        case 2: //ע�����
            page = sign_up();
            break;
        case 3: //��¼����
            page = log(account_name);
            break;
        case 4: //��������ҳ��
            page = reset_key();
            break;
        case 5: //�༭��ҳ��
			page = operate(account_name);
            break;
        case 6:
            page = help();
            break;
        case 0:           //�˳�����
            closegraph(); //�رջ�ͼ
            delay(100);   //�ɽ��������ʱ���״̬���ȶ�������ѧ����Ӧ���ױ���������
            exit(0);      //�˳�����
        }
    }
}