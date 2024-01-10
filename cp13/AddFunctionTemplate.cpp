#include <iostream>
using namespace std;

/*
함수 템플릿
- 함수 템플릿은 함수를 만들어 내며, 함수의 기능은 결정되어 있지만 자료형은 겨정되어 있지 않아 결정해야 함 -> 함수를 만드는 도구

템플릿으로 정의하면, 매 호출문장마다 함수를 만들지 않고, 컴파일 할 때 자료형당 하나씩만 만들어짐
-> 컴파일 할 때 만들어지기 때문에 속도 감소 발생하지만, 실행속도가 아닌 컴파일 속도이므로 신경 쓸 요소까진 아님
*/

// 덧셈 기능을 하는 함수 템플릿, T : 자료형을 결정짓지 않겠다는 의미로 사용
template <typename T> // T라는 이름을 이용해서 아래 함수를 템플릿으로 정의한다는 의미
// int형 덧셈을 진행하는 Add 함수와 double형 덧셈을 진행하는 Add함수를 만듦
T Add(T num1, T num2) 
{
	return num1+num2;
}

int main(void)
{
	cout<< Add<int>(15, 20)			<<endl; // T가 int인 경우 Add<int>()
	cout<< Add<double>(2.9, 3.7)	<<endl; // T가 double인 경우 Add<int>()
	cout<< Add<int>(3.2, 3.2)		<<endl; // T가 int인 함수를 호출하면서 double형 실수를 전달하니, 그 과정에서 값의 손실 발생함
	cout<< Add<double>(3.14, 2.75)	<<endl;

  /*
  아래와 같이 사용 가능
  -> 컴파일러가 인자의 자료형으로 T가 어떤 자료형이어야 하는지를 판단하기 때문
  cout<< Add(15, 20)		<<endl; // 35
	cout<< Add(2.9, 3.7)	<<endl; // 6.6
	cout<< Add(3.2, 3.2)	<<endl; // 6.4
	cout<< Add(3.14, 2.75)	<<endl; // 5.89
  */
	return 0;
}

/*
실행결과
----------------
35
6.6
6
5.89
*/
