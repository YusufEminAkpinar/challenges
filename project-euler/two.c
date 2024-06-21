#include "stdio.h"
#include "math.h"

#define PHI 1.618034

int fibn(int n){
	float fib = (pow(PHI, n+1) - pow( (1-PHI), n+1))/sqrt(5);
	return (int)fib;
}

// get sum of 2th, 5th, 8th, ... nth, (n+3)th term.
int main(int argc, char **argv){
	(void) argc;
	(void) argv;
	unsigned long ret = 0;
	int n = 2;
	int fib = 0;
	while(fib < 4000000){
		fib = fibn(n);
		printf("fib(%d) = %d\n", n, fib);
		n = n + 3;
		ret += fib;
	}
	printf("Sum is %lu\n", ret);
	return 0;
}

