#include <iostream>
#include"File.h"
#include"Scene.h"
#include"Player2D.h"
#include"Render2D.h"
using namespace std;

int main(int argc, char** argv)
{
	File file;
	file.ParametersIn();
	
	Player2D player;
	Scene sc;
	sc.Initial();
	
	Render2D r(600, 600);

	//player.Initial(argc, argv);
	//player.scence = &sc;
	//


	int i = 0;
	while (1)
	{
		file.FileIn(i, *sc.bar);
		//cout << sc.bar->particles[14].position[1] << endl;

		r.CanvasDraw(sc.bar);
		r.CanvasOutput(i);
		//r.CanvasShow();
		r.CanvasClear();
	//	player.Render();
		i++;
		//sc.Update();
	}

	/*file.Initial();
	int i = 0;
	while (1)
	{
		sc.Update();
		file.FileOut(i, *sc.bar);
		i++;
	}*/



	//show(argc,  argv);
	//Sleep(5);
	//srand((int)time(0));
	//glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	//glutInitWindowPosition(0, 0);
	//glutInit(&argc, argv);  //��GLUT���г�ʼ�����������������������GLUTʹ��֮ǰ����һ��
	//glutCreateWindow("MPMElastic");
	//glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//������ʾ��ʽ������GLUT_RGB��ʾʹ��RGB��ɫ����֮��Ӧ�Ļ���GLUT_INDEX����ʾʹ��������ɫ����GLUT_SINGLE��ʾʹ�õ����壬��֮��Ӧ�Ļ���GLUT_DOUBLE��ʹ��˫���壩
	//InitGL();
	//InitMPM();
	//glutDisplayFunc(Render);
	//glutIdleFunc(Update);
	//glutMainLoop();
	return 0;
}
