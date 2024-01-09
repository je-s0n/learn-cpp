#include <iostream>
using namespace std;

/*
pos1.operator+(pos2)와 pos1 + pos2는 동일한 문장
-> C++에서 operator 키워드와 연산자를 묶어서 함수의 이름을 정의하면 함수의 이름을 이용한 함수의 호출뿐만 아니라, 연산자를 이용한 함수의 호출도 허용함

연산자를 오버로딩 하는 두 가지 방법
1) 멤버함수에 의한 연산자 오버로딩 -> pos1.operator+(pos2);
2) 전역함수에 의한 연산자 오버로딩 -> operator+(pos1, pos2);
-> 동일한 자료형을 대상으로 + 연산자를 전역함수 기반으로, 그리고 멤버함수 기반으로 동시에 오버로딩 할 경우, 1의 경우가 2의 경우보다 우선시되어 호출됨
*/
class Point
{
private:
  int xpos, ypos;
public:
  Point(int x=0, int y=0) : xpos(x), ypos(y)
  {}

  void ShowPosition() const
  {
    cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
  }

  Point operator+(const Point &ref) // operator+이름을 가진 함수
  {
    Point pos(xpos + ref.xpos, ypos+ref.ypos);
    return pos;
  }
};

int main(void)
{
  Point pos1(3,4);
  Point pos2(10,20);
  Point pos3 = pos1 + pos2; // pos1과 pos2를 더한 결과 저장
  
  pos1.ShowPosition();
  pos2.ShowPosition();
  pos3.ShowPosition();
  return 0;
}

/*
실행결과
---------------
[3, 4]
[10, 20]
[13, 24]
*/
