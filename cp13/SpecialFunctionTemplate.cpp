#include <iostream>
#include <cstring>
using namespace std;

// 함수 템플릿의 특수화의 정의 : 특수화하는 자료형의 정보 <char*>와 <cosnt char*>를 생략한 형태
template <typename T>
T Max(T a, T b) 
{
	return a > b ? a : b ; 
}

// 함수 템플릿 Max를 char*형에 대해 특수화 시킴
template <>
char* Max(char* a, char* b)
{
	cout<<"char* Max<char*>(char* a, char* b)"<<endl;
	return strlen(a) > strlen(b) ? a : b ;
}

// 함수 템플릿 Max를 const char*형에 대해 특수화 시킴
template <> 
const char* Max(const char* a, const char* b)
{
	cout<<"const char* Max<const char*>(const char* a, const char* b)"<<endl;
	return strcmp(a, b) > 0 ? a : b ;
}


int main(void)
{	cout<< Max(11, 15)				<<endl;
	cout<< Max('T', 'Q')			<<endl;
	cout<< Max(3.5, 7.5)			<<endl;
	cout<< Max("Simple", "Best")	<<endl; // 문자열의 선언으로 인해 반환되는 주소 값의 포인터 형은 const char*로, const char* Max(const char* a, const char* b) 함수가 호출됨
	char str1[]="Simple";
	char str2[]="Best";
	cout<< Max(str1, str2)			<<endl; // str1과 str2는 변수 형태로 선언되어 str1과 str2의 포인터 형은 char*이므로 이 문장에 의해 호출되는 함수는 char* Max(char* a, char* b)임
	return 0;
}

/*
실행결과
-------------
15
T
7.5
const char* Max<const char*>(const char* a, const char* b)
Simple
char* Max<char*>(char* a, char* b)
Simple
*/
