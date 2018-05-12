#include<iostream>
#include<math.h>
#include<time.h>
#include"Parameters.h"
#include"SDF.h"
#include"Player2D.h"
#include"ParallelRender.h"
#include"File.h"
#include"Scene.h"
#include"Render2D.h"
#include"MarchingCube.h"
using namespace std;
using namespace tbb;


int main(int argc, char** argv)
{
	File file;
	file.ParametersIn();
	
	Player2D player;
	Scene sc;
	sc.Initial();
	player.Initial(argc, argv);
	player.scene = &sc;
	SDF a;
	a.Insert(1.3, 2.6);
	a.Insert(2.3, 2.6);
	a.Insert(2.3, 3.6);
	a.Insert(1.3, 3.2);

	sc.AddObject(SAND, &a);
	//SDF b;
	//b.Insert(1.3, 2.6);
	//b.Insert(2.3, 2.6);
	//b.Insert(2.3, 3.6);
	//b.Insert(1.3, 3.2);
	SDF c;
	c.Insert(0.5, 0.5);
	c.Insert(0.5, 4.5);
	c.Insert(4.5, 4.5);
	c.Insert(4.5, 0.5);
	SDF d;
	d.Insert(1.2, 1.6);
	d.Insert(1.6, 2.0);
	d.Insert(2.0, 1.6);
	d.Insert(1.6, 1.2);
	//sc.AddObject(ELASTIC, &b);
	sc.AddPolygon(Boundary, &c);
	sc.AddPolygon(Object, &d);
	while (1)
	{
		player.Render();
		sc.Update();
	}
	
	//�ļ����
	/*file.Initial();
	int i = 0;
	while (1)
	{
		sc.Update();
		file.FileOut(i, *sc.bar);
		i++;
	}*/

	//clock_t start, end;
	//int x = 400, y = 400; 

	//Render2D render(x, y);
	//
	//File file;
	//file.ParametersIn();
	//vector<Vector2d> p;
	//file.FileIn(237, p);
	//render.CanvasDraw(p);
	//MarchingCube mc;
	//mc.Polygon(render.canvas);
	//Player2D player;
	////����չʾ
	//player.Initial(argc, argv);
	//while (1)
	//{
	//	player.DrawSDF(mc.polygons[0]);
	//	//player.DrawSurface();
	//}


	//SDF sdf(x,y);
	//sdf.Insert(100, 100);
	//sdf.Insert(200, 100);
	//sdf.Insert(200, 200);
	//sdf.Insert(100, 200);*/
	////sdf.Insert(80, 150);
	//sdf.Insert(1, 1);
	//sdf.Insert(2, 1);
	//sdf.Insert(2, 2);
	//sdf.Insert(1, 2);*/
	////sdf.GirdInitial();
	//
	////cout << sdf.GridDistance(99, 99.6) << endl;
	////cout << sdf.GridDistance(0, 0.6) << endl;
	//mc.polygons[0].GirdInitial();
	//render.sdf = &mc.polygons[0];
	//
	//
	////render.sdf = &sdf;
	//

	//start = clock();
	//const int n = x*y;
	//int* a;
	//a = (int *)malloc(n * sizeof(int));
	//for (int i = 0; i < n; i++)
	//{
	//	a[i] = i;
	//	//render.PixelCalculate(i);
	//}
	//
	//
	//parallel_for(blocked_range<size_t>(0, n), ParallelRender(a, &render), simple_partitioner());
	//end = clock();
	//cout << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
	//render.CanvasShow();


	//��ͼ
		//File file;
		//file.ParametersIn();
		//
		//Player2D player;
		//Scene sc;
		//sc.Initial();
		//
		//
		////����չʾ
		//player.Initial(argc, argv);
		////player.scene = &sc;
		//////
		////while (1)
		////{
		////	player.Render();
		////	sc.Update();
		////}
	
	
		////���Ʊ߽�
		//Render2D r(500, 500);
		//vector<Vector2d> p;
		//file.FileIn(237, p);
		////file.FileIn(i, *sc.bar);
		////cout << sc.bar->particles[14].position[1] << endl;
	
	
		//r.CanvasDraw(p);
	
		//player.render = &r;
		//while (1)
		//{
		//	player.DrawSDF();
		//	//player.DrawSurface();
		//}


}




//#include <iostream>
//#include"File.h"
//#include"Scene.h"
//#include"Player2D.h"
//#include"Render2D.h"
//#include"SDF.h"
//#include<tbb/task_scheduler_init.h>
//#include<tbb/blocked_range.h>
//#include<tbb/parallel_for.h>
//
//using namespace std;
//using namespace tbb;
//int main(int argc, char** argv)
//{
//
//	/*SDF sdf;
//	sdf.Insert(100, 100);
//	sdf.Insert(200, 100);
//	sdf.Insert(200, 200);
//	sdf.Insert(100, 200);
//	sdf.Insert(80, 150);
//	double max = 0;
//	Render2D render(400, 400);
//	render.sdf = &sdf;
//	const int n = 160000;
//	int a[n];
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = i;
//	}
//	parallel_for(blocked_range<size_t>(0, n), ParallelRender(a, &render), simple_partitioner());
//	render.CanvasShow();*/
//
//	File file;
//	file.ParametersIn();
//	
//	Player2D player;
//	Scene sc;
//	sc.Initial();
//	
//	
//	//����չʾ
//	player.Initial(argc, argv);
//	//player.scene = &sc;
//	////
//	//while (1)
//	//{
//	//	player.Render();
//	//	sc.Update();
//	//}
//
//
//	//���Ʊ߽�
//	Render2D r(500, 500);
//	vector<Vector2d> p;
//	file.FileIn(237, p);
//	//file.FileIn(i, *sc.bar);
//	//cout << sc.bar->particles[14].position[1] << endl;
//
//
//	r.CanvasDraw(p);
//
//	player.render = &r;
//	while (1)
//	{
//		player.DrawSDF();
//		//player.DrawSurface();
//	}
//	//r.CanvasOutput(237);
//
//	//int i = 0;
//	//while (1)
//	//{
//	//	vector<Vector2d> p;
//	//	file.FileIn(i, p);
//	//	//file.FileIn(i, *sc.bar);
//	//	//cout << sc.bar->particles[14].position[1] << endl;
//
//	//	r.CanvasDraw(p);
//	//	r.CanvasOutput(i);
//	//	    //r.CanvasShow();
//	//	r.CanvasClear();
//	//	p.clear();
//	////	player.Render();
//	//	i++;
//	//	//sc.Update();
//	//}
//
//
//	//�ļ����
//	//file.Initial();
//	//int i = 0;
//	//while (1)
//	//{
//	//	sc.Update();
//	//	file.FileOut(i, *sc.bar);
//	//	i++;
//	//}
//
//
//
//	//show(argc,  argv);
//	//Sleep(5);
//	//srand((int)time(0));
//	//glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
//	//glutInitWindowPosition(0, 0);
//	//glutInit(&argc, argv);  //��GLUT���г�ʼ�����������������������GLUTʹ��֮ǰ����һ��
//	//glutCreateWindow("MPMElastic");
//	//glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//������ʾ��ʽ������GLUT_RGB��ʾʹ��RGB��ɫ����֮��Ӧ�Ļ���GLUT_INDEX����ʾʹ��������ɫ����GLUT_SINGLE��ʾʹ�õ����壬��֮��Ӧ�Ļ���GLUT_DOUBLE��ʹ��˫���壩
//	//InitGL();
//	//InitMPM();
//	//glutDisplayFunc(Render);
//	//glutIdleFunc(Update);
//	//glutMainLoop();
//	return 0;
//}
