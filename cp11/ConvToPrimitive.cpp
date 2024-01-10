#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n=0) : num(n)
	{
		cout<<"Number(int n=0)"<<endl;
	}

	Number& operator=(const Number &ref)
	{
		cout<<"operator=()"<<endl;
		num=ref.num;
		return *this;
	}

  // 형 변환 연산자는 반환형을 명시하지 않지만, return문에 의한 값의 반환은 얼마든지 가능함
  // int형으로 형 반환해야 하는 상황에서 호출되는 함수
	operator int ()    // 형 변환 연산자의 오버로딩
	{
		return num;
	}

	void ShowNumber() { cout<<num<<endl; }
};

int main(void)
{
	Number num1;
	num1=30;
	Number num2=num1+20; // num1+20이 먼저 진행되어야 하는 상황으로 operator+ 함수가 정의되어 있지 않으니 덧셈이 가능하려면 num1이 int형으로 변환되어야 하는데, 이 때 호출되는 것이 형 변환 연산자임
	num2.ShowNumber();
	return 0;
}
