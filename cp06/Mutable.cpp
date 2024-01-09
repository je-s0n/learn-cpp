#include <iostream>
using namespace std;

class SoSimple
{
private:
  int num1;
  // mutable : const 함수 내에서의 값은 변경을 예외적으로 허용함 -> 가급적 사용의 빈도수를 낮춰야 하는 키워드
  mutable int num2; // const 함수에 대해 예외를 둠

public:
  SoSimple(int n1, int n2)
    : num1(n1), num2(n2)
  {}

  void ShowSimpleData() const
  {
    cout<<num1<<", "<<num2<<endl;
  }

  void CopyToNum2() const
  {
    num2=num1; // const 함수 내에서 num2에 저장된 값을 변경하고 있음 -> num2가 mutable로 선언되었기 때문
  }
};

int main(void)
{
  SoSimple sm(1,2);
  sm.ShowSimpleData();
  sm.CopyToNum2();
  sm.ShowSimpleData();
  return 0;
}

/*
실행결과
------------------------------
1, 2
1, 1
*/
