#include <iostream>
using namespace std;

/*
스마트 포인터(Smart Pointer)
- 포인터의 역할을 하는 객체를 뜻하는 것으로, 구현해야 할 대상
- 프로그램의 개발을 목적으로 라이브러리에서 제공하는 스마트 포인터를 사용할 때 도움이 될 것
*/
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) 
	{
		cout<<"Point 객체 생성"<<endl;
	}

	~Point()
	{
		cout<<"Point 객체 소멸"<<endl;
	}

	void SetPos(int x, int y)
	{
		xpos=x;
		ypos=y;
	}

	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	return os;
}

class SmartPtr
{
private:
	Point * posptr;
public:
  // 생성자에서 동적할당을 하지 않았음에도 불구하고, 소멸자에서 delete 연산을 하는 것이 생소하게 느껴질 수 있음
  // 여기에는 생성자의 인자로 전달되는 주소 값은 new 연산에 의해 동적 할당된 객체의 주소 값이라는 가정이 포함되어 있음
	SmartPtr(Point * ptr) : posptr(ptr)
	{  }

  // 스마트 포인터에서 아래 두 함수는 필수로 정의해야 함
  // 스마트 포인터의 가장 기본 
	Point& operator*() const
	{
		return *posptr;
	}

  // 스마트 포인터의 가장 기본 
	Point* operator->() const
	{
		return posptr;
	}

	~SmartPtr()
	{
		delete posptr;
	}
};

int main(void)
{
  // Point 객체를 생성하면서 동시에 스마트 포인터 SmartPtr 객체가 이를 가리키게끔 하고 있음
  // 이로써 sptr1, sptr2, sptr3는 Point 객체를 가리키는 포인터처럼 동작함
	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(4, 5));

  // sptr1, sptr2, sptr3는 포인터처럼 * 연산 진행
	cout<<*sptr1;
	cout<<*sptr2;
	cout<<*sptr3;

  // 포인터처럼 -> 연산 진행
	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr3->SetPos(50, 60);
	cout<<*sptr1;
	cout<<*sptr2;
	cout<<*sptr3;
	return 0;
}

/*
실행결과
-------------------
Point 객체 생성
Point 객체 생성
Point 객체 생성
[1, 2]
[2, 3]
[4, 5]
[10, 20]
[30, 40]
[50, 60]
Point 객체 소멸
Point 객체 소멸
Point 객체 소멸
*/
