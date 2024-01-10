#include <iostream>
#include <cstdlib>
using namespace std;

/*
Point 객체를 저장하는 배열 기반의 클래스
*/
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

class BoundCheckPointArray 
{
private:
	Point * arr;
	int arrlen;
	BoundCheckPointArray(const BoundCheckPointArray& arr) { }
	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) { }
public:
	BoundCheckPointArray(int len) :arrlen(len)
	{
		arr=new Point[len]; // Point 객체로 이뤄진 배열을 생성, 인자를 받지 않는 void 생성자의 호출을 통해서 배열요소를 이루는 객체 생성하므로 Point 클래스의 생성자를 통해 모든 멤버 0으로 초기화
	}

	Point& operator[] (int idx)
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return arr[idx];
	}

	Point operator[] (int idx) const 
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

	~BoundCheckPointArray()
	{
		delete []arr;
	}
};

int main(void)
{
	BoundCheckPointArray arr(3);
  // 임시객체를 생성해서 배열요소를 초기화하고 있음
  // 물론 초기화의 과정에서 디폴트 대입 연산자가 호출되어 멤버 대 멤버의 복사가 진행됨
  // 저장의 대상이 객체라면, 여기서 보이는 것과 같이 대입 연산자를 통해 객체에 저장된 값을 복사해야 함
	arr[0]=Point(3, 4);
	arr[1]=Point(5, 6);
	arr[2]=Point(7, 8);
	for(int i=0; i<arr.GetArrLen(); i++)
		cout<<arr[i];
	return 0;
}

/*
실행결과
-------------------
[3, 4]
[5, 6]
[7, 8]
*/
