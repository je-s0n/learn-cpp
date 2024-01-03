#include <iostream>
using namespace std;

/*
캡슐화는 관련 있는 함수와 변수를 하나의 클래스 안에 묶는 것으로, 범위를 결정하는 일이 쉽지 않기 때문에 어려운 개념임
캡슐화는 안전하게 감싸야 하므로, 이왕이먄 멤버변수가 보이지 않게 정보를 은닉해서 감싸는 것이 좋기 때문에 정보 은닉을 포함한 개념임
*/
class SinivelCap // 콧물 처치용 캡슐
{
public:
  void Take() const {cout<<"콧물이 싹~ 납니다."<<endl;}
};

class SneezeCap // 재채기 처치용 캡슐
{
public:
  void Take() const {cout<<"재채기가 멎습니다."<<endl;}
};

class SnuffleCap // 코막힘 처치용 캡슐
{
public:
  void Take() const {cout<<"코가 뻥 뚫립니다."<<endl;}
};

class CONTAC600
{
  private:
    SinivelCap sin;
    SneezeCap sne;
    SnuffleCap snu;

  public:
    void Take() const
    {
      sin.Take();
      sin.Take();
      snu.Take();
    }
};

class ColdPatient
{
public:
  void TakeCONTAC600(const CONTAC600 &cap) const {cap.Take();}
};

int main(void)
{
  CONTAC600 cap;
  ColdPatient sufferer;
  // 약의 복용 간결해짐
  sufferer.TakeCONTAC600(cap);
  return 0;
}
