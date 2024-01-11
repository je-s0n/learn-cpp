#include <iostream>
#include <new>
using namespace std;

/*
new 연산자에 의해서 발생하는 예외
- new 연산에 의한 메모리 공간의 할당이 실패하면 bad_alloc라는 예외 발생
- bad_alloc은 헤더파일 <new>에 선언된 예외 클래스로써 메모리 공간의 할당이 실패했음을 알리는 의도로 정의
- 프로그래머가 정의하지 않아도 발생하는 예외도 존재함 -> throw문 사용하지 않음
*/
int main(void)
{
	int num=0;

	try
	{
		while(1)
		{
			num++;
			cout<<num<<"번째 할당 시도"<<endl;
			new int[10000][10000]; // 메모리 할당관련 예외의 발생을 위해서 반복해서 메모리 공간을 할당하고 있음
		}
	}
	catch(bad_alloc &bad) // bad_alloc 예외의 발생을 확인하기 위한 catch 블록
	{
		cout<<bad.what()<<endl; // what함수는 예외의 원인정보를 문자열의 형태로 반환 -> 내용은 컴파일러에 따라 달라짐
		cout<<"더 이상 할당 불가!"<<endl;
	}
	return 0;
}
