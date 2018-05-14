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
	float J;
	Vector2f position, velocity;
	Matrix2f def_elastic;//�α��ݶ�
	Matrix2f svd_u, svd_v, svd_s;
	Matrix2f polar_r, polar_s;//���ֽ���
	float velocity_gradient;//�ٶ��ݶ�
	Matrix2f B;//APIC�еķ������
	Vector2f grid_position;
	Vector2f weight_gradient[16];
	Vector3d color;
	float weights[16];//����õ㵽��Χ16������B����Ȩ��ֵ
	Particle();
	Particle(Vector2f pos, Vector2f vel, float mass);
	~Particle();
};