#include <iostream>
using namespace std;

/*
임시객체로의 자동 형 변환과 형 변환 연산자
-> 객체 간 대입연산을 허용함

객체와 정수 간의 대입 연산 예시
*/
class Number
{
private:
	int num;
public:
	Number(int n=0) : num(n)
	{
		cout<<"Number(int n=0)"<<endl;
	}

  // 굳이 대입 연산자를 오버로딩 할 필요 없는 상황이지만, 대입 연산자의 호출을 확인하기 위해서 오버로딩함
  // 문자열을 출력하는 것 말고는 디폴트 대입 연산자와 차이가 없음
	Number& operator=(const Number &ref)
	{
		cout<<"operator=()"<<endl;
		num=ref.num;
		return *this;
	}

	void ShowNumber() { cout<<num<<endl; }
};

int main(void)
{
	Number num;
	num=30; // 서로 다른 두 자료형의 피연산자를 대상으로 대입연산 진행
  /*
  위 문장에서 일어나는 일을 풀어서 작성한 내용
  num = Number(30); // 1단계 임시객체의 생성
  num.operator=(Number(30)); // 2단계 임시객체를 대상으로 하는 대입 연산자의 호출
  -> 핵심은 임시객체 생성으로, 임시객체의 생성을 통해 대입연산이 진행되는 기준 필요함
  
  기준 : Number형 객체가 와야 할 위치에 int형 데이터(또는 객체)가 왔을 경우, int형 데이터를 인자로 전달받는 Number형 클래스의 생성자 호출을 통해서 Number형 임시객체를 생성함
  */
	num.ShowNumber();
	return 0;
}

/*
실행결과
-----------------
Number(int n=0)
Number(int n=0)
operator=()
30
*/
