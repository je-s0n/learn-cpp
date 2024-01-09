#include <iostream>
using namespace std;

// 두개의 전역변수 선언
// 하지만 이 둘은 SoSimple 클래스를 위한 전역변수, SoComplex 클래스를 위한 전역변수로 모두 전역변수인데, 이 제한을 지켜줄만한 아무런 장치도 존재하지 않음 (어디서든 접근 가능)
// static 멤버로 선언하면 문제 소지 없앨 수 있음 (StaticMemeber.cpp 참고)
int simObjCnt=0; // SoSimple 클래스를 위한 전역변수
int cmxObjCnt=0; // SoComplex 클래스를 위한 전역변수

class SoSimple
{
public:
  SoSimple()
  {
    simObjCnt++;
    cout<<simObjCnt<<"번째 SoSimple 객체"<<endl;
  }
};

class SoComplex
{
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
