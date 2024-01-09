/*
friend 선언
1) A클래스가 B클래스 대상으로 friend를 선언하면, B클래스는 A클래스의 private멤버에 직접 접근이 가능함
2) 단, A클래스도 B클래스의 private 멤버에 직접 접근이 가능하려면, B클래스가 A클래스를 대상으로 friend 선언을 해줘야 함
*/
#include <iostream>
#include <cstring>
using namespace std;

class Girl; // 함수 호출을 위해 함수의 원형을 선언하듯, 클래스도 선언 가능하여 Girl이라는 이름이 클래스의 이름임을 알림

class Boy
{
private:
  int height;
  friend class Girl; // Girl 클래스에 대한 friend 선언 -> private영역에도 friend 선언이 가능함을 보이기 위해 friend 선언 삽입
public:
  Boy(int len) : height(len)
  {}
  void ShowYourFriendInfo(Girl &frn); // 아직 정의되지 않은 클래스의 이름이 등장하지만, 컴파일이 가능한 이유는 10행에서 Girl이라는 클래스 이름을 알렸기 때문
};

class Girl // Girl 클래스 정의 
{
private:
  char phNum[20];
public:
  Girl(char * num)
  {
    strcpy(phNum, num);
  }

  void ShowYourFriendInfo(Boy &frn);
  friend class Boy; // Boy 클래스에 대한 friend 선언
};

void Boy :: ShowYourFriendInfo(Girl &frn) // 제대로 컴파일 하기 위해서는 Girl 클래스에 멤버변수 phNum이 존재한다는 사실을 알아야 해서 이 함수의 정의가 Girl 클래스의 정의보다 뒤에 위치
{
  cout<<"Her phone number: "<<frn.phNum<<endl;
}

void Girl :: ShowYourFriendInfo(Boy &frn) // 제대로 컴파일 하기 위해서는 Boy 클래스에 멤버변수 phNum이 존재한다는 사실을 알아야 해서 이 함수의 정의가 Boy 클래스의 정의보다 뒤에 위치
{
  cout<<"His Height: "<<frn.height<<endl;
}

int main(void)
{
  Boy boy(170);
  Girl girl("010-1234-5678");
  boy.ShowYourFriendInfo(girl);
  girl.ShowYourFriendInfo(boy);
  return 0;
}

/*
실행결과
--------------------------------
Her phone number: 010-1234-5678
His Height: 170
*/
