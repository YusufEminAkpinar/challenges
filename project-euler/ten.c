#include <stdio.h>

int isPrime(int n, int *primes, int primeSize){
	for(int i=0; i<primeSize; i++){
		if (!(n%primes[i])) return 0;
	}
	return 1;
}


