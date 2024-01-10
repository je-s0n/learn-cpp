#include <iostream>
using namespace std;

/*
함수의 호출에 사용되며, 인자의 전달에 사용되는 ()도 연산자임
멤버함수의 이름은 operator()로, adder(2,4); 문장일 경우 adder.operator()(2,4);로 해석됨
*/
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) 
	{  }

	Point operator+(const Point & pos) const  // Point형 임시객체를 생성과 동시에 반환하고 있음
	{
		return Point(xpos+pos.xpos, ypos+pos.ypos); // Point형 임시객체를 생성과 동시에 반환하며, return 문에서도 임시객체를 생성과 동시에 반환하는 것이 가능함
	}

	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	return os;
}

class Adder // 이 클래스는 두 개의 숫자 또는 Point객체에 대한 덧셈결과를 반환하도록 ()연산자가 총 3회 오버로딩 됨
{
public:
	int operator()(const int &n1, const int &n2)
	{
		return n1+n2;
	}

	double operator()(const double &e1, const double &e2)
	{
		return e1+e2;
	}

	Point operator()(const Point &pos1, const Point &pos2)
	{
		return pos1+pos2;
	}
};

int main(void)
{
	Adder adder;
  // adder는 객체임에도 함수처럼 동작하며, 함수처럼 동작하는 클래스를 '펑터(Functor)'라고 함 (= 함수 오브젝트라고 불리기도 함)
	cout<<adder(1, 3)<<endl;
	cout<<adder(1.5, 3.7)<<endl;
	cout<<adder(Point(3, 4), Point(7, 9));
	return 0;
}

/*
실행결과
---------------
4
5.2
[10, 13]
*/
