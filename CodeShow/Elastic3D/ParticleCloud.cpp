#include"ParticleCloud.h"
#include <fstream>  
#include<sstream>

ParticleCloud::ParticleCloud()
{

}
ParticleCloud::ParticleCloud(int cloud_size)
{
	size = cloud_size;
	particles.reserve(size);
	frame = 0;
}
ParticleCloud::~ParticleCloud()
{

}
//�������������У��������йص�����
void ParticleCloud::update()
{
	//���ڵ������Ӷ��ԣ������������������������ģ�����λ�ã������α��ݶȣ����α��ݶȼ���SVD
	for (int i = 0; i<size; i++) 
	{
		particles[i].updatePos();
		particles[i].updateGradient();
		particles[i].applyPlasticity();
	}
}

void ParticleCloud::merge(const ParticleCloud& other)
{
	size += other.size;
	particles.reserve(size);
	particles.insert(particles.end(), other.particles.begin(), other.particles.end());
}

void ParticleCloud::fileout()
{
	ofstream outfile, fout;
	string over = ".txt";
	stringstream ss;
	string str;
	ss << frame;
	ss >> str;
	str += over;
	outfile.open(str);
	outfile << particles.size() << endl;
	for (int i = 0; i < particles.size(); i++)
	{
		outfile << particles[i].position(0) << " " << particles[i].position(1) << " " << particles[i].position(2) << endl;
	}
	//outfile << "PPS Make and model: " << endl;  //�����д�뵽�ļ��У�����cout�ĺ�����������  
	outfile.close();
	frame++;
}