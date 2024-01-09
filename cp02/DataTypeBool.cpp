#include <iostream>
using namespace std;

// bool도 기본자료형이기 때문에 함수의 반환형으로 선언 가능
bool IsPositive(int num)
{
  if(num <= 0)
    return false;
  else
    return true;
}

int main(void)
{
  bool isPos;
  int num;
  // 숫자 num 변수에 입력
  cout<<"Input number: ";
  cin>>num;
  
  isPos=IsPositive(num); // bool형 변수를 위에서 선언하여 함수 IsPositive가 반환하는 bool형 데이터를 저장하고 있음
  if(isPos)
    cout<<"Positive number"<<endl;
  else
    cout<<"Negative number"<<endl;

  return 0;
}
