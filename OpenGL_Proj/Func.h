#pragma once

#include "Public.h"

// 鼠标检测函数
void mouseCB(int button, int state, int x, int y);

// 鼠标处理函数
void mouseMotionCB(int x, int y);

// 生成自定义纹理
void makeImage();

// 初始化函数
void SetupRC(void);

// 画一面墙
void DrawWall(void);

// 画桌子腿
void DrawPillar();

// 画桌子
void DrawTable();

// 绘图函数
void RenderScene();

// 按键处理函数
void SpecialKeys(int key, int x, int y);

// 窗口大小改变函数
void ChangeSize(int width, int height);