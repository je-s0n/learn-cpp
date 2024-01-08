#include <iostream>
using namespace std;

/*
Person형 포인터는 Person 객체뿐만 아니라, Person을 상속하는 유도 클래스의 객체도 가리킬 수 있음
-> C++에서 AAA형 포인터 변수는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있음(=객체의 주소 값을 저장할 수 있음)
*/
class Person
{
public:
  void Sleep() { cout<<"Sleep"<<endl; }
};

class Student : public Person
{
public:
  void Study() { cout<<"Study"<<endl; }
};

class PartTimeStudent : public Student
{
public:
  void Work() { cout<<"Work"<<endl; }
};

int main(void)
{
  // 포인터 변수 선언 후 포인터 변수의 객체 참조 
  Person * ptr1 = new Student(); // Student는 Person을 상속하므로, Person형 포인터 변수는 Student 객체를 가리킬 수 있음
  Person * ptr2 = new PartTimeStudent(); // PartTimeStudent는 Person을 간접 상속하므로, Person형 포인터 변수는 PartTimeStudent 객체를 가리킬 수 있음
  Student * ptr3 = new PartTimeStudent(); // PartTimeStudent는 Student를 상속하므로, Student형 포인터 변수는 PartTimeStudent 객체를 가리킬 수 있음
  ptr1->Sleep();
  ptr2->Sleep();
  ptr3->Study();
  delete ptr1; delete pt2; delete ptr3;
  return 0;
}

/*
실행결과
-----------------
Sleep
Sleep
Study\
*/
