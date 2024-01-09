#include <iostream>
#include "Point.h"
using namespace std;

// 멤버변슈에 값을 저장하는 함수 InitMembers, SetX, SetY는 0 이상 100 이하의 값이 전달되지 않으면, 에러 메시지를 출력하면서 값의 저장을 허용하지 않는 형태로 정의됨
// 따라서 값의 저장을 허용하지 않는 형태로 정의되었으며, 잘못된 값이 저장되지 않을뿐더러, 값이 잘못 전달되는 경우 출력된 메시지를 통해 문제가 있음을 확인할 수 있음
// 결론 : 멤버변수를 private으로 선언하고, 해당 변수에 접근하는 함수를 별도로 정의해서 안전한 형태로 멤버변수의 접근을 유도하는 것이 '정보은닉'이며, 좋은 클래스가 되기 위한 기본조건이 됨
bool Point::InitMembers(int xpos, int ypos)
{
  if(xpos<0 || ypos<0)
  {
    cout<<"벗어난 범위의 값 전달"<<endl;
    return false;
  }

  x=xpos;
  y=ypos;
  return true;
}

/*
const는 "이 함수 내에서는 멤버변수에 저장된 값을 변경하지 않겠다"는 뜻으로 선언
const함수 내에서는 const가 아닌 함수의 호출이 제한됨 -> 변경이 가능한 함수의 호출을 아예 허용하지 않음
*/
int Point::GetX() const // const function
{
  return x;
}

int Point::GetY() const // const function
{
  return y;
}

bool Point::SetX(int xpos)
{
  if(xpos<0 || xpos>100  
  {
    cout<<"벗어난 범위의 값 전달"<<endl;
    return false;
  }
  x=xpos;
  return true;
}

bool Point::SetY(int ypos)
{
  if(ypos<0 || ypos>100  
  {
    cout<<"벗어난 범위의 값 전달"<<endl;
    return false;
  }
  y=ypos;
  return true;
}
