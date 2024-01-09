#include <iostream>
using namespace std;

class AAA
{
private:
  int num;
public:
  AAA() : num(0) {}
  AAA& CreateInitObj(int n) const
  {
    AAA * ptr = new AAA(n); // 아래 private Constructor를 이용하여 AAA 객체를 생성 및 반환
    return *ptr;
  }

  void ShowNum() const { cout<<num<<endl; }
private:
  AAA(int n) : num(n) {} // Private Constructor
};

int main(void)
{
  AAA base;
  base.ShowNum();

  AAA &obj1=base.CreateInitObj(3);
  obj1.ShowNum();

  AAA &obj2=base.CreateInitObj(12);
  obj2.ShowNum();

  delete &obj1;
  delete &obj2;
  return 0;
}
