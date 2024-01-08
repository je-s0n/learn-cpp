#include <iostream>
#include <cstring>
using namespace std;

/*
아래 예제는 권총을 소유하는 경찰을 표현하고 있음
-> 따라서 이를 영어와 한글로 표현하면 '경찰은 has a 총'이 됨
-> has a : ~을 소유한다로 해석하여 HAS-A 관계도 상속으로 표현할 수 있지만, 소유의 관계는 다른 방식으로도 얼마든지 표현 가능
*/
class Gun
{
private:
  int bullet; // 장전된 총알의 수
public:
  Gun(int bnum) : bullet(bnum)
  {}

  void Shot()
  {
    cout<<"BBANG!"<<endl;
    bullet--;
  }
};

class Police : public Gun
{
private:
  int handcuffs;  // 소유한 수갑 수
public:
  Police(int bnum, int bcuff)
    : Gun(bnum), handcuffs(bcuff)
  {}

  void PutHandcuff()
  {
    cout<<"SNAP!"<<endl;
    handcuffs--;
  }
};

int main(void)
{
  Police pman(5, 3); // 총알 5, 수갑 3
  pman.Shot();
  pman.PutHandcuff();
  return 0;
}

/*
실행결과
--------------------
BBANG!
SNAP!
*/
