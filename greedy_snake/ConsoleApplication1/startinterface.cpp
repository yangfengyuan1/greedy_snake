#include "startinterface.h"
#include "tools.h"
#include <windows.h>

void StartInterface::PrintTest() // 输出测试，选择合适符号作为边界和蛇体
{
    for (auto& point : testpoint)
    {
        point.Test();
        Sleep(speed);
    }
}


void StartInterface::PrintFirst()//蛇从左边出现到完全出现的过程
{
    for (auto& point : startsnake)
    {
        point.Print();
        Sleep(speed);
    }
}

void StartInterface::PrintSecond()//蛇从左向右移动的过程
{
    for (int i = 10; i != 41; ++i) //蛇头需要从10移动到41(窗口宽度)
    {
        /*计算蛇头的下一个位置，并将其压入startsnake中，绘制出来，将蛇尾去掉*/
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
        startsnake.emplace_back(Point(i, j));
        startsnake.back().Print();
        startsnake.front().Clear();
        startsnake.pop_front();// 移除蛇尾最后一个
        Sleep(speed);
    }
}

void StartInterface::PrintThird()//蛇从接触右边到消失的过程
{
    while (!startsnake.empty() || textsnake.back().GetX() < 33) //当蛇还没消失或文字没移动到指定位置
    {
        if (!startsnake.empty()) //如果蛇还没消失，继续移动
        {
            startsnake.front().Clear();
            startsnake.pop_front();
        }
        ClearText();//清除已有文字
        PrintText();//绘制更新位置后的文字
        Sleep(speed);
    }
}

void StartInterface::PrintInfo()
{
    SetColor(7);
    SetCursorPosition(15, 10); // 设置光标位置
    std::cout << "杨丰源"; 
    SetCursorPosition(15, 11); // 设置光标位置
    std::cout << "2023110148";
    SetCursorPosition(15, 12); // 设置光标位置
    std::cout << "项目名称：贪吃蛇";
}


void StartInterface::PrintText() // 打印x坐标为正的点
{
    for (auto& point : textsnake)
    {
        if (point.GetX() >= 0)
            point.Print();
    }
}

void StartInterface::ClearText() // 清除，右移一格
{
    for (auto& point : textsnake) // 平移
    {
        if (point.GetX() >= 0)
            point.Clear();
        point.ChangePosition(point.GetX() + 1, point.GetY());
    }
}

void StartInterface::StartAction()
{
    //PrintTest();
    PrintFirst();
    //std::cin.ignore(); // 输入回车，测试函数
    PrintSecond();
    //std::cin.ignore();
    PrintThird();
    //std::cin.ignore();
    PrintInfo(); // 输出个人信息

}

