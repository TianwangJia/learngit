/**********************************************
Description:  �༭˼ά��ͼ���ߺ���
Function list : edit_mind
                judge_time
                edit_yugu
                rank_time
Attention:  
Author:  ������
History:  
***********************************************/
#include "common.h"
#include "EditT.h"
/**************************************************
Name: edit_mind
Function��˼ά��ͼ�����ı��༭����
Calls: ��
Called By:  Edit
            Edittr
Parameter:  x �������߽�
            y ������ϱ߽�
            message ���뵼ͼ��Ϣ�ṹ��
            mind ��ͼ��Ϣ�ṹ��
            color ��ʾ�ַ���ɫ
Return: 
Author: ������
Others: ��ͼ��С 64*16
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
    line(x + 6 + (message->cursor) * (2 * 5 - 2) - 1, y + 2, x + 6 + (message->cursor) * (2 * 5 - 2) - 1, y + 14); //���

    while (1)
    {
        //newmouse(&MouseX, &MouseY, &press);
        if (kbhit())
        {
            temp = getch();

            if (temp >= '!' && temp <= '~') //����һ���ַ�
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
                    line(x + 6 + (message->cursor - 1) * (2 * 5 - 2) - 1, y + 2, x + 6 + (message->cursor - 1) * (2 * 5 - 2) - 1, y + 14); //���
                }
            }
            else if (temp == '\b') //ɾ���ַ�
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
            line(x + 6 + (message->cursor) * (2 * 5 - 2) - 1, y + 2, x + 6 + (message->cursor) * (2 * 5 - 2) - 1, y + 14); //���
        }
    }

    strcpy(mind->content, message->str);
    return;
}

/**************************************************
Name: judge_time
Function���жϴ���ʱ���Ƿ���ȷ
Calls: ��
Called By:  Edidate
Parameter: time �洢�����սṹ��
Return: ��ʽ��ȷ����1����ʽ���󷵻�0
Author: ������
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
        if ((time.year % 4 == 0 && time.year % 100) || time.year % 400 == 0) //����
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
Function��Ϊʱ���������ʱ���������
Calls: ��
Called By: Editdate
Parameter:  timeline ��ǰʱ��������
            time     ������ʱ���
Return: 1 ��ӳɹ� 0���ʧ��
Author: ������
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
Name: edit_yugu
Function���༭���ͼ�ı�
Calls: ��
Called By: Editfb
Parameter: x �������߽�
            y ������ϱ߽�
            message ���뵼ͼ��Ϣ�ṹ��
            bone ��ǿ���Ϣ�ṹ��
            color ��ʾ�ַ���ɫ
Return: ��
Author: ������
Others: ���Ϊ���ԣ�����64
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
    line(x + 6 + (info->cursor) * (2 * 5 - 2) - 1, y + 2, x + 6 + (info->cursor) * (2 * 5 - 2) - 1, y + 14); //���

    while (1)
    {
        if (kbhit())
        {
            tmp = getch();

            if (tmp >= '!' && tmp <= '~') //����һ���ַ�
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
                    line(x + 6 + (info->cursor - 1) * (2 * 5 - 2) - 1, y + 2, x + 6 + (info->cursor - 1) * (2 * 5 - 2) - 1, y + 14); //���
                }
            }
            else if (tmp == '\b') //ɾ���ַ�
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
            line(x + 6 + (info->cursor) * (2 * 5 - 2) - 1, y + 2, x + 6 + (info->cursor) * (2 * 5 - 2) - 1, y + 14); //���
        }
    }

    strcpy(bone->content, info->str);
    return;
}
