#include <iostream>
#include <cstring>
using namespace std;

/*
상속
- UnivStudent 클래스의 생성자는 자신이 상속한 Person 클래스의 멤버를 초기화할 의무를 지님
  -> UnivStudent 생성자는 Person의 생성자를 호출하는 형태로 Person 클래스의 멤버를 초기화하는 것이 좋음
- UnivStudent 클래스와 같이 상속받는 클래스는 이니셜라이저를 이용하여 상속하는 클래스의 생성자 호출을 명시할 수 있음
- 상속의 접근 제한 기준은 클래스이기 때문에 클래스 외부에서는 private 멤버에 접근 불가능
  -> 직접 접근이 불가능해서 Person 클래스에 정의된 public 함수를 통해 간접적으로 접근을 해야 함
  -> 정보의 은닉은 하나의 객체 내에서도 진행됨
*/

/*
용어 정리
Person              <->      UnivStudent
상위 클래스            <->      하위 클래스    
기초(base) 클래스      <->      유도(derived) 클래스 (C++에서 가장 일반적으로 사용되는 표현)
슈퍼(super) 클래스     <->      서브(sub) 클래스
부모 클래스            <->      자식 클래스    
*/
class Person 
{
private:
  int age;
  char name[50];
public:
  Person(int myage, char * myname)
    : age(myage)
  {
    strcpy(name, myname);
  }

  void WhatYourName() const
  {
    cout<<"My name is "<<name<<endl;
  }

  void HowOldAreYou() const
  {
    cout<<"I'm "<<age<<" years old"<<endl;
  }
};

// UnivStudent 클래스가 Person 클래스를 상속한다.
class UnivStudent : public Person
{
private:
  char major[50]; // 전공과목
public:
  UnivStudent(char * myname, int myage, char mymajor)
    :Person(myage, myname)
  {
    strcpy(major, mymajor);
  }

  void WhoAreYou() const
  {
    WhatYourName();
    HowOldAreYou();
    cout<<"My major is "<<major<<endl<<endl;
  }
};

int main(void)
{
  UnivStudent ustd1("Lee", 22, "Computer eng.");
  ustd1.WhoAreYou();
  
  UnivStudent ustd2("Yoon", 21, "Eletronic eng.");
  ustd1.WhoAreYou();
  return 0;
}

/*
실행결과
----------------
My name is Lee
I'm 22 years old
My major is Computer eng.

My name is Yoon
I'm 21 years old
My major is Eletronic eng.
*/
