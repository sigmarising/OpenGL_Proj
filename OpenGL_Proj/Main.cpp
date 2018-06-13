#include "Public.h"
#include "Func.h"

//	程序入口点
int main(int argc, char *argv[]) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);	// 设置显示模式 双缓冲
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);					// 窗口大小设置
	glutInitWindowPosition(10, 10);								// 窗口初始位置
	glutCreateWindow(WIN_NAME);									// 窗口名称

	SetupRC();						// 初始化函数
	glutDisplayFunc(RenderScene);	// 显示函数 用于绘图
	glutReshapeFunc(ChangeSize);	// 窗口大小改变处理函数
	glutSpecialFunc(SpecialKeys);	// 按键交互函数
	glutMouseFunc(mouseCB);			// 鼠标检测函数
	glutMotionFunc(mouseMotionCB);	// 鼠标处理函数

	glutMainLoop();					// 开始运行

	return 0;
}