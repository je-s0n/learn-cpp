#include <iostream>
using namespace std;

class SoSimple
{
private:
  int num;
public:
  SoSimple(int n) : num(n)
  {}

  SoSimple& AddNum(int n)
  {
    num += n;
    return *this;
  }

  void ShowData() const
  {
    cout<<"num: "<<num<<endl;
  }
};

int main(void)
{
  // 멤버변수에 저장된 값을 수정하지 않는 함수는 가급적 const로 선언해서 const 객체에서도 호출 가능하도록 할 필요 있음
  const SoSimple obj(7); // const 객체 생성
  // obj.AddNum(20);
  obj.ShowData();
  return 0;
}
