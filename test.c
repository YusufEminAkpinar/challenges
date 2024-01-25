// 796. Rotate String
// Given two strings s and goal, return true if and only if s can become goal
// after some number of shifts on s. A shift on s consists of moving the
// leftmost character of s to the rightmost position.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *doubleIt(char *str, int size){
  char *retarr = malloc(2*size);
  memcpy(retarr, str, size);
  memcpy(retarr+size, str, size);
  return retarr;
}

bool methodOne(char *s1, char *s2){
  int size1 = strlen(s1);
  int size2 = strlen(s2);
  if (size1 != size2) return false;
  char *twox = doubleIt(s1, size1);
  for(int i=0;i<size1;i++){
    if(!memcmp(twox+i, s2, size1)){
      free(twox);
      return true;
    }
  }
  free(twox);
  return false;
}


int main(void)
{
  char *str = "abcde";
  char *str2= "deabc";
  // int size = strlen(str);
  // char *test = doubleIt(str, size);
  // printf("%s\n", test);
  // free(test);
  bool b = methodOne(str, str2);
  if (b==true) printf("True\n");
  else printf("False\n");
  return 0;
}
