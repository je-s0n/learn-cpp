#include <iostream>
using namespace std;

/*
오래된 C스타일 형 변환 연산자(Old C-style cast operator) : C 스타일의 형 변환 연산자를 가리키는 말
-> C 스타일의 형 변환 연산자는 C언어와의 호환성을 위해 존재할 뿐, C++에서는 새로운 형 변환 연산자와 규칙을 제공함

화물의 무게:3801464
-> 실행결과에서는 전혀 엉뚱한 화물의 무게가 보여 오해할 수 있음
  컴파일러는 위 형변환 연산인지 아닌지 모르겠지만, 형 변환을 하라니까 한 것임

위와 같은 유형의 논란과 문제점 때문에 4개 연산자를 추가로 제공하여 용도에 맞는 형 변환 연산자를 사용 유도
1) static_cast : A타입에서 B타입으로 변환 -> 프로그래머가 책임을 져야 하기 때문에 신중히 사용해야 함
2) const_cast : const 성향을 제거하는 형 변환 -> 함수의 인자전달 시 const 선언으로 인한 형 불일치가 발생해서 인자의 전달이 불가능한 경우에 유용하게 사용됨
3) dynamic_cast : 상속관계에서의 안전한 형 변환, Polymorphic 클래스(=하나 이상의 가상함수를 지니는 클래스) 기반의 형 변환
4) reinterpret_cast : 상관없는 자료형으로의 형 변환 -> 포인터를 대상으로 하는, 그리고 포인터와 관련이 있는 모든 유형의 형 변환 허용
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
	Car * pcar1 = new Truck(80, 200);
  // 포인터 변수 pcar1이 가리키는 대상이 실제로 Truck 객체이기 때문에 형변환 연산은 문제가 되지 않을 수 있음
  // 하지만 기초 클래스의 포인터형을 유도 클래스의 포인터 형으로 형변환하는 것은 일반적인 경우의 형변환이 아님 -> 프로그래머의 의도인지, 아니면 실수인지 알 수 없음
	Truck * ptruck1=(Truck *)pcar1;
	ptruck1->ShowTruckState();
	cout<<endl;
  
	Car * pcar2=new Car(120);
  // 포인터 변수 pcar2가 가리키는 대상이 실제로는 Car 객체이기 때문에 이 문장의 형변환은 문제 없음
  // 하지만 C스타일의 형 변환 연산자는 컴파일로 하여금 가능하도록 함 -> 무적의 형 변환 연산자이기 때문
	Truck * ptruck2=(Truck *)pcar2;
	ptruck2->ShowTruckState(); // 실행 결과 예측 불가능 -> 포인터 변수 ptruck2가 가리키는 대상은 Car 객체이기 때문에 ShowTruckState 함수의 호출은 논리적으로 맞지 않으며, 특히 이 객체에는 화물의 무게를 의미하는 멤버 freightWeight가 존재하지 않음
	return 0;
}

/*
실행결과
-----------------------
잔여 연료량: 80
화물의 무게: 200

잔여 연료량: 120
화물의 무게:3801464
*/
