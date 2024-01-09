#include <iostream>

/*
C++에서 콘솔 입출력에 사용되는 cout, endl의 이해를 돕기 위한 예제
-> 이 예제에서는 cout과 endl을 아주 조금 흉내 내서 이 둘에 대한 이해를 돕고 있음
*/
namespace mystd // cout와 endl를 직접 구현하기 위해 선언한 이름공간
{
  using namespace std; // using 선언은 mystd내에서 지역적으로 이루어졌으니 이 지역 내에서만 유효한 선언

  // cout는 객체 이름이며, 객체 내에서는 다양한 기본 자료형 데이터를 대상으로 << 연산자를 오버로딩 하고 있음
  class ostream
  {
  public:
    void operator<< (char * str)
    {
      printf("%s", str);
    }

    void operator<< (char str)
    {
      printf("%c", str);
    }

    void operator<< (int num)
    {
      printf("%d", num);
    }

    void operator<< (double e)
    {
      printf("%g", e);
    }

    // 42행에서 정의된 함수의 경우, 36행에 정의된 함수를 인자로 전달받을 수 있도록 정의되어 있음
    void operator<< (ostream& (*fp)(ostream &ostm))
    {
      fp(*this);
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
  // 이름공간 mystd 내 선언된 cout와 endl의 사용을 위해 지역적으로 using 선언
  using mystd::cout;
  using mystd::endl;

  cout<<"Simple String";
  cout<<endl;
  cout<<3.14;
  cout<<endl;
  cout<<123;
  endl(cout);
  return 0;
}

/*
실행결과
-----------------
Simple String
3.14
123
*/
