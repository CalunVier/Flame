#pragma once
#include"Grid.h"
#include"ParticleCloud.h"
#include"Parameters.h"
#include<map>
//��һ��֮�����Ҫ�ģ���ΪҪ����SPH�����������кܶණ���Ͳ�Ӧ�ó�����
using namespace std;
class Scene
{
public:
	Scene(int resolution);
	~Scene();
	map<SDF*, ParticleType> SPaType;//����SDF����������
	Grid* grid;
	ParticleCloud* bar;
	int Resolution;
	bool source;
	int frames;

	bool key;
	int startframes, endframes;

	void Initial();
	void Update();
	void Draw();

	void AddObject(ParticleType Type, SDF* polygon, Vector2d velocity = Vector2d::Zero());//�����������ʱ��Ĭ�����ʼ�ٶ�Ϊ��
	void AddPolygon(SDFType Type, SDF* polygon);
	void AddSource(SDFType Type, SDF* polygon, ParticleType PType, Vector2d velocity);
};