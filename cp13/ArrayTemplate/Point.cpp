#include <iostream>
#include "Point.h"
using namespace std;

// BoundCheckArray<Point> 객체의 생성을 위한 Point 클래스 정의
Point::Point(int x, int y) : xpos(x), ypos(y) {  }

ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	return os;
}
