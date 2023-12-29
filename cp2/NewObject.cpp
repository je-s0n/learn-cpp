#include <iostream>
#include <stdlib.h>
using namespace std;

// C언어의 구조체 같은 것 -> 프로그래머가 직접 정의한 자료형으로 인식
class Simple
{
  public:
    Simple()
    {
      cout<<"I'm simple constructor!"<<endl;
    }
};

int main(void)
{
  cout<<"case 1: ";
  Simple * sp1 = new Simple; // new 연산자를 이용해 힙 영역에 변수를 할당

  cout<<"case 2: ";
  Simple * sp2 = (Simple*)malloc(sizeof(Simple)*1); // malloc 함수 호출을 통해 힙 영역에 변수를 할당

  cout<<endl<<"end of main"<<endl;
  // 할당 방법에 따른 소멸
  delete sp1;
  free(sp2);
  return 0;
}
