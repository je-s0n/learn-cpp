#include <iostream>

/*
cout<<123<<endl<<3.14<<endl; 문장의 경우에는 컴파일 에러 발생
-> ( ( ( ( cout<<(123) ) << endl ) << 3.14 ) << endl ); 
순서로 연산이 이루어지며, 모든 << 연산의 결과로는 cout이 반환되어야 하는데, 위 예저는 cout를 반환하지 않음
참고로 << 연산자는 왼쪽에서 오른쪽으로 진행됨
*/

namespace mystd
{
  using namespace std;

  class ostream
  {
  public:
    // cout 객체의 참조값을 반환하는 형태로 확장
    ostream& operator<< (char * str)
    {
      printf("%s", str);
      return *this;
    }

    ostream& operator<< (char str)
    {
      printf("%c", str);
      return *this;
    }

    ostream& operator<< (int num)
    {
      printf("%d", num);
      return *this;
    }

    ostream& operator<< (double e)
    {
      printf("%g", e);
      return *this;
    }

    // endl 함수는 인자로 전달된 객체의 참조값을 반환하므로, 반환된 값을 재반환하는 형태로 연산자 오버로딩 함
    ostream& operator<< (ostream& (*fp)(ostream &ostm))
    {
      return fp(*this);
    }
  };

  ostream& endl(ostream &ostm)
  {
    ostm<<'\n';
    fflush(stdout); // 버퍼를 비우는 작업까지 함께 진행
    return ostm;
  }

  ostream cout;
}

int main(void)
{
  using mystd::cout;
  using mystd::endl;
  cout<<3.14<<endl<<123<<endl;
  return 0;
}

/*
실행결과
-----------------
3.14
123
*/
