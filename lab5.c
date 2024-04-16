#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	unsigned long a = 0;
	for(unsigned long i = 0; (sizeof(a) == 4) ? i <= 23 : i <= 565; i++) {
		a = i * i * i * i * i * i * i;
		printf("%lu\n", a);
	}	
}
