
/**********************************************
Description:  ��ɱ༭��ҳ�漰��ع���
Function list :  operate   ����˼ά��ͼ����
                 operate_screen  ���Ʋ���ҳ��
Attention:  
Author:  ������
History:  
***********************************************/

#include "common.h"
#include "operate.h"

/**************************************************
Name: operate
Function���༭˼ά��ͼ����
Calls:  drawmind 
        drawmind_tr
        drawbone
        drawdate
        new
        operate_screen
        opena
        delete_mind
Called By: main
Parameter: account_name 
Return: page ҳ����ת
Author: ������
Others: ��
**************************************************/
int operate(char *account_name)
{
    MIND daotu_info = {0, ""}; //��ͼ��Ϣ
	char temdt[30 + 1]; //��ǰ˼ά��ͼ�ļ�λ������
	FILE *fp; //��ŵ�ǰ�򿪵��ļ�ָ��
	int open_ste; //��Ŵ�״̬
	MINDBOX oper_temp[HORI][VERT];
	MINDBOX oper_temptr[HORI][VERTREE];
	FISHINFO oper_fish;
	DATEINFO oper_date;
    int page = 5;
    int state = 0, pre_state = 0; //��ʾ���״̬�����ֵ��δ�����
                                  // 0 �޲���״̬ 1 �˳�����ť 2 ���ػ�ӭ���水ť
                                  //����� 3 �� 4 �� 5 �� 6 ��
                                  // 7 �½�  8 ��  9 �ر�  10 ɾ��
                                  // 11 ���� 12 �༭
    clrmous(MouseX, MouseY);
    delay(100);
    operate_screen();
    mouseinit();

    while (page == 5)
    {
        newmouse(&MouseX, &MouseY, &press);

        if (mouse_press(616, 0, 640, 24) == 2) //�˳�����δ���
        {
            pre_state = state;
            state = 1;

            if (pre_state != 1) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(RED);
                setlinestyle(0, 0, 1);
                rectangle(616, 0, 640, 24);
                setlinestyle(0, 0, 3);
                line(624, 4, 632, 20);
                line(624, 20, 632, 4);
            }
        }
        else if (mouse_press(616, 0, 640, 24) == 1) //�˳����ҵ��
        {
            page = 0;
        }
        else if (mouse_press(496, 0, 496 + 24, 24) == 2) //���ص�¼�������δ���
        {
            pre_state = state;
            state = 2;

            if (pre_state != 2) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(RED);
                setlinestyle(0, 0, 1);
                rectangle(496, 0, 496 + 24, 24);
            }
        }
        else if (mouse_press(496, 0, 496 + 24, 24) == 1) //���ص�¼������ҵ��
        {
            page = 1;
        }
        else if (mouse_press(496 + 24 + 12, 40, 496 + 24 + 12 + 72, 40 + 32) == 2) //�½�δ���
        {
            pre_state = state;
            state = 7;
            if (pre_state != 7) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 40, 496 + 24 + 12 + 72, 40 + 32);
            }
        }
        else if (mouse_press(496 + 24 + 12, 40, 496 + 24 + 12 + 72, 40 + 32) == 1) //�½����
        {
			clrmous(MouseX, MouseY);
            delay(5);
            if((new(account_name, &daotu_info) == 1)||daotu_info.type != 0)
			{
				operate_screen();
                puthz(16, 4, "��ͼ����", 16, 16, BLACK);
                settextjustify(LEFT_TEXT, TOP_TEXT);
                settextstyle(SMALL_FONT, HORIZ_DIR, 7);
                setcolor(BLACK);
                outtextxy(96, 0, daotu_info.mindname);
                setfillstyle(SOLID_FILL, WHITE);
                bar(0, 24, 496, 480);
				
				if(fp != NULL)
				{
					fclose(fp);
				}
				sprintf(temdt, ".\\daotu\\%s\\%s.dat", account_name,daotu_info.mindname);//д����һ����������
				if((fp = fopen(temdt,"rb+")) == NULL)//��ʧ�ܣ��쳣�˳�
				{
					closegraph();
                    printf("\nFile mind opening error.(from new_in_edit)\n");
                    delay(3000);
                    exit(1);
				}
				
				switch(daotu_info.type)
				{
					case 1:
					fseek(fp, 0, 0);
		            fread(&(oper_temp[0][0]), sizeof(MINDBOX), HORI * VERT, fp);
					drawmind(oper_temp);
					break;
					case 2:
					fseek(fp, 0, 0);
		            fread(&(oper_temptr[0][0]), sizeof(MINDBOX), HORI * VERTREE, fp);
					drawmind_tr(oper_temptr);
					break;
					case 3:
					fseek(fp, 0, 0);
					fread(&(oper_fish), sizeof(FISHINFO), 1, fp);
					drawbone(&oper_fish);
					break;
					case 4:
					fseek(fp, 0, 0);
					fread(&(oper_date), sizeof(DATEINFO), 1, fp);
					drawdate(&oper_date);
					break;
				}
			}
			else
			{
				operate_screen();
			}
        }
        else if (mouse_press(496 + 24 + 12, 72 + 8, 496 + 24 + 12 + 72, 72 + 8 + 32) == 2) //����δ���
        {
            pre_state = state;
            state = 8;
            if (pre_state != 8) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 72 + 8, 496 + 24 + 12 + 72, 72 + 8 + 32);
            }
        }
        else if (mouse_press(496 + 24 + 12, 72 + 8, 496 + 24 + 12 + 72, 72 + 8 + 32) == 1) //���ҵ��
        {
            //opena(account_name, &daotu_info);

            clrmous(MouseX, MouseY);
            delay(5);
			open_ste = opena(account_name, &daotu_info);
            if (daotu_info.type != 0)
            {
                operate_screen();
                puthz(16, 4, "��ͼ����", 16, 16, BLACK);	
                settextjustify(LEFT_TEXT, TOP_TEXT);
                settextstyle(SMALL_FONT, HORIZ_DIR, 7);
                setcolor(BLACK);
                outtextxy(96, 0, daotu_info.mindname);
                setfillstyle(SOLID_FILL, WHITE);
                bar(0, 24, 496, 480);
			}
            else
            {
                operate_screen();
            }

            if(open_ste == 1)
			{
				if(fp != NULL)
				{
					fclose(fp);
				}
				sprintf(temdt, ".\\daotu\\%s\\%s.dat", account_name, daotu_info.mindname);
			    if((fp = fopen(temdt,"rb+")) == NULL)//��ʧ�ܣ��쳣�˳�
			    {
					closegraph();
                    printf("\nFile mind opening error.(from open_in_edit)\n");
                    delay(3000);
                    exit(1);
			    }
			}
			
			switch(daotu_info.type)
			{
				case 1:
				fseek(fp, 0, 0);
		        fread(&(oper_temp[0][0]), sizeof(MINDBOX), HORI * VERT, fp);
				drawmind(oper_temp);
				break;
				case 2:
				fseek(fp, 0, 0);
		        fread(&(oper_temptr[0][0]), sizeof(MINDBOX), HORI * VERTREE, fp);
				drawmind_tr(oper_temptr);
				break;
				case 3:
			    fseek(fp, 0, 0);
				fread(&(oper_fish), sizeof(FISHINFO), 1, fp);
				drawbone(&oper_fish);
				break;
				case 4:
				fseek(fp, 0, 0);
				fread(&(oper_date), sizeof(DATEINFO), 1, fp);
				drawdate(&oper_date);
				break;
			}
        }
        else if (mouse_press(496 + 24 + 12, 112 + 8, 496 + 24 + 12 + 72, 112 + 8 + 32) == 2) //�ر���δ���
        {
            pre_state = state;
            state = 9;
            if (pre_state != 9) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 112 + 8, 496 + 24 + 12 + 72, 112 + 8 + 32);
            }
        }
        else if (mouse_press(496 + 24 + 12, 112 + 8, 496 + 24 + 12 + 72, 112 + 8 + 32) == 1) //�ر��ҵ��
        {
			daotu_info.type = 0;
			strcpy(daotu_info.mindname, ""); //�����Ϣ
			if(fp != NULL)
			{
                fclose(fp);
			}
			
			clrmous(MouseX, MouseY);
            delay(5);

            operate_screen();
        }
        else if (mouse_press(496 + 24 + 12, 152 + 8, 496 + 24 + 12 + 72, 152 + 8 + 32) == 2) //ɾ����δ���
        {
            pre_state = state;
            state = 10;
            if (pre_state != 10) //��ֹ���ظ�����
            {
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 152 + 8, 496 + 24 + 12 + 72, 152 + 8 + 32);
            }
        }
        else if (mouse_press(496 + 24 + 12, 152 + 8, 496 + 24 + 12 + 72, 152 + 8 + 32) == 1) //ɾ���ҵ��
        {
            delete_mind(account_name, daotu_info.mindname); //ɾ������
            daotu_info.type = 0;
            strcpy(daotu_info.mindname, ""); //���MIND�ṹ����Ϣ
			
			clrmous(MouseX, MouseY);
            delay(5);

            operate_screen();
        }
		else if (mouse_press(496 + 24 + 12, 192 + 8, 496 + 24 + 12 + 72, 192 + 8 + 32) == 2) //�༭δ���
		{
			pre_state = state;
			state = 12;
			if(pre_state != 12)//��ֹ���ظ�����
			{
				clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

                MouseS = 1; //�������
                setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 192 + 8, 496 + 24 + 12 + 72, 192 + 8 + 32);
			}
		}
		else if(mouse_press(496 + 24 + 12, 192 + 8, 496 + 24 + 12 + 72, 192 + 8 + 32) == 1) //�༭�ҵ��
		{
			if(fp != NULL)
			{
				switch(daotu_info.type)
				{
					case 1:
					edit(oper_temp);
					break;
					case 2:
					edittr(oper_temptr);
					break;
					case 3:
					editfb(&oper_fish);
					break;
					case 4:
					edidate(&oper_date);
					break;
				}
                
                clrmous(MouseX, MouseY);
                delay(5); //��ͼǰ�������꣬��ֹ����

				operate_screen();
				if(daotu_info.type != 0)
				{
					puthz(16, 4, "��ͼ����", 16, 16, BLACK);
                    settextjustify(LEFT_TEXT, TOP_TEXT);
                    settextstyle(SMALL_FONT, HORIZ_DIR, 7);
                    setcolor(BLACK);
                    outtextxy(96, 0, daotu_info.mindname);
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(0, 24, 496, 480);
				}
				
				switch(daotu_info.type)
				{
					case 1:
					drawmind(oper_temp);
					break;
					case 2:
					drawmind_tr(oper_temptr);
					break;
					case 3:
					drawbone(&oper_fish);
					break;
					case 4:
					drawdate(&oper_date);
					break;
				}
				
			}
		}
		else if(mouse_press(496 + 24 + 12, 232 + 8, 496 + 24 + 12 + 72, 232 + 8 + 32) == 2) //����δ���
		{
			pre_state = state;
			state = 13;
			if(pre_state != 13)//��ֹ���ظ�����
			{
				clrmous(MouseX, MouseY);
				delay(5); //��ͼǰ�������꣬��ֹ����
				
				MouseS = 1; //�������
				setcolor(LIGHTRED);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 232 + 8, 496 + 24 + 12 + 72, 232 + 8 + 32);
			}
		}
		else if(mouse_press(496 + 24 + 12, 232 + 8, 496 + 24 + 12 + 72, 232 + 8 + 32) == 1) //�����ѵ��
		{
			if(fp != NULL)
			{
				switch(daotu_info.type)
				{
					case 1:
					fseek(fp, 0, 0);
	                fwrite(&(oper_temp[0][0]), sizeof(MINDBOX), HORI * VERT, fp);
					break;
					case 2:
					fseek(fp, 0, 0);
	                fwrite(&(oper_temptr[0][0]), sizeof(MINDBOX), HORI * VERTREE, fp);
					break;
					case 3:
					fseek(fp, 0, 0);
					fwrite(&oper_fish, sizeof(FISHINFO), 1, fp);
					break;
					case 4:
					fseek(fp, 0, 0);
					fwrite(&oper_date, sizeof(DATEINFO), 1, fp);
					break;
				}
				
			}
		}
        else //�޲���״̬
        {
            pre_state = state;
            state = 0;
        }

        //���״̬�����ı䣬��֮ǰ�����޲���״̬����������������
        if (pre_state != state && pre_state != 0)
        {
            clrmous(MouseX, MouseY);
            delay(5);

            switch (pre_state)
            {
            case 1:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(616, 0, 640, 24);
                setlinestyle(0, 0, 3);
                line(624, 4, 632, 20);
                line(624, 20, 632, 4);
                break;
            case 2:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496, 0, 496 + 24, 24);
                break;
            case 7:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 40, 496 + 24 + 12 + 72, 40 + 32);
                break;
            case 8:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 72 + 8, 496 + 24 + 12 + 72, 72 + 8 + 32);
                break;
            case 9:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 112 + 8, 496 + 24 + 12 + 72, 112 + 8 + 32);
                break;
            case 10:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 12, 152 + 8, 496 + 24 + 12 + 72, 152 + 8 + 32);
                break;
            case 11:
                MouseS = 0;
                setcolor(WHITE);
                setlinestyle(0, 0, 1);
                rectangle(496 + 24 + 20, 0, 496 + 24 + 20 + 56, 0 + 24);
				break;
			case 12:
			    MouseS = 0;
				setcolor(WHITE);
				setlinestyle(0, 0, 1);
				rectangle(496 + 24 + 12, 192 + 8, 496 + 24 + 12 + 72, 192 + 8 + 32);
			case 13:
			    MouseS = 0;
				setcolor(WHITE);
				setlinestyle(0, 0, 1);
				rectangle(496 + 24 + 12, 232 + 8, 496 + 24 + 12 + 72, 232 + 8 + 32);
            }
        }
    }
    return page;
}

