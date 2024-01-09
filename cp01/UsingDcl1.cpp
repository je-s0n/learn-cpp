#include <iostream>

namespace Hybrid
{
  void HybFunc(void)
  {
    std::cout<<"So simple function!"<<std::endl;
    std::cout<<"In namespace Hybrid!"<<std::endl;
  }
}

int main(void)
{
  using Hybrid::HybFunc; // 키워드 using을 이용해 '이름공간 Hybrid에 정의된 HybFunc를 호출할 때에는 이름 공간을 지정하지 않고 호출하겠다'는 것을 명시(선언)하고 있음
  HybFunc(); // 위 행의 using 선언을 통해 이름공간 지정 없이 HybFunc 함수를 호출하고 있음
  return 0;
}
