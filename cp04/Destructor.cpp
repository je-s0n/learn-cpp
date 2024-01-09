/*
소멸자(Destructor)
1) 클래스의 이름 앞에 ~가 붙은 형태의 이름을 가짐
2) 반환형이 선언되어 있지 않으며, 실제로 반환하지 않음
3) 매개변수는 void형으로 선언되어야 하기 때문에 오버로딩도, 디폴트 값 설정도 불가능함
*/
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
  char * name;
  int age;
public:
  Person(char * myname, int myage)
  {
    // 불필요한 메모리 공간의 낭비 또는 부족을 막기 위해 문자열의 길이만큼 메모리 공간 동적 할당
    int len = strlen(myname)+1;
    name = new char[len];
    strcpy(name, myname);
    age=myage;
  }

  void ShowPersonInfo() const
  {
    cout<<"이름: "<<name<<endl;
    cout<<"나이: "<<age<<endl;
  }

  // 소멸자 
  ~Person()
  {
    delete []name;
    cout<<"called destructor!"<<endl;
  }
};

int main(void)
{
  Person man1("Lee dong woo", 29);
  Person man2("Jang dong gun", 41);
  man1.ShowPersonInfo();
  man2.ShowPersonInfo();
  return 0;
}
