#include<iostream>
#include<math.h>
#include<time.h>
#include"../include/common/Parameters.h"
#include"../include/geometry/SDFObject.h"
#include"../include/common/File.h"
#include"../include/scene/Scene.h"
#include"../include/render/Render2D.h"
#include"../include/visual/UI2D.h"
#include"../include/simulation/Simulator.h"
using namespace std;

int main()
{
	//��������
	ParametersInput();

	Scene sc;

	//��ӱ߽�
	SDFBoundary c(0, Boundary);
	c.sdfName = "bond";
	c.Insert(0.3, 0.3);
	c.Insert(0.3, 4.7);
	c.Insert(4.7, 4.7);
	c.Insert(4.7, 0.3);
	sc.AddObject(&c);

	//��Ӳ����߽����漸�ֶ�����
	SDFSampleBound d(0, WATER, BOUNDSDF_P);
	d.sdfName = "particle water";
	d.Insert(2.3, 0.5);
	d.Insert(2.3, 1.5);
	d.Insert(3.3, 1.5);
	d.Insert(3.3, 0.5);
	sc.AddObject(&d);

	SDFSampleBound e(0, WETSAND, BOUNDSDF_P);
	e.sdfName = "particle sand";
	e.Insert(3.5, 0.5);
	e.Insert(3.5, 1.5);
	e.Insert(4.3, 1.5);
	e.Insert(4.3, 0.5);
	sc.AddObject(&e);

	//ģ������ʼ��
	Simulator sim;
	sim.SimulatorInitial(&sc, MPMMulti, EXPLICIT);

	int i = 0;
	//��Ⱦ����ʼ����UI��ʾ
	Render2D render(WINDOW_HEIGHT, WINDOW_WIDTH);
	UI2D ui;
	while (1)
	{
		sim.SimulatorUpdate();
		render.CanvasDraw(&sc);
		ui.UIShow(&render.canvas);
		render.CanvasClear();
		i++;
		cout << i << endl;
	}
}