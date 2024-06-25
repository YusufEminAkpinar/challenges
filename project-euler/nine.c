#include <stdio.h>
#include <math.h>

int isPythagorean(int a, int b, int c){
	return (a*a + b*b == c*c);
}


int main(void){
	for (int i=1; i<1000; i++){
		for (int j=i+1; j<1000; j++){
			float k = pow(i*i + j*j, .5);
			if (isPythagorean(i, j, k))
				if ( ((int)k == k) && (k + i + j == 1000)) printf("i: %d, j: %d, k: %d\n", i, j, (int)k);
		}
	}
	return 0;
}
