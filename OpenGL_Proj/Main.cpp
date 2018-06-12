#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
using namespace std;

#define imageWidth 10
#define imageHeight 10

static GLubyte image[imageHeight][imageWidth][4];
static GLuint texName;

static GLfloat xrot = 0;
static GLfloat yrot = 0;

static bool mouseLeftDown;
static float mouseX;
static float mouseY;

void mouseCB(int button, int state, int x, int y) {
	mouseX = x;
	mouseY = y;

	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			mouseLeftDown = true;
		}
		else if (state == GLUT_UP)
			mouseLeftDown = false;
	}
}

void mouseMotionCB(int x, int y) {
	if (mouseLeftDown) {
		yrot += (x - mouseX) * 0.1f;
		xrot += (y - mouseY) * 0.1f;
		mouseX = x;
		mouseY = y;
	}
}

void makeCheckImage() {
	for (int i = 0; i < imageWidth; i++) {
		for (int j = 0; j <imageHeight; j++) {
			int r = (rand()) % 255;
			int g = (rand()) % 255;
			int b = (rand()) % 255;

			image[i][j][0] = (GLubyte)b;
			image[i][j][1] = (GLubyte)g;
			image[i][j][2] = (GLubyte)r;
			image[i][j][3] = (GLubyte)100;
		}
	}
}

void SetupRC(void) {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);


	GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);


	GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat high_shininess[] = { 100.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


	makeCheckImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void DrawWall(void) {
	glPushMatrix();
	glTranslated(1.2, 0.01, 1.2);
	glScaled(2.4, 0.02, 2.4);
	glutSolidCube(1.0);
	glPopMatrix();
}

void DrawPillar() {
	glPushMatrix();
	glTranslated(0, 0.15, 0);
	glScaled(0.02, 0.3, 0.02);
	glutSolidCube(1.0);
	glPopMatrix();
}

void DrawTable() {
	glPushMatrix();
	glTranslated(0.05, 0.3, 0.05);
	glScaled(0.6, 0.02, 0.6);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.275, 0, 0.275);
	DrawPillar();
	glTranslated(0, 0, -0.45);
	DrawPillar();
	glTranslated(-0.45, 0, 0.45);
	DrawPillar();
	glTranslated(0, 0, -0.45);
	DrawPillar();
	glPopMatrix();
}

void RenderScene() {
	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	const double a = t * 90.0;

	GLfloat light_position[] = { 2.0f, 6.0f, 3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat h = 1.0;
	glOrtho(-h * 64 / 48.0, h * 64 / 48.0, -h, h, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2, 1.6, 2, 0, 0.2, 0, 0, 1, 0);

	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// wall1
	glPushMatrix();
	glRotated(90.0, 0.0, 0.0, 1.0);
	glColor4f(0.968f, 0.792f, 0.788f, 1.0f);
	DrawWall();
	glPopMatrix();

	// wall2
	glPushMatrix();
	glRotated(-90.0, 1.0, 0.0, 0.0);
	glColor4f(0.968f, 0.792f, 0.788f, 1.0f);
	DrawWall();
	glPopMatrix();

	// table
	glPushMatrix();
	glTranslated(0.6, 0, 1.7);
	glRotated(a, 0, 1, 0);
	glColor4f(1.0f, 0.843f, 0.0f, 1.0f);
	DrawTable();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.2, 0.16, 0.4);
	glScaled(0.8, 0.8, 0.8);
	glRotated(-1.5* a, 0, 1, 0);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glutSolidCube(0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.9, 0.2, 0.9);
	glRotated(-100, 0, 1, 0);
	glRotated(5*a, 0, 1, 0);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glutSolidTeapot(0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.3, 0.33, 0.5);
	glRotated(180, 0, 180, 180);
	glRotated(1.6* a, 1, 0, 0);
	glColor4f(0.777f, 0.469f, 0.042f, 1.0f);
	glutSolidTorus(0.05f, 0.12, 25, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5, 0.7 + sin(a / 40) / 2, 0.3);
	glColor4f(0.441f, 0.637f, 0.354f, 1.0f);
	glutSolidSphere(0.1, 15, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.0, 0.7, 0.4);
	glRotated(0.9* a, 1, 0, 0);
	glRotated(180, 180, 0, 0);
	glColor4f(0.741f, 0.137f, 0.654f, 1.0f);
	glutSolidCone(0.15f, 0.25f, 30, 25);
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBegin(GL_QUADS);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 0.0, 2.4);
	glTexCoord2f(1.0, 1.0); glVertex3f(2.4, 0.0, 2.4);
	glTexCoord2f(1.0, 0.0); glVertex3f(2.4, 0.0, 0.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glutPostRedisplay();
	glFlush();
}

void SpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		xrot -= 1.0;
		break;
	case GLUT_KEY_DOWN:
		xrot += 1.0;
		break;
	case GLUT_KEY_LEFT:
		yrot -= 1.0;
		break;
	case GLUT_KEY_RIGHT:
		yrot += 1.0;
		break;
	default:
		break;
	}
}

void ChangeSize(int width, int height) {
	glViewport(0, 0, width, height);
}

int main(int argc, char *argv[]) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 600);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("����ķ���");

	SetupRC();
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);
	glutMouseFunc(mouseCB);
	glutMotionFunc(mouseMotionCB);

	glutMainLoop();

	return 0;
}