#include <glut.h>
#include <GL.h>
#include <GLU.h>
#include <windows.h>
#include <math.h>

static double time = 0;

GLUquadricObj* cyl;

GLfloat R_Arm_x = 0;
GLfloat R_Arm_y = 0;
GLfloat L_Arm_x = 0;
GLfloat L_Arm_y = 0;
GLfloat R_Leg_x = 0;
GLfloat R_Leg_y = 0;
GLfloat L_Leg_x = 0;
GLfloat L_Leg_y = 0;
GLfloat L_Shoulder = 0;
GLfloat R_Shoulder = 0;


GLfloat line1 = 0;
GLfloat line2 = 0;

static int direction = 1;

int a = 0;
int b = 0;
int c = 0;

void glInit(void) {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_SMOOTH);
	glEnable(GL_LIGHTING);

	GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	GLfloat diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat position[] = { 400.0, 300.0, -700.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void DrawHead() {
	glTranslatef(0.0, 0.02, 0.0);
	glPushMatrix();
	cyl = gluNewQuadric();

	//赣府
	glColor3f(0.8, 1, 1);
	gluSphere(cyl, 0.20, 30, 10);

	//哭率 蓖
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(-0.12, 0.0, -0.17);
	glRotatef(35.0, 0.0, 1.0, 0.0);
	gluSphere(cyl, 0.05, 30, 10);
	glPopMatrix();
	glPushMatrix();

	//坷弗率 蓖
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.12, 0.0, -0.17);
	glRotatef(-35.0, 0.0, 1.0, 0.0);
	gluSphere(cyl, 0.05, 30, 10);
	glPopMatrix();
	glPushMatrix();
	
	//哭率 传
	glTranslatef(-0.06, 0.03, -0.18);
	glColor3f(0.0, 0.0, 0.0);
	gluSphere(cyl, 0.015, 30, 10);
	glPopMatrix();
	glPushMatrix();

	//坷弗率 传
	glTranslatef(0.06, 0.03, -0.18);
	glColor3f(0.0, 0.0, 0.0);
	gluSphere(cyl, 0.015, 30, 10);
	glPopMatrix();
	glPushMatrix();

	//哭率 传界
	glRotatef(15.0, 0.0, 1.0, 0.0);
	glTranslatef(0.03, 0.07, -0.2);

	glRotatef(-90.0, 0.0, 1.0, 0.0);
	gluCylinder(cyl, 0.008, 0.008, 0.08, 26, 13);
	glPopMatrix();
	glPushMatrix();

	//坷弗率 传界
	glRotatef(-15.0, 0.0, 1.0, 0.0);
	glTranslatef(-0.03, 0.07, -0.2);

	glRotatef(90.0, 0.0, 1.0, 0.0);
	gluCylinder(cyl, 0.008, 0.008, 0.08, 26, 13);
	glPopMatrix();
	glPushMatrix();

	//内
	glTranslatef(0.0, -0.02, -0.18);
	glColor3f(0.0, 0.0, 0.0);
	gluSphere(cyl, 0.025, 30, 10);
	glPopMatrix();
	glPushMatrix();

	//倔奔
	glColor3f(0.83, 0.59, 0.17);
	glTranslatef(0.0, 0.00, -0.01);
	gluSphere(cyl, 0.195, 30, 13);
	glPopMatrix();
	glPushMatrix();

	//哭率涝
	glTranslatef(-0.02, -0.04, -0.17);
	glColor3f(1.0, 1.0, 1.0);
	gluSphere(cyl, 0.036, 30, 10);
	glPopMatrix();
	glPushMatrix();

	//坷弗率率涝
	glTranslatef(0.02, -0.04, -0.17);
	glColor3f(1.0, 1.0, 1.0);
	gluSphere(cyl, 0.036, 30, 10);
	glPopMatrix();
	
}

void DrawNeck() {
	glPushMatrix();
	glColor3f(0.8, 1, 1);
	cyl = gluNewQuadric();

	glTranslatef(0.0, -0.3, 0.0);
	gluSphere(cyl, 0.15, 30, 13);
	glPopMatrix();
}

void DrawHip() {
	glPushMatrix();
	cyl = gluNewQuadric();
	glColor3f(0.83, 0.59, 0.17);

	glTranslatef(0.0, -0.36, 0.0);
	gluSphere(cyl, 0.15, 30, 13);
	glPopMatrix();
}

