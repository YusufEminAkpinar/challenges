#include <stdio.h>
#include <signal.h>
#include <math.h>

static volatile int keepRunning = 1;
static long double start = 1e12-1;


void intHandler(int dummy){
	keepRunning = 0;
}

#define _DEFAULT_SOURCE

// x**2 - x - k = 0
// x = ( 1 + sqrt(1+4k) ) / 2
int isOddIntegerAfterOperations(long x){
	long double k = powl( 1.0+2.0*x*x-2.0*x, .5 ); // sqrt( 1 + 2x**2 - 2x)
	if ( ((long)k == k) && ((long)k % 2) ){
		long res = (1+k)/2;
		printf("Total of %ld disc and %ld blue discs.\n", x, res);
		return 1;
	}
	return 0;
}

int main(void){
	signal(SIGINT, intHandler);
	while(keepRunning) if(isOddIntegerAfterOperations(start++))
		;
	printf("\rC-c detected. Last tried number is %Lf\n", start);
	return 0;
}
