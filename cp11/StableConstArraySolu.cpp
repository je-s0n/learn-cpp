#include <iostream>
#include <cstdlib>
using namespace std;

// const 기반의 함수 오버로딩이 유용하게 사용될 수 있음
class BoundCheckIntArray 
{
private:
	int * arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }

public:
	BoundCheckIntArray(int len) 
    : arrlen(len)
	{
		arr=new int[len];
	}

	int& operator[] (int idx)
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return arr[idx];
	}

	int operator[] (int idx) const // const 멤버함수가 추가되었으며, 이 함수는 앞서 정의된 함수와 오버로딩 관계를 가짐. 참조값이 아닌 배열요소의 값을 단순히 반환하는 형태로 정의됨
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return arr[idx];
	}

	int GetArrLen() const 
	{
		return arrlen;
	}

	~BoundCheckIntArray()
	{
		delete []arr;
	}
};

void ShowAllData(const BoundCheckIntArray& ref)
{
	int len=ref.GetArrLen();
	for(int idx=0; idx<len; idx++)
		cout<<ref[idx]<<endl; // const 참조자를 이용한 연산이니, 위 const로 선언된 operator함수가 호출됨
}

int main(void)
{
	BoundCheckIntArray arr(5);
	for(int i=0; i<5; i++)
		arr[i]=(i+1)*11; // const 참조자를 이용한 연산이니, 위 operator함수가 호출됨
	ShowAllData(arr);
	return 0;
}

/*
실행결과
------------------
11
22
33
44
55
*/
