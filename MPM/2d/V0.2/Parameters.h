#pragma once
#include <Eigen/Dense>
#include<tbb/task_scheduler_init.h>
#include<tbb/blocked_range.h>
#include<tbb/parallel_for.h>
extern int SOLVER_STEPS;
const static int fps = 40;
extern double DT;//ÿһ����ʱ��CFL����
const static int WINDOW_WIDTH = 700;//��ʾ����
const static int WINDOW_HEIGHT = 700;
const static double VIEW_WIDTH = 5.0f;//�о����򣬶���Ҫ�ɱ���
const static double VIEW_HEIGHT = WINDOW_HEIGHT*VIEW_WIDTH / WINDOW_WIDTH;
extern double lambda; 
extern double mu;
extern double STICKY;
extern double h0;
extern double h1;
extern double h2;
extern double h3;
extern double mass;
extern int insert_time;
extern double p_start_x, p_start_y, p_size_x, p_size_y, r;
extern int iteratime, endtime;
extern Eigen::Vector2d gravity;
extern double start_x, start_y, end_x, end_y, g;
extern int size_x, size_y;
#define M_PI 3.14159265358
#define deb true