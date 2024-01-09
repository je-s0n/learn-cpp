#include <iostream>
using namespace std;

class BaseOne
{
public:
  void SimpleFuncOne() { cout<<"BaseOne"<<endl; }
};

class BaseTwo
{
public:
  void SimpleFuncTwo() { cout<<"BaseTwo"<<endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo // 콤마를 이용해서 상속 대상이 되는 클래스를 구분하여 명시 -> 다중 상속
{
public:
  void ComplexFunc()
  {
    // BaseOne 클래스의 멤버함수와 BaseTwo 클래스의 멤버함수를 각각 호출하고 있음 -> 다중상속을 해서 가능한 일
    SimpleFuncOne();
    SimpleFuncTwo();
  }
};

int main(void)
{
  MultiDerived mdr;
  mdr.ComplexFunc();
  return 0;
}

/*
실행결과
-----------------
BaseOne
BaseTwo
*/
