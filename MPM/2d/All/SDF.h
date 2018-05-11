#pragma once
#define EPSILON 0.01f
#include<Eigen/Dense>
#include<iostream>
#include<vector>
#include <GL/freeglut.h>

using namespace Eigen;

typedef struct
{
	double distance;
	int num_s;//��֮������߶α��
	int num_e;
} SDFinfo;

double CircleSDF(double x, double y, double c_x, double c_y, double r);
double PlaneSDF(double x, double y, double px, double py, double nx, double ny);//ƽ��
double SegmentSDF(double x, double y, double sx, double sy, double ex, double ey);
double CapsuleSDF(double x, double y, double sx, double sy, double ex, double ey, double r);
double BoxSDF(double x, double y, double cx, double cy, double theta, double sx, double sy);

class SDF
{
public:
	std::vector<Vector2d> vertices;//��Ŷ���ζ���
	std::vector<Vector2d> velocity;//��Ŷ�����ٶ�
	Vector2d v_center;
	SDF(); 
	SDF(int x, int y);
	~SDF();
	double omega;

	//��������SDF
	int grid_sizex,grid_sizey;
	double cell_sizex, cell_sizey;
	double* record;

	//SDF������
	SDFinfo Distance(Vector2d point);//����㵽����εľ���
	Vector2d Gradient(double x, double y);//����õ㴦���ݶ�
	int Contains(double x, double y);//�鿴ĳ���Ƿ��ڶ�����ڲ�
	Vector2d SDFveloctiy(double x, double y);//��ȡ�ٽ���

											 //SDF��������
	void Insert(double x, double y, Vector2d v = Vector2d::Zero());//����һ������
	void Update(double DT);//���¶���ζ���λ�á��ٶ� 
	void Draw();//���ƣ���OpenGL����
	void Initialize();
	void GirdInitial();
	double GridDistance(double x, double y);

private:
	Vector2d center;//������ͼ�ε�����λ�� 
	Vector2d Rotate(Vector2d p, double theata);

};