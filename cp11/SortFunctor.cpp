#include <iostream>
using namespace std;

class SortRule
{
public:
	virtual bool operator()(int num1, int num2) const = 0; // 유도 클래스에서 정의하도록 가상함수로 정의
};

class AscendingSort : public SortRule   // 버블정렬 오름차순
{
public:
	bool operator()(int num1, int num2) const
	{
		if(num1>num2)
			return true;
		else 
			return false;
	}
};

class DescendingSort : public SortRule    // 버블정렬 내림차순
{
public:
	bool operator()(int num1, int num2) const
	{
		if(num1<num2)
			return true;
		else 
			return false;
	}
};

class DataStorage    // 단순히 정수 데이터를 저장할 수 있도록 설계된 클래스
{
private:
	int * arr;
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) :idx(0), MAX_LEN(arrlen) // 생성자의 인자를 통해서 저장할 정수의 최대 개수를 결정할 수 있도록 정의함
	{
		arr=new int[MAX_LEN];
	}

	void AddData(int num) // 정수형 데이터의 저장을 목적으로 정의된 함수
	{
		if(MAX_LEN<=idx)
		{
			cout<<"더 이상 저장이 불가능합니다."<<endl;
			return;
		}
		arr[idx++]=num;
	}

	void ShowAllData() // 데이터를 배열에 저장된 순서대로 출력하는 함수
	{
		for(int i=0; i<idx; i++)
			cout<<arr[i]<<' ';
		cout<<endl;
	}

  /*
  매개변수 형이 SortRule의 참조형이므로, SortRule클래스를 상속하는 AscendingSort클래스와 DescendingSort클래스의 객체는 인자로 전달 가능함
  그리고 SortRule의 operator()함수는 virtual로 선언되었으니, 유도 클래스의 operator() 함수가 대신 호출됨
  -> 핑터로 무엇이 전달되느냐에 따라 정렬의 기준이 바뀌게 되며, 이것이 바로 핑터를 정의하는 이우임
  */
	void SortData(const SortRule &functor) // 버블정렬을 진행하는데, fuctor의 함수호출 결과를 통해 정렬 진행
	{
		for(int i=0; i<(idx-1); i++)
		{
			for(int j=0; j<(idx-1)-i; j++)
			{
				if(functor(arr[j], arr[j+1]))
				{
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
	}
};

int main(void)
{
	DataStorage storage(5);
	storage.AddData(40);
	storage.AddData(30);
	storage.AddData(50);
	storage.AddData(20);
	storage.AddData(10);

	storage.SortData(AscendingSort()); // 오름차순으로 정렬 진행, AscendingSort 객체를 임시객체의 형태로 생성해서 전달함 
	storage.ShowAllData();

	storage.SortData(DescendingSort()); // 내림차순으로 정렬 진행, DescendingSort 객체를 임시객체의 형태로 생성해서 전달함 
	storage.ShowAllData();
	return 0;
}

/*
실행결과
---------------
10 20 30 40 50
50 40 30 20 10
*/
