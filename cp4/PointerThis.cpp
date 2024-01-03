#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
private:
  int num;
public:
  SoSimple(int n) : num(n)
  {
    cout<<"num="<<num<<", ";
    cout<<"address="<<this<<endl;
  }

  void ShowSimpleData()
  {
    cout<<num<<endl;
  }
  
  SoSimple * GetThisPointer()
  {
    return this; // 이 문장을 실행하는 객체의 포인터를 반환하라는 의미로, 반환형도 SoSimple* 형으로 선언되어 있음
  }
};

int main(void)
{
  SoSimple sim1(100);
  // 객체 sim1에 의해 반환된 this를 ptr1에 저장하며, 이 때 this는 SoSimple의 포인터이므로 SoSimple형 포인터 변수에 저장해야 함
  SoSimple * ptr1 = sim1.GetThisPointer();
  cout<<ptr1<<", "; // 포인터 주소값 출력
  ptr1 -> ShowSimpleData();
  
  SoSimple sim2(200);
  SoSimple * ptr2 = sim2.GetThisPointer(); // sim2 객체 주소값 저장
  cout<<ptr2<<", ";
  ptr2 -> ShowSimpleData();
}
