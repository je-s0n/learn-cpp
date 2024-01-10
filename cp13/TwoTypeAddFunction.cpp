#include <iostream>
using namespace std;

/*
함수 템플릿과 템플릿 함수
1) 함수 템플릿 : 함수를 만드는데 사용되는 템플릿
template <typename T>
T Add(T num1, T num2) 
{
	cout<<"T Add(T num1, T num2)"<<endl;
	return num1+num2;
}

2) 템플릿 함수 : 템플릿을 기반으로 컴파일러가 만들어 내는 함수
int Add(int num1, int num2)
{
	cout<<"Add(int num1, int num2)"<<endl;
	return num1+num2;
}

double Add(double num1, double num2)
{
	cout<<"Add(double num1, double num2)"<<endl;
	return num1+num2;
}
*/
template <typename T>
T Add(T num1, T num2) 
{
	cout<<"T Add(T num1, T num2)"<<endl;
	return num1+num2;
}

int Add(int num1, int num2) // 일반함수 형태로 Add함수 정의됨. 템플릿이 정의되어도 일반함수를 정의할 수 있으며, 템플릿 함수와 일반함수는 구분됨
{
	cout<<"Add(int num1, int num2)"<<endl;
	return num1+num2;
}

double Add(double num1, double num2)
{
	cout<<"Add(double num1, double num2)"<<endl;
	return num1+num2;
}

int main(void)
{
	cout<< Add(5, 7)				<<endl; // 일반함수가 정의되어 있기 때문에 템플릿 함수가 아닌 일반 함수가 호출됨
	cout<< Add(3.7, 7.5)			<<endl; // 일반함수가 정의되어 있기 때문에 템플릿 함수가 아닌 일반 함수가 호출됨
	cout<< Add<int>(5, 7)			<<endl; // 일반함수가 정의되어 있기 때문에 <int>, <double> 표시를 통해 템플릿 함수의 호출을 명시함
	cout<< Add<double>(3.7, 7.5)	<<endl; // 일반함수가 정의되어 있기 때문에 <int>, <double> 표시를 통해 템플릿 함수의 호출을 명시함
	return 0;
}

/*
실행결과
--------------
Add(int num1, int num2)
12
Add(double num1, double num2)
11.2
T Add(T num1, T num2)
12
T Add(T num1, T num2)
11.2
*/
