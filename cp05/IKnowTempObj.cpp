#include <iostream>
using namespace std;

class Temporary
{
private:
  int num;
public:
  Temporary(int n) : num(n)
  {
    cout<<"create obj: "<<num<<endl;
  }

  ~Temporary()
  {
    cout<<"destroy obj: "<<num<<endl;
  }

  void ShowTempInfo()
  {
    cout<<"My num is "<<num<<endl;
  }
};

int main(void)
{
    Temporary(100); // 임시객체를 직접 생성하는 방법으로, 100으로 초기화된 Temporary 임시객체 생성
    cout<<"************ after make!"<<endl<<endl;
  
    Temporary(200).ShowTempInfo(); // 임시객체를 생성하고 이 객체를 대상으로 ShowTempInfo 함수를 호출하고 있으며, 객체 생성 및 반환 시 생성 및 반환된 위치에 객체를 참조할 수 있는 참조 값 반환
    cout<<"************ after make!"<<endl<<endl;

    // 실제로는 임시객체가 통쨰로 반환되어서가 아닌 임시객체는 메모리에 저장되고, 그 객체의 참조 값이 반환되었기 때문 -> 참조자에 참조되는 임시객체는 바로 소멸되지 않음 
    const Temporary &ref = Temporary(300); // 임시객체 생성했으며, 앞에서 생성한 두 객체와 달리 참조자 ref로 임시객체를 참조하고 있음
    cout<<"************ end of main!"<<endl<<endl;
    return 0;
}

/*
실행결과
----------------------------
create obj: 100
destroy obj: 100
************ after make!

create obj: 200
My num is 200
destroy obj: 200
************ after make!

create obj: 300
************ end of main!

destroy obj: 300
*/
