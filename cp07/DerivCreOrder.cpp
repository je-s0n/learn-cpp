#include <iostream>
using namespace std;

/*
- e.g. line 68 SoDerived dr3(23,24); -> 기본적으로 메모리 공간이 할당된 다음에 생성자가 호출되어야 함
- 유도 클래스의 객체생성 과정에서 기초 클래스의 생성자는 100% 호출됨
- 유도 클래스의 생성자에서 기초 클래스의 생성자 호출을 명시하지 않으면, 기초 클래스의 void 생성자가 호출됨
*/
class SoBase
{
private:
  int baseNum;
public:
  SoBase() : baseNum(20)
  {
    cout<<"SoBase()"<<endl;
  }
  
  SoBase(int n) : baseNum(n)
  {
    cout<<"SoBase(int n)"<<endl;
  }

  void ShowBaseData()
  {
    cout<<baseNum<<endl;
  }
};

class SoDerived : public SoBase
{
private: 
  int derivNum;
public:
  SoDerived() : derivNum(30)
  {
    cout<<"SoDerived()"<<endl;
  }

  SoDerived(int n) : derivNum(n)
  {
    cout<<"SoDerived(int n)"<<endl;
  }

  SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
  {
    cout<<"SoDerived(int n1, int n2)"<<endl;
  }

  void ShowDerivData()
  {
    ShowBaseData();
    cout<<derivNum<<endl;
  }
};

int main(void)
{
  cout<<"case1..... "<<endl;
  SoDerived dr1;
  dr1.ShowDerivData();
  cout<<"----------------"<<endl;
  cout<<"case2..... "<<endl;
  SoDerived dr2;
  dr2.ShowDerivData();
  cout<<"----------------"<<endl;
  cout<<"case3..... "<<endl;
  SoDerived dr3(23,24);
  dr3.ShowDerivData();
  return 0;
}

/*
실행결과
-----------------
case1..... 
SoBase()
SoDerived()
20
30
----------------
case2..... 
SoBase()
SoDerived(int n)
20
12
----------------
case3.....
SoBase(int n)
SoDerived(int n1, int n2)
23
24
*/
