#include <iostream>
using namespace std;

/*
if문을 이용한 예외의 처리
- if문을 통해 예외상황의 발생유무를 확인한 다음 그에 따른 처리를 진행하는 방식
*/
int main(void)
{
	int num1, num2;
	cout<<"두 개의 숫자 입력: ";
	cin>>num1>>num2;

	if(num2==0)
	{
		cout<<"제수는 0이 될수 없습니다."<<endl;
		cout<<"프로그램을 다시 실행하세요."<<endl;
	}
	else
	{
		cout<<"나눗셈의 몫: "<< num1/num2 <<endl;
		cout<<"나눗셈의 나머지: "<< num1%num2 <<endl;
	}
	return 0;
}

/*
실행결과
------------
두 개의 숫자 입력: 7 0
제수는 0이 될 수 없습니다.
프로그램을 다시 실행하세요.
*/
