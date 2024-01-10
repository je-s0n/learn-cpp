#include <iostream>
using namespace std;

/*
기본적으로 제공되는 new 연산자가 하는 일
1) 메모리 공간의 할당
2) 생성자의 호출
3) 할당하고자 하는 자료형에 맞게 반환된 주소 값의 형 변환

new 연산자의 오버로딩 관련한 C++ 컴파일러는 객체의 생성과정은 다소 복잡한 과정을 거치기 때문에 생성자의 호출과 반환된 주소 값의 형 변환은 계속 해서 책임지지만, new 연산자를 오버로딩 할 때에는 메모리 공간의 할당만을 책임지게 됨
*/
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) {  }
	friend ostream& operator<<(ostream& os, const Point& pos);

  // 아래와 같이 오버로딩 하도록 약속되어 있음
	void * operator new (size_t size)
	{
		cout<<"operator new : "<<size<<endl;
		void * adr=new char[size]; // 바이트 단위로 필요한 메모리 공간을 할당하고 있으며, 할당에 사용되는 크기정보는 컴파일러가 계산해서 전달해줌. 참고로 이렇듯 char형 대상으로 new 연산을 하는 문장은 malloc 함수의 호출문으로 대신할 수 있음
		return adr;
	}

	void operator delete (void * adr)
	{
		cout<<"operator delete ()"<<endl;
		delete []adr; // 배열의 형태로 할당했기 때문에 배열의 삭제를 위한 delete문을 구성했으며, 이 역시 char형으로 할당된 메모리 공간을 해제하는 것이기 때문에 free함수의 호출문으로 대신할 수 있음
	}
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	return os;
}

int main(void)
{  
  /*
  먼저 필요한 메모리 공간을 계산한 후 크기가 계산되면 operator new 함수를 호출하면서 계산된 크기의 값을 인자로 전달함
  cf. 크기 정보는 바이트 단위로 계산되어 전달됨 그리하여 Line 20에 있는 함수 정의를 해야 하는 것
  */
	Point * ptr = new Point(3, 4);
	cout<<*ptr;

  /*
  객체 소멸 명령 시 컴파일러는 먼저 ptr이 가리키는 객체의 소멸자를 호출하는데, Line 28에 있는 함수에 ptr에 저장된 주소 값을 전달함
  소멸자는 오버로딩 된 함수가 호출되기 전에 호출이 되므로 오버로딩 된함수에서는 메모리 공간의 소멸을 책임져야 함
  */
	delete ptr;
	return 0;
}

/*
실행결과
--------------
operator new : 8
[3, 4]
operator delete ()
*/
