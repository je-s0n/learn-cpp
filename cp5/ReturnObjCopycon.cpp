#include <iostream>
using namespace std;

class SoSimple
{
private:
  int num;
public:
  SoSimple(int n) : num(n)
  {}

  SoSimple(const SoSimple& copy) : num(copy.num)
  {
    cout<<"Called SoSimple(const SoSimple& copy)"<<endl;
  }

  SoSimple& AddNum(int n)
  {
    num += n;
    return *this; // 반환형이 참조형으로 참조 값이 반환됨
  }

  void ShowData() 
  {
    cout<<"num: "<<num<<endl;
  }
};

SoSimple SimpleFuncObj(SoSimple ob) // 매개변수 선언을 봤을 때 인자의 전달과정에서 복사 생성자 호출됨
{
  cout<<"return 이전"<<endl;
  /*
  객체를 반환하게 되면, '임시객체'라는 것이 생성되며 최종적으로 반환됨
  함수호출이 완료되고 나면, 지역적으로 선언된 갹체 ob는 소멸되고 obj객체와 임시객체만 남음
  */
  return ob; // ob객체를 반환하고 있지만, 반환형이 참조형이 아님 -> ob 객체의 복사본이 만들어지면서 반환이 진행됨
}

int main(void)
{
  SoSimple obj(7);
  SimpleFuncObj(obj).AddNum(30).ShowData();
  obj.ShowData();
  return 0;
}

/*
실행결과
----------------------------------------
Called SoSimple(const SoSimple& copy)
return 이전
Called SoSimple(const SoSimple& copy)
num: 37
num: 7
*/
