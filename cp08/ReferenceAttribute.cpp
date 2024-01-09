#include <iostream>
using namespace std;

/*
참조자의 참조 가능성
포인터 관련하여 "C++에서 AAA형 포인터 변수는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다(객체의 주소 값을 저장할 수 있다)" 라고 설명함
그런데, 이러한 특성은 참조자에도 적용이 되어 아래 문장 또한 성립됨
- "C++에서 AAA형 참조자는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 참조할 수 있다"

아래 예시에서
"First형 참조자를 이용하면 First 클래스에 정의된 MyFunc 함수가 호출되고, Second형 참조자를 이용하면 Second 클래스에 정의된 MyFunc 함수가 호출되고, Third형 참조자를 이용하면 Third 클래스에 정의된 MyFunc 함수가 호출됨"

void GoodFunction(const First &ref)
{ ... }
- First 객체 또는 First를 직접 혹은 간접적으로 상속하는 클래스의 객체가 인자의 대상이 됨
- 인자로 전달되는 객체의 실제 자료형에 상관없이 함수 내에서는 First 클래스에 정의된 함수만 호출할 수 있음
*/

class First
{
public:
  void FirstFunc() { cout<<"FirstFunc()"<<endl; }
  virtual void SimpleFunc() { cout<<"First's SimpleFunc()"<<endl; }
};

class Second : public First
{
public:
  void SecondFunc() { cout<<"SecondFunc()"<<endl; }
  virtual void SimpleFunc() { cout<<"Second's SimpleFunc()"<<endl; }
};

class Third : public Second
{
public:
  void ThirdFunc() { cout<<"ThirdFunc()"<<endl; }
  virtual void SimpleFunc() { cout<<"Third's SimpleFunc()"<<endl; }
};

int main(void)
{
  Third obj;
  obj.FirstFunc();
  obj.SecondFunc();
  obj.ThirdFunc();
  obj.SimpleFunc();

  Seconde & sref = obj; // obj는 Second를 상속하는 Third 객체이므로, Second형 참조자로 참조 가능
  // 컴파일러는 참조자의 자료형을 가지고 함수의 호출 가능성을 판단하기 때문에 First 클래스에 정의된 FirstFunc 함수와 Second 클래스에 정의된 SecondFunc 함수는 호출 가능하지만, Third 클래스에 정의된 ThirdFunc 함수는 호출 불가능함
  sref.FirstFunc();
  sref.SecondFunc();
  sref.SimpleFunc(); // SimpleFunc 함수는 가상함수이므로, Third 클래스에 정의된 SimpleFunc 함수 호출
  
  First & fref = obj;
  fref.FirstFunc(); // 컴파일러는 참조자의 자료형을 가지고 함수의 호출 가능성을 판단하기 때문에 First 클래스에 정의된 함수만 호출 가능
  fref.SimpleFunc(); // SimpleFunc 함수는 가상함수이므로, Third 클래스에 정의된 SimpleFunc 함수 호출
  return 0;
}

/*
실행결과
--------------------------
FirstFunc()
SecondFunc()
ThirdFunc()
Third's SimpleFunc()
FirstFunc()
SecondFunc()
Third's SimpleFunc()
FirstFunc()
Third's SimpleFunc()
*/
