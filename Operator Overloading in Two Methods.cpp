#include <iostream>
using namespace std;
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
	friend Point operator-(const Point& pos1, const Point& pos2);
	friend bool operator==(const Point& ref1, const Point& ref2);
	friend bool operator!= (const Point& ref1, const Point& ref2);
	Point& operator+=(const Point &ref)
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
		/* xpos+=ref.xpos;
		* ypos+=ref.ypos;
		* return *this;
		*/ 
	}
	Point& operator-= (const Point & ref)
	{
		Point pos(xpos - ref.xpos, ypos - ref.ypos);
		return pos;
		/*xpos-=ref.xpos;
		* ypos-=ref.ypos;
		* return *this;
		*/
	}
};
Point operator-(const Point& ref1, const Point& ref2)
{
	Point pos(ref1.xpos - ref2.xpos, ref1.xpos -ref2.ypos);
	return pos;
}
bool operator==(const Point& ref1, const Point& ref2)
{
	if ((ref1.xpos == ref2.xpos) && (ref1.ypos == ref2.ypos))
	{
		return true;
	}
	else
		return false;
}
bool operator!= (const Point & ref1, const Point & ref2)
{
	return !(ref1 == ref2);
}
int main(void)
{
	Point pos1(20, 30);
	Point pos2(5, 7);
	Point pos3(5, 7);
	Point pos4 = pos1 += pos2;
	Point pos5 = pos1 -= pos2;
	/*(pos2+=po3).ShowPosition();
	(pos2 -= pos3).ShowPosition();*/
	(pos1 - pos2).ShowPosition();
	pos4.ShowPosition();
	pos5.ShowPosition();
	if (pos2 == pos3)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}
	if (pos2 != pos3)
	{
		cout << "not equal" << endl;
	}
	else
	{
		cout<<"equal" << endl;
	}
	return 0;

}
