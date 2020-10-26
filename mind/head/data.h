/**********************************************
Description:  完成程序所需结构体，联合体，符号常量等头文件
Include:  
Function list :  
Attention:  
Author:  贾田旺、倪启源
History:  
***********************************************/

#ifndef _DATA_H_
#define _DATA_H_

#define HORI 6 //横向框上限数
#define VERT 16//纵向框上限数
#define VERTREE 12 //树状图上限数
#define NON 20 //未选中框的数
#define BONEMAX 8 //鱼骨数
#define MAXDATE 25//时间轴最多数量

typedef struct //输入信息结构体
{
    int x1; //输入框坐标
    int y1;
    int x2;
    int y2;
    char length;  //输入的最大长度
    char cursor;  //光标位置
    char flag;    //0代表不能输入，1代表可以输入
    char str[19]; //输入的字符串内容
} ENTER;

typedef struct //用户相关信息
{
    char username[12 + 1]; //用户名
    char password[12 + 1]; //密码
    char ID[18 + 1];       //身份证号
} USER;

typedef struct //思维导图文件信息
{
    int type;             //思维导图的种类，1为单向思维导图，2为树状图
    char mindname[8 + 1]; //思维导图名
} MIND;

typedef struct
{
    int length;      //输入最大长度
    int cursor;      //光标位置
    char str[7 + 1]; //最长输入七个字符

} MINPUT;

typedef struct //思维导图框信息
{
	int ste; //框是否在使用中 0为不使用 1为使用
	char content[8]; //框内文字
	int textcolor; //文字颜色
	int boxcolor; //框颜色 CYAN, BLACK, GREEN, BLUE, LIGHTGRAY
} MINDBOX; 

typedef struct //鱼骨图骨头信息
{
	char content[8]; //骨头上的文字
} FISHBONE;

typedef struct //鱼骨图综合信息
{
	FISHBONE bone[BONEMAX]; //骨头
	int bonenum; //骨头数
} FISHINFO;

typedef struct //时间轴单元信息
{
    int year;        //年
    int month;       //月
    int day;         //日
    char content[8]; //时间轴的文字
} DATEHAPPEN;

typedef struct //时间轴综合信息
{
    DATEHAPPEN date[MAXDATE]; //某一天，天数暂定
    int daynum;          //天数
} DATEINFO;


#endif // !_DATA_H_
