#include <iostream>
using namespace std;

// 구조체 Car와 관련된 각종 정보를 상수화
#define ID_LEN  20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

// 함수를 멤버로 지니는 구조체의 정의
struct Car
{
  char gamerID[ID_LEN]; // 소유자 ID
  int fuelGauge;        // 연료량
  int curSpeed;         // 현재 속도

  void ShowCarState()
  {
    cout<<"소유자ID: "<<gamerId<<endl;
    cout<<"연료량: "<<fuelGauge<<"%"<<endl;
    cout<<"현재속도: "<<curSpeed<<"km/s"<<endl<<endl;
  }

  void Accel()
  {
    if(fuelGuage <= 0)
      return;
    else fuelGauge -= FUEL_STEP;
  
    if(curSpeed + ACC_STEP >= MAX_SPD)
    {
      curSpeed=MAX_SPD;
      return;
    }
    curSpeed += ACC_STEP;
  }

  void Break()
  {
    if(curSpeed<BRK_STEP)
    {
      curSpeed=0;
      return;
    }
    curSpeed -= BRK_STEP;
  }

}

int main(void)
{
  Car run99 = {"run99", 100, 0}; // 구조체 변수의 선언 및 초기화
  run99.Accel(); // 구조체 run99에 존재하는 Accel함수를 호출, 구조체 내에 선언된 변수에 접근하는 방법과 동일하게 호출함
  run99.Accel(); 
  run99.ShowCarState();
  run99.Break();
  run99.ShowCarState();

  Car sped77 = {"sped77", 100, 0};
  sped77.Accel(); // 구조체 내에 함수가 정의가 되었기 때문에 구조체 변수를 대상으로 함수의 호출이 이뤄져야 함
  sped77.Break();
  sped77.ShowCarState();
  return 0;
}
