#include <iostream>
#include <cstring>
using namespace std;

/*
상속을 위한 기본 조건인 IS-A 관계 성립
- 전화기(기초 클래스) -> 무선 전화기(유도 클래스)
- 컴퓨터(기초 클래스) -> 노트북 컴퓨터(유도 클래스)

이러한 상속 관계가 성립하면, 아래 문장으로 구성됨
- 무선 전화기는 일종의 전화기입니다.
- 노트북 컴퓨터는 일종의 컴퓨터입니다.

두 문장을 영어 반, 한글 반 섞어서 표현하면(is a -> 일종의 ~이다.) 아래와 같이 구셩됨
- 무선 전화기 is a 전화기
- 노트북 컴퓨터 is a 컴퓨터

만약에 상속관계로 묶고자 하는 두 클래스가 IS-A 관계로 표현되지 않는다면, 적절한 상속 관계가 아닐 확률이 높음
*/
class Computer
{
private:
  char owner[50];
public:
  Computer(char * name)
  {
    strcpy(owner, name);
  }

  void Calculate()
  {
    cout<<"요청 내용을 계산합니다."<<endl;
  }
};

class NotebookComp : public Computer
{
private: 
  int Battery;
public:
  NotebookComp(char * name, int initChag)  
    : Computer(name), Battery(initChag)
  {}

  void Charging() {Battery += 5;}
  void UseBattery() {Battery -= 1;}
  void MovingCal()
  {
    if(GetBatteryInfo() < 1)
    {
      cout<<"충전이 필요합니다."<<endl;
      return;
    }
    cout<<"이동하면서 ";
    Calculate();
    UseBattery();
  }

  int GetBatteryInfo() { return Battery; }
};

class TableNotebook : public NotebookComp
{
private:
  char regstPenModel[50];
public:
  TableNotebook(char * name, int initChag, char * pen)
    : NotBookComp(name, initChag)
  {
    strcpy(regstPenModel, pen);
  }

  void Write(char * penInfo)
  {
    if(GetBatteryInfo() < 1)
    {
      cout<<"충전이 필요합니다."<<endl;
      return;
    }

    if(strcmp(regstPenModel, penInfo) != 0)
    {
      cout<<"등록된 펜이 아닙니다.";
      return;
    }

    cout<<"필기 내용을 처리합니다."<<endl;
    UseBattery();
  }
};

int main(void)
{
  NotebookComp nc("이수종", 5);
  TableNotebook tn("정수영", 5, "ISE-241-242");
  nc.MovingCal();
  tn.Write("ISE-241-242");
  return 0;
}

/*
실행결과
-------------------
이동하면서 요청 내용을 계산합니다.
필기 내용을 처리합니다.
*/
