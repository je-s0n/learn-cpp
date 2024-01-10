#include <iostream>
using namespace std;

/*
템플릿 매개변수 : 템플릿을 정의할 때 결정되지 않은 자료형을 의미하는 용도로 사용되는 T 또는 T1, T2와 같은 문자를 가리킴
템플릿 인자 : 템플릿 매개변수에 전달되는 자료형 정보를 가리킴
-> 템플릿 매개변수에는 변수의 선언이 올 수 있음
e.g. SimpleArray<int, 5> i5arr;
len에 전달된 인자 5는 해당 템플릿 클래스에서 상수처럼 사용되며, len은 5로 치환되어 컴파일러에 의해 SimpleArray<int, 5>형 템플릿 클래스가 생성됨
*/
template <typename T, int len>
class SimpleArray
{
private:
	T arr[len];
public:

	T& operator[] (int idx) {  return arr[idx]; }
	SimpleArray<T, len>& operator=(const SimpleArray<T, len>& ref)
  {
    for(int i=0; i<len; i++)
      arr[i] = ref.arr[i];
    return *this;
  }
};

int main(void)
{	
	SimpleArray<int, 5> i5arr1;
	for(int i=0; i<5; i++)
		i5arr1[i]=i*10;

	SimpleArray<int, 5> i5arr2;
	i5arr2=i5arr1; // i5arr1과 i5arr2 모두 SimpleArray<int,5>형이기 때문에 대입연산이 가능함
	for(int i=0; i<5; i++)
		cout<<i5arr2[i]<<", ";
	cout<<endl;

	SimpleArray<int, 7> i7arr1;
	for(int i=0; i<7; i++)
		i7arr1[i]=i*10;

	SimpleArray<int, 7> i7arr2;
	i7arr2=i7arr1; // i7arr1과 i7arr2 모두 SimpleArray<int,7>형이기 때문에 대입연산이 가능함
	for(int i=0; i<7; i++)
		cout<<i7arr2[i]<<", ";
	cout<<endl;
	return 0;
  /*
  cf. SimpleArray<int, 5>와 SimpleArray<int, 7>은 서로 다른 형임
    -> 길이가 다른 두 배열 객체간의 대입은 허용하지 않으며, 대입연산 할 경우 컴파일 에러가 발생함 
    -> 배열에서 자료형도 같고 길이도 같은 배열 객체에 대해서만 대입 및 복사 허용

  int main(void)
  {
    SimpleArray<int, 5> i5arr1;
    SimpleArray<int, 7> i7arr1;
    i5arr1 = i7arr1; // compile error
  }

  만약, 생성자를 이용해 배열의 길이를 결정하게 됐다면,
  길이가 같은 배열에 대해서만 대입을 허용하기 위해 추가적인 코드의 삽입이 불가피함
  이러한 추가적인 코드는 대입 및 복사 과정에서 CPU가 수행해야 할 일을 늘리는 결과로 이어짐
  */
}

/*
실행결과
--------------------------
0, 10, 20, 30, 40,
0, 10, 20, 30, 40, 50, 60,
*/
