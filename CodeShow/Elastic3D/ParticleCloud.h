#pragma once
#include"Particle.h"
using namespace std;
using namespace Eigen;
//�������������ŵĲ�����
class ParticleCloud 
{
public:
	
	vector<Particle> particles;
	int size;
	int frame;
	ParticleCloud();
	ParticleCloud(int cloud_size);
	~ParticleCloud();
	void update();//�������������У��������йص�����
	void merge(const ParticleCloud& other);//�����ŵĺϲ�����

	//�����ƵĹ��죨�˴���ģ�µı��˵Ĵ��룩
	static ParticleCloud* Insert(std::vector<Particle> points)
	{
		ParticleCloud *obj = new ParticleCloud(points.size());

		for (int i = 0; i < points.size(); i++)
		{
			obj->particles.push_back(points[i]);
		}
		return obj;
	}
	void fileout();//���������е�������Ϣ��txt�ļ����
};