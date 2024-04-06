// Amk aptali yaptigin cozumu sikeyim
// duzgun cozum asagida

#include "stdbool.h"

bool canConstruct(char *magazine, char *ransomNote){
  int table[30] = {0};
  while(*magazine){
    table[*magazine]++;
    magazine++;
  }
  while(*ransomNote){
    if (table[*ransomNote] > 0)
      table[*ransomNote]--;
    else return false;
    ransomNote++;
  }
  return true;
}

#include <stdio.h>
int main(void)
{
  char *m = strdup("aab");
  char *c = strdup("aa");
  printf("%d\n", canConstruct(m, c));
  return 0;
}
