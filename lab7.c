#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main() {
	int n; scanf("%d", &n);
	int c[10000] = { 0 };

	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
		sum += c[i];
	}

	double average = sum / n;

	//printf("%f %d\n", sum, n);

	double delta = 0, min_delta = 1000000; int zn = 0;
	for (int i = 0; i < n; i++) {
		delta = (c[i])-average;
		//printf("%.1f\n", delta);
		//if (delta == 0){
			//printf("%d", c[i]);
			//break;
		//}
		if (fabs(delta) < min_delta) {
			zn = (delta < 0)? ( - 1) : 1;
			min_delta = fabs(delta);
			
		}
	}
	//printf("%f + %d * %f\n", average, zn, min_delta);
	double res = average + (zn * min_delta);
	printf("%.0f", res);
}