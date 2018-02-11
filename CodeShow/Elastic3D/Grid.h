#pragma once
#include <vector>
#include <math.h>
#include <Eigen/Dense>//Eigen�����·����ͬ����Ҫ����·��
#include<iostream>
#include"ParticleCloud.h"
using namespace std;
using namespace Eigen;
const float BSPLINE_EPSILON = 1e-6;
const int BSPLINE_RADIUS = 2;

typedef struct GridNode//ÿ���������� 
{
	float mass;//�������
	bool active;//�ø���ڼ���ʱ�Ƿ�Ӧ�ñ�����
	Vector3f velocity, velocity_new;//����ٶ�
	Vector3f position;//�������λ��
} GridNode;

//����ࣺ�������ڸ��Ĳ�����
class Grid 
{
public:
	Vector3f start, end, size, cellsize;//������ʼλ�ã���ֹλ�ã���С��ÿ��Ĵ�С
	int nodes_length;//�������
	float node_area;//�������
	GridNode* nodes;//������и��
	ParticleCloud* obj;//�������࣬���ڸ������֮�����Ϣ����
	Grid(Vector3f pos, Vector3f dims, Vector3f cells, ParticleCloud* object);
	~Grid();

	void initializeMass();//�����������Ӳ�ֵ�����
	void initializeVelocities();//���ٶȴ����Ӳ�ֵ�����
	void calculateVolumes() const;//�������ӵ����
	void explicitVelocities(const Vector3f& gravity);//��ʽ�����������������¸����ٶ�
	void updateVelocities() const;//�������ӵ��ٶȣ��ٶ��ݶȣ��������
	void collisionGrid();//���ڸ��Ƕȵ���ײ��⣬��Ϊ�ֲ�
	void collisionParticles() const;//�������ӵ���ײ��⣬Ŀǰ�ѷϣ���֮����

	//��ֵ����
	static float bspline(float x)
	{
		x = fabs(x);
		float w;
		if (x < 1)
			w = x*x*(x / 2 - 1) + 2.0 / 3.0;
		else if (x < 2)
			w = x*(x*(-x / 6 + 1) - 2) + 4.0 / 3.0;
		else return 0;
		//Clamp between 0 and 1... if needed
		if (w < BSPLINE_EPSILON) return 0;
		return w;
	}

	//��B������
	static float bsplineSlope(float x)
	{
		float abs_x = fabs(x), w;
		if (abs_x < 1)
			return 1.5*x*abs_x - 2 * x;
		else if (x < 2)
			return -x*abs_x / 2 + 2 * x - 2 * x / abs_x;
		else return 0;
	}
};