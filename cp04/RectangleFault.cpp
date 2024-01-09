/*
문제점 파악을 위한 예시
1) 점의 좌표는 0 이상 100 이하가 되어야 하는데, 그렇지 못한 Point 객체 존재
2) 직사각형을 의미하는 Rectangle 객체의 좌 상단 좌표 값이 우 하단 좌표 값보다 큼

프로그래머의 실수에 대한 대책이 준비되어 있지 않음 
-> 제한된 방법으로의 접근만 허용해서 잘못된 값이 저장되지 않도록 도와야 하고, 실수했을 때 실수가 쉽게 발견되도록 해야 함
*/
#include <iostream>
using namespace std;

// 점을 표현한 Point클래스의 멤버변수 x, y는 public으로 선언되어서 어디서든 접근이 가능함
class Point
{
public:
  int x; // x좌표의 범위는 0이상 100이하
  int y; // y좌표의 범위는 0이상 100이하
};

// Rectangle 클래스는 직사각형을 표현한 것으로, 직사각형은 두 개의 점으로 표현이 가능하므로 두 개의 Point 객체를 멤버로 두었음
class Rectangle
{
public:
  Point upLeft;
  Point lowRight;

public:
  void ShowRecInfo()
  {
    cout<<"좌 상단: "<<'['<<upLeft.x<<", ";
    cout<<upLeft.y<<"]"<<endl;
    cout<<"우 하단: "<<'['<<lowRight.x<<", ";
    cout<<lowRight.y<<"]"<<endl;
  }
};

int main(void)
{
  // 직사각형을 표현할 두 개의 Point 객체를 생성하였고, 멤버변수가 public으로 선언되면 구조체 변수를 초기화하듯이 초기화 가능함
  Point pos1 = {-2, 4};
  Point pos2 = {5, 9};
  // Point 객체를 이용해서 Rectangle 객체를 생성 및 초기화 하고 있음
  Rectangle rec = {pos2, pos1};
  rec.ShowRecInfo();
  return 0;
}
