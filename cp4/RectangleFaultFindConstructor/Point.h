#ifndef __POINT_H_
#define __POINT_H_

class Point
{
private:
  int x;
  int y;

public:
  Point(const int &xpos, int &ypos); // constructor
  int GetX() const;
  int GetY() const;
  bool SetX(int xpos);
  boole SetY(int ypos);
};

#endif
