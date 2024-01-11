#include <iostream>
using namespace std;

/*
프로그래머가 정의하지 않아도 발생하는 예외 존재
-> 이러한 유형 중 하나로, 형 변환 시 발생하는 bad_cast 예외 소개
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
	SoSimple simObj;
	SoSimple& ref=simObj;

	try
	{
    // 참조형을 대상으로 dynamic_cast 연산을 진행할 경우에는 bad_cast 예외 발생할 수 있음
		SoComplex& comRef=dynamic_cast<SoComplex&>(ref); // 참조자 ref가 실제 참조하는 대상이 SoSimple 객체이기 때문에 SoComplex 참조형의 형 변환은 안전하지 못하며, 참조자를 대상으로는 NULL을 반환할 수 없기 때문에 이러한 상황에서는 bad_cast 예외 발생
		comRef.ShowSimpleInfo(); // 예외의 발생으로 인해 실행되지 못함
	}
	catch(bad_cast expt)
	{
		cout<<expt.what()<<endl; // 예외처리 부분에서도 언급한적 있지만, what 함수는 예외의 원인을 문자열 형태로 반환하며, 컴파일러마다 반환하는 문자열의 내용 차이 존재
	}
	return 0;
}

/*
실행결과
------------------
Bad dynamic_cast!
*/
