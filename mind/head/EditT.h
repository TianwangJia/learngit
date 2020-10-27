/**********************************************
Description: 思维导图编辑页面部分工具函数头文件
Include:  无
Function list : edit_mind 思维导图内容文本编辑函数
                judge_time 判断传入时间是否正确
                rank_time 为时间轴输入的时间进行排序
                edit_yugu 编辑鱼骨图文本
Attention:
Author：贾田旺
History:
***********************************************/

#ifndef _EDIT_T_H_
#define _EDIR_T_H_

void edit_mind(int x, int y, MINPUT *message, MINDBOX *mind, int color); //思维导图内容文本编辑函数

int judge_time(DATEHAPPEN time); //判断传入时间是否正确

void edit_yugu(int x, int y, MINPUT *info, FISHBONE *bone, int color); //为时间轴输入的时间进行排序

int rank_time(DATEINFO *timeline, DATEHAPPEN time); //编辑鱼骨图文本

#endif // !_EDIT_T_H
