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
    int len = strlen(myname) + 1;
    name = new char[len];
    strcpy(name, myname);
    age=myage;
  }

  /*
  // 디폴트 복사 생성자 - 얕은 복사
  Person(const Person &person)
    : name(person.name), age(person.age)
  {
  // empty
  } 

  
  // 디폴트 복사 생성자 - 깊은 복사
  // 멤버변수 age의 멤버 대 멤버 복사
  // 메모리 공간 할당 후 문자열 복사, 그리고 할당된 메모리의 주소 값을 멤버 name에 저장
  Person(const Person &person)
    : age(person.age)
  {
    name = new char[strlen(copy.name)+1];
    strcpy(name, copy.name);
  } 
  */

  void ShowPersonInfo() const
  {
    cout<<"이름: "<<name<<endl;
    cout<<"나이: "<<age<<endl;
  }

  ~Person()
  {
    delete []name;
    cout<<"called destructor!"<<endl;
  }
};

int main(void)
{
  Person man1("Lee dong woo", 29);
  /*
  얇은 복사(Shallow Copy) : 멤버 대 멤버의 복사하는 방식
  -> 멤버변수가 힙 메모리 공간을 참조하는 경우에 문제 발생

  Person man2 = man1; 코드에서 man1객체와 man2객체는 같은 문자열 주소를 참조함
  소멸 시 man2 먼저 진행되었다고 가정했을 때
  1) man2 객체와 man2가 포인터 참조하는 문자열 삭제
  2) man1 객체 소멸 진행 시 man1이 참조하는 문자열이 이미 소멸된 상태로 문제 발생
  */
  
  /*
  깊은 복사(Deep Copy) : 멤버 뿐만 아니라 포인터로 참조하는 대상까지 복사하는 방식
  1) 멤버변수 age의 멤버 대 멤버 복사
  2) 메모리 공간 할당 후 문자열 복사, 그리고 할당된 메모리의 주소 값을 멤버 name에 저장
  */
  Person man2 = man1; // 별도의 복사 생성자가 정의되지 않았으므로, 디폴트 복사 생성자에 의한 멤버 대 멤버의 복사가 진행됨
  man1.ShowPersonInfo();
  man2.ShowPersonInfo();
  return 0;
}
