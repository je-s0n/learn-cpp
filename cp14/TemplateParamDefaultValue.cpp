#include <iostream>
using namespace std;

/*
함수의 매개변수에 디폴트 값의 지정 가능하듯이, 템플릿 매개변수는 디폴트 값 지정도 가능함
*/
template <typename T=int, int len=7> // T에 int가, len에 7이 Default Value 지정
class SimpleArray
{
private:
	T arr[len];
public:
	T& operator[] (int idx) {  return arr[idx];  }
	SimpleArray<T, len>& operator = (const SimpleArray<T, len>&ref)
	{
		for(int i=0; i<len; i++)
			arr[i]=ref.arr[i];
    return *this;
	}
};

int main(void)
{
	SimpleArray<> arr; // 디폴트 값을 이요한 객체 생성 보임
	for(int i=0; i<7; i++)
		arr[i]=i+1;
	for(int i=0; i<7; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}

/*
실행결과
-------------------------
1 2 3 4 5 6 7
*/
