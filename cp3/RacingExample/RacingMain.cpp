#include "Car.h" // main 함수를 구성하는 문장은 클래스 Car와 관련된 것 뿐이기 때문에 헤더파일 Car.h만 포함하면 됨

int main(void)
{
  Car run99;
  run99.InitMembers("run99", 100);
  run99.Accel();
  run99.Accel();
  run99.Accel();
  run99.ShowCarState();
  run99.Break();
  run99.ShowCarState();
  return 0;
}
