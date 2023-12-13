#include <iostream>
#include <vector>
#include <algorithm>
#include "leaderboard.h"

using namespace std;

void Ranklist::InitInfo() // 打印框
{
    int x1 = 13;
    int y1 = 6;
    int x2 = 27;
    int y2 = 17;
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            if (j == y1 || j == y2 || i == x1 || i == x2)
            {
                NameBoard.emplace_back(i, j);
            }
        }
    }
    system("cls");
    for (auto& point : NameBoard)
    {
        point.Print();// 口
    }
    SetCursorPosition(15, 8);
    SetColor(15);
    std::cout << "姓名: "; //(19,8)
    SetCursorPosition(14, 9);
    SetColor(12);
    std::cout << "（最多8个字母或数字组合）";
    SetCursorPosition(15, 12);
    SetColor(15);
    std::cout << "分数："; // (19,12) 
    SetCursorPosition(21, 15);
    std::cout << "按回车继续";
    SetCursorPosition(0, 31);
    
}

void Ranklist::InitRanklist()
{
    ranklists.clear();
}

bool Ranklist::Update_pl_score(const std::string& name, int newScore) {
    for (auto& pair : ranklists) {
        if (pair.first == name && pair.second < newScore) {
            pair.second = newScore; // 更新分数
            return true;
        }
    }
    return false;
}

void Ranklist::Get_name(int score_result) // 输入名字，输出分数，写入ranklists
{
    while (1)
    {
        SetCursorPosition(19, 12);
        std::cout << score_result;
        SetCursorPosition(19, 8);
        std::cout << "______________";
        // 通过getline获取用户输入的内容
        SetCursorPosition(19, 8);
        std::getline(std::cin, NAME);
        if (NAME.length() > 8) {
            SetCursorPosition(19, 8);
            std::cout << "______________";
            continue;
        }
        //vector<std::pair<std::string, int>> ranklist;
        if ( Update_pl_score(NAME, score_result))
            break;

        ranklists.push_back(std::make_pair(NAME, score_result));        
        break;
    }
}

void Ranklist::UpdateList()
{
    // 使用 lambda 表达式定义排序规则
    std::sort(ranklists.begin(), ranklists.end(), [](const auto& left, const auto& right) 
    {
        return left.second > right.second;  // 根据分数从大到小排序
    });

}

void Board::Init_leaderboard() // 生成边界框
{
    int x1 = 5;
    int y1 = 3;
    int x2 = 34;
    int y2 = 22;
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            if (j == y1 || j == y2 || i == x1 || i == x2)
            {
                lboard.emplace_back(i, j);
            }
        }
    }
}

void Board::Print_board() // 画出边界框
{
    system("cls");
    for (auto& point : lboard)
    {
        //point.PrintCircular();// o
        point.Print();// 口
    }
}

void Ranklist::PrintRank(int count) 
{
    //int count = 8;
    SetCursorPosition(16, 4);
    std::cout << "--- 排行榜 ---";
    int i = 6;    
    for (const auto& pair : ranklists) 
    {
        SetCursorPosition(9, i);
        i += 2;
        std::cout << "玩家:" << pair.first << "\t得分：" << pair.second << std::endl;
        count--;
        if (count == 0)
            break;
    }
}

void Ranklist::Search()
{
    std::string name = NAME;
    auto it = std::find_if(ranklists.begin(), ranklists.end(), [&name](const auto& pair) 
    {
        return pair.first == name;
    });

    if (it != ranklists.end()) 
    {
        int ranking = std::distance(ranklists.begin(), it) + 1; // 排名
        int score = it->second; // 成绩
        SetCursorPosition(7, 21);
        std::cout << "我：" << it->first << "\t排名：" << ranking << "\t成绩：" << score << std::endl;
    }
    SetCursorPosition(26, 21);
    std::cout << "按回车继续";
}

