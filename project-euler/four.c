#include "stdio.h"

int reverse(int n){
	int rem;
	int rev = 0;
	while(n != 0){
		rem = n % 10;
		rev = rev * 10 + rem;
		n /= 10;
	}
	return rev;
}

int isPalindrome(int n){
	if (n == reverse(n)) return 1;
	return 0;
}

int main(void){
	int goal = 0;
	for(int i=999; i>100; i--){
		for (int j=i; j>100; j--){
			if (isPalindrome(i*j) && (i*j > goal)) {
				goal = i*j;
			}
		}
	}
	printf("Goal is: %d\n", goal);
	return 0;
}

