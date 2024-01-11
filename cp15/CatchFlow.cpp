#include <iostream>
using namespace std;

/*
예외 발생 시, 해당 예외 데이터를 전달받을 수 있는 catch 블록을 위에서 아래로 찾아내려 감
그리고 적절한 catch 블록을 찾게 되면, 해당 catch 블록이 실행되면서 예외 처리는 완료됨
이러한 특성으로 인해 아래 예시처럼 catch 블록을 구성하면 안됨
*/
class AAA
{
public:
	void ShowYou() { cout<<"AAA exception!"<<endl; }
};

class BBB : public AAA // 예외 클래스가 상속 관계로 묶임 -> BBB 객체가 AAA 객체의 일종으로 인식
{
public:
	void ShowYou() { cout<<"BBB exception!"<<endl; }
};

class CCC : public BBB // 예외 클래스가 상속 관계로 묶임 -> CCC 객체가 BBB 객체/AAA 객체의 일종으로 인식
{
public:
	void ShowYou() { cout<<"CCC exception!"<<endl; }
};

void ExceptionGenerator(int expn)
{
	if(expn==1)
		throw AAA();
	else if(expn==2)
		throw BBB();
	else
		throw CCC();
}

int main(void)
{
	try
	{
    // 무조건 예외 발생
		ExceptionGenerator(3);
		ExceptionGenerator(2);
		ExceptionGenerator(1);
	}
	catch(AAA& expn) // 예외에 적절한 catch 블록은 나열 순서대로 찾게 됨 -> 어떤 예외가 발생하건 맨 위에 있는 catch 블록을 대상으로 내려가면서 적합성 여부 판단 
	{
		cout<<"catch(AAA& expn)"<<endl;
		expn.ShowYou();
	}	
	catch(BBB& expn)
	{
		cout<<"catch(BBB& expn)"<<endl;
		expn.ShowYou();
	}
	catch(CCC& expn)
	{
		cout<<"catch(CCC& expn)"<<endl;
		expn.ShowYou();
	}

  /*
  만약, BBB 예외객체는 catch(BBB& expn) 블록에 의해서 처리가 되고, CCC 예외객체는 catch(CCC& expn)블록에 의해 처리가 되길 바랄 경
  catch 블록을 아래와 같이 변경해야 함

	catch(CCC& expn)
	{
		cout<<"catch(CCC& expn)"<<endl;
		expn.ShowYou();
	}
	catch(BBB& expn)
	{
		cout<<"catch(BBB& expn)"<<endl;
		expn.ShowYou();
	}
 	catch(AAA& expn)
	{
		cout<<"catch(AAA& expn)"<<endl;
		expn.ShowYou();
	}	
  // BBB/CCC 객체는 일종의 AAA 객체지만, AAA 객체가 일종의 BBB/CCC 객체는 아님
  -> 따라서 원하는 결과 얻을 수 있음
  */
	return 0;
}

/*
실행결과
--------------------
catch(AAA& expn)
AAA exception!
*/
