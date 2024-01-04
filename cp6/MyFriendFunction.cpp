#include <iostream>
using namespace std;

class Point; // Point가 클래스의 이름임을 선언

class PointOP
{
private:
  int opcnt;
public:
  PointOP() : opcnt(0)
  {}

  Point PointAdd(const Point&, const Point&);
  Point PointSub(const Point&, const Point&);
  ~PointOP()
  {
    cout<<"Operation times: "<<opcnt<<endl;
  }
};

class Point
{
private:
  int x;
  int y;
public:
  Point(const int &xpos, const int &ypos) : x(xpos), y(ypos)
  {}

  // PointOP 클래스의 멤버함수 PointAdd와 PointSub에 대해 friend 선언을 하고 있음
  friend Point PointOP::PointAdd(const Point&, const Point&);
  friend Point PointOP::PointSub(const Point&, const Point&);
  // 아래 정의한 함수 ShowPointPos에 대해 friend 선언을 하고 있음
  friend void ShowPointPos(const Point&);
};

// Point클래스의 friend 선언되었기 때문에 private 멤버에 접근 가능
Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2)
{
  opcnt ++;
  return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2)
{
  opcnt ++;
  return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

int main(void)
{
  Point pos1(1,2);
  Point pos2(2,4);
  PointOP op;

  // ShowPointPos함수 friend 선언이 되었기 때문에 private 멤버(x,y)에 접근 가능
  ShowPointPos(op.PointAdd(pos1, pos2));
  ShowPointPos(op.PointSub(pos1, pos2));
  return 0;
}

void ShowPointPos(const Point& pos)
{
  cout<<"x: "<<pos.x<<", ";
  cout<<"y: "<<pos.y<<endl;
}
