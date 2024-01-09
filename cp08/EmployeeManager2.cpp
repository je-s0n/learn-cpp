#include <iostream>
#include <cstring>
using namespace std;

/*
상속을 통해 연관된 일련의 클래스 PermanentWorker, TemporaryWorker, SalesWorker에 공통적인 규약을 정의할 수 있음
이로 인해 Employee 클래스를 상속하는 모든 클래스의 객체는 Employee 객체로 바라볼 수 있음

실제로 EmployeeHandler 클래스는 저장되는 모든 객체를 Employee 객체로 바라보고 있기 때문에 새로운 클래스가 추가되어도 EmployeeHandler 클래스는 변경하지 않아도 됨
*/

/*
순수 가상함수(Pure Virtual Function)와 추상 클래스(Abstract Class)
- Employee 클래스는 기초 클래스로서만 의미를 가지며, 객체 생성 목적으로 정의된 클래스가 아님
- 클래스 중에서는 객체 생성을 목적으로 정의되지 않는 클래스도 존재하며, Employee * emp = new Employee("Lee Dong"); 문장이 만들어진다면, 프로그래머의 명백한 실수지만 문법적으로 문제가 없어서 컴파일러에 의해 발견되지 않음
- virtual int GetPay() const = 0;, virtual void ShowSalaryInfo() const = 0; 과 같이 선언하여 객체의 생성을 문법적으로 막는 것이 좋음
- 순수 가상함수 : 함수의 몸체가 정의되지 않은 함수로, 이를 표현하기 위해 보이듯이 0의 대입을 표시하며 컴파일러에게 이 부분에서 함수의 몸체가 정의되지 않았음을 알림
- 추상 클래스 : 하나 이상의 멤버함수를 순수 가상함수로 선언한 클래스
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

  virtual int GetPay() const
  {
    return 0;
  }

  virtual void ShowSalaryInfo() const
  {}
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

  int GetPay() const
  {
    return PermanentWorker::GetPay()  // PermanentWorker의 GetPay 함수 호출
      + (int)(salesResult * bonusRatio);
  }

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
    for(int i=0; i<empNum; i++)
    {
      empList[i]->ShowSalaryInfo();
    }
  }

  void ShowTotalSalary() const
  {
    int sum = 0;
    for(int i=0; i<empNum; i++)
    {
      sum += empList[i] -> GetPay();
    }
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
실행결과
----------------
name: KIM
salary: 1000

name: LEE
salary: 1500

name: Jung
salary: 3500

name: Hong
salary: 1700

salary sum : 7700
*/
