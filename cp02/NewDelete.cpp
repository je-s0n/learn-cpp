#include <iostream>
#include <string.h>
using namespace std;

char * MakeStrAdr(int len)
{
  // char * str = (char*)malloc(sizeof(char)*len);
  char * str = new char[len]; // new를 이용한 동적할당이 훨씬 간결함
  return str;
}

int main(void)
{
  char * str = MakeStrAdr(20);
  strcpy(str, "I am so happy~");
  cout<<str<<endl; // I am so happy~
  // free(str);
  delete []str; // 배열의 형태로 할당된 메모리 공간의 해제를 보이고 있음
  return 0;
}
