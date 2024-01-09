/*
Self-Reference : 객체 자신을 참조할 수 있는 참조자를 의미함
- this 포인터를 이용해서 객체가 자신의 참조에 사용할 수 있는 참조자의 반환문을 구성할 수 있음
*/
#include <iostream>
using namespace std;

class SelfRef
{
private:
  int num;
public:
  // 반환의 내용은 *this인데, 이 문장을 실행하는 객체 자신의 포인터가 아닌, 객체 자신을 반환하겠다는 의미
  // 반환형이 참조형 SelfRef& 으로 선언되었으므로, 객체 자신을 참조할 수 있는 참조의 정보 반환됨
  SelfRef(int n) : num(n)
  {
    cout<<"객체생성"<<endl;
  }
  
  SelfRef& Adder(int n)
  {
    num += n;
    return *this;
  }
  
  SelfRef& ShowTwoNumber()
  {
    cout<<num<<endl;
    return *this;
  }
};

int main(void)
{
  SelfRef obj(3);
  // 객체 자신의 참조 값을 반환하며, 참조자 ref는 객체 obj를 참조하게 됨
  SelfRef &ref = obj.Adder(2);

  obj.ShowTwoNumber();
  ref.ShowTwoNumber();

  // Adder, ShowTwoNumber 함수가 객체의 참조 값을 반환하기 때문에 구성이 가능한 문장
  ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
  return 0;
}
