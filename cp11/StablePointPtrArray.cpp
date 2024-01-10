#include <iostream>
#include <cstdlib>
using namespace std;

// Point 객체의 주소 값을 저장하는 배열 기반의 클래스
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) {  }
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	return os;
}

typedef Point * POINT_PTR; // Point 포인터 형을 의미하는 POINT_PTR 정의 -> 저장의 대상, 또는 연산의 주 대상이 포인터인 경우 별도의 자료형을 정의하는 것이 좋음

class BoundCheckPointPtrArray 
{
private:
	POINT_PTR * arr;
	int arrlen;
	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { }

public:
	BoundCheckPointPtrArray(int len) :arrlen(len)
	{
		arr=new POINT_PTR[len]; // 저장의 대상이 Point 객체의 주소값이기 때문에 POINT_PTR 배열을 생성함
	}

	POINT_PTR& operator[] (int idx)
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return arr[idx];
	}

	POINT_PTR operator[] (int idx) const 
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return arr[idx];
	}

	int GetArrLen() const 
	{
		return arrlen;
	}

	~BoundCheckPointPtrArray()
	{
		delete []arr;
	}
};

int main(void)
{
	BoundCheckPointPtrArray arr(3);
  // Point 객체의 주소 값을 저장하고 있으며, 객체의 주소 값을 저장할 때 깊은 복사냐 얕은 복사냐 하는 문제를 신경쓰지 않아도 됨
	arr[0]=new Point(3, 4);
	arr[1]=new Point(5, 6);
	arr[2]=new Point(7, 8);
	for(int i=0; i<arr.GetArrLen(); i++)
		cout<<*(arr[i]);
	delete arr[0];
	delete arr[1];
	delete arr[2];
	return 0;
}

/*
실행결과
---------------
[3, 4]
[5, 6]
[7, 8]
*/
