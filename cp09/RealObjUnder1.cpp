#include <iostream>
using namespace std;

/*
설명을 위한 모델의 코드 제시
*/
class Data
{
private:
  int data;
public:
  Data(int num) : data(num)
  {}
  void ShowData() { cout<<"Data: "<<data<<endl; }
  void Add(int num) { data += num; }
};

int main(void)
{
  Data obj(15);
  obj.Add(17);
  obj.ShowData();
  return 0;
}

/*
실행결과
---------------
Data: 32
*/
