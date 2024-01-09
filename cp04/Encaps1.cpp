/*
캡슐화의 잘못된 예시
아래 예제에서 "코감기는 항상 콧물, 재채기, 코막힘을 동반한다"라고 가정하면 캡슐화가 무너진 대표적인 사례가 됨
1) 복용 절차가 너무 복잡함
2) 약의 복용은 반드시 SinivelCap, SneezeCap, SnuffleCap 순으로 이뤄져야 한다고 가정하면 위 클래스 설계는 매우 위험한 구조가 됨
3) 약의 복용을 위해 클래스 간 상호관계도 매우 잘 알아야 하는 상황에 놓였으며, 순서가 틀어지면 부작용이 발생할 수 있는 결과 초래
-> (결과) 캡슐화가 무너지면 객체의 활용이 매우 어려워지며, 클래스 상호관계가 복잡해지기 때문에 복잡도를 높임
*/
#include <iostream>
using namespace std;

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

// 감기환자를 클래스로 간단히 정의하였고, 이 환자는 감기의 치료를 위해서 앞에 정의한 클래스의 객체를 복용해야 함
class ColdPatient
{
public:
  void TakeSinivelCap(cobst SinivelCap &cap) const {cap.Take();}
  void TakeSneezeCap(cobst SneezeCap &cap) const {cap.Take();}
  void TakeSnuffleCap(cobst SnuffleCap &cap) const {cap.Take();}
};

int main(void)
{
  SinivelCap scap;
  SneezeCap zcap;
  SnuffleCap ncap;

  ColdPatient sufferer;
  // 코감기의 처치를 위해서 콧물, 재채기, 코막힘을 치료하기 위한 캡슐을 순서대로 복용하고 있음
  sufferer.TakeSinivelCap(scap);
  sufferer.TakeSneezeCap(zcap);
  sufferer.TakeSnuffleCap(ncap);
  return 0;
}
