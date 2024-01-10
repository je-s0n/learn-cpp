#include <iostream>
using namespace std;

/*
함수 템플릿의 특수화 필요한 이유에 대한 예시
*/
template <typename T>
T Max(T a, T b) 
{
	return a > b ? a : b ; 
}

int main(void)
{
	cout<< Max(11, 15)				<<endl;
	cout<< Max('T', 'Q')			<<endl;
	cout<< Max(3.5, 7.5)			<<endl; 
	cout<< Max("Simple", "Best")	<<endl; // 문자열을 대상으로 호출할 경우 그 결과에 대해서는 아무런 의미를 부여할 수 없음 (단순히 주소 값의 비교결과 반환)
	return 0;
}

/*
실행결과
--------------
15
T
7.5
Best
*/
