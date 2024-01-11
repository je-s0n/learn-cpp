#include <iostream>
using namespace std;

/*
static_cast<T>(expr) 
-> 유도 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로뿐만 아니라, 기초 클래스의 포인터 및 참조형 데이터도 유도 클래스의 포인터 및 참조형 데이터로 아무런 조건 없이 형 변환 시켜주지만, 책임은 프로그래머가 져야 함

dynamic_cast 연산자보다 static_cast 연산자를 사용했을 때 연산의 속도가 더 빠름
-> 이러한 이유로 dynamic_cast연산자를 사용해도 되는 상황에서 static_cast를 사용하는 경우도 적지 않음
*/

/*
static_cast 연산자는 기본 자료형 데이터간의 형 변환에도 사용됨
double result = (double)20/3;
double result = static_cast<double>(20)/3;
-> static_cast 연산자는 '기본 자료형 간의 형 변환'과 '클래스의 상속관계에서의 형 변환'만 허용을 하지만, C언어의 형 변환 연산자는 다음과 같이 말도 안되는(일반적이지 않은) 형 변환도 허용하기 때문에 여전히 static_cast 연산자의 사용은 의미를 가짐

e.g. 아래 형변환은 static_cast 연산자로는 불가능한 형 변환임
-> 여전히 static_cast 연산자는 C언어의 형 변환 연산자보다 적은 것을 허용하고 있음
int main(void)
{
	const int num=20; 
 	int * ptr = (int*) &num; // const 상수의 포인터는 const 포인터임
  	*ptr = 30; // const 상수의 num의 값이 실제로 변경됨
   	cout<<*ptr<<endl; // 30 출력

    	float * adr = (float*)ptr; // int형 포인터를 float형으로 변환함
     	cout<<*adr<<endl; // 저장된 데이터를 float형으로 해석해서 출력함
      	. . .
}
*/
class Car
{
private:
	int fuelGauge;		
public:
	Car(int fuel) : fuelGauge(fuel)
	{  }
	void ShowCarState()
	{
		cout<<"잔여 연료량: "<<fuelGauge<<endl;
	}
};

class Truck : public Car
{
private:
	int freightWeight;

public:
	Truck(int fuel, int weight)
		: Car(fuel), freightWeight(weight)
	{  }
	void ShowTruckState()
	{
		ShowCarState();
		cout<<"화물의 무게: "<<freightWeight<<endl;
	}
};

int main(void)
{
	Car * pcar1=new Truck(80, 200);
	Truck * ptruck1=static_cast<Truck*>(pcar1);     // 컴파일 OK!
	ptruck1->ShowTruckState();
	cout<<endl;

	Car * pcar2=new Car(120);
	Truck * ptruck2=static_cast<Truck*>(pcar2);     // 컴파일 OK! 그러나!
  /*
  static_cast 연산자는 dynamic_cast 연산자와 다르게 보다 많은 형 변환을 허용하지만, 그에 따른 책임도 프로그래머가 져야 하기 때문에 신중하게 선택해야 함
  dynamic_cast 연산자를 사용할 수 있는 경우에는 dynamic_cast 연산자를 사용해서 안전성을 높여야 하며, 그 이외의 경우에는 정말 책임질 수 있는 상황에서만 제한적으로 static_cast 연산자를 사용해야 함
  */
	ptruck2->ShowTruckState();
	return 0;
}

/*
실행결과
---------------------
잔여 연료량: 80
화물의 무게: 200

잔여 연료량: 120
화물의 무게: 3801464
*/
