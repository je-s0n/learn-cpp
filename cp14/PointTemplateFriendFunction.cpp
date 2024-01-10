#include <iostream>
using namespace std;

/*
템플릿 클래스의 자료형을 대상으로도 템플릿이 아닌 일반함수의 정의가 가능하고, 클래스 템플릿 내에서 이러한 함수를 대상으로 friend 선언도 가능함
*/
template <typename T>
class Point 
{
private:
	T xpos, ypos;
public:
	Point(T x=0, T y=0): xpos(x), ypos(y)
	{  }

	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl; 
	}

  // 아래 정의된 두 함수에 대해 friend 선언을 하고 있으며, 클래스 템플릿에서도 일반함수에 대해 friend 선언을 할 수 있는 것 확인함
	friend Point<int> operator+(const Point<int>&, const Point<int>&);
	friend ostream& operator<<(ostream& os, const Point<int>& pos);
};

Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2)
{
	return Point<int>(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
}

ostream& operator<<(ostream& os, const Point<int>& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	return os;
}

int main(void)
{	
	Point<int> pos1(2, 4);
	Point<int> pos2(4, 8);
	Point<int> pos3=pos1+pos2;
	cout<<pos1<<pos2<<pos3;
	return 0;
}

/*
실행결과
-------------------
[2, 4]
[4, 8]
[6, 12]
*/
