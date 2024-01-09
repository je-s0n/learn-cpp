#include <iostream>
using namespace std;

namespace AAA
{
  namespace BBB
  {
    namespace CCC
    {
      int num1;
      int num2;
    }
  }
}

int main(void)
{
  // 별칭 선언되기 전
  AAA::BBB::CCC::num1 = 20;
  AAA::BBB::CCC::num2 = 30;

  namespace ABC = AAA::BBB::CCC; // 별칭 선언

  // 별칭 선언 이후 접근
  cout<<ABC::num1<<endl;
  cout<<ABC::num2<<endl;
  return 0;
}
