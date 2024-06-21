#include "stdio.h"


int squareSum(int n){
	return (n *(n+1)*(2*n+1))/6;
}

int sum(int n){
	return (n* (n+1))/2;
}

int main(void){
	int ret = -squareSum(100)+sum(100)*sum(100);
	printf("%d\n", ret);
	return 0;
}
