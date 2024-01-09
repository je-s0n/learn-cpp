#include <iostream>
#include <cstring>
using namespace std;
/*
유도 클래스의 생성자 및 소멸자 정의의 모델 제시
*/

class Person
{
private:
  char * name;
public:
  Person(char * myname)
  {
    // 생성자에서 할당한 메모리 공간
    name=new char[strlen(myname)+1];
    strcpy(name, myname);
  }

  ~Person()
  {
    // UnivStudent인 기초 클래스인 Person 클래스의 소멸자는 생성자에서 할당한 메모리 공간을 해제하도록 정의
    // 기초 클래스의 소멸자가 호출이 되면서 기초 클래스의 생성자에서 할당한 메모리 공간을 해제하기 때문
    delete []name;
  }

  void WhatYourName() const
  {
    cout<<"My name is "<<name<<endl;
  }
};

class UnivStudent : public Person
{
priavte:
  char * major;
public
  ~(char * myname, char * mymajor)
    : Person(myname)
  {
    major = new char[strlen(mymajor)+1];
    strcpy(major, mymajor);
  }

  ~UnivStudent()
  {
    delete []major;
  }

  public WhoAreYou() const
  {
    WhatYourName();
    cout<<"My major is "<<major<<endl<<endl;
  }
};

int main(void)
{
  UnivStudent st1("Kim", "Mathematics");
  st1.WhoAreYou();
  UnivStudent st2("Hong", "Physics");
  st2.WhoAreYou();
  return 0;
}

/*
실행결과
------------------------
My name is Kim
My major is Mathematics

My name is Hong
My major is Physics
*/
