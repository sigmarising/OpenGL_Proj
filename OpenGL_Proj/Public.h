#pragma once

// 必包含的头文件
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
using namespace std;

// ------------ 宏定义部分 ------------

// 窗口定义
#define WIN_NAME	"跳舞的房间"
#define WIN_WIDTH	900
#define WIN_HEIGHT	600

// 自定义纹理大小定义
#define imageWidth	10
#define imageHeight 10


// ------------ 全局变量部分 ------------

// 纹理
extern GLubyte	image[imageHeight][imageWidth][4];

// 视角
extern GLfloat xrot;
extern GLfloat yrot;

// 鼠标相关
extern bool		mouseLeftDown;
extern float	mouseX;
extern float	mouseY;