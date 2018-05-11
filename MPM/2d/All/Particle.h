#pragma once
#include <vector>
#include <math.h>
#include <Eigen/Dense>
#include<iostream>
#include"Parameters.h"
using namespace std;
using namespace Eigen;

class Particle 
{
public:
	bool volume_check;
	double volume, mass, density;
	/*double alpha;
	double delta_q;
	double q;
	double V_c;
	double Lambda;
	double Mu;*/
	int index;
	Vector2d position, velocity;
	Matrix2d def_elastic;//�����α��ݶ�
	Matrix2d def_plastic;//�����α��ݶ�
	Matrix2d svd_u, svd_v, svd_s;
	Matrix2d polar_r, polar_s;//���ֽ���
	Matrix2d velocity_gradient;//�ٶ��ݶ�
	Matrix2d B;//APIC�еķ������
	Vector2d grid_position;
	Vector2d weight_gradient[16];
	Vector3d color;
	double weights[16];//����õ㵽��Χ16������B����Ȩ��ֵ
	Particle();
	Particle(Vector2d pos, Vector2d vel, double mass, int num = 0, double lambda = 0,double mu = 0);
	virtual~Particle();

	virtual Matrix2d energyDerivative() = 0;
	virtual void Update() = 0;
	double random_number(double lo, double hi);
	/*void updatePos();
	void updateGradient();
	void applyPlasticity();
	const Matrix2d energyDerivative();
	Matrix2d Derivative(Matrix2d s);
	Matrix2d project();*/
};