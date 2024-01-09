#include <iostream>
// using 선언을 함수 밖에 전역의 형태로 삽입
// cin, cout, endl의 사용에 있어서 이름공간의 지정이 불필요함
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
  int num=20;
  // using 선언을 통해 코드 구성이 한결 간단해짐
  cout<<"Hello World!"<<endl;
  cout<<"Hello "<<"World!"<<endl;
  cout<<num<<' '<<'A';
  cout<<num<<' '<<3.14<<endl;
  return 0;
}
