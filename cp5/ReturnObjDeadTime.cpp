#include <iostream>
using namespace std;

class SoSimple
{
private:
  int num;
public:
  SoSimple(int n) : num(n)
  {
    cout<<"New Object: "<<this<<endl;
  }

  SoSimple(const SoSimple& copy) : num(copy.num)
  {
    cout<<"New Copy obj: "<<this<<endl;
  }

  ~SoSimple()
  {
    cout<<"Destroy obj: "<<this<<endl;
  }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
  cout<<"Parm ADR: "<<&ob<<endl;
  return ob;
}

int main(void)
{
  SoSimple obj(7);
  SimpleFuncObj(obj);

  cout<<endl;
  SoSimple tempRef=SimpleFuncObj(obj); // 추가로 객체 생성하지 않고, 반환되는 임시객체에 tempRef라는 이름을 할당하고 있음을 보여줌
  cout<<"Retrun Obj "<<&tempRef<<endl;
  return 0;
}

/*
실행결과
-------------------------------
Parm ADR: 0012FE38 -- 27행 실행을 통해
New Copy obj: 0012FE64 -- 28행의 반환으로 인한 임시객체 생성
Destroy obj: 0012FE38 -- 매개변수 ob의 소멸
Destroy obj: 0012FE64 -- 26행의 반환으로 생성된 임시객체  소멸

New Copy obj: 0012FE38 -- 37행의 함수호출로 인한 25행의 매개변수 ob 생성
Parm ADR: 0012FE38 -- 27행 실행을 통해서
New Copy obj: 0012FF48 -- 28행의 반환으로 인한 임시객체 생성
Destroy obj: 0012FE38 -- 매개변수 ob의 소멸
Return obj: 0012FF48 -- 38행 실행결과 임시객체의 주소 값과 동일함
Destroy obj: 0012FF48 -- tempRef가 참조하는 임시객체 소멸
Destroy obj: 0012FE54 -- 33행의 obj 소멸
*/
