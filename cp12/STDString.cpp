#include <iostream>
#include <string>
using namespace std;

/*
표준 string 클래스
- C++ 표준 라이브러리에는 string이라는 이름의 클래스가 정의되어 있음
클래스의 이름이 의미하는 것처럼, 문자열의 처리를 목적으로 정의된 클래스이며, 이 클래스의 사용을 위해서는 헤더파일 <string>을 포함해야 함
*/
int main(void)
{
	string str1="I like ";
	string str2="string class";
	string str3=str1+str2; // string 객체간 덧셈연산이 가능함을 알 수 있으며, 이는 operator+ 연산자의 오버로딩으로 인해 가능함

  // string 클래스가 << 연산자에 대해서도 오버로딩 되어있음을 확인할 수 있음
	cout<<str1<<endl;
	cout<<str2<<endl;
	cout<<str3<<endl;

  // += 연산의 결과로 문자열 str1의 끝에 문자열 str2가 덧붙여졌음을 "동일 문자열!" 문자열 출력을 통해 알 수 있음
	str1+=str2;
	if(str1==str3) 	
		cout<<"동일 문자열!"<<endl;
	else
		cout<<"동일하지 않은 문자열!"<<endl;
  
  // string 클래스는 >> 연산자에 대해서도 오버로딩이 되어있음
  // 따라서 이러한 형태로 string 객체를 통해 문자열을 입력 받는 것이 가능함
	string str4;
	cout<<"문자열 입력: ";
	cin>>str4;
	cout<<"입력한 문자열: "<<str4<<endl;
	return 0;
}

/*
실행결과
-----------------
I like 
string class
I like string class
동일 문자열!
문자열 입력: test
입력한 문자열: test
*/
