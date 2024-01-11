#include <iostream>
using namespace std;

/*
모든 예외를 처리하는 catch 블록
try { ... }
catch(...) // ... 은 전달되는 모든 예외를 다 받아주겠다는 선언
{
  ...
}
-> 마지막 catch 블록에 덧붙여지는 경우가 많은데, 대신 catch의 매개변수 선언에서 보이듯이, 발생한 예외와 관련해서 그 어떠한 정보도 전달받을 수 없음
-> 전달된 예외의 종류 구분도 불가능함

예외 던지기
- catch 블록에 전달된 예외는 다시 던져질 수 있음
- 이로 인해 하나의 예외가 둘 이상의 catch블록에 의해 처리되게 할 수 있음
- 예외처리는 가급적 간결한 구조를 띠는게 좋음
  -> 정말 필요하지 않으면, 굳이 예외를 다시 던지기 위해서 노력할 필요 없음
*/
void Divide(int num1, int num2)
{
	try
	{
		if(num2==0)
			throw 0;
		cout<<"몫: "<<num1/num2<<endl;
		cout<<"나머지: "<<num1%num2<<endl;
	}
	catch(int expn)
	{
		cout<<"first catch"<<endl;
		throw; // 예외를 다시 던짐 -> 이 문장에 의해 catch 블록으로 전달된 예외가 소멸되지 않고, 다시 던져짐
    // 따라서 이 함수를 호출한 영역으로 예외가 전달됨
	}
}

int main(void)
{	
	try
	{
		Divide(9, 2);
		Divide(4, 0);
	}
	catch(int expn) // Divide 함수에 의해 다시 전달된 예외가 이 catch 블록으로 전달됨
	{
		cout<<"second catch"<<endl;
	}
	return 0;
}

/*
실행결과
---------------------
몫: 4
나머지: 1
first catch
second catch
*/
