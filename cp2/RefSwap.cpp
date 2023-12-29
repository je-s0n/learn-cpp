#include <iostream>
using namespace std;

/*
  Call-by-value & Call-by-reference
  1) Call-by-value : 값을 인자로 전달하는 함수의 호출방식
  2) Call-by-reference : 주소 값 또는 참조자를 인자로 전달하는 함수의 호출방식
*/

// 두 참조자를 통해서 값을 교환하는 과정을 거쳐 결과로 val1, val2의 값 교환으로 이어짐
// 매개변수는 함수가 호출되어야 초기화를 진행되는 변수로, 참조자는 매개변수로 사용 가능
void SwapByRef2(int &ref1, int &ref2)
{
  int temp = ref1;
  ref1 = ref2;
  ref2 = temp;
}

int main(void)
{
  int val1 = 10;
  int val2 = 0;

  SwapByRef2(val1, val2); // 매개변수로 참조자가 선언되어 참조의 대상이 될 변수를 인자로 전달함
  cout<<"val1: "<<val1<<endl;
  cout<<"val2: "<<val2<<endl;

  return 0;
}
