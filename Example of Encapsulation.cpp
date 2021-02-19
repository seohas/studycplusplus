#include <iostream>
using namespace std;
class Point
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
};
class Circle
{
private:
	int radius;
	Point center;
public:
	void Init(int x, int y, int r)
	{
		center.Init(x, y);
		radius = r;
	
	}
	void showcircle()
	{
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	
	}
	
};
class Ring
{
private:
	Circle inner;
	Circle outer;
public:
	void Init(int x1, int y1, int r1, int x2, int y2, int r2)
	{
		inner.Init(x1, y1, r1);
		outer.Init(x2, y2, r2);
	}
	void ShowRingInfo()
	{
		cout << "Inner Circle Info..." << endl;
		inner.showcircle();
		cout << "Outter Circle Info..." << endl;
		outer.showcircle();
	}

};
int main(void)
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}
//Ring클래스, Cricle 클래스, Point 클래스 모두 자신의 정보를 출력하기 위한 함수를 멤버에 포함시켜서 캡슐화를 완성하였다

//!!Answer with constructor!!
#include <iostream>
using namespace std;
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y):xpos(x),ypos(y)
	{
		
	}
	void ShowPointInfo()const
	{
		cout << "[" << xpos << "," << ypos << "]"<<endl;
	}
};
class Circle
{
private:
	int rad;
	Point center;
public:
	Circle(int x, int y, int r):center(x,y)
	{
		rad = r;
	}
	void ShowCircleInfo() const
	{
		cout << "radius: " << rad << endl;
		center.ShowPointInfo();
	}
};
class Ring
{
private:
	Circle inner;
	Circle outer;
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2): inner(x1,y1,r1),outer(x2,y2,r2)
	{

	}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info.." << endl;
		inner.ShowCircleInfo();
		cout << "outter Circle Info.." << endl;
		outer.ShowCircleInfo();
	}


};
int main(void)
{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}
