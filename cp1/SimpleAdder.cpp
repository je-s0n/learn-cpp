#include <iostream> // 헤더파일 선언문으로 std, cout, endl 사용하기 위함

int main(void) {
  int val1;
  std::cout<<"첫번째 숫자입력: ";
  std::cin>>val1; // 키보드로부터의 데이터 입력 시 사용됨

  int val2;
  std::cout<<"두번째 숫자입력: ";
  std::cin>>val2;

  int result=val1+val2;
  // 출력하는 방법으로, C와 다르게 printf 함수에 %d, %s와 같은 서식문자를 이용해서 별도의 출력포맷을 지정하지 않아도 됨
  // << 연산자를 이용하면 출력대상의 연이은 표현과 개행이 가능함
  std::cout<<"덧셈 결과: "<<result<<std::end1;
  return 0;
}
