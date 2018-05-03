#include"ParticleCloud.h"

ParticleCloud::ParticleCloud()
{
	size = 0;
	p_num = 0;
}
ParticleCloud::ParticleCloud(int cloud_size)
{
	size = cloud_size;
	particles.reserve(size);
	p_num = 0;
}
ParticleCloud::~ParticleCloud()
{
}

void ParticleCloud::update()
{
	for (int i = 0; i<size; i++) {
		/*if (i == 0|| i == 29 )
		{
			cout << particles[i].velocity[0]<<"  "<< particles[i].velocity[1] << endl;
		}*/
		particles[i].updatePos();
		particles[i].updateGradient();
		particles[i].applyPlasticity();
	}
	//cout << endl;
}

void ParticleCloud::merge(ParticleCloud& other)
{
	size += other.size;
	for (int i = 0; i < other.particles.size(); i++){
		other.particles[i].index += p_num;
	}
	p_num += other.size;
	particles.reserve(size);
	particles.insert(particles.end(), other.particles.begin(), other.particles.end());
}

void ParticleCloud::copy(ParticleCloud other)
{
	//欠鲁棒
	size = other.size;
	particles.reserve(size);
	for (int i = 0; i < other.particles.size(); i++)
	{

	}
}

ParticleCloud* ParticleCloud::Insert(std::vector<Particle> points)
{
	ParticleCloud *obj = new ParticleCloud(points.size());

	for (int i = 0; i < points.size(); i++)
	{
		obj->particles.push_back(points[i]);
	}
	return obj;
}

void ParticleCloud::draw()
{
	glColor3f(0.1, 0.1, 1);
	glPointSize(3);
	glBegin(GL_POINTS);
	for (int i = 0; i < size; i++)
	{
		glVertex2f(particles[i].position[0], particles[i].position[1]);
	}
	glEnd();
}

void ParticleCloud::output()
{
	//通过测试，重建的粒子总体积大致等于格点所占体积，且粒子分布越密，粒子所占体积越小
	double va,m;
	for (int i = 0; i < size; i++)
	{
		va += particles[i].volume;
		m += particles[i].mass;
		//cout << particles[i].mass << endl;
	}
	cout << va << endl;
	cout << m << endl;
}

void ParticleCloud::InitialSample()
{
	vector<Particle> points;
	points = PossionSample(Vector2d(p_start_x, p_start_y), Vector2d(p_size_x, p_size_y), Vector2d(0.0, 0), r, iteratime);
	size = points.size();
	particles.reserve(size);
	for (int i = 0; i < points.size(); i++)
	{
		particles.push_back(points[i]);
	}
}



double ParticleCloud::random_number(double lo, double hi)
{
	return lo + rand() / (double)(RAND_MAX / (hi - lo));
}

vector<Vector2d> ParticleCloud::PossionDisc(double r, double start_x, double start_y, double x_length, double y_length, int k)
{
	vector<Vector2d> cloud;
	double grid_size = r / sqrt(2);
	int x_size = ceil(x_length / grid_size);
	int y_size = ceil(y_length / grid_size);

	int* Inside = new int[x_size*y_size];                                         //存放格子内是否有粒子
	memset(Inside, 0, sizeof(int)*x_size*y_size);
	Eigen::Vector2d* C;
	C = new Eigen::Vector2d[x_size*y_size];                                       //
	memset(C, 0, sizeof(Eigen::Vector2d)*x_size*y_size);
	//用链表代替cell来进行操作
	list<int> active;
	double x, y;
	double x0 = x_length*random_number(0, 1);
	double y0 = y_length*random_number(0, 1);
	int x_index = floor(x0 / grid_size), y_index = floor(y0 / grid_size);          //确定出生点

	Inside[x_size*y_index + x_index] = 1;
	C[x_size*y_index + x_index] = Eigen::Vector2d(x0, y0);
	cloud.push_back(Vector2d(x0 + start_x, y0 + start_y));
	active.push_back(x_size*y_index + x_index);
	while (active.size() != 0)
	{
		int l = active.size();
		int seed = l*random_number(0, 1);
		list<int>::iterator iter = active.begin();
		for (int i = 0; iter != active.end(); iter++, i++)
		{
			if (i == seed)
			{
				x0 = C[(*iter)](0);
				y0 = C[(*iter)](1);
				break;
			}
		}
		bool key1 = false;
		int j;
		for (j = 0; j < k; j++)
		{
			bool key2 = false;
			double R = r*sqrt(1.0 + 3.0 * random_number(0, 1));//R属于r到2r
			x = x0 + R*cos(random_number(0, 1) * 2.0 * M_PI);
			y = y0 + R*sin(random_number(0, 1) * 2.0 * M_PI);
			x_index = floor(x / grid_size);
			y_index = floor(y / grid_size);
			//if (x_index< 0 || x_index >= x_size || y_index < 0 || y_index >= y_size)
			if (x< 0 || x > x_length || y < 0 || y > y_length) continue;
			for (int u = x_index - 2; u <= x_index + 2; u++)
			{
				for (int v = y_index - 2; v <= y_index + 2; v++)
				{
					if (u< 0 || u >= x_size || v < 0 || v >= y_size) continue;
					if (Inside[v*x_size + u] == 1)
					{
						if (C[v*x_size + u](0) < 0 || C[v*x_size + u](0) >= x_length || C[v*x_size + u](1) < 0 || C[v*x_size + u](1) >= y_length)	continue;
						double d = sqrt(pow(x - C[v*x_size + u](0), 2) + pow(y - C[v*x_size + u](1), 2));
						if (d < r)
						{
							key2 = true;
							break;
						}
					}
				}
			}
			if (key2 == false)
			{
				C[x_size*y_index + x_index] = Eigen::Vector2d(x, y);
				Inside[x_size*y_index + x_index] = 1;
				active.push_back(x_size*y_index + x_index);
				cloud.push_back(Vector2d(x + start_x, y + start_y));
				//Cloud.push_back(Particle(Eigen::Vector2d(x + start_x, y + start_y)));
				key1 = true;
			}
		}
		if (key1 == false)
		{
			active.erase(iter);
		}
	}
	return cloud;
}


vector<Particle> ParticleCloud::PossionSample(Vector2d start, Vector2d end, Vector2d v, double r, int k)
{
	vector<Vector2d> set = PossionDisc(r, start[0], start[1], end[0], end[1], k);
	while (set.size() < 20)
	{
		set = PossionDisc(r, start[0], start[1], end[0], end[1], k);
	}
	vector<Particle> points;
	for (int i = 0; i < set.size(); i++)
	{
		points.push_back(Particle(set[i], v, mass, p_num, lambda, mu));
		p_num++;
	}

	return points;
}

vector<Particle> ParticleCloud::OrderSample(Vector2d start, Vector2d end, Vector2d size, Vector2d v)
{
	Vector2d cellsize;
	cellsize[0] = (end[0] - start[0]) / (size[0] - 1);//格点横向长度
	cellsize[1] = (end[1] - start[1]) / (size[1] - 1);//格点竖直方向长度
	int length = size[0] * size[1];
	vector<Particle> points(length);

	//如果不绘制格点，就不要加这些
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			points[(int)(j*size[0] + i)] = Particle(start + Vector2d(cellsize[0] * i, cellsize[1] * j), v, mass, p_num, lambda, mu);
			p_num++;
			/*points[(int)(j*size[0] + i)].mass = 1;
			points[(int)(j*size[0] + i)].velocity = Vector2d(0, 0);*/
		}
	}
	return points;
}
