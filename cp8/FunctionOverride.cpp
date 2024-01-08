#include <iostream>
using namesapce std;

/*
  Second * sptr = new Third(); // 컴파일 
  Third * tptr = sptr; // 컴파일 에러
  -> C++의 컴파일러는 포인터 연산의 가능성 여뷰를 판단할 때, 포인터의 자료형을 기준으로 판단하지, 실제 가리키는 객체의 자료형을 기준으로 판단하지 않음
  포인터 sptr의 포인터 형만을 가지고 대입의 가능성 판단함
  컴파일러는 앞서 sptr이 실제로 가리키는 객체가 Third 객체라는 사실을 기억하지 않고, 문장이 성립하지 않는다고 판단하여 컴파일 에러 발생

  Third * tptr = new Third(); // 컴파일 
  Second * sptr = tptr; // 컴파일
  -> tptr는 Third 클래스의 포인터 변수니까, 이 포인터가 가리키는 객체는 분명 Second 클래스를 직접 혹은 간접적으로 상속하는 객체이므로 참조 가능함
*/
class First
{
public:
  void MyFunc() { cout<<"FirstFunc"<<endl;}
};

class Second : public First
{
public:
  void MyFunc() { cout<<"SecondFunc"<<endl; }
};

class Third : public Second
{
public:
  void MyFunc() { cout<<"ThirdFunc"<<endl; }
}

int main(void)
{
  Third * tptr = new Third();
  Second * sptr = tptr;
  First * fptr = sptr;

  fptr -> MyFunc(); // 컴파일러 판단 : fptr이 First형 포인터이니, 이 포인터가 가리키는 객체를 대상으로 First클래스에 정의된 MyFunc함수는 무조건 호출할 수 있음
  sptr -> MyFunc(); // 컴파일러 판단 : sptr이 Second형 포인터이니, 이 포인터가 가리키는 객체에는 First클래스의 MyFunc함수와 Second클래스의 MyFunc함수가 오버라이딩 관계로 존재하여 오버라이딩 한 Second의 MyFunc함수 호출
  tptr -> MyFunc();
  delete tptr;
  return 0;
}

/*
실행결과
---------------
FirstFunc
SecondFunc
ThirdFunc
*/
