#pragma once
const static int SOLVER_STEPS = 10;
const static int fps = 40;
static double DT = ((1.0f / fps) / SOLVER_STEPS);//ÿһ����ʱ��CFL����

const static double lambda = 1000.0f;
//const static double mu = 8000.0f;
const static double EPS = 0.0000001f;//��С���룬С�ڴˣ���Ϊ��
const static double EPS2 = EPS*EPS;
const static double FLIP_PERCENT = .95;//FLIP�ڴ˴�Ч���ƺ�Ч�����Ǻܺ�
const static double HARDERN = 11000;
const static double GAMA = 7;
const static double STICKY = 0.2;
const static double throld = 0.6;
#define deb true