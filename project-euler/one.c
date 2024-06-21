#include "stdio.h"

int main(int argc, char **argv){
	(void) argc;
	(void) argv;
	unsigned long ret = 0;

	for (int i=1; i < 1000000000; i++){
		if (!(i%3 && i%5)) ret += i;
	}
	printf("%lu\n", ret);
	return 0;
}
