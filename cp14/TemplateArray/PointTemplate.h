#ifndef __POINT_TEMPLATE_H_
#define __POINT_TEMPLATE_H_

/*
객체 생성 규칙
-> Point, BoundCheckArray 클래스 템플릿을 기반으로 Point<int> 템플릿 클래스의 객체를 저장할 수 있는 객체 생성하는 방법

BoundCheckArray<int> iarr(50);와 같이 int형 데이터 저장이 가능함

1) 저장대상 자료형이 Point<int>로, 아래와 같이 객체 생성하면 Point<int> 템플릿 클래스의 객체를 저장할 수 있음
-> BoundCheckArray<Point<int>> oarr[50]; 

2) 저장대상 자료형이 Point<int> 템플릿 클래스의 객체가 아닌 Point<int>형 포인터일 경우 객체 생성 가능
-> BoundCheckArray<Point<int>*> oparr[50]; 

typedef 선언을 통해 구성할 수 있음
1) -> typedef Point<int>* POINT_PTR;
2) -> BoundCheckArray<POINT_PTR> oparr(50);
*/
template <typename T>
class Point 
{
private:
	T xpos, ypos;
public:
	Point(T x=0, T y=0);
	void ShowPosition() const;
};

template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y)
{  }

template <typename T>
void Point<T>::ShowPosition() const
{
	cout<<'['<<xpos<<", "<<ypos<<']'<<endl; 
}

#endif
