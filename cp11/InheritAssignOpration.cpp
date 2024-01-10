#include <iostream>
using namespace std;

class First
{
private:
  int num1, num2;
public:
  First(int n1=0, int n2=0) : num1(n1), num2(n2)
  {}

  void ShowData() { cout<<num1<<", "<<num2<<endl; }

  // 기초 클래스에는 멤버 대 멤버의 복사가 이뤄지도록 대입 연산자를 오버로딩 함
  First operator=(const First& ref)
  {
    cout<<"First& operator=()"<<endl;
    num1 = ref.num1;
    num2 = ref.num2;
    return *this;
  }
};

class Second : public First
{
private:
  int num3, int num4;
public:
  Second(int n1, int n2, int n3, int n4)
    : First(n1, n2) , num3(n3), num4(n4)
  {}

  void ShowData()
  {
    First::ShowData();
    cout<<num3<<", "<<num4<<endl;
  }

  /*
  /************************************************************************************* 주석 *************************************************************************************/
  // 유도 클래스에도 멤버 대 멤버의 복사가 이루어지도록 대입 연산자를 오버로딩함
  // 이 부분 주석처리 후 디폴트 대입 연산자의 특성 발견하기
  -> 유도 클래스의 대입 연산자 정의에서, 명시적으로 기초 클래스의 대입 연산자 호출문을 삽입하지 않으면, 기초 클래스의 대입 연산자는 호출되지 않아서 기초 클래스의 멤버변수는 멤버 대 멤버의 복사 대상에서 제외됨
  Second& operator=(const Second& ref)
  {
    cout<<"Second& operator=()"<<endl;
    num3 = ref.num3;
    num4 = ref.num4;
    return *this;
  }

  주석 해제 시 주석한 것처럼 결과가 나오려면, 아래 코드로 Second 클래스의 대입 연산자의 형태가 되어야 함
  Second& operator=(const Second& ref)
  {
    cout<<"Second& operator=()"<<endl;
    First::operator=(ref); // 기초 클래스의 대입 연산자 호출 명령
    num3 = ref.num3;
    num4 = ref.num4;
    return *this;
  }
  */
};

int main(void)
{
  Second ssrc(111, 222, 333, 444);
  Second scpy(0, 0, 0, 0);
  scpy = ssrc;
  scpy.ShowData();
  return 0;
}

/*
실행결과
-------------------------
First& operator=()
111, 222
333, 444

주석 해제 후 실행 결과
-------------------------
First& operator=()
0, 0
333, 444
*/
