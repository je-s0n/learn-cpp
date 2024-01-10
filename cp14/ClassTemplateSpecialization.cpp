#include <iostream>
#include <cstring>
using namespace std;

/*
클래스 템플릿 특수화
특수화 이유 : 특정 자료형을 기반으로 생성된 객체에 대해 구분이 되는 다른 행동양식을 적용하기 위함
  -> 클래스 템플릿을 특수화하면, 템플릿을 구성하는 멤버함수의 일부 또는 전부를 다르게 행동하도록 정의할 수 있음

클래스 템플릿 특수화 e.g.
아래와 같이 정의된 클래스 템플릿이 존재할 때, 
template <typename T>
class SoSimple
{
public:
  T SimpleFunc(T num) { .. }
}

위 클래스 템플릿을 기반으로 자료형 int에 대해 특수화 한 템플릿 클래스를 아래와 같이 정의함
template<>
class SoSimple<int>
{
public:
  int SimpleFunc(int num) { ... }
};
-> 이렇게 int형에 대해 특수화가 되고 나면 SoSimple<int> obj;형태로 객체생성 시 특수화된 템플릿 클래스 SoSimple<int> 대상으로 객체 생성
*/
template <typename T>
class Point 
{
private:
	T xpos, ypos;
public:
	Point(T x=0, T y=0): xpos(x), ypos(y)
	{  }

	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl; 
	}
};

// 클래스 템플릿 SimpleDataWrapper 정의 -> 간단히 하나의 데이터를 저장하고, 이 데이터를 담긴 정보를 출력하도록 정의함
template <typename T>
class SimpleDataWrapper 
{
private:
	T mdata;
public:
	SimpleDataWrapper(T data) : mdata(data)
	{ }

	void ShowDataInfo(void)
	{
		cout<<"Data: "<<mdata<<endl;
	}
};

// 클래스 템플릿 SimpleDataWrapper를 char*형에 대해 특수화
// 문자열을 저장하기 위한 것으로 이를 목적으로 동적할당 기반의 생성자와 소멸자를 별도로 정의함
// 데이터의 출력을 진행하는 ShowDataInfo 함수에서는 문자열의 길이정보도 함께 출력하도록 정의함
template<>
class SimpleDataWrapper <char*>
{
private:
	char* mdata;
public:
	SimpleDataWrapper(char* data)
	{
		mdata=new char[strlen(data)+1];
		strcpy(mdata, data);
	}
	void ShowDataInfo(void)
	{
		cout<<"String: "<<mdata<<endl;
		cout<<"Length: "<<strlen(mdata)<<endl;
	}
	~SimpleDataWrapper()
	{
		delete []mdata;
	}
};

// 템플릿 클래스인 Point<int>형에 대해서 특수화 하는 방법을 보임
// 자료형의 이름을 Point<int>가 대신한다는 것 이외 차이점 없음
template<>
class SimpleDataWrapper <Point<int>>
{
private:
	Point<int> mdata;
public:
	SimpleDataWrapper(int x, int y) : mdata(x, y)
	{ }

	void ShowDataInfo(void)
	{
		mdata.ShowPosition();
	}
};

int main(void)
{	
	SimpleDataWrapper<int> iwrap(170);
	iwrap.ShowDataInfo();
  // char* 형에 대해서 특수화가 진행되었으므로, 별도의 템플릿 클래스가 생성되지 않고 SimpleDataWrapper <char*> 템플릿 클래스의 객체 생성
	SimpleDataWrapper<char*> swrap("Class Template Specialization");
	swrap.ShowDataInfo();
  // Point<int> 형에 대해서 특수화가 진행되었으므로, 별도의 템플릿 클래스가 생성되지 않고 SimpleDataWrapper <Point<int>> 템플릿 클래스의 객체 생성
	SimpleDataWrapper<Point<int>> poswrap(3, 7);
	poswrap.ShowDataInfo();
	return 0;
}

/*
실행방법
--------------
Data: 170
String: Class Template Specialization
Length: 29
[3, 7]

*/
