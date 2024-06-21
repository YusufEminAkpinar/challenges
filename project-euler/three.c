#include "stdio.h"
#include "math.h"

unsigned long isPrime(unsigned long n){
	for(unsigned long i=2; i<n; i++){
		if (!(n%i)) return 0;
	}
	return 1;
}

int main(void){
	unsigned long goal = 600851475143;
	for (unsigned long i=2; i<goal; i++){
		while(1){
			if (!(goal%i)) {
				goal = goal/i;
				printf("%lu, ", i);
			}
			else break;
		}
		if (isPrime(goal)){
			printf("%lu\n", goal);
			return 0;
		}
	}
	return -1;
}
