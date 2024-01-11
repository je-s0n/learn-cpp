#include <iostream>
using namespace std;

/*
try : 예외 발견
catch : 예외 잡기
throw : 예외 던지기
---------------------
try  {
  // 예외발생 예상지역
  throw expn; // 예외 발생 알림 -> throw에 의해 던져진 예외 데이터는 예외 데이터를 감싸는 try 볼록에 의해서 감지가 되어 이어서 등장하는 catch 블록에 의해 처리됨
  // expn은 변수, 상수 그리고 객체 등 표현 가능한 모든 데이터가 될 수 있으나, 예외상황에 대한 정보를 담은 의미 있는 데이터여야 함
} catch (T exn){
  // 예외처리 코드 삽입
}
*/
int main(void)
{
	int num1, num2;
	cout<<"두 개의 숫자 입력: ";
	cin>>num1>>num2; // 8행이 실행된 후 이어서 등장하는 try 블록의 첫 행을 실행함

	try
	{
		if(num2==0) // num2에 0이 입력되었을 경우 throw절 실행됨 -> 예외처리 매커니즘 동작
			throw num2;
		cout<<"나눗셈의 몫: "<< num1/num2 <<endl;
		cout<<"나눗셈의 나머지: "<< num1%num2 <<endl;
	}
  // 예외상황이 발생해 throw num2;가 실행되면, 예외 데이터 num2의 값은 이어서 등장하는 catch 블록에 전달됨
  // num2의 값이 인자로 전달되면서 catch문 호출되고, 이로인해 매개변수 expn은 num2에 저장된 값으로 초기화
	catch(int expn) 
	{
		cout<<"제수는 "<<expn<<"이 될 수 없습니다."<<endl;
		cout<<"프로그램을 다시 실행하세요."<<endl;
	}
	cout<<"end of main"<<endl;
	return 0;
}

/*
정상적인 실행결과
------------------
두 개의 숫자 입력: 9 2
나눗셈의 몫: 4
나눗셈의 나머지: 1
end of main

예외 발생 실행결과
------------------
두 개의 숫자 입력: 7 0
제수는 0이 될 수 없습니다.
프로그램을 다시 실행하세요.
end of main
// 예외가 발생한 지점 이후를 실행하는 것이 아닌 catch블록의 이후가 실행됨을 알 수 있음
// throw절에 의해 던져진 예외 데이터의 자료형과 catch 블록의 매개변수 자료형은 일치해야 함
*/
