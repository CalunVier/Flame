#pragma once
#include <vector>
#include <math.h>
#include <GL/freeglut.h>
#include <Eigen/Dense>
#include<iostream>
#include"ParticleCloud.h"
#include"SDF.h"

using namespace std;
using namespace Eigen;
const double BSPLINE_EPSILON = 1e-12;
const int BSPLINE_RADIUS = 2;

typedef struct GridNode {
	double mass;
	bool active;
	bool collision;
	Vector2d velocity, velocity_new, velocity_out;
	Vector2d position;
	Vector2d normal;
	GridNode()
	{
		collision = false;
		normal = Vector2d::Identity();
	}
} GridNode;

class Grid 
{
public:
	Vector2d start, end, size, cellsize;
	double Time;
	vector<SDF*> polygon;//�����߽磬����
	int nodes_length;//�������
	double node_area;//�������
	GridNode* nodes;
	ParticleCloud* obj;
	Grid(Vector2d pos, Vector2d dims, Vector2d cells, ParticleCloud* object);
	~Grid();

	void initializeMass();
	void initializeVelocities();
	void calculateVolumes() const;
	//ParticleCloud* InitVolume();
	void explicitVelocities(const Vector2d& gravity);
	void updateVelocities();
	void collisionGrid();
	void collisionParticles() const;
	void Friction();
	void draw();
	void output();
	static double bspline(double x)
	{
		x = fabs(x);
		double w;
		if (x < 1)
			w = x*x*(x / 2 - 1) + 2 / 3.0;
		else if (x < 2)
			w = x*(x*(-x / 6 + 1) - 2) + 4 / 3.0;
		else return 0;
		//Clamp between 0 and 1... if needed
		if (w < BSPLINE_EPSILON) return 0;
		return w;
	}
	//Slope of interpolation function
	//��B������
	static double bsplineSlope(double x)
	{
		double abs_x = fabs(x);
		if (abs_x < 1)
			return 1.5*x*abs_x - 2 * x;
		else if (x < 2)
			return -x*abs_x / 2 + 2 * x - 2 * x / abs_x;
		else return 0;
		//Clamp between -2/3 and 2/3... if needed
	}
};