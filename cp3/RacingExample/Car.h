// Car.h : 클래스 선언을 담음
/*
  다른 소스파일이 여러 번 include 했을 때 발생하는 문제를 미리 방지하기 위해서 사용함
  ifdef :  define이 됐을 때 사용한다는 뜻
  ifndef : define이 되지 않았을 때 선언한다는 뜻
  define : 상수값을 지정하기 위한 예약어로, 매크로라고 부름
  endif : ifdef, infdef 이 끝났음을 알림
*/
#ifndef __CAR_H__
#define __CAR_H__

// 클래스 Car에서 제한적으로 사용되는 상수의 선언이므로 클래스 Car와 같은 파일에 선언함
namespace CAR_CONST
{
  enum
  {
    ID_LEN=20, MAX_SPD=200, FUEL_STEP=2,
    ACC_STEP=10, BRK_STEP=1
  };
}

class Car
{
  private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;
  public:
    void InitMembers(char * ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

#endif
