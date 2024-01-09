#include <iostream>
using namespace std;
/*
포인터(*) : 주소값을 갖는 변수
이중포인터(**) : 포인터 주소값을 갖는 변수
*/
int main(void)
{
  int num=12;
  int *ptr=&num; // num의 주소값을 갖는 포인터 변수
  int **dptr=&ptr; // 포인터 변수의 주소값을 갖는 이중포인터 변수

  int &ref=num; // num 변수의 참조자 ref 선언
  
  // 포인터 변수 ptr의 참조자이므로, 변수 num에 저장된 값이 출력됨
  int *(&pref)=ptr;
  int **(&dpref)=dptr;

  cout<<ref<<endl; // 12
  // pref는 포인터 변수 ptr의 참조자이므로, 변수 num에 저장된 값이 출력됨
  cout<<*pref<<endl; // 12
  // dpref는 포인터 변수 dptr의 참조자이므로, 변수 num에 저장된 값이 출력됨
  cout<<**dpref<<endl; // 12
  return 0;
}
