#include <iostream>
#include <cstring>
using namespace std;

/*
상속에서의 함수 오버로딩 vs 함수 오버라이딩
- 기초 클래스와 동일한 이름의 함수를 유도 클래스에서 정의한다고 해서 무조건 함수 오버라이딩이 되는 것이 아님
- 매개변수의 자료형 및 개수가 다르면, 이는 함수 오버로딩 되어 전달되는 인자에 따라 호출되는 함수 결정되며, 상속 관계에서도 구성될 수 있음
- 함수 오버라이딩은 기초 클래스의 함수와 동일하게 구성된 함수를 유도 클래스에서 정의하는 것
*/
class Employee  // 고용인
{
private:
  char name[100];
public:
  Employee(char * name)
  {
    strcpy(this->name, name);
  }

  void ShowYourName() const
  {
    cout<<"name: "<<name<<endl;
  }
};

class PermanentWorker : public Employee  // 정규직
{
private:
  int salary; // 급여
public:
  PermanentWorker(char * name, int money)
    : Employee(name), salary(money)
  {}

  int GetPay() const
  {
    return salary;
  }

  void ShowSalaryInfo() const
  {
    ShowYourName();
    cout<<"salary: "<<GetPay()<<endl<<endl;
  }
};

class TemporaryWorker : public Employee  // 임시직
{
private:
  int workTime; // 이 달에 일한 시간의 합계
  int payPerHour; // 시간당 급여
public:
  TemporaryWorker(char * name, int pay)
    : Employee(name), workTime(0), payPerHour(pay)
  {}

  void AddWorkTime(int time)
  {
    workTime += time;
  }

  int GetPay() const // 이 달의 급여
  {
    return workTime * payPerHour;
  }

  void ShowSalaryInfo() const
  {
    ShowYourName();
    cout<<"salary: "<<GetPay()<<endl<<endl;
  }
};

class SalesWorker : public PermanentWorker  // 영업직
{
private:
  int salesResult;  // 월 판매실적
  double bonusRatio;  // 상여금 비율
public:
  SalesWorker(char * name, int money, double ratio)
    : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
  {}

  void AddSalesResult(int value)
  {
    salesResult += value;
  }

  // 함수 오버라이딩(Function Overriding) : PermanentWorker 클래스에도 GetPay함수와 ShowSalleryInfo함수가 있는데, 유도 클래스인 SalesWorker 클래스에서도 동일한 이름과 형태로 두 함수 정의
  int GetPay() const
  {
    return PermanentWorker::GetPay()  // PermanentWorker의 GetPay 함수 호출
      + (int)(salesResult * bonusRatio);
  }

  // SalesWorker 클래스에서 ShowSalleryInfo 함수를 오버라이딩 한 이유?
  // PermanentWorker 클래스의 ShowSalaryInfo 함수는 상속에 의해 SalesWorker 객체에도 존재하게 됨
  // 하지만 PermanentWorker 클래스의 ShowSalaryInfo 함수 내에서 호출되는 GetPay 함수는 PermanentWorker 클래스에 정의된 GetPay 함수의 호출로 이어짐
  // 따라서 SalesWorker 클래스에 정의된 GetPay 함수가 호출되도록 SalesWorker 클래스에 별도의 ShowSalaryInfo 함수를 정의하는 것
  void ShowSalleryInfo() const
  {
    ShowYourName();
    cout<<"salary: "<<GetPay()<<endl<<endl; // SalesWorker의 GetPay 함수 호출
  }
};

class EmployeeHandler
{
private:
  Employee* empList[50];
  int empNum;
public:
  EmployeeHandler() : empNum(0)
  {}

  void AddEmployee(Employee* emp)
  {
    empList[empNum++] = emp;
  }

  void ShowAllSalaryInfo() const
  {
    /*
    for(int i=0; i<empNum; i++)
    {
      empList[i]->ShowSalaryInfo();
    }
    */
  }

  void ShowTotalSalary() const
  {
    int sum = 0;
    /*
    for(int i=0; i<empNum; i++)
    {
      sum += empList[i] -> GetPay();
    }
    */
    cout<<"salary sum: "<<sum<<endl;
  }

  ~EmployeeHandler()
  {
    for(int i=0; i<empNum; i++)
    {
      delete empList[i];
    }
  }
};

int main(void)
{
  // 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
  EmployeeHandler handler;
  
  // 정규직 등록
  handler.AddEmployee(new PermanentWorker("KIM", 1000));
  handler.AddEmployee(new PermanentWorker("LEE", 1500));
  
  // 임시직 등록
  TemporaryWorker * alba =  new TemporaryWorker("Jung", 700);
  alba -> AddWorkTime(5); // 5시간 일한 결과 등록
  handler.AddEmployee(alba);
  
  // 영업직 등록
  SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
  seller->AddSalesResult(7000);  // 영업실적 7000
  handler.AddEmployee(seller);
  
  // 이번 달에 지불해야 할 급여의 정보
  handler.ShowAllSalaryInfo();
  
  // 이번 달에 지불해야 할 급여의 총합
  handler.ShowTotalSalary();
  return 0;
}

/*
salary sum: 0
*/
