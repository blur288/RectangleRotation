#include <cmath>
#include <iostream>
#include <vector>
#define PI 3.1415926538

//degrees to radians
float DtR(float degrees)
{
	return (degrees * (PI / 180));
}

struct Point
{
	float x, y;
};

Point rotate(Point p, float Theta)
{
	Point pp;
	pp.x = p.x * cos(Theta) - p.y * sin(Theta);
	pp.y = p.x * sin(Theta) + p.y * cos(Theta);
	return pp;
}

class Rectangle
{
public:
	std::vector<Point> Vertices;

	void Rotate(float ThetaRad)
	{
		for (int i = 0; i < 4; i++)
		{
			Point NewPoint;
			NewPoint.x = ( Vertices[i].x * cos(ThetaRad) ) - ( Vertices[i].y * sin(ThetaRad) );
			NewPoint.y = ( Vertices[i].x * sin(ThetaRad) ) + ( Vertices[i].y * cos(ThetaRad) );
			Vertices[i].x = floor(NewPoint.x*100+0.5)/100;
			Vertices[i].y = floor(NewPoint.y*100+0.5)/100;
		}
	}

	void Print()
	{
		for (int i = 0; i < 4; i++)
		{
			std::cout << Vertices[i].x << " : " << Vertices[i].y << std::endl;
		}
	}

	Rectangle(std::vector<Point> Verts)
	{
		if (Verts.size() < 4)
		{
			throw -1;
		}

		Vertices = Verts;
	}
};

int main()
{
	Rectangle rect({ {0,0}, {1,0}, {1,1}, {0,1} });
	
	rect.Rotate(DtR(90));
	rect.Print();
}