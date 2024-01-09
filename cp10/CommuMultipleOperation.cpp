#include <iostream>
using namespace std;

/*
교환법칙이 성립되기 위해 멤버함수 형태가 아닌 전역함수의 형태로 곱셈 연산자를 오버로딩 하는 수밖에 없음
cpy = 3 * pos; 
cpy = operater*(3, pos);
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

  Point operator*(int times)
  {
    Point pos(xpos*times, ypos*times);
    return pos;
  }

  friend Point operator*(int times, Point& ref);
};

Point operator*(int times, Point& ref)
{
  return ref * times;  
}

int main(void)
{
  Point pos(1, 2);
  Point cpy;

  cpy = 3 * pos; // operater*(3, pos);
  cpy.ShowPosition();

  cpy = 2 * pos * 3;  // operater*(2, pos * 3);
  cpy.ShowPosition();
  return 0;
}

/*
실행결과
-----------------
[3, 6]
[6, 12]
*/
