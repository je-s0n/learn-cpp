/*
복사 생성자가 호출되는 시점
case 1 : 기존에 생성된 객체를 이용해서 새로운 객체를 초기화하는 경우
case 2 : Call-by-value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
case 3 : 객체를 반환하되, 참조형으로 반환하지 않는 경우
-> 세 가지의 공통점 : 객체를 새로 생성해야 하며, 생성과 동시에 동일한 자료형의 객체로 초기화해야 함
*/
#include <iostream>
using namespace std;

class SoSimple
{
private:
  int num;
public:
  SoSimple(int n) : num(n)
  {}
  SoSimple(const SoSimple& copy) : num(copy.num)
  {
    cout<<"Called SoSimple(const SoSimple& copy)"<<endl;
  }
  void ShowData()
  {
    cout<<"num: "<<num<<endl;
  }
};

void SimpleFuncObj(SoSimple ob)
{
  ob.ShowData();
}

int main(void)
{
  SoSimple obj(7);
  cout<<"함수호출 전"<<endl;
  SimpleFuncObj(obj);
  cout<<"함수호출 후"<<endl;
  return 0;
}

/*
실행결과
----------------------------------------
함수호출 전
Called SoSimple(const SoSimple& copy)
num: 7
함수호출 후
*/

/*
실행결과를 통해 함수에 인자를 전달하는 과정에서 복사 생성자가 호출됨을 확인했고, 이로 인해 멤버변수 num에 저장된 값이 복사됨을 확인함
복사 생성자의 호출주체는 ob객체로 ob객체의 복사 생성자가 호출되면서, obj 객체가 인자로 전달되어야 함
*/
