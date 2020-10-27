/**********************************************
Description:  编辑思维导图工具函数
Function list : edit_mind
                judge_time
                edit_yugu
                rank_time
Attention:  
Author:  贾田旺
History:  
***********************************************/
#include "common.h"
#include "EditT.h"
/**************************************************
Name: edit_mind
Function：思维导图内容文本编辑函数
Calls: 无
Called By:  Edit
            Edittr
Parameter:  x 输入框左边界
            y 输入框上边界
            message 输入导图信息结构体
            mind 导图信息结构体
            color 显示字符颜色
Return: 
Author: 贾田旺
Others: 框图大小 64*16
**************************************************/
void edit_mind(int x, int y, MINPUT *message, MINDBOX *mind, int color)
{
    char temp;
    int i;

    clrmous(MouseX, MouseY);
    delay(100);

    strcpy(message->str, mind->content);
    message->cursor = strlen(message->str);
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    setcolor(color);
    outtextxy(x + 6, y, message->str);
    setcolor(RED);
    setlinestyle(0, 0, 1);                                                                                         //FIXME
    line(x + 6 + (message->cursor) * (2 * 5 - 2) - 1, y + 2, x + 6 + (message->cursor) * (2 * 5 - 2) - 1, y + 14); //光标

    while (1)
    {
        //newmouse(&MouseX, &MouseY, &press);
        if (kbhit())
        {
            temp = getch();

            if (temp >= '!' && temp <= '~') //输入一个字符
            {
                if (message->cursor < message->length)
                {
                    (message->str)[message->cursor] = temp;
                    (message->str)[message->cursor + 1] = '\0';
                    (message->cursor)++;
                }
                if (message->cursor > 0)
                {
                    setcolor(WHITE);
                    setlinestyle(0, 0, 1);
                    line(x + 6 + (message->cursor - 1) * (2 * 5 - 2) - 1, y + 2, x + 6 + (message->cursor - 1) * (2 * 5 - 2) - 1, y + 14); //光标
                }
            }
            else if (temp == '\b') //删除字符
            {
                if (message->cursor > 0)
                {
                    setlinestyle(SOLID_LINE, 0, 3);
                    setcolor(RED);
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(x, y, x + 64, y + 16);
                    rectangle(x, y, x + 64, y + 16);
                    (message->str)[message->cursor - 1] = '\0';
                    (message->cursor)--;
                }
            }
            else if (temp == 13)
            {
                break;
            }

            setcolor(color);
            settextstyle(SMALL_FONT, HORIZ_DIR, 5);
            outtextxy(x + 6, y, message->str);

            setcolor(RED);
            setlinestyle(0, 0, 1);
            line(x + 6 + (message->cursor) * (2 * 5 - 2) - 1, y + 2, x + 6 + (message->cursor) * (2 * 5 - 2) - 1, y + 14); //光标
        }
    }

    strcpy(mind->content, message->str);
    return;
}

/**************************************************
Name: judge_time
Function：判断传入时间是否正确
Calls: 无
Called By:  Edidate
Parameter: time 存储年月日结构体
Return: 格式正确返回1，格式错误返回0
Author: 贾田旺
Others: 
**************************************************/
int judge_time(DATEHAPPEN time)
{
    int i;
    int monthdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (time.year > 3000 || time.year < 1)
        return 0;
    if (time.month > 12 || time.month < 1)
        return 0;
    if (time.month != 2)
    {
        if (time.day > 0 && time.day <= monthdays[time.month])
            return 1;
        else
            return 0;
    }
    else
    {
        if (time.month % 4 == 0 && time.month % 100 || time.month % 400 == 0) //闰年
        {
            if (time.day <= monthdays[2] + 1)
                return 1;
            else
                return 0;
        }
        else
        {
            if (time.day <= monthdays[2])
                return 1;
            else
                return 0;
        }
    }
}

