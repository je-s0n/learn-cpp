#include <iostream>
using namespace std;

int main(void)
{
  int num = 10;
  int i = 0;

  // 키워드 true와 false를 콘솔에 출력했을 때 출력내용을 확인하기 위함
  // 1과 0이 아닌 참과 거짓을 표현하기 위한 1바이트 크기의 데이터
  cout<<"true: "<<true<<endl; // 1
  cout<<"false: "<<false<<endl; // 0

  while(true) 
  {
    cout<<i++<<' ';
    if(i>num)
      break;
  }
  cout<<endl;

  // 상수 1과 상수 0의 데이터 크기를 확인하기 위함 
  cout<<"sizeof 1: "<<sizeof(1)<<endl; // 4
  cout<<"sizeof 0: "<<sizeof(0)<<endl; // 4

  // 참과 거짓을 의미하는 데이터 true와 false의 크기를 확인하기 위함
  cout<<"sizeof true: "<<sizeof(true)<<endl; // 1
  cout<<"sizeof false: "<<sizeof(false)<<endl; // 1
  return 0;
}
