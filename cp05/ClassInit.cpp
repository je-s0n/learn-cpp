#include <iostream>
using namespace std;

class SoSimple
{
private:
  int num1;
  int num2;
public:
  SoSimple(int n1, int n2)
    : num1(n1), num2(n2)
  {
    // empty
  }

  // SoSimple 객체를 인자로 받는 생성자가 추가되었으며, 아래 행에서는 이니셜라이저를 이용해 멤버 대 멤버의 복사를 진행 
  // 복사 생성자라고 하며, 이 생성자가 호출되는 시점이 다른 일반 생성자와 차이 존재
  // 복사 생성자를 정의하지 않으면, 멤버 대 멤버의 복사를 진행하는 디폴트 복사 생성자가 자동으로 삽입됨

  /*
  explict 키워드 : SoSimple sim2 = sim1; 코드가 묵시적 변환이 일어나서 SoSimple sim2(sim1); 형태로 복사 생성자 호출하는 것을 허용하지 않는 키워드
  e.g. 대입 연산자를 이용한 객체의 생성 및 초기화 불가능
  explict SoSimple(const SoSimple &copy)
    : num1(copy.n1), num2(copy.n2)
  {
      cout<<"Called SoSimple(SoSimple &copy)"<<endl;
  }
  */

  SoSimple(SoSimple &copy)
    : num1(copy.n1), num2(copy.n2)
  {
      cout<<"Called SoSimple(SoSimple &copy)"<<endl;
  }

  void ShowSimpleData()
  {
    cout<<num1<<endl;
    cout<<num2<<endl;
  }
};

int main(void)
{
  SoSimple sim1(15, 30);
  cout<<"생성 및 초기화 직전"<<endl;
  
  /*
  SoSimple sim2(sim1);
  - SoSimple형 객체를 생성
  - 객체 이름은 sim2로 정함
  - sim1을 인자로 받을 수 있는 생성자의 호출을 통해서 객체 생성 완료
  */ 
  
  SoSimple sim2 = sim1; // SoSimple sim2(sim1) 으로 변환 가능
  cout<<"생성 및 초기화 직후"<<endl;
  sim2.ShowSimpleData();
  return 0;
}