/**************************************************
Name: rank_time
Function：为时间轴输入的时间进行排序
Calls: 无
Called By: Editdate
Parameter:  timeline 当前时间轴内容
            time     待插入时间点
Return: 1 添加成功 0添加失败
Author: 贾田旺
Others: 
**************************************************/
int rank_time(DATEINFO *timeline, DATEHAPPEN time)
{
    int i, j, k, n;
    DATEHAPPEN temp;
    if (timeline->daynum == 0)
    {
        timeline->date[0] = time;
        timeline->daynum++;
        return 1;
    }
    else if (timeline->daynum == MAXDATE)
    {
        return 0;
    }
    for (i = timeline->daynum - 1; i >= 0; i--)
    {
        if (timeline->date[i].year < time.year)
        {
            for (j = timeline->daynum - 1; j > i; j--)
            {
                if (timeline->date[j].year == time.year && timeline->date[j].month < time.month)
                {
                    for (k = timeline->daynum - 1; k > j; k--)
                    {
                        if (timeline->date[k].year == time.year && timeline->date[k].month == time.month && timeline->date[k].day < time.day)
                        {
                            for (n = timeline->daynum; n > k + 1; n--)
                            {
                                timeline->date[n] = timeline->date[n - 1];
                            }
                            timeline->date[n] = time;
                            timeline->daynum++;
                            return 1;
                        }
                    }
                    for (n = timeline->daynum; n > j + 1; n--)
                    {
                        timeline->date[n] = timeline->date[n - 1];
                    }
                    timeline->date[n] = time;
                    timeline->daynum++;
                    return 1;
                }
            }
            for (n = timeline->daynum; n > i + 1; n--)
            {
                timeline->date[n] = timeline->date[n - 1];
            }
            timeline->date[n] = time;
            timeline->daynum++;
            return 1;
        }
    }
    for (n = timeline->daynum; n > 0; n--)
    {
        timeline->date[n] = timeline->date[n - 1];
    }
    timeline->date[n] = time;
    timeline->daynum++;
    return 1;
}

/**************************************************
Name: eidt_yugu
Function：编辑鱼骨图文本
Calls: 无
Called By: Editfb
Parameter: x 输入框左边界
            y 输入框上边界
            message 输入导图信息结构体
            bone 鱼骨框信息结构体
            color 显示字符颜色
Return: 无
Author: 贾田旺
Others: 鱼骨为线性，长度64
**************************************************/
void edit_yugu(int x, int y, MINPUT *info, FISHBONE *bone, int color)
{
    char tmp;
    int i;

    clrmous(MouseX, MouseY);
    delay(100);

    strcpy(info->str, bone->content);
    info->cursor = strlen(info->str);
    setcolor(color);
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    outtextxy(x + 6, y, info->str);
    setcolor(RED);
    setlinestyle(0, 0, 1);
    line(x + 6 + (info->cursor) * (2 * 5 - 2) - 1, y + 2, x + 6 + (info->cursor) * (2 * 5 - 2) - 1, y + 14); //光标

    while (1)
    {
        if (kbhit())
        {
            tmp = getch();

            if (tmp >= '!' && tmp <= '~') //输入一个字符
            {
                if (info->cursor < info->length)
                {
                    (info->str)[info->cursor] = tmp;
                    (info->str)[info->cursor + 1] = '\0';
                    (info->cursor)++;
                }
                if (info->cursor > 0)
                {
                    setcolor(WHITE);
                    setlinestyle(0, 0, 1);
                    line(x + 6 + (info->cursor - 1) * (2 * 5 - 2) - 1, y + 2, x + 6 + (info->cursor - 1) * (2 * 5 - 2) - 1, y + 14); //光标
                }
            }
            else if (tmp == '\b') //删除字符
            {
                if (info->cursor > 0)
                {
                    setlinestyle(SOLID_LINE, 0, 3);
                    setcolor(RED);
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(x, y, x + 64, y + 16);
                    rectangle(x, y, x + 64, y + 16);
                    (info->str)[info->cursor - 1] = '\0';
                    (info->cursor)--;
                }
            }
            else if (tmp == 13)
            {
                break;
            }

            setcolor(color);
            settextstyle(SMALL_FONT, HORIZ_DIR, 5);
            outtextxy(x + 6, y, info->str);

            setcolor(RED);
            setlinestyle(0, 0, 1);
            line(x + 6 + (info->cursor) * (2 * 5 - 2) - 1, y + 2, x + 6 + (info->cursor) * (2 * 5 - 2) - 1, y + 14); //光标
        }
    }

    strcpy(bone->content, info->str);
    return;
}
