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
	int num_s;//与之最近的线段编号
	int num_e;
} SDFinfo;

class SDF 
{
public:
	std::vector<Vector2d> vertices;//存放多边形顶点
	std::vector<Vector2d> velocity;//存放顶点的速度
	Vector2d v_center;
	SDF();
	~SDF();
	double omega;
	
	
	//SDF与其他
	SDFinfo Distance(Vector2d point);//计算点到多边形的距离
	Vector2d Gradient(double x, double y);//计算该点处的梯度
	int Contains(double x, double y);//查看某点是否在多边形内部
	Vector2d SDFveloctiy(double x, double y);//获取临近点

	//SDF自身特性
	void Insert(double x, double y,Vector2d v= Vector2d::Zero());//新增一个顶点
	void Update(double DT);//更新多边形顶点位置、速度
	void Draw();//绘制，有OpenGL才行
	void Initialize();


	//SDF子类
	double SegmentSDF(double x, double y, double sx, double sy, double ex, double ey);//计算点到线段的最短距离
private:
	Vector2d center;//纯几何图形的质心位置 
	Vector2d Rotate(Vector2d p, double theata);
	
};