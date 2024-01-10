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
    int len = strlen(myname)+1;
    name = new char[len];
    strcpy(name, myname);
    age = myage;
  }

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

  /*
  정상적으로 아래 메모리 누수 문제 해결하는 대입 연산자 정의
  Person& operator=(const Person& ref)
  {
    delete []name; // 메모리 누수를 막기 위한 메모리 해제 연산
    int len = strlen(ref.name) + 1;
    name = new char[len];
    strcpy(name, ref.name);
    age = ref.age;
    return *this;
  }
  */
};

int main(void)
{
  Person man1("Lee dong woo", 29);
  Person man2("Yoon ji yul", 22);
  
  // 대입 연산자가 호출되지만, Person클래스에는 대입 연산자가 정의되어 있지 않으니, 디폴트 대입 연산자 호출됨 -> 얕은 복사
  /*
  위 코드를 통해
  1) 문자열 "Yoon ji yul"을 가리키던 문자열의 주소 값을 잃게 됨 -> 접근 불가능한 상태가 되어 메모리 누수로 이어지게 됨
  2) 얕은 복사로 인해서 객체 소멸과정에서 지워진 문자열을 중복 소멸하는 문제가 생김

  생성자 내 동적 할당을 하는 경우, 디폴트 대입 연산자는 두 가지 문제를 일으키므로 아래 형태로 대입 연산자를 정의해야 함
  1) 깊은 복사를 진행하도록 정의함
  2) 메모리 누수가 발생하지 않도록, 깊은 복사에 앞서 메모리 해제 과정을 거침
  */
  man2 = man1;
  man1.ShowPersonInfo();
  man2.ShowPersonInfo();
  return 0;
}

/*
실행결과
--------------------------------
이름: Lee dong woo
나이: 29
이름: Lee dong woo
나이: 29
called destructor!
*/
