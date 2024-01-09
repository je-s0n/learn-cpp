#include <iostream>
using namespace std;

/*
함수가 오버로딩 되면, 오버로딩 된 수만큼 다양한 기능을 제공하게 됨
-> 이름은 하나지만 기능은 여러 가지가 되는 셈

마찬가지로 연산자의 오버로딩을 통해 기존에 존재하던 연산자의 기본 기능 이외에 다른 기능을 추가할 수 있음
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
  Point pos3 = pos1.operator+(pos2); // pos1 객체의 멤버함수 operator+를 호출하면서 인자로 pos2 객체를 전달
  // 따라서 이 두 객체의 멤버 별 덧셈 결과로 새로운 Point 객체가 만들어지며, 이것이 반환되어 pos3를 초기화 (이 과정에서 복사 생성자 호출)

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