void DrawBody(int x, int a, int b, int c) {
	glPushMatrix();
	glColor3f(0.8, 1, 1);
	cyl = gluNewQuadric();

	//个烹
	glTranslatef(0.0, -0.3, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluCylinder(cyl, 0.15, 0.15, 0.06, 26, 13);
	glPopMatrix();
	glPushMatrix();

	//哭率临
	glColor3f(1, 1, 1);
	glRotatef(10, 1.0, 0.0, 0.0);
	glTranslatef(-0.02, -0.2, -0.1);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glRotatef(x, 1, b, c);
	gluCylinder(cyl, 0.01, 0.01, 0.1, 26, 13);
	glPopMatrix();
	glPushMatrix();

	glColor3f(0.8, 1, 1);
	glTranslatef(-0.02, -0.2, -0.1);
	glRotatef(x, 1, b, c);
	glTranslatef(0.02, 0.2, 0.1);
	glRotatef(10, 1.0, 0.0, 0.0);
	glTranslatef(-0.02, -0.27, -0.1);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluSphere(cyl, 0.02, 30, 13);
	glPopMatrix();
	glPushMatrix();

	//坷弗率临
	glColor3f(1, 1, 1);
	glRotatef(10, 1.0, 0.0, 0.0);
	glTranslatef(0.02, -0.2, -0.1);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glRotatef(a, 1, b, c);
	gluCylinder(cyl, 0.01, 0.01, 0.1, 26, 13);
	glPopMatrix();
	glPushMatrix();

	glColor3f(0.8, 1, 1);
	glTranslatef(0.02, -0.2, -0.1);
	glRotatef(a, 1, b, c);
	glTranslatef(-0.02, 0.2, 0.1);
	glRotatef(10, 1.0, 0.0, 0.0);
	glTranslatef(0.02, -0.27, -0.1);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluSphere(cyl, 0.02, 30, 13);
	glPopMatrix();
}

void DrawL_Shoulder(int x, int a, int b, int c) {
	glPushMatrix();
	cyl = gluNewQuadric();
	glColor3f(0.8, 1, 1);

	glRotatef(x, a, b, c);
	glTranslatef(-0.12, -0.215, 0.0);
	gluSphere(cyl, 0.05, 30, 13);
	glPopMatrix();
}

void DrawR_Shoulder(int x, int a, int b, int c) {
	glPushMatrix();
	cyl = gluNewQuadric();
	glColor3f(0.8, 1, 1);

	glRotatef(x, a, b, c);
	glTranslatef(0.12, -0.215, 0.0);
	gluSphere(cyl, 0.05, 30, 13);
	glPopMatrix();
}

void DrawL_Arm(int x, int a, int b, int c) {
	glPushMatrix();
	cyl = gluNewQuadric();
	glColor3f(0.8, 1, 1);

	glTranslatef(-0.12, -0.215, 0.0);
	glRotatef(x, -1, 0, 0);
	glRotatef(-30.0, 0, 0, 1.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluCylinder(cyl, 0.05, 0.05, 0.15, 26, 13);
	glPopMatrix();
}

void DrawR_Arm(int x, int a, int b, int c) {
	glPushMatrix();
	cyl = gluNewQuadric();
	glColor3f(0.8, 1, 1);

	glTranslatef(0.12, -0.215, 0.0);
	glRotatef(x, -1, 0, 0);
	glRotatef(30.0, 0, 0, 1.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluCylinder(cyl, 0.05, 0.05, 0.15, 26, 13);
	glPopMatrix();
}

void DrawL_Hand(int x, int a, int b, int c) {
	glPushMatrix();
	cyl = gluNewQuadric();
	glColor3f(0.83, 0.59, 0.17);

	glTranslatef(-0.12, -0.215, 0.0);
	glRotatef(x, -1, 0, 0);
	glTranslatef(0.12, 0.215, 0.0);
	glTranslatef(-0.195, -0.3449, 0.0);
	gluSphere(cyl, 0.05, 30, 13);
	glPopMatrix();
}

void DrawR_Hand(int x, int a, int b, int c) {
	glPushMatrix();
	cyl = gluNewQuadric();
	glColor3f(0.83, 0.59, 0.17);

	glTranslatef(-0.12, -0.215, 0.0);
	glRotatef(x, -1, 0, 0);
	glTranslatef(0.12, 0.215, 0.0);
	glTranslatef(0.195, -0.3449, 0.0);
	gluSphere(cyl, 0.05, 30, 13);
	glPopMatrix();
}

void DrawL_Leg(int x, int a, int b, int c) {
	glPushMatrix();
	cyl = gluNewQuadric();
	glColor3f(0.83, 0.59, 0.17);

	glTranslatef(-0.085, -0.4, -0.03);
	glRotatef(x, a, b, c);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluCylinder(cyl, 0.055, 0.055, 0.15, 26, 13);
	glPopMatrix();
}

void DrawR_Leg(int x, int a, int b, int c) {
	glPushMatrix();
	cyl = gluNewQuadric();
	glColor3f(0.83, 0.59, 0.17);

	glTranslatef(0.085, -0.4, -0.03);
	glRotatef(x, a, b, c);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	gluCylinder(cyl, 0.055, 0.055, 0.15, 26, 13);
	glPopMatrix();
}

void DrawL_Foot(int x, int a, int b, int c) {
	glPushMatrix();
	cyl = gluNewQuadric();
	glColor3f(0.83, 0.59, 0.17);

	glTranslatef(-0.085, -0.4, -0.03);
	glRotatef(x, 1, 0, 0);
	glTranslatef(0.085, 0.4, 0.03);

	glTranslatef(-0.085, -0.55, -0.03);
	gluSphere(cyl, 0.055, 30, 13);
	glPopMatrix();
}

void DrawR_Foot(int x, int a, int b, int c) {
	glPushMatrix();
	cyl = gluNewQuadric();
	glColor3f(0.83, 0.59, 0.17);

	glTranslatef(0.085, -0.4, -0.03);
	glRotatef(x, 1, 0, 0);
	glTranslatef(-0.085, 0.4, 0.03);

	glTranslatef(0.085, -0.55, -0.03);
	gluSphere(cyl, 0.055, 30, 13);
	glPopMatrix();
}

void DrawRyan() {
	if (direction == 1)
		gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);
	else if (direction == 2)
		gluLookAt(0, 0, 0, 1, 0, 0, 0, 1, 0);
	else if (direction == 3)
		gluLookAt(0, 0, 0, 0, 0, 1, 0, 1, 0);
	else
		gluLookAt(0, 0, 0, -1, 0, 0, 0, 1, 0);

	DrawBody(line1, line2, 0, 0);
	DrawNeck();
	DrawHead();
	DrawHip();
	DrawL_Shoulder(L_Shoulder, 1, 0, 0);
	DrawR_Shoulder(R_Shoulder, 1, 0, 0);
	DrawL_Arm(L_Arm_x, 1, 0, 0);
	DrawL_Hand(L_Arm_y, 1, 0, 0);
	DrawR_Arm(R_Arm_x + 180, 1, 0, 0);
	DrawR_Hand(R_Arm_y + 180, 1, 0, 0);
	DrawL_Leg(L_Leg_x, 1, 0, 0);
	DrawR_Leg(R_Leg_x, 1, 0, 0);
	DrawL_Foot(L_Leg_y, 1, 0, 0);
	DrawR_Foot(R_Leg_y, 1, 0, 0);
}

void Run() {
	glLoadIdentity();
	
	L_Arm_x = time * 50;
	L_Arm_y = L_Arm_x;
	R_Arm_x = L_Arm_x;
	R_Arm_y = R_Arm_x;

	R_Leg_y = sin(time) * 35;
	L_Leg_y = -R_Leg_y;
	R_Leg_x = sin(time) * 35;
	L_Leg_x = -R_Leg_x;
	
	line1 = fabs(sin(time) * 20);
	line2 = fabs(cos(time) * 20);

	cyl = gluNewQuadric();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	
	glRotatef(30, -1, 0, 0);
	glRotatef(fabs(sin(time) * 10), 1, 0, 0);
	glRotatef(sin(time) * 10, 0, 1, 0);

	float i = 0;
	i = fabs(sin(time)*0.08);
	glPushMatrix();
	glTranslatef(0.0, i, 0);
	
	glTranslatef(0.0, 0.5, 0.0);
	DrawRyan();
	glutSwapBuffers();
}

void MyKeyboard(unsigned char KeyPressed, int x, int y) {
	switch (KeyPressed) {
	case 'd':
		direction = 4;
		break;
	case 'a':
		direction = 2;
		break;
	case 'w':
		direction = 3;
		break;
	case 's':
		direction = 1;
		break;

	}
}

void MyTimer(int Value) {
	time = time + 0.1;
	glutPostRedisplay();
	glutTimerFunc(15, MyTimer, 1);
}

void MyDisplay() {
	Run();
	glPopMatrix();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("RYAN");
	glInit();
	glutTimerFunc(15, MyTimer, 1);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();

	return 0;
}