/*
두 함수 오버로딩 가능
void SimpleFunc() {}
void SimpleFunc() const {}
*/
#include <iostream>
using namespace std;

class SoSimple
{
private:
  int num;
public:
  SoSimple(int n) : num(n)
  {}

  SoSimple& AddNum(int n)
  {
    num += n;
    return *this;
  }

  void SimpleFunc()
  {
    cout<<"SimpleFunc: "<<num<<endl;
  }

  void SimpleFunc() const
  {
    cout<<"const SimpleFunc: "<<num<<endl;
  }
};

void YouerFunc(const SoSimple &obj)
{
  obj.SimpleFunc();
}

int main(void)
{
  SoSimple obj1(2); // 일반 객체 생성
  const SoSimple obj2(7); // const 객체 생성

  obj1.SimpleFunc(); // 일반 객체를 대상으로 일반 멤버함수 호출
  obj2.SimpleFunc(); // const 객체를 대상으로 const 멤버함수 호출

  YourFunc(obj1); // YourFunc함수는 전달되는 인자를 const 참조자로 받음 -> 참조자를 이용한 obj.SimpleFunc() 결과로 const 멤버함수가 호출됨
  YourFunc(obj2);
  return 0;
}

/*
실행결과
--------------------------------
SimpleFunc: 2
const SimpleFunc: 7
const SimpleFunc: 2
const SimpleFunc: 7
*/
