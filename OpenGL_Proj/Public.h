#pragma once

// �ذ�����ͷ�ļ�
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
using namespace std;

// ------------ �궨�岿�� ------------

// ���ڶ���
#define WIN_NAME	"����ķ���"
#define WIN_WIDTH	900
#define WIN_HEIGHT	600

// �Զ��������С����
#define imageWidth	10
#define imageHeight 10


// ------------ ȫ�ֱ������� ------------

// ����
extern GLubyte	image[imageHeight][imageWidth][4];

// �ӽ�
extern GLfloat xrot;
extern GLfloat yrot;

// ������
extern bool		mouseLeftDown;
extern float	mouseX;
extern float	mouseY;