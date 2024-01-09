#ifndef __POINT_H_
#define __POINT_H_

class Point
{
// 멤버변수 x와 y를 private으로 선언해서 임의로 값이 저장되는 것을 막아놓음 -> 정보를 은닉한 상황
private:
  int x;
  int y;

public:
  bool InitMembers(int xpos, int ypos);
  // 대신에 값의 저장 및 참조를 위한 함수를 추가로 정의하였음 -> 멤버변수에 저장되는 값을 제한할 수 있게 되었음
  int GetX() const;
  int GetY() const;
  bool SetX(int xpos);
  boole SetY(int ypos);
};
#endif
