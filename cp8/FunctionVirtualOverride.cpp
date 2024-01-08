#include <iostream>
using namesapce std;

/*
FunctionOverride.cpp을 보면서, "함수를 오버라이딩 했다는 것은 해당 객체에서 호출되어야 하는 함수를 바꾼다는 의미인데, 포인터 변수의 자료형에 따라 호출되는 함수의 종류가 달라지는 것은 문제가 있어보인다"는 생각할 수 있음
위와 같은 생각에 대비하여 가상함수 (Virtual Function) 제공함
가상함수의 선언은 virtual 키워드를 통해 선언하며, First 클래스의 MyFunc 함수가 virtual로 선언하면 Second 클래스의 MyFunc 함수도, Third 클래스의 MyFunc 함수도 가상함수가 됨
*/
class First
{
public:
  virtual void MyFunc() { cout<<"FirstFunc"<<endl;}
};

class Second : public First
{
public:
  virtual void MyFunc() { cout<<"SecondFunc"<<endl; } // First 클래스 외 굳이 virtual 선언하지 않아도 되지만, 알리는 것이 좋기 때문에 선언함
};

class Third : public Second
{
public:
  virtual void MyFunc() { cout<<"ThirdFunc"<<endl; } // First 클래스 외 굳이 virtual 선언하지 않아도 되지만, 알리는 것이 좋기 때문에 선언함
}

int main(void)
{
  Third * tptr = new Third();
  Second * sptr = tptr;
  First * fptr = sptr;

  fptr -> MyFunc(); 
  sptr -> MyFunc();
  tptr -> MyFunc();
  delete tptr;
  return 0;
}

/*
실행결과
---------------
ThirdFunc
ThirdFunc
ThirdFunc
*/
