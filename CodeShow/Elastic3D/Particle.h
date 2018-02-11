#pragma once
#include <vector>
#include <math.h>
#include <Eigen/Dense>//Eigen�����·����ͬ����Ҫ����·��
#include<iostream>
#include"Parameters.h"
using namespace std;
using namespace Eigen;
//����Ϊ�����࣬�������ӵ������Լ�����صĲ���
class Particle 
{
public:
	float volume, mass, density;//������������ܶ�
	Vector3f position, velocity;//λ�á��ٶ�
	Matrix3f def_elastic;//�α��ݶ�
	Matrix3f svd_u, svd_v, svd_s;//���SVD�ֽ�Ľ��
	Matrix3f polar_r, polar_s;//���ֽ���
	Matrix3f velocity_gradient;//�ٶ��ݶ�
	Matrix3f B;//�������
	Vector3f grid_position;//���λ��
	Vector3f weight_gradient[64];//���ڴ�����ӵ���Χ64������Ȩ��
	float weights[64];//���ڴ�Ÿõ㵽��Χ16������B����Ȩ��ֵ
	Particle();
	Particle(Vector3f pos, Vector3f vel, float mass);//���ӹ��캯��
	~Particle();
	void updatePos();//��������λ��
	void updateGradient();//�α��ݶȵĸ���
	void applyPlasticity();//���α��ݶȽ���SVD�ֽ�
	const Matrix3f energyDerivative();//������������ʱ�Ĺؼ���
};