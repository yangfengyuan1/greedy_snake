#pragma once
#ifndef TOOLS_H
#define TOOLS_H
#include <string>


void SetWindowSize(int cols, int lines, const std::string& win_title);
void SetCursorPosition(const int x, const int y);
void SetColor(int colorID);
void SetBackColor();

#endif // TOOLS_H
