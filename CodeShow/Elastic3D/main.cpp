#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include"Parameters.h"
#include"Grid.h"
#include"ParticleCloud.h"
using namespace std;

int frame = 0;//��������ļ���Ϣ

Vector3f gravity = Vector3f(0, 0,-1.1);//������Ϣ
Grid* grid;//����
ParticleCloud* bar;//������

//�������ɱ�ģ�������
vector<Particle> sample(Vector3f start, Vector3f end, Vector3f size,Vector3f v)
{
	Vector3f cellsize;
	cellsize[0] = (end[0] - start[0]) / (size[0] - 1);//���x�򳤶�
	cellsize[1] = (end[1] - start[1]) / (size[1] - 1);//���y���򳤶�
	cellsize[2] = (end[2] - start[2]) / (size[2] - 1);//���z���򳤶�
	int length = size[0] * size[1] * size[2];
	vector<Particle> points(length);

	for (int i = 0; i < size[0]; i++)
		for (int j = 0; j < size[1]; j++)
			for (int k = 0; k < size[2]; k++)
				points[(int)(k*size[0] * size[1] + j*size[0] + i)] = Particle(start + Vector3f(cellsize[0] * i, cellsize[1] * j, cellsize[2] * k), v, 0.1);

	return points;
}


//�ڴ˴���ʼ������ģ�ⳡ��
void InitMPM()
{
	vector<Particle> points = sample(Vector3f(1.618, 1.618, 1.118), Vector3f(2.245, 2.245, 1.745), Vector3f(20, 20, 20), Vector3f(0, 0, 0));//��������
	bar = ParticleCloud::Insert(points);//��vector�е����Ӹ���������
	grid = new Grid(Vector3f(0, 0, 0), Vector3f(VIEW_WIDTH, VIEW_HEIGHT, VIEW_HEIGHT), Vector3f(100, 100, 100), bar);//����������grid��
	grid->initializeMass();	//��ʼ�����������������һ�������������
	grid->calculateVolumes();//�����������
}



int main(int argc, char** argv)
{
	//������ģ���������£�
	InitMPM();
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			grid->initializeMass();//���������ֵ
			grid->initializeVelocities();//����ٶȲ�ֵ
			grid->explicitVelocities(gravity);//����������ٶȸ��£�����Ϊ������
			grid->updateVelocities();//�������ӵ��ٶȡ��ٶ��ݶȡ��������
			bar->update();//�������ӵ��α��ݶ�
		}
		bar->fileout();//���������Ϣ
	}
}
