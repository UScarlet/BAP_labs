#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int x = 1;
	unsigned long long count = 0;
	while(x!=0) {
		scanf("%d", &x);
		//printf("%d", x);
		if (abs(x) < 500) count++;
	}

	printf("%llu", count-1);
}