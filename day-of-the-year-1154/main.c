#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//Given a string date representing a Gregorian calendar date formatted as
//YYYY-MM-DD, return the day number of the year.

int dayOfYear(char *date);

int main() {
    char *date = "2019-02-10";
    int a = dayOfYear(date);
    printf("%d\n", a);
    return 0;
}

int dayOfYear(char *date){
    //YYYY-MM-DD
    int feb = 28;
    char *year = malloc(5);
    char *month = malloc(3);
    char *day = malloc(3);
    int ybase = 0;
    int mbase = 5;
    int dbase = 8;
    //bad code...
    //should do date[4] = date[7] = '\0' so it can be parsed easily also strtol
    //(or atoi) can be used directly that way without using memcpy so memcpy is
    //redunant here
    memcpy(year, date+ybase, 4);
    memcpy(year+4, &"\0", 1);
    memcpy(month, date+mbase, 2);
    memcpy(month+2, &"\0", 1);
    memcpy(day, date+dbase, 2);
    memcpy(day+2, &"\0", 1);
    long y = strtol(year, NULL, 10);
    long m = strtol(month, NULL, 10);
    long d = strtol(day, NULL, 10);
    free(year);
    free(month);
    free(day);
    if (!(y%4) && (y!=1900)) feb = 29;
    long num_of_days[12] = {31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long retval = 0;
    for (long i=0; i<m-1; i++) retval += num_of_days[i];
    retval += d;
    return retval;
}


// 2-3 ms beats %97 of C users
// 58 ms beats %99.9 of Python users
