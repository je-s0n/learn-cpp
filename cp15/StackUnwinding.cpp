#include <iostream>
using namespace std;

/*
스택 풀기 : 예외가 처리되지 않아서 함수를 호출한 영역으로 예외 데이터가 전달되는 현상
아래 예제는 main -> SimpleFuncOne -> SimpleFuncTwo -> SimpleFuncThree 순서로 함수호출
하지만 예외 데이터가 전달되면서 스택이 해제되는 순서는 반대임 -> 예외 데이터 전달 시 예외 데이터를 전달한 함수는 종료되기 때문에 예외 데이터를 전달한 함수의 스택이 반환되는 것

만약 아래 코드에서 try-catch문 삭제 시 어떠한 일이 발생할까?
-> 예외 처리가 되지 않아서 예외 데이터가 main함수에까지 도달했는데, main함수에서조차 예외를 처리하지 않으면, terminate함수(프로그램을 종료시키는 함수)가 호출되면서 프로그램이 종료되어 버림
시스템 오류로 인해 발생한 예외상황이 아니고 더 이상 프로그램의 실행이 불가능한 예외상황이 아니라면, 반드시 프로그래머가 예외상황을 처리해야 함
*/
void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

int main(void)
{
	try
	{
		SimpleFuncOne();
	}
	catch(int expn)
	{
		cout<<"예외코드: "<< expn <<endl;
	}
	return 0;
}

void SimpleFuncOne(void) 
{ 
	cout<<"SimpleFuncOne(void)"<<endl;
	SimpleFuncTwo(); 
}
void SimpleFuncTwo(void) 
{ 
	cout<<"SimpleFuncTwo(void)"<<endl;
	SimpleFuncThree(); 
}
void SimpleFuncThree(void) 
{ 
	cout<<"SimpleFuncThree(void)"<<endl;
	throw -1; 
}

/*
실행결과
------------------
SimpleFuncOne(void)
SimpleFuncTwo(void)
SimpleFuncThree(void)
예외코드: -1
*/
