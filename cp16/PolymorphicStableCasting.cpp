#include <iostream>
using namespace std;

/*
e.g.
SoSimple * simPtr=new SoComplex;
SoComplex * comPtr=dynamic_cast<SoComplex*>(simPtr);
-> dynamic_cast 연산 성공한 이유는 포인터 변수 simPtr이 실제 가리키는 객체가 SoComplex 객체이기 때문으로, 포인터 변수 simPtr이 가리키는 객체를 SoComplex형 포인터 변수 comPtr이 함께 가리켜도 문제가 되지 않음

SoSimple * simPtr=new SoSimple;
SoComplex * comPtr=dynamic_cast<SoComplex*>(simPtr);
-> 위 경우에는 simPtr이 가리키는 대상을 comPtr이 가리킬 수 없음. 이 경우에는 형 변환 결과로 NULL 포인터 반환되어 안정적인 형 변환 보장됨 (컴파일 시간이 아닌 실행 시간에 안전성을 검사하도록 컴파일러가 바이너리 코드 생성함)
*/
class SoSimple
{
public:
	virtual void ShowSimpleInfo()
	{
		cout<<"SoSimple Base Class"<<endl;
	}
};

class SoComplex : public SoSimple
{
public:
	void ShowSimpleInfo()
	{
		cout<<"SoComplex Derived Class"<<endl;
	}
};

int main(void)
{
	SoSimple * simPtr=new SoSimple;
	SoComplex * comPtr=dynamic_cast<SoComplex*>(simPtr); // 안정적이지 못한 형 변환 시도, 이 경우 dynamic_cast 연산자는 NULL 반환
	if(comPtr==NULL)
		cout<<"형 변환 실패"<<endl;
	else
		comPtr->ShowSimpleInfo();
	return 0;
}

/*
실행결과
-----------------------
형 변환 실패
*/
