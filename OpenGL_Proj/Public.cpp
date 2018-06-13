#include "Public.h"

// ------------ 全局变量 ------------

// 贴图
GLubyte	image[imageHeight][imageWidth][4];

// 视角
GLfloat xrot = 0;
GLfloat yrot = 0;

// 鼠标相关
bool	mouseLeftDown;
float	mouseX;
float	mouseY;