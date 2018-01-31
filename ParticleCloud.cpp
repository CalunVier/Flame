#include"ParticleCloud.h"

ParticleCloud::ParticleCloud()
{

}
ParticleCloud::ParticleCloud(int cloud_size)
{
	size = cloud_size;
	particles.reserve(size);
}
ParticleCloud::~ParticleCloud()
{

}

void ParticleCloud::update()
{
	for (int i = 0; i<size; i++) 
	{
		particles[i].updatePos();
		particles[i].updateGradient();
		particles[i].applyPlasticity();
#ifdef debs
		//if (ji >= 52)
		//{
		//	cout << ji << "  " << i << "  " << particles[i].position[0] << "  " << particles[i].position[1] << endl;
		//}
#endif // deb

		
	}
}

void ParticleCloud::merge(const ParticleCloud& other)
{
	size += other.size;
	particles.reserve(size);
	particles.insert(particles.end(), other.particles.begin(), other.particles.end());
}

void ParticleCloud::draw()
{
	glColor3f(0.1, 0.1, 1);
	glPointSize(4);
	glBegin(GL_POINTS);

	for (int i = 0; i < size; i++)
	{
		glVertex2f(particles[i].position[0], particles[i].position[1]);
	}
	glEnd();
}

void ParticleCloud::output()
{
	//ͨ�����ԣ��ؽ���������������µ��ڸ����ռ����������ӷֲ�Խ�ܣ�������ռ���ԽС
	float va,m;
	for (int i = 0; i < size; i++)
	{
		va += particles[i].volume;
		m += particles[i].mass;
		//cout << particles[i].mass << endl;
	}
	cout << va << endl;
	cout << m << endl;
}