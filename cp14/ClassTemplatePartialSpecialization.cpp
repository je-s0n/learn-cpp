#include <iostream>
using namespace std;

/*
아래 클래스가 있다고 가정했을 때,
template <typename T1, typename T2>
class MySimple { ... }

T1, T2를 각각 char와 int로 하여 특수화를 진행하면 아래 형태가 됨
template <>
class MySimple<char, int> { ... }
-> 템플릿의 정의에 사용된, 결정되지 않은 자료형의 수가 하나 더 늘어난 상황에서의 특수화를 보인 것 뿐임

template <typename T1>
class MySimple<T1, int> { ... }
-> T2 하나에 대해서만 부분적으로 특수화를 진행한 것을 '클래스 템플릿의 부분 특수화(class template partial specialization)'라고 함
*/
template <typename T1, typename T2>
class MySimple 
{ 
public:
	void WhoAreYou()
	{
		cout<<"size of T1: "<<sizeof(T1)<<endl;
		cout<<"size of T2: "<<sizeof(T2)<<endl;
		cout<<"<typename T1, typename T2>"<<endl;
	}
};

template<>
class MySimple<int, double>
{
public:
	void WhoAreYou()
	{
		cout<<"size of int: "<<sizeof(int)<<endl;
		cout<<"size of double: "<<sizeof(double)<<endl;
		cout<<"<int, double>"<<endl;
	}
};

/*
// T2를 double로 부분 특수화
template<typename T1>
class MySimple<T1, double>
{
public:
	void WhoAreYou()
	{
		cout<<"size of T1: "<<sizeof(T1)<<endl;
		cout<<"size of double: "<<sizeof(double)<<endl;
		cout<<"<T1, double>"<<endl;
	}
};
*/

int main(void)
{
	MySimple<char, double> obj1;
	obj1.WhoAreYou();
	MySimple<int, long> obj2;
	obj2.WhoAreYou();
	MySimple<int, double> obj3;
	obj3.WhoAreYou();
	return 0;
}

/*
주석 있는 상태의 실행결과
----------------------
size of T1: 1
size of T2: 8
<typename T1, typename T2>
size of T1: 4
size of T2: 4
<typename T1, typename T2>
size of int: 4
size of double: 8
<int, double>
*/

/*
주석 해제한 상태의 실행결과
----------------------
size of T1: 1
size of double: 8
<T1, double>
size of T1: 4
size of T2: 4
<typename T1, typename T2>
size of int: 4
size of double: 8
<int, double>
*/
