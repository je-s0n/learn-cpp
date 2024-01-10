#include <iostream>
using namespace std;

/*
클래스 템플릿과 static 멤버변수
- static 멤버변수는 변수가 선언된 클래스의 객체간 공유가 가능한 변수

e.g. 클래스 템플릿 정의
template <typename T>
class SimpleStaticMem
{
private:
  static T mem;
public: 
  void AddMem(T num) {  mem+=num;  }
  void ShowMem() {  cout<<mem<<endl;  }
};

template <typename T>
T SimpleStaticMem<T>::mem=0; // 템플릿 기반의 static 멤버 초기화 문장

e.g. 위 정의된 클래스 템플릿을 기반으로 컴파일러에 의해 생성된 템플릿 클래스
class SimpleStaticMem<int> // 1
{
private:
  static int mem;
public:
  voidAddMem(int num) {  mem+=num;  }
  void ShowMem() {  cout<<mem<<endl;  }
}
int SimpleStaticMem<int>::mem=0;

class SimpleStaticMem<double> // 2
{
private:
  static double mem;
public:
  voidAddMem(double num) {  mem+=num;  }
  void ShowMem() {  cout<<mem<<endl;  }
}
double SimpleStaticMem<double>::mem=0;
-> 템플릿 클래스 별로 static 멤버변수를 유지하게 됨
*/
template <typename T>
class SimpleStaticMem
{
private:
	static T mem;

public:
	void AddMem(int num) { mem+=num; }
	void ShowMem() { cout<<mem<<endl; }
} ;

template <typename T> 
T SimpleStaticMem<T>::mem=0;

int main(void)
{
	SimpleStaticMem<int> obj1;
	SimpleStaticMem<int> obj2;
	obj1.AddMem(2);
	obj2.AddMem(3);
	obj1.ShowMem();
	SimpleStaticMem<long> obj3;
	SimpleStaticMem<long> obj4;
	obj3.AddMem(100);
	obj4.ShowMem();
	return 0 ;
}

/*
실행결과
----------------------
5
100 
*/

/*
<<템플릿 참고>>
1) 언제 template<typename T>를 쓰고, 언제 template<>을 쓰는가?
-> 템플릿 관련 정의에는 template<typename T> 또는 template<>와 같은 선언을 둬서, 템플릿의 일부 또는 전부를 정의하고 있다는 사실을 컴파일러에 알려야 함
-> 정의 부분에 T가 존재하면 T에 대한 설명을 위해 <typename T>의 형태로 덧붙이면 되고, T가 존재하지 않으면 <>의 형태로 간단하게 선언하면 됨

2) 템플릿 static 멤버변수 초기화의 특수화
e.g. 아래 형태로 static 멤버를 초기화 했을 경우
template <typename T> 
T SimpleStaticMem<T>::mem=0;

e.g. SimpleStaticMem<long> 형으로 mem을 0이 아닌 5로 초기화 하는 형태
template <>
long SimpleStaticMem<long>::mem=5;
*/
