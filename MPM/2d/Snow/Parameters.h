#pragma once
#define debs false
const static int SOLVER_STEPS = 30;
const static int fps = 40;
static double DT = ((1.0f / fps) / SOLVER_STEPS);//ÿһ����ʱ��CFL����
const static int WINDOW_WIDTH = 700;//��ʾ����
const static int WINDOW_HEIGHT = 700;
const static double VIEW_WIDTH = 5.0f;//�о����򣬶���Ҫ�ɱ���
const static double VIEW_HEIGHT = WINDOW_HEIGHT*VIEW_WIDTH / WINDOW_WIDTH;
const static double lambda = 5000.0f; 
const static double mu = 5000.0f;
const static double EPS = 0.0000001f;//��С���룬С�ڴˣ���Ϊ����
const static double EPS2 = EPS*EPS;
const static double FLIP_PERCENT = .95;//FLIP�ڴ˴�Ч���ƺ�Ч�����Ǻܺ�
const static double CRIT_COMPRESS = 1 - 3.9e-2;
const static double CRIT_STRETCH = 1 + 7.5e-3;
const static double HARDENING = 4.0;
const static double STICKY = 0.6;
extern int ji;
