#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H


class Controller
{
public:
    Controller() : speed(200), key(1), score(0) {}
    void Start();// 开始动画
    void Select();// 选择难度
    void DrawGame();// 初始化界面
    int PlayGame();
    void UpdateScore(const int&);
    void RewriteScore();
    int Menu();
    void Game();
    int GameOver();
    //void GetScore(); // 将score传递出来
    int score1;
private:
    int speed;
    int key;
    int score;
};
#endif // CONTROLLER_H
