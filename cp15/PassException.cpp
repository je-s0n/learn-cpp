#include <iostream>
using namespace std;

void Divide(int num1, int num2) // 예외처리에 대한 책임은 이 함수를 호출한 영역으로 넘어감
{
	if(num2==0)
		throw num2; // 예외가 처리되지 않으면 예외가 발생한 함수를 호출한 영역으로 예외 데이터가(더불어 예외처리에 대한 책임까지) 전달됨
	
	cout<<"나눗셈의 몫: "<< num1/num2 <<endl;
	cout<<"나눗셈의 나머지: "<< num1%num2 <<endl;
}

int main(void)
{
	int num1, num2;	
	cout<<"두 개의 숫자 입력: ";
	cin>>num1>>num2;

	try
	{
		Divide(num1, num2);
		cout<<"나눗셈을 마쳤습니다."<<endl;
	}
	catch(int expn)
	{
		cout<<"제수는 "<<expn<<"이 될 수 없습니다."<<endl;
		cout<<"프로그램을 다시 실행하세요."<<endl;
	}
	return 0;
}

/*
정상적인 실행결과
------------------
두 개의 숫자 입력: 9 2
나눗셈의 몫: 4
나눗셈의 나머지: 1
나눗셈을 마쳤습니다.

예외발생 실행결과
------------------
두 개의 숫자 입력: 7 0
제수는 0이 될 수 없습니다.
프로그램을 다시 실행하세요.
*/
