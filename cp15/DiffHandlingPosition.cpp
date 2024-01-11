#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StoI(char * str)
{
	int len=strlen(str);
	int num=0;

	for(int i=0; i<len; i++)
	{
    // 인자로 전달된 문자열에 숫자가 아닌 형태의 문자가 존재할 경우 예외 발생
    // 이 예외에 대한 처리는 Stol 함수를 호출하는 대상 및 상황에 따라서 달라지기 때문에 예외의 처리는 Stol함수를 호출한 영역으로 넘기는 것이 타당함
		if(str[i]<'0' || str[i]>'9')
			throw str[i]; // 함수 내에서 예외 데이터를 전달하면, return문 실행을 통한 함수의 종료와 마찬가지로 함수를 완전히 빠져나옴

		num += (int)(pow((double)10, (len-1)-i) * (str[i]+(7-'7'))); // 문자열을 정수의 형태로 변환하는 문장 -> 이 기능의 표준함수로 정의되어 있음
	}
	return num;	
}

int main(void)
{
	char str1[100];
	char str2[200];

	while(1) // 정수로 변경 가능한 문자열을 입력 받을 때까지 계속해서 입력 받도록 구성 while(true) 사용 가능
	{
		cout<<"두 개의 숫자 입력: ";
		cin>>str1>>str2;

		try
		{
			cout<<str1<<" + "<<str2<<" = "<<StoI(str1)+StoI(str2)<<endl;
			break; // 덧셈 연산 성공 시 이 문장의 실행을 통해 반복문 빠져나감
		}
		catch(char ch)
		{
      // break 문이 없으므로 예외 발생 시 반복문 영역 재실행
			cout<<"문자 "<< ch <<"가 입력되었습니다."<<endl;
			cout<<"재입력 진행합니다."<<endl<<endl;
		}
	}
	cout<<"프로그램을 종료합니다."<<endl;
	return 0;
}

/*
실행결과
-----------------------
두 개의 숫자 입력: 123 3A5
문자 A가 입력되었습니다.
재입력 진행합니다.

두 개의 숫자 입력: 28F 211
문자 F가 입력되었습니다.
재입력 진행합니다.

두 개의 숫자 입력: 231 891
231 + 891 = 1122
프로그램을 종료합니다.
*/
