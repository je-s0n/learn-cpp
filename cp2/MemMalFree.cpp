#include <iostream>
// C언어 헤더파일을 추가하는 것 가능함
#include <string.h>
#include <stdlib.h>
using namespace std;

/*
  C언어 mallow & free
  - mallow : 인자로 전달된 정수 값에 해당하는 바이트 크기의 메모리 공간을 힙 영역에 할당하고, 이 메모리 공간의 '주소 값'을 반환함 (메모리 공간의 할당에 실패할 경우 NULL 반환)
  - free : 인자로 전달된 포인터 변수가 가리키는 메모리 공간을 소멸

  e.g.
  // malloc함수의 반환형은 void이기 때문에 원하는 크기만큼 메모리를 할당해주고 그 메모리 주소를 반환해주는 기능밖에 없음 
  // -> 할당한 메모리 공간을 int형으로 사용할지 float형으로 사용할지 등은 포인터의 반환형으로 지정해줘야 함
  int *ptr1=(int*)malloc(4);
  
  // ﻿12바이트짜리 메모리 공간을 힙 영역에 할당
  // ptr2은 방금 malloc함수가 할당한 12바이트 메모리 공간의 주소를 가리킴
  void *ptr2=malloc(12); 
  
  // int 타입사이즈 * 4 만큼의 메모리를 할당
  int* pArr = (int *)malloc(sizeof(int) * 4); 

  // 메모리 공간 해제
  free(ptr1);
  free(ptr2);
  free(pArr);
*/
char * MakeStrAdr(int len)
{
  char * str = (char*)malloc(sizeof(char)*len); // 문자열 저장을 위한 배열을 힙 영역에 할당함
  return str;
}

int main(void)
{
  char * str = MakeStrAdr(20);
  strcpy(str, "I am so happy ~");
  cout<<str<<endl; // I am so happy ~
  free(str); // 힙에 할당된 메모리 공간을 소멸하고 있음
  return 0;
}
