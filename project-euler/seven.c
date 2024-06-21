#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"

int isPrime(int n, int *primes, int primeSize){
	for(int i=0; i<primeSize; i++){
		if (!(n%primes[i])) return 0;
	}
	return 1;
}

int main(void){
	int *primes = malloc(10002 * sizeof(int));
	memset(primes, 0, 10002 * sizeof(int));
	int i=2, k=0;
	while(1){
		if (isPrime(i, primes, k+1)) primes[k++] = i;
		i++;
		if (k == 10001) break;
	}
	for(int j=0; j<k; j++) printf("%d, ", primes[j]);
	return 0;
}
