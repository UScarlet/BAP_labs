#include <stdio.h>
#include <math.h>
#include <float.h>

long double fact(unsigned int n) {
	long double m = 1;
	for (int i = 1; i <= n; i++) m *= i;
	return m;
}

long double f(unsigned int n, long double x) { return (pow(-1, n) / fact(2 * n) * pow(x, 2 * n)); }

long double given_acc( long double x, long double eps) {
	long double sm = f(1,x);

	int i = 1;
	while (fabs(f(i+1, x) - f(i, x)) > eps ) { 
		sm += f(i+1, x); 
		i++;
		//printf("\n");
		//printf("%lf\t%.15lf\n", f(i, x), sm);
	}
	
	if (isnan(sm)) { 
		printf("Error (!!!The value x is too big. Eps value is unreachable :( !!!). Result: ");
		return sm;
	}
	else { return sm; }
}

long double sum_n(long double x, unsigned int n) {
	long double sm = 0;
	for (int i = 1; i <= n; i++) { 
		long double r = f(i, x);
		if (isnormal(r)) sm += r; 
		// при n = 500 иначе -nan (ind)
	}

	return sm;
}

long double max_acc(long double x) {
	long double sm = f(1, x); //0.0
	long double eps = LDBL_EPSILON;
	int i = 1;
	while (fabs(f(i + 1, x) - f(i, x)) > eps) {
		if (isnormal(f(i + 1, x))) sm += f(i + 1, x);
		i++;
		//printf("%.15e\t%.15lf\n", f(i, x), sm);
		//for нельзя - зависит от i, либо переписать
	}

	return sm;
}

int main() {
	long double x = 0; long double eps = 0; unsigned int n = 0;
	printf("Enter x ");
	scanf_s("%lf/n", &x);
	printf("Enter eps ");
	scanf_s("%lf/n", &eps);
	printf("Enter n ");
	scanf_s("%u/n", &n);
	
	printf("%.15e\n", given_acc(x, eps));
	printf("%.15e\n", sum_n(x, n));
	printf("%.15e\n", max_acc(x));

	return 0;
}
