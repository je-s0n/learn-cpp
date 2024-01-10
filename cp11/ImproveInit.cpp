#include <iostream>
using namespace std;

/*
실행결과를 보면, BBB객체의 생성과정에서는 복사 생성자만 호출되었는데, CCC 객체의 생성과정에서는 생성자와 대입 연산자까지 호출되었음
-> CCC 객체의 생성과정에서 호출된 함수의 수가 하나 더 많음

이니셜라이저를 이용하면 선언과 동시에 초기화가 이뤄지는 형태로 바이너리 코드가 생성됨
BBB(const AAA& ref) : mem(ref) {} -> AAA mem=ref; // 이니셜라이저를 통한 초기화 구문 비유

생성자의 몸체부분에서 대입연산을 통한 초기화를 진행하면, 선언과 초기화를 각각 별도의 문장에서 진행하는 형태로 바이너리 코드 생성됨
CCC(const AAA& ref) { mem=ref; } -> 객체 mem 초기화 과정에서 생성자와 대입 연산자가 각각 한 번씩 호출된 것

따라서 이니셜라이저를 이용해 초기화를 진행하면, 함수의 호출횟수를 줄일 수 있어 성능향상 기대할 수 있음
*/
class AAA 
{
private:
  int num;
public:
  AAA(int n=0) : num(n)
  {
    cout<<"AAA(int n=0)"<<endl;
  }

  AAA(const AAA& ref):num(ref.num)
  {
    cout<<"AAA(const AAA& ref)"<<endl;
  }

  AAA& operator=(const AAA& ref)
  {
    num=ref.num;
    cout<<"operator=(const AAA& ref)"<<endl;
    return *this;
  }
};

class BBB
{
private:
  AAA mem;
public:
  BBB(const AAA& ref) : mem(ref) {} // 이니셜라이저를 이용해 멤버 초기화
};

class CCC
{
private:
  AAA mem;
public:
  CCC(const AAA& ref) { mem=ref; } // 대입연산을 이용해 멤버 초기화
}

int main(void)
{
  AAA obj1(12);
  cout<<"******************"<<endl;
  BBB obj2(obj1);
  cout<<"******************"<<endl;
  CCC obj3(obj1);
  return 0;
}

/*
실행결과
-----------------------
AAA(int n=0)
******************
AAA(const AAA& ref)
******************
AAA(int n=0)
operator=(const AAA& ref)
*/
