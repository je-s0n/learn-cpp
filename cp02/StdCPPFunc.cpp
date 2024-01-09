#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
  C언어 라이브러리에는 매우 다양한 유형의 함수들이 정의되어 있으며, 이러한 함수들은 C++ 표준 라이브러리에도 포함되어 있어 어렵지 않게 사용 가능함
  C언어 헤더파일 -> C++ 헤더정보
  #include <stdio.h> -> #include <cstdio>
  #include <stdlib.h> -> #include <cstdlib>
  #include <math.h> -> #include <cmath>
  #include <string.h> -> #include <cstring>
*/
int main(void)
{
  char str1[] = "Result";
  char str2[30];

  strcpy(str2, str1);
  printf("%s: %f \n", str1, sin(0.14)); // Result: 0.139543
  printf("%s: %f \n", str2, abs(-1.25)); // Result: 1.25000
}
