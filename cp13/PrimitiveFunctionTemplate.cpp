#include <iostream>
using namespace std;

/*
둘 이상의 형(Type)에 대해 템플릿 선언하기 예시

cout<<(T1)num<<", "<<(T2)num<<endl;
// cout<<T1(num)<<", "<<T2(num)<<endl; 형태로 대신할 수 있음 -> 데이터에 소괄호를 묶는 형태로 형 변환을 명령할 수 있음

따라서 int num = (int) 3.14;는 int num = int(3.14);형 변환문과 완전히 일치함
*/

// template <typename T1, typename T2> typename과 class는 같은 의미로 해석됨
template <class T1, class T2>
void ShowData(double num) 
{
	cout<<(T1)num<<", "<<(T2)num<<endl;
}

int main(void)
{
	ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, double>(68.9);
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);
	return 0;
}

/*
실행결과
-----------------
A, 65
C, 67
D, 68.9
69, 69.2
70, 70.4
*/
