#include "point.h"
#include "tools.h"
#include <iostream>
#include <Windows.h>


// 特殊符号输入：
// win+“;”
// unicode,直接上网复制粘贴，注意占用字符数

void Point::Test() // 测试unicode字符 大小和占用宽度
{
    SetCursorPosition(x, y);
    std::wstring unicodeStr = L"⿴⨀〇●■□"; // 使用宽字符
    std::cout << "⿴ ⨀ 〇 ● ■ □" << std::endl;
    std::cout << "size:" << unicodeStr.size() << std::endl; // 输出 Unicode 字符串的字符数

    int width = 0;
    for (wchar_t c : unicodeStr) {
        WORD charType;
        GetStringTypeW(CT_CTYPE1, &c, 1, &charType);
        if (charType & C1_ALPHA) {
            width += 1; // 单字节字符或标点符号
            std::cout << "1 ";
        }
        else {
            width += 2; // 双字节字符
            std::cout << "2 ";
        }
    }
    std::cout << "\nString width: " << width << std::endl;


    //std::setlocale(LC_ALL, ""); // 设置本地化环境
    //wchar_t unicodeChar = L'⿴'; // Unicode 字符
    //int width = wcwidth(unicodeChar); // 计算字符宽度
    // 不兼容
    //std::wcout << L"Character width: " << width << std::endl;
    //std::cout << sizeof("⿴⨀〇●■□");

}

void Point::Print()//输出方块
{
    SetCursorPosition(x, y);
    std::cout << "■";
}

void Point::PrintCircular()//输出圆形
{
    SetCursorPosition(x, y);
    std::cout << "●";
}

void Point::Clear()//清除输出
{
    SetCursorPosition(x, y);
    std::cout << "  ";
}

void Point::ChangePosition(const int x, const int y)//改变坐标
{
    this->x = x;
    this->y = y;
}
