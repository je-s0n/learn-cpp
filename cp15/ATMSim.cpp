#include <iostream>
#include <cstring>
using namespace std;

/*
예외객체 : 예외발생을 알리는데 사용되는 객체
예외 클래스 : 예외객체의 생성을 위해 정의된 클래스
-> 객체를 이용하여 예외상황을 알리면, 예외가 발생한 원인에 대한 정보를 보다 자세히 담을 수 있음
*/

// 현금 인출기에서의 돈 인출 과정 시뮬레이션 예시
class DepositException // 입금 예외 클래스
{
private:
	int reqDep;		// 요청 입금액
public:
	DepositException(int money) : reqDep(money)
	{ }
	void ShowExceptionReason()
	{
		cout<<"[예외 메시지: "<<reqDep<<"는 입금불가]"<<endl;
	}
};

class WithdrawException // 출금 예외 클래스
{
private:
	int	balance;	// 잔고
public:
	WithdrawException(int money) : balance(money)
	{ }
	void ShowExceptionReason()
	{
		cout<<"[예외 메시지: 잔액 "<<balance<<", 잔액부족]"<<endl;
	}
};

class Account
{
private:
	char accNum[50];	// 계좌번호
	int	balance;		// 잔고
public:
	Account(char * acc, int money) : balance(money)
	{
		strcpy(accNum, acc);
	}
	void Deposit(int money) throw (DepositException)
	{
		if(money<0)
		{
			DepositException expn(money);
			throw expn;	
		}
		balance+=money;
	}
	void Withdraw(int money) throw (WithdrawException)
	{
		if(money>balance)
			throw WithdrawException(balance);
		balance-=money;
	}
	void ShowMyMoney()
	{
		cout<<"잔고: "<<balance<<endl<<endl;
	}
};

int main(void)
{
	Account myAcc("56789-827120", 5000);

	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	catch(DepositException &expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch(WithdrawException &expn)
	{
		expn.ShowExceptionReason();
	}	
	myAcc.ShowMyMoney();
	return 0;
}

/*
실행결과
-------------------
[예외 메시지: -300는 입금불가]
잔고: 7000

[예외 메시지: 잔액 3500, 잔액부족]
잔고: 3500
*/
