#include <iostream>
using namespace std;

/*
클래스 템플릿(Class Template) : 함수를 템플릿으로 정의했듯이, 클래스를 템플릿으로 정의하는 것
템플릿 클래스(Template Class) : 템플릿을 기반으로 컴파일러가 만들어 내는 클래스

템플릿 함수를 호출할 때와 다르게 템플릿 클래스의 객체 생성 시에는 <int>, <double>과 같은 자료형 정보를 생략할 수 없음
*/
template <typename T>
class Point 
{
private:
	T xpos, ypos;
public:
	Point(T x=0, T y=0) : xpos(x), ypos(y)
	{  }

	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl; 
	}
};

int main(void)
{
	Point<int> pos1(3, 4); // 위에 정의된 템플릿을 기반으로 컴파일러가 만들어 내는 템플릿 클래스 Point<int>의 객체 생성을 명령
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6); // 위에 정의된 템플릿을 기반으로 컴파일러가 만들어 내는 템플릿 클래스 Point<double>의 객체 생성을 명령
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');   // 위에 정의된 템플릿을 기반으로 컴파일러가 만들어 내는 템플릿 클래스 Point<char>의 객체 생성을 명령
	pos3.ShowPosition();
	return 0;
}

/*
실행결과
-------------------------
[3, 4]
[2.4, 3.6]
[P, F]
*/
