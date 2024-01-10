#include <iostream>
#include <cstdlib>
using namespace std;

/*
컴파일 에러 발생하는 예시
*/
class BoundCheckIntArray 
{
private:
	int * arr;
	int arrlen;

	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }

public:
	BoundCheckIntArray(int len) :arrlen(len)
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

	int GetArrLen() const 
	{
		return arrlen;
	}

	~BoundCheckIntArray()
	{
		delete []arr;
	}
};

void ShowAllData(const BoundCheckIntArray& ref) // BoundCheckIntArray 객체의 배열에 저장된 모든 요소를 출력하는 함수
{
	int len=ref.GetArrLen();

	for(int idx=0; idx<len; idx++)
    // 위 매개변수 const 선언으로 인한 문제 - 컴파일 에러 발생
    /*
    ref.operator[] (idx);로 해석이 되며, 위에서 정의한 operator[] 함수는 const 선언이 되지 않음
    -> 위 함수에 const 선언 추가하더라도, 배열을 멤버로 선언하는 경우에 저장 자체가 불가능해지기 때문에 다른 부분에서 컴파일 에러 발생
    -> 하지만, const의 선언유무도 함수 오버로딩의 조건에 해당하는 것을 인지해야 함
    */
		cout<<ref[idx]<<endl;
}

int main(void)
{
	BoundCheckIntArray arr(5);
	for(int i=0; i<5; i++)
		arr[i]=(i+1)*11;
	ShowAllData(arr);
	return 0;
}
