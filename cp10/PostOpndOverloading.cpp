#include <iostream>
using namespace std;

/*
int main(void)
{
  int num = 100;
  ++(++num); // 컴파일 ok
  --(--num); // 컴파일 ok
  . . .
  // const 선언으로 인해 에러 발생
  // C++의 연산 특성을 그대로 반영함
  (num++)++; // 컴파일 error
  (num--)--; // 컴파일 error
}

*/
class Point
{
private:
  int xpos, ypos;
public:
  Point(int x=0, int y=0)
    : xpos(x), ypos(y)
  {}

  void ShowPosition() const
  {
    cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
  }

  Point& operator++()
  {
    xpos+=1;
    ypos+=1;
    return *this;
  }

  // 반환형에서의 const 선언 의미
  // operator++ 함수의 반환으로 인해서 생성되는 임시객체를 const 객체로 생성하겠다는 뜻
  // const 함수 내에서는 const 함수의 호출만 허용하도록 제한함
  const Point operator++(int)
  {
    // 복사본은 값이 변경되면 안되기 때문에 const로 선언했음
    const Point retobj(xpos, ypos); // const Point retobj(*this);와 같이 복사 생성자 호출하는 형태로도 구현 가능함
    xpos+=1;
    ypos+=1;
    return retobj; // 값이 증가하기 전에 만들어둔 복사본을 반환하여 후위증가 효과를 내는 방법
  }

  friend Point& operator--(Point &ref);
  friend const Point operator--(Point &ref, int);
};

Point& operator--(Point &ref)
{
  ref.xpos -= 1;
  ref.ypos -= 1;
  return ref;
}

const Point operator--(Point &ref, int)
{
  const Point retobj(ref);
  ref.xpos -= 1;
  ref.ypos -= 1;
  return retobj;
}

int main(void)
{
  Point pos(3,5);
  Point cpy;
  cpy=pos--;
  cpy.ShowPosition();
  pos.ShowPosition();

  cpy=pos++;
  cpy.ShowPosition();
  pos.ShowPosition();
  return 0;
}

/*
실행결과
-------------
[3, 5]
[2, 4]
[2, 4]
[3, 5]
*/
