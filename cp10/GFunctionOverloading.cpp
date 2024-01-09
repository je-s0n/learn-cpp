#include <iostream>
using namespace std;

/*
오버로딩 가능한 연산자 종류
1) = 대입 연산자
2) () 함수 호출 연산자
3) [] 배열 접근 연산자(인덱스 연산자)
4) -> 멤버 접근을 위한 포인터 연산자
-> 객체를 대상으로 진행해야 의미가 통하는 연산자들이기 때문에, 멤버함수 기반으로만 연산자의 오버로딩 허용
*/

/*
오버로딩 불가능한 연산자 종류
1) . 멤버 접근 연산자
2) .* 멤버 포인터 연산자
3) :: 범위 지정 연산자
4) ?: 조건 연산자(3항 연산자)
5) sizeof 바이트 단위 크기 계산
6) typeid RTTI 관련 연산자
7) static_cast 형변환 연산자
8) dynamic_cast 형변환 연산자
9) const_cast 형변환 연산자
10) reinterpret_cast 형변환 연산자
-> 제한하는 이유는 C++ 문법 규칙을 보존하기 위함
*/

/*
연산자를 오버로딩 하는데 있어서의 주의사항
1) 본래의 의도를 벗어난 형태의 연산자 오버로딩은 좋지 않음
2) 연산자의 우선순위와 결합성은 바뀌지 않음
3) 매개변수의 디폴트 값 설정이 불가능함
4) 연산자의 순수 기능까지 빼앗을 수 없음
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
  friend Point operator+(const Point &pos1, const Point &pos2); // 아래 함수에 대해 private 영역의 접근을 허용하기 위해 friend 선언 사용
};

// + 연산자를 전역함수의 형태로 오버로딩 하였으며, Point 클래스는 이 함수에 대해 friend 선언을 하였으므로 함수 내에서는 Point 클래스의 private 멤버에 접근 가능
Point operator+(const Point &pos1, const Point &pos2)
{
  Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
  return pos;
}

int main(void)
{
  Point pos1(3,4);
  Point pos2(10,20);
  Point pos3 = pos1 + pos2; // + 연산자가 전역함수 형태로 오버로딩 되었으므로, operator+(pos1, pos2)로 해석됨

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
