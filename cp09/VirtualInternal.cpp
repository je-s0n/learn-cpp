#include <iostream>
using namespace std;

/*
가상함수의 동작원리
- AAA클래스와 BBB클래스의 멤버변수들은 형식적으로 선언한 으로 무시해도 좋으며, 멤버변수의 초기화에 필요한 생성자도 정의하지 않음

- AAA클래스의 가상함수 테이블(V-table, Virtual Table) 
- key : 호출하고자 하는 함수를 구분 지어주는 구분자 역할
- value : 구분자에 해당하는 함수의 주소정보를 알려주는 역할
  -> 컴파일러가 한 개 이상의 가상함수를 포함하는 클래스에 대해서 만듦
  key                  value
  void AAA::Func1()    0x1024번지
  void AAA::Func2()    0x2048번지

  
- BBB클래스의 가상함수 테이블(V-table, Virtual Table) 
  key                  value
  void BBB::Func1()    0x3072번지
  void AAA::Func2()    0x2048번지
  void BBB::Func3()    0x4096번지

AAA 클래스의 오버라이딩 된 가상함수 Func1에 대한 정보가 존재하지 않음
- 오버라이딩 된 가상함수의 주소정보는 유도 클래스의 가상함수 테이블에 포함되지 않음
  -> 때문에 오버라이딩 된 가상함수를 호출하면, 무조건 가장 마지막에 오버라이딩을 한 유도 클래스의 멤버함수 호출되는 것
*/
class AAA
{
private:
  int num1;
public:
  virtual void Fucn1() { cout<<"Func1"<<endl; }
  virtual void Fucn2() { cout<<"Func2"<<endl; }
};

class BBB : public AAA
{
private:
  int num2;
public:
  virtual void Func1() { cout<<"BBB::Func1"<<endl; }
  void Func3() { cout<<"Func3"<<endl; }
};

int main(void)
{
  AAA * aptr = new AAA();
  aptr -> Func1();

  BBB * bptr = new BBB();
  bptr -> Func1();
  return 0;
}

/*
실행결과
--------------
Func1
BBB::Func1
*/


