#include <iostream>
#include <cstring>
using namespace std;

/*
상속관계에 있는 예외 클래스
- 예외 클래스도 상속의 관계를 구성할 수 있음
- 둘 이상의 예외 클래스를 상속의 관계로 묶어놓으면, 예외 처리 단순화 가능
*/
class AccountException
{
public:
	virtual void ShowExceptionReason() = 0; // 순수 가상함수
};

class DepositException : public AccountException // 입금 예외 클래스 - AccountException 클래스 상속
{
private:
	int reqDep;	
public:
	DepositException(int money) : reqDep(money)
	{ }
	void ShowExceptionReason()
	{
		cout<<"[예외 메시지: "<<reqDep<<"는 입금불가]"<<endl;
	}
};

class WithdrawException : public AccountException // 출금 예외 클래스 - AccountException 클래스 상속
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
	char accNum[50]; // 계좌번호
	int	balance; // 잔고
public:
	Account(char * acc, int money) : balance(money)
	{
		strcpy(accNum, acc);
	}
	void Deposit(int money) throw (AccountException)
	{
		if(money<0)
		{
			DepositException expn(money);
			throw expn;	
		}
		balance+=money;
	}
	void Withdraw(int money) throw (AccountException)
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
	catch(AccountException &expn) // 실제 전달되는 예외객체는 DepositException이지만, 상속의 관계로 묶여있기 때문에 catch 블록 참조자를 AccountException형으로 선언할 수 있음
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch(AccountException &expn) // 실제 전달되는 예외객체는 WithdrawException이지만, 상속의 관계로 묶여있기 때문에 catch 블록 참조자를 AccountException형으로 선언할 수 있음
	{
		expn.ShowExceptionReason();
	}	
	myAcc.ShowMyMoney();
	return 0;
}

/*
실행결과
------------------
[예외 메시지: -300은 입금불가]
잔고: 7000

[예외 메시지: 잔액 3500, 잔액부족]
잔고: 3500
*/
