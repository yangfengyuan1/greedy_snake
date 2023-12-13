#include "tools.h"
#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;

void SetWindowSize(int cols, int lines,const std::string& win_title)         //设置窗口大小
{
    string title_command = "title " + win_title;
    system(title_command.c_str());                    //设置窗口标题
    char cmd[35];
    sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个图形■占两个字符，故宽度乘以2
    system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
}

void SetCursorPosition(const int x, const int y)//设置光标位置
{
    // COORD 是 Windows API 中的一个结构体，
    // 用于表示字符在控制台屏幕上的坐标位置。
    COORD position;
    position.X = x * 2;
    position.Y = y;
    // SetConsoleCursorPosition 是 Windows API 中用于设置控制台光标位置的函数。
    // 它接受一个输出设备句柄和一个表示坐标位置的 COORD 结构体作为参数，
    // 将控制台光标移动到指定位置。
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}


// SetConsoleTextAttribute() 是 Windows API 中用于设置控制台文本属性的函数之一。
// 它可以修改控制台中文本的颜色和样式。
// GetStdHandle(STD_OUTPUT_HANDLE) 返回标准输出设备的句柄，
// SetConsoleTextAttribute() 利用这个句柄来改变输出文本的颜色。
//文本颜色：
//第一个位标志（最低有效位）表示蓝色（1）
//第二个位标志表示绿色（2）
//第三个位标志表示红色（4）
//第四个位标志表示加亮（8）
//背景颜色：
//第五个位标志表示蓝色背景（16）
//第六个位标志表示绿色背景（32）
//第七个位标志表示红色背景（64）
//第八个位标志表示加亮背景（128）
void SetColor(int colorID)//设置文本颜色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//设置文本背景色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 121);//1111001
    //FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED
}
