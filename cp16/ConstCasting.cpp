#include <iostream>
using namespace std;

/*
const_cast: const의 성향을 제거하는 형 변환을 목적으로 함
const_cast<T>(expr); 형태를 가짐

const_cast연산자가 존재함으로 인해 키워드 const 선언에 값의 변경을 허용하지 않는다는 의미를 부여하기 어려워진 것 같지만, 아래 예제와 같이 const_cast 연산자의 긍정적인 측면이 잘 드러나는 경우에만 제한적으로 사용해야 함
*/
void ShowString(char* str) // 문자열의 주소 값을 인자로 전달받는 함수 정의
{
	cout<<str<<endl;
}

void ShowAddResult(int& n1, int& n2) // 인자로 전달되는 변수를 참조형으로 전달받는 함수 정의
{
	cout<<n1+n2<<endl;
}

int main(void)
{
  // 여기서 선언된 포인터 변수 name은 const char* 형이고, 위 ShowString 함수의 매개변수는 char*형임
  // 따라서 name은 위에 정의된 ShowString 함수의 인자로 전달될 수 없음
  // 참고로 name이 char*형이고, 위 ShowString 함수 매개변수가 const char*형이면 인자로 전달 가능함
	const char * name="Lee Sung Ju";

  // 인자의 전달을 위해 포인터 변수 name의 const를 제거하는 형태로 형 변환을 진행하고 있음
  // 그 결과 ShowString 함수의 인자로 전달하고 있음
	ShowString(const_cast<char*>(name));

	const int& num1=100;
	const int& num2=200;
  // ShowString(const_cast<char*>(name));와 유사하게 인자의 전달을 위해서 const int& 형 데이터를 int& 형으로 형 변환하고 있음
	ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2));
	return 0;
}

/*
실행결과
---------------------
Lee Sung Ju
300
*/
