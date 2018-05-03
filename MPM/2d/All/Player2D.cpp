#include"Player2D.h"

Player2D::Player2D()
{

}
Player2D::~Player2D()
{

}
void Player2D::Initial(int argc, char** argv)
{
	srand((int)time(0));
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutInit(&argc, argv);  //��GLUT���г�ʼ�����������������������GLUTʹ��֮ǰ����һ��
	glutCreateWindow("MPMElastic");
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//������ʾ��ʽ������GLUT_RGB��ʾʹ��RGB��ɫ����֮��Ӧ�Ļ���GLUT_INDEX����ʾʹ��������ɫ����GLUT_SINGLE��ʾʹ�õ����壬��֮��Ӧ�Ļ���GLUT_DOUBLE��ʹ��˫���壩
	glClearColor(0.9f, 0.9f, 0.9f, 1);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(3);
	glMatrixMode(GL_PROJECTION);
}

void Player2D::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glOrtho(0, VIEW_WIDTH, 0, VIEW_HEIGHT, 0, 1);


	//grid->draw();
	scene->Draw();
	glFlush();
}

void Player2D::Update()
{
	scene->Update();
	glutPostRedisplay();
}

//void Player2D::Show(int argc, char** argv)
//{
//
//	
//	Initial();
//	while (1)
//	{
//		Render();
//		scence->Update();
//	}
//	//glutDisplayFunc(&Render);
//	//glutIdleFunc(Update);
//	//glutIdleFunc(&(*scence).Update);
//	//glutMainLoop();
//}