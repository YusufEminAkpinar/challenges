// Given two strings ransomNote and magazine, return true if ransomNote can be
// constructed by using the letters from magazine and false otherwise. Each
// letter in magazine can only be used once in ransomNote.

#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include <stdint.h>
#include "stdbool.h"


static int cmpchar(const void *p1, const void *p2){
  return (* (char *)p1 - * (char *) p2);
}

void sort_str(char *str, int size){
  if(str == NULL) return;
  qsort(str, size, 1, cmpchar);
}

char *next_char(char *str, char chr){
  char *ret = strrchr(str, chr);
  ret++;
  return ret;
}

bool canConstruct(char *magazine, char* ransomNote){
  int lenmag = strlen(magazine);
  int lennote = strlen(ransomNote);
  if (lenmag < lennote){
    return false;
  }
  char cur_char;
  char *mag_tmp;
  char *note_tmp;
  sort_str(magazine, lenmag);
  sort_str(ransomNote, lennote);
  while(*ransomNote){
    cur_char = *ransomNote;
    magazine = strchr(magazine, cur_char);
    if (magazine == NULL) {
      printf("NULL?\n");
      return false;
    }
    mag_tmp = next_char(magazine, cur_char);
    note_tmp = next_char(ransomNote, cur_char);
    if ((mag_tmp - magazine) < (note_tmp - ransomNote)){
      printf("You fucked up in %c\n", cur_char);
      return false;
    }
    ransomNote++;
  }
  printf("True\n");
  return true;
}


int main(void)
{
  char *note = strdup("aa");
  char *mag = strdup("aab");
  int val = canConstruct(mag, note);
  printf("And val is: %d\n", val);
  free(mag);
  free(note);
  return 0;
}
