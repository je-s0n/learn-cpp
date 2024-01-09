#include <iostream>
using namespace std;

class FruitSeller
{
private:
  const int APPLE_PRICE;
  int numOfApples;
  int myMoney;
public:
  FruitSeller(int price, int num, int money)
    : APPLE_PRICE(price), numOfApples(num), myMoney(money)
  {
      // 멤버 이니셜라이저 (Member Initializer)
      // 초기화의 대상을 명확히 인식할 수 있으며, 성능에 약간의 이점이 있음
      // 이니셜라이저를 이용하면 선언과 동시에 초기화가 이루어지는 형태로 바이너리 코드가 생성됨
      // const 멤버변수도 이니셜라이저를 이용하면 초기화 가능함
      // 이니셜라이저를 이용하면 참조자도 멤버변수로 선언될 수 있음
  }

  int SaleApples(int money)
  {
    int num = money/APPLE_PRICE;
    numOfApples-=num;
    myMoney += money;
    return num;
  }

  void ShowSaleResult() const
  {
    cout<<"남은 사과: "<<numOfApples<<endl;
    cout<<"판매 수익: "<<myMoney<<endl<<endl;
  }
};

class FruitBuyer
{
  private:
    int myMoney;
    int numOfApples;
  public:
    FruitBuyer(int money)
      : myMoney(money), numOfApples(0)
    {
    }

    void BuyApples(FruitSeller &seller, int money)
    {
      numOfApples += seller.SaleApples(money);
      myMoney -= money;
    }

    void ShowBuyResult() const
    {
      cout<<"현재 잔액: "<<myMoney<<endl;
      cout<<"사과 개수: "<<numOfApples<<endl<<endl;
    }
};

int main(void)
{
  FruitSeller seller(1000,20,0); // 생성자 기반 객체 생성
  FruitBuyer buyer(5000); // 생성자 기반 객체 생성
  buyer.BuyApples(seller, 2000);

  cout<<"과일 판매자의 현황"<<endl;
  seller.ShowSalesResult();
  cout<<"과일 구매자의 현황"<<endl;
  buyer.ShowBuyResult();
  return 0; 
}
