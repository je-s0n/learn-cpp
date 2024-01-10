#include <iostream>
#include <cstdlib>
using namespace std;

/*
C/C++의 기본 배열은 경계 검사를 하지 않는 단점을 가지고 있음
-> 때문에 엉뚱한 코드가 만들어 질 수 있으며, 컴파일도 되고 실행도 무리 없이 진행되기 때문
int main(void)
{
  int arr[3] = {1, 2, 3};
  cout<<arr[-1]<<endl; // arr주소 + sizeof(int) * (-1)의 위치에 접근
  cout<<arr[-2]<<endl; // arr주소 + sizeof(int) * (-2)의 위치에 접근
  cout<<arr[-3]<<endl;
  cout<<arr[-4]<<endl;
  . . . .
}

arrObject[2];
-> 객체 arrObject의 멤버함수 호출로 이어짐
-> 연산자가 []이므로 멤버함수 이름은 operator[]임
-> 함수호출 시 전달되는 인자의 값은 정수 2

멤버함수 호출로 이루어지기 때문에 arrObject.operator[] (2);로 해석됨을 알 수 있음
*/
class BoundCheckIntArray
{
private:
  int * arr;
  int arrlen;
public:
  BoundCheckIntArray(int len) : arrlen(len)
  {
    arr=new int[len];
  }

  int& operator[] (int idx) // 반환형이 인자로 전달된 인덱스에 해당하는 배열요소로 반환하는데 참조형임 -> 때문에 배열요소의 참조값이 반환되고, 이 값을 이용해서 배열요소에 저장된 값의 참조뿐만 아니라 변경도 가능
  {
    if(idx<0 || idx >= arrlen)
    {
      cout<<"Array index out of bound exception"<<endl;
      exit(1);
    }
    return arr[idx];
  }

  ~BoundCheckIntArray()
  {
    delete []arr;
  }
};

int main(void)
{
  BoundCheckIntArray arr(5);
  for(int i=0; i<5; i++)
    arr[i] = (i+1) * 11;
  for(int i=0; i<6; i++)
    cout<<arr[i]<<endl;
  return 0;
}

/*
실행결과
------------------
11
22
33
44
55
Array index out of bound exception
*/
