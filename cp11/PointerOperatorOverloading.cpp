#include <iostream>
using namespace std;

/*
포인터 연산자 : 포인터를 기반으로 하는 연산자

대표적인 포인터 연산자
->   포인터가 가리키는 객체의 멤버에 접근
*    포인터가 가리키는 객체에 접근
-> 둘 다 피연산자가 하나인 단항 연산자의 형태로 오버로딩 된다는 특징 가지고 있음
*/
class Number
{
private:
	int num;
public:
	Number(int n) : num(n) {  }
	void ShowData() { cout<<num<<endl; }

	Number * operator->() // 이 함수는 객체 자신의 주소 값을 반환하도록 -> 연산자를 오버로딩 하고 있음 -> 연산자를 다른 형태로 오버로딩 하는 것도 가능하지만, 이 연산자의 오버로딩을 허용하는 이유는 주소 값의 반환이 목적이기 때문에 다른 형태로 오버로딩 하지 않는 것이 좋음
	{
		return this;
	}

	Number & operator*() // 이 함수는 객체 자신을 참조의 형태로 반환하도록 * 연산자를 오버로딩 하고 있음
	{
		return *this;
	}
};

int main(void)
{
	Number num(20);
	num.ShowData();
	(*num)=30; // 객체 num이 포인터 변수인 것처럼 연산문 구성되었고, 이는 * 연산자의 오버로딩 결과 (num.operator*()) = 30으로 표현 가능
	num->ShowData(); // num이 포인터 변수처럼 사용되었으며, 이는 -> 연산자의 오버로딩 결과는 아래 설명 작성
  /*
  위 코드를 일반적인 해석의 방법을 적용하면 num.operator->() ShowData();와 같지만, 멤버함수 operator->()가 반환하는 것은 주소 값이기 때문에 ShowData 함수의 호출은 문법적으로 성립하지 않음
  때문에 반환되는 주소 값을 대상으로 적절한 연산이 가능하도록 -> 연산자를 하나 더 추가하여 num.operator->()->ShowData();로 해석을 진행함
  */
	(*num).ShowData(); // (num.operator*()).ShowData();로 표현 가능

	return 0;
}

/*
실행결과
--------------
20
30
30
*/
