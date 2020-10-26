#ifndef __HZ_H__
#define __HZ_H__

void puthz(int x, int y, char *s, int flag, int part, int color);
#endif
/*jia*********************************
x，y表示开始输出的坐标 x，y为第一个字左上角显示点 的坐标
flag表示输出的不同汉字大小 ：16*16？24*24？ 输入16or24，etc
flag汉字大小还会影响y的偏移
part表示一行中每两个汉字之间的偏移量，单位为屏幕坐标单位
color为输出字符颜色
**********************************jia*/
