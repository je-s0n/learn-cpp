#include <iostream>
using namespace std;

class SoSimple
{
private:
  static int simObjCnt;
public:
  SoSimple()
  {
    simObjCnt++;
    cout<<simObjCnt<<"번째 SoSimple 객체"<<endl;
  }
};
// static 변수를 생성자에서 초기화하면 안되는 이유 : 변수 simObjCnt는 객체가 생성될 때 동시에 생성되는 변수가 아니고, 이미 메모리 공간에 할당이 이뤄진 변수
int SoSimple::simObjCnt=0; // static 멤버변수 초기화 -> 이는 SoSimple 클래스의 static 멤버변수 simObjCnt가 메모리 공간에 저장될 때 0으로 초기화하라는 뜻

class SoComplex
{
private:
  static int cmxObjCnt;
public:
  SoComplex()
  {
    cmxObjCnt++;
    cout<<cmxObjCnt<<"번째 SoComplex 객체"<<endl;
  }

  SoComplex(SoComplex &copy)
  {
    cmxObjCnt++;
    cout<<cmxObjCnt<<"번째 SoComplex 객체"<<endl;
  }
};
int SoComplex::cmxObjCnt=0; // static 멤버변수 초기화

int main(void)
{
  SoSimple sim1;
  SoSimple sim2;

  SoComplex com1;
  SoComplex com2=com1;
  SoComplex();
  return 0;
}


/*
실행결과
--------------------------------------------
1번째 SoSimple 객체
2번째 SoSimple 객체
1번째 SoComplex 객체
2번째 SoComplex 객체
3번째 SoComplex 객체
*/
