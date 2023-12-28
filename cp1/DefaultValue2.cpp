#include <iostream>

/*
매개변수의 디폴트 값은 오른쪽 매개변수의 디폴트 값부터 채우는 형태로 정의해야 함
e.g.  int YourFunc(int num1, int num2, int num3 = 30) { ... }
      int YourFunc(int num1, int num2 = 20, int num3 = 30) { ... }
      int YourFunc(int num1 = 10, int num2 = 20, int num3 = 30) { ... }
*/
int Adder(int num1 = 1, int num2 = 2);

int main(void) {
  std::cout<<Adder()<<std::endl;
  std::cout<<Adder(5)<<std::endl;
  std::cout<<Adder(3,5)<<std::endl;
  return 0;
}


int Adder(int num1, int num2)
{
  return num1 + num2;
}
