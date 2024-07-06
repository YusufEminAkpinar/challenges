#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 2000000
#define ARRSIZE 150000

int *primeSieve(int limit) {
	int *sieve = (int *)malloc (sizeof(int) * limit);
	int sqrt = (int)pow(limit, .5) + 1;
	for (int i=0; i<limit; i++){
		sieve[i] = 1;
	}
	//memset(sieve, 1, sizeof(int)*limit);
	sieve[0] = 0; sieve[1] = 0;
	for (int i=0; i<sqrt; i++){
		if(sieve[i]){
			for(int j=i*i; j<limit; j+=i){
				sieve[j] = 0;
			}
		}
	}
	return sieve;
}

int main(void){
	int *primes = primeSieve(LIMIT);
	long sum=0;
	for (int i=0; i<LIMIT; i++){
		if(primes[i]){
			sum += i;
		}
	}
	//print(primes, LIMIT);
	printf("%ld\n", sum);
	free(primes);
	return 0;
}




