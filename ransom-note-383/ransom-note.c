#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"


/*  Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote. */

int *str_to_int(char *string){
    int len_str = strlen(string);
    int *int_arr = (int *)malloc(len_str * sizeof(int));
    for (int i = 0; i < len_str; i++) {
      int_arr[i] = (int)string[i];
    }
    for (int i = 0; i < len_str; i++) {
      printf("%d, \n", int_arr[i]);
    }
    return int_arr;
}

/* Plan:
 * Number of occurence'lardan git*/

void rm_char(char *string, char chr){
    for (size_t i=0; i<strlen(string); i++){
        if (string[i] == chr){
            string[i] = '_';
        }
    }
}

int num_of_occ(char *string, char chr){
  int retval = 0;
  for (size_t i = 0; i < strlen(string); i++) {
    if (string[i] == '_')
        ;
    else if (string[i] == chr) {
      retval ++;
      rm_char(string, string[i]);
    }
  }
  return retval;
}

bool canConstruct(char *ransomNote, char *magazine){
  if (strlen(ransomNote) > strlen(magazine)) {
    return false;
  }
  int rans = 0;
  int magan = 0;
  for (size_t i = 0; ransomNote[i] != '\0'; i++) {
    rans = num_of_occ(ransomNote, ransomNote[i]);
    magan = num_of_occ(magazine, ransomNote[i]);
    if (rans > magan) {
      return false;
    }
  }
  return true;
}


int main(int argc, char *argv[])
{
  (void) argc;
   char *str1 = (char *)argv[1];
   char *str2 = (char *)argv[2];
   if (canConstruct(str1, str2)) {
     printf("yeyyy\n");
   }
   else {
     printf("NOOO\n");
   }
    // char some[] = "yusuf";
    // int *arr = arr_of_occ(some);
    // for (size_t i = 0; i < strlen(some); i++) {
      // printf("%c | %d\n", some[i], arr[i]);
    // }
    return 0;
}

