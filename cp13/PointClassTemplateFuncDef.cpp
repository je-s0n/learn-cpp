#include <iostream>
using namespace std;

/*
클래스의 템플릿 선언과 정의의 분리
- 클래스 템플릿도 멤버함수를 클래스 외부에 정의하는 것이 가능함
e.g. 
// 클래스 템플릿
template <typename T>
class SimpleTemplate
{
public:
  T SimpleFunc(const T& ref);
};

// 멤버함수 SimpleFunc
template <typename T> // 함수 외부 정의 시 빼먹으면 컴파일러 에러 발생
T SimpleTemplate<T>::SimpleFunc(const T& ref) // SimpleTemplate<T>의 의미 : T에 대해 템플릿화 된 SimpleTemplate 클래스 템플릿
{ ... }
*/
template <typename T>
class Point 
{
private:
	T xpos, ypos;
public:
	Point(T x=0, T y=0); // 일반적인 클래스의 정의와 마찬가지로 매개변수의 디폴트 값은 클래스 템플릿 내에만 표시
	void ShowPosition() const;
};

template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y) // 일반적인 클래스의 정의와 마찬가지로 생성자를 외부에 정의할 때는 클래스 템플릿의 외부에 정의된 생성자에만 이니셜라이저 삽입
{  }

template <typename T>
void Point<T>::ShowPosition() const
{
	cout<<'['<<xpos<<", "<<ypos<<']'<<endl; 
}


int main(void)
{
	Point<int> pos1(3, 4);
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();
	return 0;
}

/*
실행결과
--------------------
[3, 4]
[2.4, 3.6]
[P, F]
*/
