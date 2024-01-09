#include <iostream>
#include <cstring>
using namespace std;

/*
HASInheritance.cpp 예제와 비교해 상속 기반 예제보다 좋은 모델
HASInheritance.cpp에서 보여준 방식으로는 다음의 요구사항 반영하기 쉽지 않음
1) 권총을 소유하지 않은 경찰을 표현
2) 경찰이 권총과 수갑뿐만 아니라 전기봉도 소유하기 시작

-> 상속으로 묶인 두 개의 클래스는 강한 연관성을 띔
멤버변수 pistol을 NULL로 초기화함으로써 권총을  소유하지 않은 경찰을 매우 간단히 표현함
HASComposite.cpp 에서는 전기봉을 소유하는 경찰을 표현하기 위해 멤버변수 하나만 추가하면 되지만, HASInheritance.cpp에서는 상황을 대체하기 난감함

결론 : 상속은 IS-A 관계의 표현에 매우 적절함
*/
class Gun
{
private:
  int bullet;
public:
  Gun(int bnum) : bullet(bnum)
  {}

  void Shot()
  {
    cout<<"BBANG!"<<endl;
    bullet--;
  }
};

class Police
{
private:
  int handcuffs;  // 소유한 수갑 수
  int * pistol; // 소유하고 있는 권총
public:
  Police(int bnum, int bcuff)
    : handcuffs(bcuff)
  {
    if(bnum > 0)
      pistol = new Gun(bnum);
    else
      pistol = NULL;
  }

  void PutHandcuff()
  {
    cout<<"SNAP!"<<endl;
    handcuffs--;
  }

  void Shot()
  {
    if(pistol == NULL)
      cout<<"Hut BBANG!"<<endl;
    else 
      pistol -> Shot();
  }

  ~Police()
  {
    if(pistol != NULL)
      delete pistol;
  }
};

int main(void)
{
  Police pman1(5,3);
  pman1.Shot();
  pman1.PutHandcuff();

  Police pman2(0,3);
  pman2.Shot();
  pman2.PutHandcuff();
  return 0;
}

/*
실행결과
-------------------
BBANG!
SNAP!
HUT BBANG!
SNAP!
*/
