#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <float.h>


int main() {
	unsigned long i = 0;
	unsigned long a = 0;
	unsigned long b = 0;
	while (a >= b ) {
		b = a;
		a = i * i * i * i * i * i * i;
		if (a >= b) printf("%lu\n", a);
		i++;
	}
}