/**************************************************
Name: operate_screen
Function�����Ʊ༭ҳ��
Calls: ��
Called By: operate
Parameter: a ���淽�����״����
Return: ��
Author: ������
Others: ��
**************************************************/
void operate_screen(void)
{
    //����
    cleardevice();
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, 496, 480);
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    bar(496, 0, 640, 480);
    bar(0, 0, 496, 24);
    setcolor(WHITE);
    setlinestyle(0, 0, 3);
    line(496, 0, 496, 480);

    //�˳�����İ�ť
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(616, 0, 640, 24);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(616, 0, 640, 24);
    setlinestyle(0, 0, 3);
    line(624, 4, 632, 20);
    line(624, 20, 632, 4);

    //�˳���¼�İ�ť
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(496, 0, 496 + 24, 24);
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(496, 0, 496 + 24, 24);
    setlinestyle(0, 0, 3);
    line(496 + 16, 4, 496 + 8, 12);
    line(496 + 8, 12, 496 + 16, 20);

    //���ܰ�ť
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(496 + 24 + 12, 40, 496 + 24 + 12 + 72, 40 + 32);
    bar(496 + 24 + 12, 72 + 8, 496 + 24 + 12 + 72, 72 + 8 + 32);
    bar(496 + 24 + 12, 112 + 8, 496 + 24 + 12 + 72, 112 + 8 + 32);
    bar(496 + 24 + 12, 152 + 8, 496 + 24 + 12 + 72, 152 + 8 + 32);
    bar(496 + 24 + 12, 192 + 8, 496 + 24 + 12 + 72, 192 + 8 + 32);
	bar(496 + 24 + 12, 232 + 8, 496 + 24 + 12 + 72, 232 + 8 + 32);
	
    setcolor(WHITE);
    setlinestyle(0, 0, 1);
    rectangle(496 + 24 + 12, 40, 496 + 24 + 12 + 72, 40 + 32);
    rectangle(496 + 24 + 12, 72 + 8, 496 + 24 + 12 + 72, 72 + 8 + 32);
    rectangle(496 + 24 + 12, 112 + 8, 496 + 24 + 12 + 72, 112 + 8 + 32);
    rectangle(496 + 24 + 12, 152 + 8, 496 + 24 + 12 + 72, 152 + 8 + 32);
    rectangle(496 + 24 + 12, 192 + 8, 496 + 24 + 12 + 72, 192 + 8 + 32);
	rectangle(496 + 24 + 12, 232 + 8, 496 + 24 + 12 + 72, 232 + 8 + 32);
	
    puthz(496 + 24 + 12 + 8, 40 + 4, "�½�", 24, 32, WHITE);
    puthz(496 + 24 + 12 + 8, 72 + 8 + 4, "��", 24, 32, WHITE);
    puthz(496 + 24 + 12 + 8, 112 + 8 + 4, "�ر�", 24, 32, WHITE);
    puthz(496 + 24 + 12 + 8, 152 + 8 + 4, "ɾ��", 24, 32, WHITE);
    puthz(496 + 24 + 12 + 8, 192 + 8 + 4, "�༭", 24, 32, WHITE);
	puthz(496 + 24 + 12 + 8, 232 + 8 + 4, "����", 24, 32, WHITE);

    //����
    puthz(152, 216, "��ӭ����˼ά��ͼ", 24, 24, LIGHTGRAY);
}