#include <iostream>
using namespace std;

class SoSimple
{
private:
  static int simObjCnt;
public:
  SoSimple() // 불필요하지만 변수와 하수의 구분을 목적으로 삽입하기도 함
  {
    simObjCnt++;
  }
};
int SoSimple:simObjCnt = 0; // static 변수 초기화

int main(void)
{
  cout<<SoSimple::simObjCnt<<"번째 SoSimple 객체"<<endl; // SoSimple 객체를 하나도 생성하지 않은 상태임에도 불구하고 클래스의 이름을 이용해 simObjCnt에 접근
  SoSimple sim1;
  SoSimple sim2;

  cout<<SoSimple::simObjCnt<<"번째 SoSimple 객체"<<endl;

  // 두 문장에서 보이듯이 객체를 이용해서도 static 멤버변수에 접근 가능 -> 이러한 형태의 접근은 추천하지 않으며, 멤버변수에 접근하는 것과 같은 오해를 불러일으킴
  cout<<sim1.simObjCnt<<"번째 SoSimple 객체"<<endl;
  cout<<sim2.simObjCnt<<"번째 SoSimple 객체"<<endl;
  return 0;
}

/*
실행결과
-------------------------------------------
0번째 SoSimple 객체
2번째 SoSimple 객체
2번째 SoSimple 객체
2번째 SoSimple 객체
*/
