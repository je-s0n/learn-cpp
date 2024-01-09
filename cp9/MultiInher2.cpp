#include <iostream>
using namespace std;

/*
다중상속의 모호성(Ambiguous)
- 다중상속의 대상이 되는 두 기초 클래스에 동일한 이름의 멤버가 존재하는 경우 문제 발생 가능성 있음
- 이러한 경우에는 유도 클래스 내에서 멤버의 이름만으로 접근 불가능하며, 이름만으로 접근하려 한다면 컴파일러 에러 발생할 것
*/
class BaseOne
{
public:
  void SimpleFunc() { cout<<"BaseOne"<<endl; }
};

class BaseTwo
{
public:
  void SimpleFunc() { cout<<"BaseTwo"<<endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
  void ComplexFunc()
  {
    // 어느 클래스에 정의된 함수의 호출을 원하는지 명시 필요
    BaseOne::SimpleFunc();
    BaseTwo::SimpleFunc();
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
