#include <iostream>
#include <cstring>
using namespace std;

/*
  클래스는 구조체와 같이 아래 방식으로 선언하지 못함
  Car run99 = {"run99", 100, 0}; (X)
  -> 이유는 클래스 내에 선언된 함수가 아닌 다른 영역에서 변수를 초기화하려고 했기 때문
  클래스는 기본적으로 클래스 내에 선언된 변수는 클래스 내에 선언된 함수에서만 접근 가능하며, 클래스를 정의하는 과정에서 각각의 변수 및 함수의 접근 허용범위를 별도로 선언해야 함

  접근제어 지시자(접근제어 레이블)
  1) public : 어디서든 접근 허용
  2) protected : 상속관계에 놓여있을 때, 유도 클래스에서의 접근허용
  3) private : 클래스 내(클래스 내에 정이된 함수)에서만 접근허용
*/

namespace CAR_CONST
{
  enum
  {
    ID_LEN=20, MAX_SPEED=200, FUEL_STEP=2,
    ACC_STEP=10, BRK_STEP=10
  };
}

// 클래스 정의
class Car
{
  private: // private으로 선언되었으므로, 이어서 등장하는 변수와 함수는 private에 해당하는 범위인 클래스 내에서만 접근 가능
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;
  public: // public으로 선언되었으므로, 이어서 등장하는 변수와 함수는 public에 해당하는 범위로 어디서든 접근 가능
    void InitMembers(char * ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

// 클래스 안에 선언된 변수의 초기화를 목적으로 정의된 함수로, 변수가 모든 private으로 선언되어서 main함수에서 접근 불가능
// 하지만 이 함수는 동일 클래스 내에 정의된 함수로 접근 가능할 뿐만 아니라,. public으로 선언되어 main함수에서 호출 가능하여 이 함수를 호출해서 클래스 안에 선언된 변수 초기화
void Car::InitMembers(char * ID, int fuel)
{
  strcpy(gamerID, ID);
  fuelGauge=fuel;
  curSpeed=0;
}

void Car::ShowCarState()
{
  cout<<"소유자ID: "<<gamerID<<endl;
  cout<<"연료량: "<<fuelGauge<<"%"<<endl;
  cout<<"현재속도: "<<curSpeed<<"km/s"<<endl;
}

void Car::Accel()
{
    if(fuelGuage <= 0)
      return;
    else fuelGauge -= CAR_CONST::FUEL_STEP;
  
    if(curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
    {
      curSpeed=CAR_CONST::MAX_SPD;
      return;
    }
    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
    if(curSpeed<CAR_CONST::BRK_STEP)
    {
      curSpeed=0;
      return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
  Car run99;
  run99.InitMembers("run99", 100); // 초기화 목적으로 InitMembers 함수를 호출하고 있으며, 이 함수는 ID정보와 연료의 게이지 정보를 전달받아서 초기화되는 형태로 정의됨
  run99.Accel(); 
  run99.Accel(); 
  run99.Accel(); 
  run99.ShowCarState();
  run99.Break();
  run99.ShowCarState();
  return 0;
}
