#include <iostream>
using namespace std;

/*
함수 템플릿과 static 지역변수
e.g.
template <typename T>
void ShowStaticValue(void)
{
	static T num = 0; // static 지역변수도 템플릿 함수 별로 각각 존재하게 됨
	num+=1;
	cout<<num<<" ";
}
-> 함수 템플릿을 기반으로 컴파일러는 아래와 같이 템플릿 함수들을 만듦

void ShowStaticValue<int>(void)
{
  static int num = 0;
  num += 1;
  cout<<num<<" ";
}

void ShowStaticValue<long>(void)
{
  static long num = 0;
  num += 1;
  cout<<num<<" ";
}
-> 따라서 static 지역변수도 템플릿 함수 별로 각각 존재하게 됨
*/
template <typename T>
void ShowStaticValue(void)
{
	static T num = 0; 
	num+=1;
	cout<<num<<" ";
}

int main(void)
{
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	cout<<endl;

	ShowStaticValue<long>();
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	cout<<endl;

	ShowStaticValue<double>();
	ShowStaticValue<double>();
	ShowStaticValue<double>();
	return 0;
}

/*
실행결과
------------------
1 2 3
1 2 3
1 2 3
*/
