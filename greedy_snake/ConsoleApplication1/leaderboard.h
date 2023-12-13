#pragma once
#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include "controller.h"
#include "point.h"
#include "tools.h"

using namespace std;
class Controller;
class Board
{
public:
	Board() {}
	void Init_leaderboard();// 生成边界框坐标
	void Print_board();		// 打印边界框
private:
	friend class Controller;
	friend class Ranklist;
	std::vector<Point> lboard;
};

class Ranklist {
public:
	void InitInfo();			// 生成NameBoard
	void InitRanklist();		// clear
	void Get_name(int score_result);// 获取名字
	void UpdateList();				// 更新排序
	void PrintRank(int);		// 打印前count名（8）
	void Search();					// 搜索并打印自己的名次
	bool Update_pl_score(const std::string& , int );// 同名更新成更好成绩
	// 
private:
	friend class Controller;// 获取score
	friend class Board; 
	std::string NAME; // 用户名，8位
	std::vector<Point> NameBoard;
	std::vector<std::pair<std::string,int>> ranklists;
};

#endif //LEADERBOARD_H



