#include <iostream>
using namespace std;

/*
dynamic_cast는 Polymorphic 클래스 기반의 형 변환에 사용되기도 함
(앞서 설명한 내용은 상속관계에서의 안전한 형변환 (유도 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환에 사용되는 것으로 설명)

[상속 관련된 형 변환]
1) 상속관계에 놓여있는 두 클래스 사이에서, 유도 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환할 경우에는 dynamic_cast 연산자 사용
2) 반대로 상속관계에 놓여있는 두 클래스 사이에서 기초 클래스의 포인터 및 참조형 데이터를 유도 클래스의 포인터 및 참조형 데이터로 형 변환할 경우에는 static_cast 연산자 사용
하지만, dynamic_cast 연산자도 기초 클래스의 포인터 및 참조형 데이터를 유도 클래스의 포인터 및 참조형으로의 형 변환을 허용함 -> 기초 클래스가 Polymorphic 클래스일 경우

cf. Polymorphic 클래스 : 하나 이상의 가상함수를 지니는 클래스를 뜻함
상속 관계에 놓여있는 두 클래스 사이에서 기초 클래스에 가상함수가 하나 이상 존재하면, dynamic_cast 연산자를 이용해서 기초 클래스의 포인터 및 참조형 데이터를 유도 클래스의 포인터 및 참조형 데이터로 변환이 가능함
*/
class SoSimple // Polymorphic class
{
public:
	virtual void ShowSimpleInfo() // 예제를 통해 먼저 확인할 사실 : 여기서 정의된 ShowSimpleInfo함수에서 virtual 선언 존재 유무에 따른 컴파일 결과 -> virtual 선언하지 않았을 때는 에러 발생
	{
		cout<<"SoSimple Base Class"<<endl;
	}
};

class SoComplex : public SoSimple // SoSimple 클래스가 Polymorphic class이라서 SoComplex 클래스도 Polymorphic class임
{
public:
	void ShowSimpleInfo()
	{
		cout<<"SoComplex Derived Class"<<endl;
	}
};

int main(void)
{
	SoSimple * simPtr=new SoComplex; // simPtr이 가리키는 것은 SoComplex 객체임
	SoComplex * comPtr=dynamic_cast<SoComplex*>(simPtr); // 기초 클래스인 SoSimple형 포인터 변수 simPtr을 유도 클래스인 SoComplex형 포인터로 형 변환 하고 있음 -> 기초 클래스인 SoSimple 클래스가 Polymorphic class라서 dynamic_cast연산자로 형 변환 가능
	comPtr->ShowSimpleInfo();
	return 0;
}

/*
실행결과
-------------------------
SoComplex Derived Class
*/
