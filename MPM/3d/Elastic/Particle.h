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
	float volume, mass, density;
	Vector3f position, velocity;
	Matrix3f def_elastic;//�α��ݶ�
	Matrix3f svd_u, svd_v, svd_s;
	Matrix3f polar_r, polar_s;//���ֽ���
	Matrix3f velocity_gradient;//�ٶ��ݶ�
	Vector3f grid_position;
	Vector3f weight_gradient[64];
	float weights[64];//����õ㵽��Χ16������B����Ȩ��ֵ
	Particle();
	Particle(Vector3f pos, Vector3f vel, float mass);
	~Particle();
	void updatePos();
	void updateGradient();
	void applyPlasticity();
	const Matrix3f energyDerivative();
};