#include <iostream>
using namespace std;

/*
reinterpret_cast : 상관없는 자료형으로의 형 변환에 사용됨
reinterpret_cast<T>(expr) 형태를 가짐

class SimpleCar { ... };
class BestFriend { ... };
-> 위 두 클래스는 상속으로 관계를 맺은 것도 아니니, 서로 전혀 관련없는 클래스임
그런데 이 두 클래스를 대상으로 아래 코드를 작성할 때 사용되는 연산자가 바로 reinterpret_cast임

int main(void)
{
  SimpleCar * car = new Car;
  BestFriend * fren = reinterpret_cast<BestFriend*>(car);
  . . .
}
-> 포인터를 대상으로 하는, 그리고 포인터와 관련이 있는 모든 유형의 형 변환을 허용함
-> 컴파일 환경에 따라 어떻게 동작하는지 알 수 없음 -> 컴파일 환경에 따라 결과가 달라짐 (의미 부여 X)
-> 특정 상황에서는 이러한 유형의 연산이 유용하게 사용되기도 하며, 이는 reinterpret_cast 연산자가 포인터와 관련이 있는 모든 유형의 형 변환을 허용한다는 사실을 뒷받침하기도 함
*/
int main(void)
{
	int num=0x010203;
	char * ptr=reinterpret_cast<char*>(&num);

	for(int i=0; i<sizeof(num); i++)
		cout<<static_cast<int>(*(ptr+i))<<endl;

	return 0;
}

/*
실행결과
-----------------
3
2
1
0
*/
