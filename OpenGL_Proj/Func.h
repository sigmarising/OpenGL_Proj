#pragma once

#include "Public.h"

// ����⺯��
void mouseCB(int button, int state, int x, int y);

// ��괦����
void mouseMotionCB(int x, int y);

// �����Զ�������
void makeImage();

// ��ʼ������
void SetupRC(void);

// ��һ��ǽ
void DrawWall(void);

// ��������
void DrawPillar();

// ������
void DrawTable();

// ��ͼ����
void RenderScene();

// ����������
void SpecialKeys(int key, int x, int y);

// ���ڴ�С�ı亯��
void ChangeSize(int width, int height);