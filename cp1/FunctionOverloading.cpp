#include <iostream>

/*
함수 오버로딩 : 동일한 이름의 함수 정의 허용
C는 오버로딩을이 불가능하며 문법적으로도 허용하지 않지만, C++의 경우 허용하는데 그 이유로는 호출할 함수를 찾는 방법이 서로 다르기 때문
C++은 호출할 함수를 찾을 때 '함수의 이름', '매개변수의 선언' 정보를 활용하여 찾음
*/

void MyFunc(void) 
{
  std::cout<<"MyFunc(void) called"<<std::endl;
}

void MyFunc(char c) 
{
  std::cout<<"MyFunc(char c) called"<<std::endl;
}

void MyFunc(int a, int b) 
{
  std::cout<<"MyFunc(int a, int b) called"<<std::endl;
}

int main(void)
{
  MyFunc();
  MyFunc('A');
  MyFunc(12, 13);
  return 0;
}
