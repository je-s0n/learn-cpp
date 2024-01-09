#include <iostream>
using namespace std;

/*
단항 연산자
1) 1 증가 연산자 ++
2) 1 감소 연산자 --

++pos; // pos는 Point 객체
pos.operator ++; // 멤버함수로 오버로딩 된 경우 호출 방법
operator++(pos); // 전역함수의 오버로딩 된 경우 호출 방법

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

  Point& operator++() // ++ 연산자가 멤버함수 형태로 오버로딩
  {
    xpos+=1;
    ypos+=1;
    return *this;
  }
  friend Point& operator--(Point &ref); // 아래 정의된 전역함수에 대해 friend 선언함
};

Point& operator--(Point &ref) // -- 연산자가 전역함수 형태로 오버로딩
{
  ref.xpos -= 1;
  ref.ypos -= 1;
  return ref;
}

int main(void)
{
  Point pos(1,2);
  ++pos;
  pos.ShowPosition();
  --pos;
  pos.ShowPosition();

  ++(++pos);
  /*
  위 코드 연산 과정
  ++(++pos); -> ++(pos.operator++()); -> ++(pos의 참조 값); -> (pos의 참조 값).operator++();
  */
  pos.ShowPosition();
  --(--pos);
  pos.ShowPosition();
  return 0;
}

/*
실행결과
---------------------
[2, 3]
[1, 2]
[3, 4]
[1, 2]
*/
