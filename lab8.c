#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int per(int n) {
	while (n % 2 == 0) n /= 2;
	while (n % 5 == 0) n /= 5;
	long long a = 1;
	for (int i = 1; i < 21; i++) {
		a *= 10;
		//printf("%d\n", a);
		if (a % n == 1) { return i; };
	}
	return -1;
}
int main() {
	int n1; scanf("%d", &n1);
	int c[60] = { 0 };
	int size = 60;
	int n = abs(n1);
	int delim = 1;

	int ost = 1, i = 0;
	
	while (ost != 0 && i < size) {
		c[i] = delim / n; i++;
		ost = (delim % n) * 10;
		//printf("%d\n", c[i-1]);
		delim = ost;
	}

	if (ost == 0) printf("%d", 0);
	else {
		int l_p = per(n); 
		if (l_p == -1) {
			printf("%d", 0);
		}
		else {
			int l = 0, prev_len = 0;
			int period[18] = { 0 }, ans[18] = { 0 };
			int i = 1;
			while (i < size) {
				int j = i + l_p;
				if (c[i] == c[j] && j - i < 60) {
					while (c[i] == c[j] && l < l_p) {
						period[l] = c[i]; l++; i++; j++;

					}
					if (l == l_p) {
						for (int x = 0; x < 18; x++) ans[x] = period[x];
						prev_len = l;
						i = 61;
					}
					i++;
				}
				else i++;
			}
			if (prev_len > 0) for (int j = 0; j < prev_len; j++) printf("%d", ans[j]);
			else printf("%d", 0);
		}
	}
}