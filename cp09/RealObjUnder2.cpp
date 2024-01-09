#include <iostream>
using namespace std;

/*
핵심은 두 개의 구조체 변수(객체)가 함수를 공유하고 있다는 사실
- 실제로 C++의 객체와 멤버함수는 이러한 관계를 가짐 -> 즉, 객체가 생성되면 멤버변수는 객체 내에 존재하지만, 멤버함수는 메모리의 한 공간에 별도로 위치하고선 이 함수가 정의된 클래스의 모든 객체가 이를 공유하는 형태를 취함
- 객체가 지니고 있는 멤버변수 대상의 연산이 진행되도록 함수를 호출하는 것이며, 멤버함수의 존재에 대해 이해할 수 있음
*/
//클래스 Data를 흉내 낸 영역 - 구조체
typedef struct Data
{
  int data;
  // 함수 포인터 변수가 구조체의 멤버로 등장
  void (*ShowData)(Data*); // 포인터 변수는 아래 정의된 함수의 주소 값을 저장하기 위한 것
  void (*Add)(Data*, int); // 포인터 변수는 아래 정의된 함수의 주소 값을 저장하기 위한 것
} Data;

void ShowData(Data* THIS) { cout<<"Data: "<<THIS->data<<endl; }
void Add(Data* THIS, int num) { THIS->data += num; }

// 적절히 변경된 main 함수
int main(void)
{
  // obj1, obj2를 객체라고 할 때, 이 두 객체는 ShowData 함수와 Add 함수를 공유하는 셈
  // 이 두 함수를 이용해 멤버인 함수 포인터 변수를 초기화
  Data obj1 = {15, ShowData, Add};
  Data obj2 = {7, ShowData, Add};

  obj1.Add(&obj1, 17);
  obj2.Add(&obj2, 9);
  obj1.ShowData(&obj1);
  obj2.ShowData(&obj2);
  return 0;
}

/*
실행결과
-------------
Data: 32
Data: 16
*/
