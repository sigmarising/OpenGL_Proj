#include "Public.h"
#include "Func.h"

//	������ڵ�
int main(int argc, char *argv[]) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);	// ������ʾģʽ ˫����
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);					// ���ڴ�С����
	glutInitWindowPosition(10, 10);								// ���ڳ�ʼλ��
	glutCreateWindow(WIN_NAME);									// ��������

	SetupRC();						// ��ʼ������
	glutDisplayFunc(RenderScene);	// ��ʾ���� ���ڻ�ͼ
	glutReshapeFunc(ChangeSize);	// ���ڴ�С�ı䴦����
	glutSpecialFunc(SpecialKeys);	// ������������
	glutMouseFunc(mouseCB);			// ����⺯��
	glutMotionFunc(mouseMotionCB);	// ��괦����

	glutMainLoop();					// ��ʼ����

	return 0;
}