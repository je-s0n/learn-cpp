#include <iostream>
using namespace std;

/*
참조자는 변수를 대상으로만 선언이 가능하며, &연산자를 이용해서 주소 값을 반환 받을 수도 있음
함수 내에서 선언된 지역적 참조자는 지역벼수와 마찬가지로 함수를 빠져나가면 소멸됨
참조자는 변수에 대해서만 선언이 가능하고, 선언됨과 동시에 누군가를 참조해야만 함
*/
int main(void)
{
  int num1=1020;
  int &num2=num1; // num1에 대한 참조자 num2 선언함 -> num1과 num2가 동일하게 메모리 공간을 참조하게 됨

  num2=3047;
  cout<<"VAL: "<<num1<<endl; // 3047
  cout<<"REF: "<<num2<<endl; // 3047

  cout<<"VAL: "<<&num1<<endl; // 0012FF60
  cout<<"REF: "<<&num2<<endl; // 0012FF60
  return 0;
}
