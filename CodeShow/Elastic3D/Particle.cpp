#include"Particle.h"
Particle::Particle()
{

}
Particle::Particle(Vector3f pos, Vector3f vel, float mass)
{
	position = pos;
	velocity = vel;
	this->mass = mass;
	def_elastic = Matrix3f::Identity();
	svd_u = Matrix3f::Identity();
	svd_v = Matrix3f::Identity();
	svd_s = Matrix3f::Identity();
	polar_r = Matrix3f::Identity();
	polar_s = Matrix3f::Identity();
	B = Matrix3f::Zero();
}
Particle::~Particle()
{

}
//��������λ��
void Particle::updatePos()
{
	position += DT*velocity;
}
//�α��ݶȵĸ���
void Particle::updateGradient()
{
	velocity_gradient *= DT;
	velocity_gradient = velocity_gradient+Matrix3f::Identity();
	def_elastic = velocity_gradient * def_elastic;
}

//������������ʱ�Ĺؼ���
const Matrix3f Particle::energyDerivative()
{
	
	float Je = def_elastic.determinant();
	Matrix3f out;
	//������ı���ģ�����£�
	Matrix3f first = 2 * mu*(def_elastic - svd_u*svd_v.transpose())*def_elastic.transpose();//�����mu��һ������
	Matrix3f second = lambda*Je*(Je - 1)*Matrix3f::Identity();//�����lamda��һ������
	out = first + second;
	return volume * out;

}

//���α��ݶȽ���SVD�ֽ�
void Particle::applyPlasticity()
{
	JacobiSVD<Eigen::MatrixXf>svd(def_elastic, ComputeThinU | ComputeThinV);
	svd_u = svd.matrixU();
	svd_v = svd.matrixV();
}