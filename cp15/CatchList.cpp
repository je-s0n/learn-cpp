#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/*
예외 데이터의 자료형과 catch의 매개변수 형이 일치하지 않을 경우 예외 데이터 전달여부
-> 자료형의 불일치로 인해 예외는 처리되지 않음 (catch 블록으로 값이 전달되지 않음)
-> 함수를 호출한 영역으로 예외 데이터가 전달됨

하나의 try 블록과 다수의 catch 블록
- 하나의 try 블록 내에서 유형이 다른 둘 이상의 예외상황이 발생할 수도 있고, 이러한 경우 각각의 예외를 표현하기 위해 사용되는 예외 데이터의 자료형이 다를 수 있음
  -> try 블록에 이어서 등장하는 catch 블록은 둘 이상 될 수 있음

전달되는 예외의 명시
- 함수 내 발생할 수 있는 예외의 종류도 함수의 특징으로 간주됨
  -> 따라서 이미 정의된 특정 함수의 호출을 위해서는 함수의 이름, 매개변수 선언, 반환형 정보에 더해서, 함수 내에서 전달될 수 있는 예외의 종류(예외 데이터의 자료형)과 그 상황을 알아야 함
  -> 그래야 해당 함수의 호출문장을 감싸는 적절한 try-catch 블록을 구성할 수 있음

e.g.
int ThrowFunc(int num) throw (int, char) 
// 위 throw 선언은 ThrowFunc 함수 내에서 예외상황의 발생으로 인해, int형 예외 데이터와 char형 예외 데이터가 전달될 수 있음을 알림
{
  ...
}

// 위 원형 선언을 본 프로그래머는 아래와 같이 함수 호출문 구성
try
{
  ...
  ThrowFunc(20);
  ...
} 
catch(int expn) { ... }
catch(char expn) { ... }
-> int형 예외 데이터와 char형 예외 데이터만이 전달되어야 하며, 이외 다른 자료형의 예외 데이터가 전달될 경우 unexpected라는 이름의 함수가 호출됨
-> unexpected함수의 기본 기능은 프로그램 종료(terminate 함수의 호출)인데, 이로 인해 프로그램 종료됨

e.g. 다음의 함수 선언은 전달되는 예외의 자료형을 명시하는 부분이 비어있으므로 이는 어떠한 예외도 전달하지 않음을 의미함
함수가 예외를 전달할 경우 프로그램은 그냥 종료함
int ThrowFunc(void) throw () 
{
  ...
}
*/
int StoI(char * str)
{
	int len=strlen(str);
	int num=0;

	if(len!=0 && str[0]=='0')
		throw 0;

	for(int i=0; i<len; i++)
	{
		if(str[i]<'0' || str[i]>'9')
			throw str[i];

		num += (int)(pow((double)10, (len-1)-i) * (str[i]+(7-'7')));
	}
	return num;	
}

int main(void)
{
	char str1[100];
	char str2[200];

	while(1)
	{
		cout<<"�� ���� ���� �Է�: ";
		cin>>str1>>str2;

		try
		{
			cout<<str1<<" + "<<str2<<" = "<<StoI(str1)+StoI(str2)<<endl;
			break;
		}
		catch(char ch)
		{
			cout<<"문자 "<< ch <<"가 입력되었습니다."<<endl;
			cout<<"재입력 진행합니다."<<endl<<endl;
		}
		catch(int expn)
		{
			if(expn==0)
				cout<<"0으로 시작하는 숫자는 입력불가."<<endl;
			else
				cout<<"비정상적인 입력이 이루어졌습니다."<<endl;

			cout<<"재입력 진행합니다."<<endl<<endl;
		}
	}
	cout<<"프로그램을 종료합니다."<<endl;
	return 0;
}

/*
실행결과
--------------------------
두 개의 숫자 입력: 12A 519
문자 A가 입력되었습니다.
재입력 진행합니다. 

두 개의 숫자 입력: 082 910
0으로 시작하는 숫자는 입력불가.
재입력 진행합니다.

두 개의 숫자 입력: 123 456
123 + 456 = 579
프로그램을 종료합니다.
*/
