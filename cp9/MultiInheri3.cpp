#include <iostream>
using namespace std;

/*
가상 상속
- virtual 선언이 되지 않은 상태에서 객체가 생성되면 Base 클래스의 멤버가 두 번 포함되어 있음
  -> 하나의 객체 내에 두 개의 Base 클래스 멤버가 존재하면 ComplexFunc 함수 내에서 이름만 가지고 SimpleFunc 함수를 호출할 수 없음
  -> 클래스 명시하여 호출해야 함
- Base 클래스의 멤버가 LastDerived 객체에 하나씩만 존재하는 것이 타당한 경우가 대부분이기 때문에, Base 클래스를 딱 한번만 상속하게끔 하는 것이 현실적인 해결책으로 볼 수 있음
  -> 이를 위한 문법이 가상 상속으로, 가상으로 Base 클래스를 상속하는 두 클래스를 아래 코드와 같이 다중으로 상속하게 될 경우 SimpleFunc 함수를 이름만 가지고 호출할 수 있음
  -> 따라서 실행 결과를 보면 실제로 Base 클래스의 생성자가 한번만 호출되는 것을 확인할 수 있으며, 가상 상속을 하지 않을 경우네는 Base 클래스의 생성자는 두 번 호출됨
*/
class Base
{
public:
  Base() { cout<<"Base Constructor"<<endl; }
  void SimpleFunc() { cout<<"BaseOne"<<endl; }
};

class MiddleDeriveOne : virtual public Base // 가상 상속
{
public:
  MiddleDerivedOne() : Base()
  {
    cout<<"MiddleDerivedOne Constructor"<<endl;
  }

  void MiddleFuncOne()
  {
    SimpleFunc();
    cout<<"MiddleDerivedOne"<<endl;
  }
};

class MiddleDerivedTwo : virtual public Base // 가상 상속
{
public:
  MiddleDerivedTwo() : Base()
  {
    cout<<"MiddleDerivedTwo Constructor"<<endl;
  }

  void MiddleFuncTwo()
  {
    SimpleFunc();
    cout<<"MiddleDerivedTwo"<<endl;
  }
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo 
{
public:
  LastDerived() : MiddleDeriveOne(), MiddleDerivedTwo()
  {
    cout<<"LastDerived Constructor"<<endl;
  }

  void ComplexFunc()
  {
    MiddleFuncOne();
    MiddleFuncTwo();
    SimpleFunc();
  }
};

int main(void)
{
  cout<<"객체생성 전 ..... "<<endl;
  LastDerived ldr;
  cout<<"객체생성 후 ..... "<<endl;
  ldr.ComplexFunc();
  return 0;
}

/*
실행결과
----------------
객체생성 전 ..... 
Base Constructor
MiddleDerivedOne Constructor
MiddleDerivedTwo Constructor
LastDerived Constructor
객체생성 후 ..... 
BaseOne
MiddleDerivedOne
BaseOne
MiddleDerivedTwo
BaseOne
*/
