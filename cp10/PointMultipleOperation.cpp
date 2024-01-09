#include <iostream>
using namespace std;

/*
교환법칙이란 'A+B의 결과는 B+A의 결과와 같음'을 뜻함
즉, 연산자를 중심으로 한 피연산자의 위치는 연산의 결과에 아무런 영향을 미치지 않는다는 법칙
대표적으로 교환법칙이 성립하는 연산으로는 덧셈연산과 곱셈연산이 있음
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

  Point operator*(int times) // 곱셈 연산자를 오버로딩 -> Point 객체와 정수간의 곱셈 가능함
  {
    // 곱의 배수만큼 xpos와 ypos의 값이 증가된 Point 객체를 생성 및 반환하는 형태로 연산자 오버로딩 함
    Point pos(xpos*times, ypos*times);
    return pos;
  }
};

int main(void)
{
  Point pos(1, 2);
  Point cpy;

  // 곱셈 연산은 pos.operator*(3);으로 해석됨
  // 이렇게 해석되기 위해서는 Point 객체가 곱셈 연산자의 왼편에 와야 함
  cpy = pos * 3;
  // cpy = 3 * pos;도 같은 결과를 보여야 함
  // 3.operator*(pos); 로는 해석 불가능함 -> 오버로딩 형태로는 연산 불가능이며, 멤버함수가 정의된 클래스의 객체가 오버로딩 된 연산자의 왼편에 와야 함
  cpy.ShowPosition();

  // 3을 곱했을 때 반환되는 객체를 대상으로 다시 2를 곱하는 연산을 하고 있음
  // 결과가 cpy 객체에 저장됨
  cpy = pos * 3 * 2;
  cpy.ShowPosition();
  return 0;
}

/*
실행결과
-----------------
[3, 6]
[6, 12]
*/
