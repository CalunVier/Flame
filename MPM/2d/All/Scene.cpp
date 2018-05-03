
#include"Scene.h"

Scene::Scene()
{
	num = 0;
}

Scene::~Scene()
{
}

void Scene::Initial()
{
	int resulotion = 100;
	//double dx = 150.0f*0.018f / (double)resulotion;
	double dx = 0.025;
	end_x = start_x + dx*size_x;
	end_y = start_y + dx*size_y;
	bar = new ParticleCloud();
	//bar->InitialSample();
	grid = new Grid(Vector2d(0, 0), Vector2d(VIEW_WIDTH, VIEW_HEIGHT), Vector2d(resulotion, resulotion), bar);
	grid->initializeMass();
	grid->calculateVolumes();
}
void Scene::Update()
{
	for (int i = 0; i < SOLVER_STEPS; i++)
	{
		
		if (num % insert_time == 0 && num < endtime)
		{

			ParticleCloud* bar2;
			bar2 = new ParticleCloud();
			bar2->InitialSample();
			Grid*grid_temp;
			grid_temp = new Grid(Vector2d(0, 0), Vector2d(VIEW_WIDTH, VIEW_HEIGHT), Vector2d(100, 100), bar2);
			grid_temp->initializeMass();
			grid_temp->calculateVolumes();
			bar->merge(*grid_temp->obj);
		}
		num++;
		grid->initializeMass();
		grid->initializeVelocities();
		grid->explicitVelocities(gravity);
		grid->updateVelocities();
		bar->update();
	}
}

void Scene::Draw()
{
	grid->glass->Draw();
	bar->draw();
	
}