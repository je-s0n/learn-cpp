#include <iostream>
using namespace std;

// 구조체 Car와 관련된 각종 정보를 상수화
#define ID_LEN  20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car
{
  char gamerID[ID_LEN]; // 소유자 ID
  int fuelGauge;        // 연료량
  int curSpeed;         // 현재 속도
}

// 차의 정보를 출력하는 기능의 함수
// 단순히 정보를 출력하기 때문에 const 참조자를 매개변수로 선언
void ShowCarState(const Car &car)
{
  cout<<"소유자ID: "<<car.gamerId<<endl;
  cout<<"연료량: "<<car.fuelGauge<<"%"<<endl;
  cout<<"현재속도: "<<car.curSpeed<<"km/s"<<endl<<endl;
}

// 차의 가속을 위해 엑셀을 밟은 상황을 표현해놓은 함수
// 엑셀을 밟을 때마다 연료는 줄어들고 스피드가 올라가는 상황 표현
void Accel(Car &car)
{
  if(car.fuelGuage <= 0)
    return;
  else car.fuelGauge -= FUEL_STEP;

  if(car.curSpeed + ACC_STEP >= MAX_SPD)
  {
    car.curSpeed=MAX_SPD;
    return;
  }
  car.curSpeed += ACC_STEP;
}

// 브레이크를 밟은 상황을 표현한 함수
// 브레이크도 연료의 소모가 동반되지만, 단순히 속도가 감속하는 것으로 표현
void Break(Car &car)
{
  if(car.curSpeed<BRK_STEP)
  {
    car.curSpeed=0;
    return;
  }
  car.curSpeed -= BRK_STEP;
}

int main(void)
{
  Car run99 = {"run99", 100, 0}; // 구조체 변수의 선언 및 초기화
  // 엑셀과 브레이크 function 호출
  Accel(run99);
  Accel(run99);
  ShowCarState(run99);
  Break(run99);
  ShowCarState(run99);

  Car sped77 = {"sped77", 100, 0};
  Accel(sped77);
  Break(sped77);
  ShowCarState(sped77);
  return 0;
}
