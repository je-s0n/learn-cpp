#include <iostream>

/*
인라인 함수 : 프로그램 코드라인 안으로 들어가 버린 함수
매크로 함수는 정의하기 복잡하니, 일반 함수처럼 정의가 가능하면 좋아서 사용함 (완전 대체 X)
매크로 함수는 자료형에 의존적이지 않은 반면, 인라인 함수는 자료형에 의존적임
*/
inline int SQUARE(int x)
{
  return x * x;
}

int main(void) 
{
  std::cout<<SQUARE(5)<<std::endl;
  std::cout<<SQUARE(12)<<std::endl;
  return 0;
}




