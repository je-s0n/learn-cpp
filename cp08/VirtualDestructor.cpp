#include <iostream>
using namespace std;
/*
가상 소멸자(Virtual Destructor)
- virtual로 선언된 소멸자를 가리키는 말
- 가상 소멸자가 호출되면, 상속의 계층구조상 맨 아래에 존재하는 유도 클래스의 소멸자가 대신 호출되면서, 기초 클래스의 소멸자가 순차적으로 호출
*/
class First
{
private:
  char * strOne;
public:
  First(char * str)
  {
    // 생성자 동적할당
    strOne = new char[strlen(str)+1];
  }
  ~First() // 소멸자 정의
  {
    cout<<"~First()"<<endl;
    delete []strOne;
  }
};

class Second : public First
{
private:
  char * strTwo;
public:
  Second(char * str1, char * str2) : First(str1)
  {
    // 생성자 동적할당
    strTwo = new char[strlen(str2)+1];
  }
  ~Second() // 소멸자 정의
  {
    cout<<"~Second()"<<endl;
    delete []strTwo;
  }
};

int main(void)
{
  First * ptr = new Second("simple", "complex");
  delete ptr; // First 클래스의 소멸자와 Second 클래스의 소멸자가 동시에 호출되어야 하지만, First 클래스의 소멸자만 호출됨 -> 메모리 누수 발생
  return 0;
}

/*
실행결과
-----------------
~First()
*/
