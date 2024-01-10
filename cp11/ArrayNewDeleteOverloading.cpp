#include <iostream>
using namespace std;

/*
operator new 함수와 operator delete 함수는 static 함수로, 멤버함수의 형태로 선언을 해도 이 둘은 static 함수로 간주됨
-> 객체생성의 과정에서 호출이 가능했던 것
*/
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) {  }
	friend ostream& operator<<(ostream& os, const Point& pos);

	void * operator new (size_t size)
	{
		cout<<"operator new : "<<size<<endl;
		void * adr=new char[size];
		return adr;
	}

  // 컴파일러는 배열 생성과정에서 객체에 필요한 메모리 공간을 바이트 단위로 계산해서 인자로 전달하면서 아래 함수 호출함
	void * operator new[] (size_t size)
	{
		cout<<"operator new [] : "<<size<<endl;
		void * adr=new char[size];
		return adr;
	}

	void operator delete (void * adr)
	{
		cout<<"operator delete ()"<<endl;
		delete []adr;
	}

  // delete 연산자를 이용한 배열소멸 시 호출되는 함수
  // 컴파일러는 소멸자를 호출한 이후에 arr에 저장된 주소 값을 전달하면서 아래 함수 호출함 
	void operator delete[] (void * adr)
	{
		cout<<"operator delete[] ()"<<endl;
		delete []adr;
	}
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	return os;
}

int main(void)
{
	Point * ptr=new Point(3, 4);
	Point * arr=new Point[3]; // 배열의 생성과정에서 총 세 개의 Point 객체가 생성되며, 이 세 Point 객체의 할당에 필요한 메모리 공간은 Line 19에 정의된 멤버함수 호출에 의해서 완성됨
	delete ptr;
	delete []arr; // 할당된 배열의 소멸을 명령하고 있으며, 객체로 구성된 배열이기 때문에 모든 객체의 소멸자가 호출된 다음에 Line 32에 정의된 멤버함수 호출됨
	return 0;
}

/*
실행결과
----------------
operator new : 8
operator new [] : 24
operator delete ()
operator delete[] ()
*/
