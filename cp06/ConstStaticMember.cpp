#include <iostream>
using namespace std;

class CountryArea
{
public:
  // 기존 const 멤버변수(상수) 초기화는 이니셜라이저를 통해서만 가능했지만,
  // const static 멤버변수는 클래스가 정의될 때 지정된 값이 유지되는 상수이기 때문에 아래와 같이 초기화 가능
  const static int RUSSIA = 1707540;
  const static int CANADA = 998467;
  const static int CHINA = 957290;
  const static int SOUTH_KOREA = 9922;

}

int main(void)
{
  cout<<"러시아 면적: "<<CountryArea.RUSSIA<<"km^2"<<endl;
  cout<<"캐나다 면적: "<<CountryArea.CANADA<<"km^2"<<endl;
  cout<<"중국 면적: "<<CountryArea.CHINA<<"km^2"<<endl;
  cout<<"한국 면적: "<<CountryArea.SOUTH_KOREA<<"km^2"<<endl;
}

/*
러시아 면적: 1707540km^2
캐나다 면적: 998467km^2
중국 면적: 957290km^2
한국 면적: 9922km^2
*/
