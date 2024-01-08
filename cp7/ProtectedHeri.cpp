/*
잘못된 예제 -> 실행 X
*/
#include <iostream>
using namespace std;

/*
protected로 선언된 멤버변수는 이를 상속하는 유도 클래스에서 접근 가능함
-> private과 protected의 유일한 차이점으로, 유도 클래스에게만 제한적으로 접근을 허용한다는 측면에서 유용하게 사용될 수 있는 키워드
-> 기본적으로 기초 클래스와 이를 상속하는 유도 클래스 사이에서도 정보 은닉은 지켜지는 것이 좋음
*/
class Base
{
private:
  int num1;
protected:
  int num2;
public:
  int num3;

  Base() : num1(1), num2(2), num3(3)
  {}
};

// protected 상속 의미 : protected보다 접근 범위가 넓은 멤버는 protected로 변경시켜서 상속함
class Derived : protected Base {}; // empty

int main(void)
{
  Derived drv;
  // Base 클래스를 protected로 상속했기 때문에 public 멤버변수인 num3는 Derived 클래스에서 protected 멤버가 되어 외부에서 접근이 불가능한 멤버가 된 것임
  cout<<drv.num3<<endl; // 컴파일 에러
  return 0;
}
