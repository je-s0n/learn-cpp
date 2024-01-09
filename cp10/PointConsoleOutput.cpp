#include <iostream>
using namespace std;

/*
cout은 ostream 클래스의 객체이다.
ostream은 이름공간 std 안에 선언되어 있으며, 이의 사용을 위해서는 헤더파일 <iostream>을 포함해야 한다.

cout<<pos 문장이 가능하기 위해서는 << 연산자 오버로딩이 되어 있어야 함
-> cout.operator<<(pos) // 멤버함수의 형태로 오버로딩 -> 선택하기 위해 cout 객체의 멤버함수를 하나 추가해야 하므로 ostream 클래스 정정 (불가능)
-> operator<<(cout, pos) // 전역함수의 형태로 오버로딩 (위 방법이 불가능해서 사용할 수 밖에 없음)
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
  friend ostream& operator<<(ostream&, const Point&);
};

ostream& operator<<(ostream& os, const Point& pos)
{
  os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
  return os;
}

int main(void)
{
  Point pos1(1,3);
  cout<<pos1;
  Point pos2(101, 303);
  cout<<pos2;
  return 0;
}

/*
실행결과
-------------
[1, 3]
[101, 303]
*/
