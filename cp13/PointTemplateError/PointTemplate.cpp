#include <iostream>
#include "PointTemplate.h"
using namespace std;

/*
컴파일 에러 발생 예시
*/
// 생성자와 멤버함수 정의
// 일반적인 클래스의 선언과 정의를 각각 헤더파일과 소스파일에 나누어 담는 것과 차이 없음
template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y)
{  }

template <typename T>
void Point<T>::ShowPosition() const
{
	cout<<'['<<xpos<<", "<<ypos<<']'<<endl; 
}
