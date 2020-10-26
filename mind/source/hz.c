#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hz.h"

void puthz(int x, int y, char *s, int flag, int part, int color)
{
	FILE *hzk_p = NULL;														 //定义汉字库文件指�?
	unsigned char quma, weima;												 //定义汉字的区码和位码
	unsigned long offset;													 //定义汉字在字库中的偏移量
	unsigned char mask[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01}; //功能数组，用于显示汉字点阵中的亮�?
	int i, j, pos;

	switch (flag) //不同的flag对应不同的汉字库，实现了汉字的大小可根据需要改�?
	{
	case 12:
	{
		char mat[24]; //16*12�ĺ�����Ҫ24���ֽڵ��������洢
		int y0 = y;
		int x0 = x;
		hzk_p = fopen(".\\HZK\\Hzk12", "rb"); //ʹ�����·��
		if (hzk_p == NULL)
		{
			settextjustify(LEFT_TEXT, TOP_TEXT);	 //�󲿶��룬��������
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 1); //����ʻ������ˮƽ�����24*24����
			outtextxy(10, 10, "Can't open hzk12 file!Press any key to quit...");
			getch();
			exit(1);
		}
		while (*s != NULL)
		{
			while (x < 640 - flag && (*s != NULL))
			{
				y = y0;
				quma = s[0] - 0xa0;								//�������
				weima = s[1] - 0xa0;							//���λ��
				offset = (94 * (quma - 1) + (weima - 1)) * 24L; //���Ҫ��ʾ�ĺ������ֿ��ļ��е�ƫ��
				fseek(hzk_p, offset, SEEK_SET);					//�ض�λ�ļ�ָ��
				fread(mat, 24, 1, hzk_p);						//�����ú��ֵľ����������,1ΪҪ���������

				for (i = 0; i < 12; i++)
				{
					pos = 2 * i;			 //16*16��������ÿһ���������ֽ�
					for (j = 0; j < 16; j++) //һ��һ�е�ɨ�裬��λ��Ϊ��1�ĵ���ʾ����
					{
						if ((mask[j % 8] & mat[pos + j / 8]) != NULL) //j%8ֻ����0��8֮��ѭ����j/8��0��1֮��ѭ��
						{
							putpixel(x + j, y, color);
						}
					}
					y++;
				}
				/*====================================================
								������һ��������ʾ��
							====================================================*/
				x += part; //��x һ��ƫ����part
				s += 2;	   //�������ŵ������룬2���ֽڣ�����Ҫ��2
			}
			x = x0;
			y0 += flag + 10; //һ�к�����ʾ���,���´���࿪ʼ������֣���yһ��ƫ����
		}

		break;
	}
	case 16:
	{
		char mat[32]; //16*16的汉字需�?32�?字节的数组来存储
		int y0 = y;
		int x0 = x;
		hzk_p = fopen(".\\HZK\\HZ16", "rb"); //使用相�?�路�?
		if (hzk_p == NULL)
		{
			settextjustify(LEFT_TEXT, TOP_TEXT);	 //左部对齐，顶部�?�齐
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 1); //黑体笔划输出，水平输出，24*24点阵
			outtextxy(10, 10, "Can't open hzk16 file!Press any key to quit...");
			getch();
			exit(1);
		}
		while (*s != NULL)
		{
			while (x < 640 - flag && (*s != NULL))
			{
				y = y0;
				quma = s[0] - 0xa0;								//求出区码
				weima = s[1] - 0xa0;							//求出位码
				offset = (94 * (quma - 1) + (weima - 1)) * 32L; //求出要显示的汉字在字库文件中的偏�?
				fseek(hzk_p, offset, SEEK_SET);					//重定位文件指�?
				fread(mat, 32, 1, hzk_p);						//读出该汉字的具体点阵数据,1为�?��?�入的项�?

				for (i = 0; i < 16; i++)
				{
					pos = 2 * i;			 //16*16矩阵�?有每一行有两�?�字�?
					for (j = 0; j < 16; j++) //一行一行地�?描，将位上为�?1的点显示出来
					{
						if ((mask[j % 8] & mat[pos + j / 8]) != NULL) //j%8�?能在0�?8之间�?�?，j/8�?0�?1之间�?�?
						{
							putpixel(x + j, y, color);
						}
					}
					y++;
				}
				/*====================================================
								以上�?一�?汉字显示�?
							====================================================*/
				x += part; //给x 一�?偏移量part
				s += 2;	   //汉字里存放的�?内码�?2�?字节，所以�?�加2
			}
			x = x0;
			y0 += flag + 10; //一行汉字显示完�?,重新从左侧开始输出汉字，给y一�?偏移�?
		}

		break;
	}

	case 24:
	{
		char mat[72]; //24*24矩阵�?72�?字节来存�?
		int y0 = y;
		int x0 = x;
		hzk_p = fopen(".\\HZK\\Hzk24k", "rb");
		if (hzk_p == NULL)
		{
			settextjustify(LEFT_TEXT, TOP_TEXT);	 //左部对齐，顶部�?�齐
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 3); //黑体笔划输出，水平输出，24*24点阵
			outtextxy(10, 10, "Can't open hzk24 file!Press any key to quit...");
			getch();
			exit(1);
		}
		while (*s != NULL)
		{
			while (x < 640 - flag && (*s != NULL))
			{
				y = y0;
				quma = s[0] - 0xa0;	 //求出区码
				weima = s[1] - 0xa0; //求出位码
				offset = (94 * (quma - 1) + (weima - 1)) * 72L;
				fseek(hzk_p, offset, SEEK_SET);
				fread(mat, 72, 1, hzk_p);
				for (i = 0; i < 24; i++)
				{
					pos = 3 * i;			 //矩阵�?每一行有三个字节
					for (j = 0; j < 24; j++) // 每一行有24�?
					{
						if ((mask[j % 8] & mat[pos + j / 8]) != NULL)
							putpixel(x + j, y, color);
					}
					y++;
				}
				x += part;
				s += 2;
			}
			x = x0;
			y0 += flag + 10;
		}
		break;
	}

	case 32:
	{
		char mat[128]; //32*32的汉字需�?128�?字节的数组来存储
		int y0 = y;
		int x0 = x;
		hzk_p = fopen(".\\HZK\\HZK32S", "rb");
		if (hzk_p == NULL)
		{
			settextjustify(LEFT_TEXT, TOP_TEXT);	 //左部对齐，顶部�?�齐
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 3); //黑体笔划输出，水平输出，24*24点阵
			outtextxy(10, 10, "Can't open hzk32 file!Press any key to quit...");
			getch();
			exit(1);
		}
		while (*s != NULL)
		{
			while (x < 640 - flag && (*s != NULL))
			{
				y = y0;
				quma = s[0] - 0xa0;	 //求出区码
				weima = s[1] - 0xa0; //求出位码
				offset = (94 * (quma - 1) + (weima - 1)) * 128L;
				fseek(hzk_p, offset, SEEK_SET);
				fread(mat, 128, 1, hzk_p);
				for (i = 0; i < 32; i++)
				{
					pos = 4 * i; //32*32矩阵�?有每一行有两�?�字�?
					for (j = 0; j < 32; j++)
					{
						if ((mask[j % 8] & mat[pos + j / 8]) != NULL)
						{
							putpixel(x + j, y, color);
						}
					}
					y++;
				}
				//以上�?一�?汉字显示�?
				x += part; //给x 一�?偏移量part
				s += 2;	   //汉字里存放的�?内码�?2�?字节，所以�?�加2
			}
			x = x0;
			y0 += flag + 10; //一行汉字显示完后，给y一�?偏移�?
		}
		break;
	}

	case 48:
	{
		char mat[288]; //48*48的汉字需�?288�?字节的数组来存储
		int y0 = y;
		int x0 = x;
		hzk_p = fopen(".\\HZK\\Hzk48k", "rb");
		if (hzk_p == NULL)
		{
			settextjustify(LEFT_TEXT, TOP_TEXT);	 //左部对齐，顶部�?�齐
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 3); //黑体笔划输出，水平输出，24*24点阵
			outtextxy(10, 10, "Can't open hzk48 file!Press any key to quit...");
			getch();
			exit(1);
		}
		while (*s != NULL)
		{
			while (x < 640 - flag && (*s != NULL))
			{
				y = y0;
				quma = s[0] - 0xa0;								 //求出区码
				weima = s[1] - 0xa0;							 //求出位码
				offset = (94 * (quma - 1) + (weima - 1)) * 288L; //求出要显示的汉字在字库文件中的偏�?
				fseek(hzk_p, offset, SEEK_SET);					 //重定位文件指�?
				fread(mat, 288, 1, hzk_p);						 //读出该汉字的具体点阵数据,1为�?��?�入的项�?

				for (i = 0; i < 48; i++)
				{
					pos = 6 * i;
					for (j = 0; j < 48; j++) //一行一行地�?描，将位上为�?1的点显示出来
					{
						if ((mask[j % 8] & mat[pos + j / 8]) != NULL) //j%8�?能在0�?8之间�?�?，j/8�?0�?1之间�?�?
						{
							putpixel(x + j, y, color);
						}
					}
					y++;
				}
				//以上�?一�?汉字显示�?
				x += part; //给x 一�?偏移量part
				s += 2;	   //汉字里存放的�?内码�?2�?字节，所以�?�加2
			}
			x = x0;
			y0 += flag + 10; //一行汉字显示完后，给y一�?偏移�?
		}
		break;
	}

	default:
		break;
	}

	fclose(hzk_p);
}
