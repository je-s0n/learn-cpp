/*
C언어에서의 static
1) 전역변수에 선언된 static의 의미 : 선언된 파일 내에서만 참조를 허용하겠다는 의미
2) 함수 내 선언된 static의 의미 : 한번만 초기화되고, 지역변수와 달리함수를 빠져나가도 소멸되지 않음
*/
#include <iostream>
using namespace std;

void Counter()
{
  static int cnt; // static 변수는 전역변수와 마찬가지로 초기화하지 않으면 0, 이 문장은 딱 한번 실행됨 -> cnt는 Counter 함수가 호출될 때마다 새롭게 할당되는 지역변수 X
  cnt++;
  cout<<"Current cnt: "<<cnt<<endl;
}

int main(void)
{
  for(int i=0; i<10; i++)
    Counter();
  return 0;
}

/*
실행결과
--------------------------------------
Current cnt: 1
Current cnt: 2
Current cnt: 3
Current cnt: 4
Current cnt: 5
Current cnt: 6
Current cnt: 7
Current cnt: 8
Current cnt: 9
Current cnt: 10
*/
