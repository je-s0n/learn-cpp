#include <iostream>
#include <cstring>
using namespace std;

/*
표준 string 클래스의 분석 (STDString.cpp 기반)
1) 문자열을 인자로 전달받는 생성자 정의
  앞서 보인 예제에서는 아래 형태로 string 객체를 생성했으며, 이는 문자열을 전달받는 생성자의 호출로 이어짐
  string str1 = "I like ";       -> string str1("I like ");
  string str2 = "string class";  -> string str2("string class");

2) 생성자, 소멸자, 복사 생성자 그리고 대입 연산자의 정의
  String 클래스는 문자열을 저장 및 표현하는 클래스로, 저장하고자 하는 문자열의 길이가 일정하지 않음
  -> 문자열의 저장을 위한 메모리 공간을 생성자 내에서 동적 할당해야 하는데, 이를 위해 소멸자를 정의해야 하며 깊은 복사를 하는 복사 생성자와 대입 연산자까지 함께 정의해야 함

3) 결합된 문자열로 초기화된 객체를 반환하는 + 연산자의 오버로딩
  string str3 = str1+str2;
  이 연산의 결과로 str1과 str2는 변화가 없지만, str3는 str1과 str2가 지니는 문자열을 합한 문자열로 초기화됨 -> str1, str2의 연산결과로 반환된 값이 str3 생성자로 전달된 결과
  -> 결과를 반환하는 값은 1) 문자열 주소 값, 2) string 객체 두가지로 볼 수 있는데, 객체로 반환되도록 정의할 예정

4) 문자열을 덧붙이는 += 연산자의 오버로딩
  str1 += str2;
  연산의 결과로 str2가 지니고 있는 문자열이 str1이 지니는 문자열 뒤에 덧붙여진 것을 확인하였고, 말한 대로 동작하기 위해 += 연산자 오버로딩 해야 함

5) 내용비교를 진행하는 == 연산자의 오버로딩
  STDString.cpp의 main함수에 삽입된 if문에서 == 연산을 통해 str1과 str3가 지니는 문자열의 내용비교를 하는 부분이 존재함
  == 연산자가 문자열의 내용비교를 한다는 사실을 알 수 있기 때문에 == 연산자가 객체에 저장된 문자열의 내용을 비교하도록 오버로딩 해야 함

6) 콘솔입출력이 가능하도록 <<, >> 연산자 오버로딩
  string 객체를 대상으로 << 연산자를 이용한 출력과 >> 연산자를 이용한 입력을 보이고 있으므로, 가능하도록 <<연산자와 >>연산자 오버로딩 해야 함
*/
class String
{
private:
	int len;
	char * str;
public:
	String();
	String(const char * s);
	String(const String& s);
	~String();
	String& operator= (const String& s);
	String& operator+= (const String& s);
	bool operator== (const String& s);
	String operator+ (const String& s);

	friend ostream& operator<< (ostream& os, const String& s);
	friend istream& operator>> (istream& is, String& s);
};

String::String()
{
	len=0;
	str=NULL;
}

String::String(const char* s)
{
	len=strlen(s)+1;
	str=new char[len];
	strcpy(str, s);
}

String::String(const String& s)
{
	len=s.len;
	str=new char[len];
	strcpy(str, s.str);
}

String::~String() 
{
	if(str!=NULL)
		delete []str; 
}

String& String::operator= (const String& s)
{
	if(str!=NULL)
		delete []str;
	len=s.len;
	str=new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+= (const String& s)
{
	len+=(s.len-1); // 문자열 길이 정보에 문자열의 끝을 의미하는 NULL 문자도 포함되어 있기 때문에 NULL이 두번 계산되어있으니 하나 빼는 것
	char* tempstr=new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	if(str!=NULL)
		delete []str;
	str=tempstr;
	return *this;
}

bool String::operator== (const String& s)
{
	return strcmp(str, s.str) ? false : true;
}

String String::operator+ (const String& s)
{
	char* tempstr=new char[len+s.len-1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);
	
	String temp(tempstr);
	delete []tempstr;
	return temp;
}

ostream& operator<< (ostream& os, const String& s)
{
	os<<s.str;
	return os;
}

istream& operator>> (istream& is, String& s)
{
	char str[100];
	is>>str;
	s=String(str);
	return is;
}

int main(void)
{
	String str1="I like ";
	String str2="string class";
	String str3=str1+str2;

	cout<<str1<<endl;
	cout<<str2<<endl;
	cout<<str3<<endl;

	str1+=str2;
	if(str1==str3) 	
		cout<<"동일 문자열!"<<endl;
	else
		cout<<"동일하지 않은 문자열!"<<endl;

	String str4;
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
문자열 입력: test!
입력한 문자열: test!
*/
