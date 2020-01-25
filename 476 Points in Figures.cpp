#include <iostream>
#include <vector>
#include <math.h>
struct Point {
	double x;
	double y;
};

class Figure {
public:
	virtual bool check(const Point&) = 0;
};


class Triangle : public Figure {
public:
	Triangle()
	{
		for (int i = 0; i < 3; ++i)
			std::cin >> data[i].x >> data[i].y;
	};
	~Triangle() {};
	bool check(const Point& p)
	{
		double denominator = ((data[1].y - data[2].y) * (data[0].x - data[2].x) + (data[2].x - data[1].x) * (data[0].y - data[2].y));
		double a = ((data[1].y - data[2].y) * (p.x - data[2].x) + (data[2].x - data[1].x) * (p.y - data[2].y)) / denominator;
		double b = ((data[2].y - data[0].y) * (p.x - data[2].x) + (data[0].x - data[2].x) * (p.y - data[2].y)) / denominator;
		double c = 1 - a - b;
		return 0 <= a && a <= 1 && 0 <= b && b <= 1 && 0 <= c && c <= 1;
	};
private:

	Point data[3] = { {0,0},{0,0},{0,0} };
};

class Rectangle : public Figure {
public:
	Rectangle()
	{
		std::cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) std::swap(x1, x2);
		if (y1 > y2) std::swap(y1, y2);
	};
	~Rectangle() {};
	bool check(const Point& p) override
	{
		
		return x1 < p.x&& x2 > p.x&& y1 < p.y&& y2 > p.y;
	};
private:
	double x1,x2,y1,y2;
};

class Circle : public Figure {
public:
	Circle()
	{
		std::cin >> data.x >> data.y >> r;
	};
	~Circle() {};
	bool check(const Point& x)
	{
		double z = pow(x.x - data.x, 2) + pow(x.y - data.y, 2);
		return z < r* r;
	};
private:
	Point data = { 0,0 };
	double r;
};


int main()
{
	char c;
	std::vector<Figure*> lista;
	int iter = 0;
	while (std::cin >> c)
	{
		if (c == '*')
		{
			break;
		}
		switch (c)
		{
		case 'r':
			lista.push_back(new Rectangle());
			break;
		case 't':
			lista.push_back(new Triangle());
			break;
		case 'c':
			lista.push_back(new Circle());
			break;
		}
	}
	double x, y;
	int id = 1;
	while (std::cin >> x >> y)
	{
		bool finder = false;
		if (x == 9999.9 && y == 9999.9) break;
		for (int i = 0; i < lista.size(); ++i)
		{
			if (lista[i]->check({ x,y }))
			{
				std::cout << "Point " << id << " is contained in figure " << i + 1 << "\n";
				finder = true;
			}
		}
		if (!finder)
		{
			std::cout << "Point " << id << " is not contained in any figure\n";
		}
		id++;
	}
	
	for (Figure* a : lista)
		delete a;

	return 0;
}
