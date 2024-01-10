#include <iostream>
#include "PointTemplate.h"
using namespace std;

/*
컴파일 에러 발생 예시
*/

/*
Point<int>, Point<double>, Point<char> 템플릿 클래스의 객체가 생성되기 때문에 PointTemplate.h를 포함했으나, 컴파일 에러 발생

main함수가 정의된 소스파일 PointMain.cpp가 컴파일 될 때, 컴파일러는 총 3개의 템플릿 클래스를 생성해야 함

이를 위해서는 클래스 템플릿인 Point의 모든 것을 알아야 함 
-> 컴파일러에는 헤더파일 PointTemplate.h에 담긴 정보뿐만 아니라, PointTemplate.cpp에 담긴 정보도 필요하여 컴파일 에러 발생
-> PointMain.cpp와 PointTemplate.cpp가 동시에 컴파일 되는 것은 맞지만, 이 둘은 서로 다른 소스파일이기 때문이며 파일 단위 컴파일 원칙에 의해 PointMain.cpp를 컴파일 하면서 PointTemplate.cpp의 내용을 참조하지 않음

위에 #include "PointTemplate.cpp"를 추가하면 해결됨 또는 헤더파일 PointTemplate.h에 템플릿 Point의 생성자와 멤버함수 정의를 모두 넣어야 함
*/
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
