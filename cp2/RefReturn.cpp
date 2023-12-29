#include <iostream>
using namespace std;

/*
  반환형이 참조형인 RefRetFunc 함수가 존재할 때 두가지 형태로 저장 가능
  int num = RefRetFunc(num1); // O
  int &num = RefRetFunc(num1); // O
  
  반환형이 기본자료형인 RefRetFunc 함수가 존재할 때 반환 값은 반드시 변수에 저장해야 함
  int num = RefRetFunc(num1); // O
  int &num = RefRetFunc(num1); // X
*/
int& RefRetFunc(int &ref) // 함수의 반환형에도 참조형이 선언될 수 있음
{
  ref ++;
  return ref;
}

int main(void)
{
  int num1=1;
  int num2=RefRetFuncOne(num1);

  num1 += 1;
  num2 += 100;

  cout<<"num1: "<<num1<<endl; // 3
  cout<<"num2: "<<num2<<endl; // 102
  return 0; 
}
