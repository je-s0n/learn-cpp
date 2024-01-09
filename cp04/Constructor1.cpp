/*
생성자(Constructor)
1) 클래스의 이름과 함수의 이름이 동일함
2) 반환형이 선언되어 있지 않으며, 실제로 반환하지 않음
3) 객체 생성 시 딱 한번 호출됨
4) 생성자도 함수의 일종이기 때문에 오버로딩 가능함
5) 생성자도 함수의 일종이니 매개변수에 Default Value 설정 가능
*/
#include <iostream>
using namespace std;

class SimpleClass
{
private:
  int num1;
  int num2;
public:
  SimpleClass()
  {
    num1=0;
    num2=0;
  }

  // 생성자 오버로딩
  SimpleClass(int n)
  {
    num1=n;
    num2=0;
  }
  
  // 생성자 오버로딩
  SimpleClass(int n1, int n2)
  {
    num1=n1;
    num2=n2;
  }

  /*
  SimpleClass(int n1=0, int n2=0)
  {
    num1=n1;
    num2=n2;
  }
  */

  void ShowData() const
  {
    cout<<num1<<' '<<num2<<endl;
  }
};

int main(void)
{
  // SimpleClass sc1(); (X)
  // SimpleClass sc1; (O)
  // SimpleClass * ptr1 = new SimpleClass; (O)
  // SimpleClass * ptr1 = new SimpleClass(); (O)
  SimpleClass sc1;
  sc1.ShowData();

  SimpleClass sc2(100);
  sc2.ShowData();

  SimpleClass sc3(100,200);
  sc3.ShowData();
  return 0;
}
