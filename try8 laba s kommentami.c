#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int per(int n) {
	while (n % 2 == 0) n /= 2;
	while (n % 5 == 0) n /= 5;
	for (int i = 1; i < 21; i++) {
		double a = pow(10, i);
		if (int(a) % n == 1) return i;
	}
	return -1;
}
int main() {
	int n; scanf("%d", &n);
	int c[21] = { 0 };
	n = abs(n);
	int delim = 1;

	int ost = 1, i = 0;

	while (ost != 0 && i<21) {
		c[i] = delim / n; i++;
		ost = (delim % n)*10;
		//printf("%d\n", c[i-1]);
		delim = ost;
	}
	
	/*
	for (int j = 0; j < 21; j++) {
		printf("%d", c[j]);
	}
	printf("\n");
	*/
	

	if (ost == 0) printf("%d", 0);
	else {
		int l_p = per(n);
		if (l_p == -1) {
			printf("%d", 0);
		}
		else {
			int l = 0, prev_len = 0;
			int period[11] = { 0 }, ans[11] = { 0 };
			int i = 1; 
			while (i < 21) {
				int j = i + l_p;
				if (c[i] == c[j] && j - i < 20) {
					while (c[i] == c[j] && l < l_p) {
						//printf("%d %d %d %d\n", c[i], i, c[j], j);
						period[l] = c[i]; l++; i++; j++;
						
					}
					if (l == l_p) {
						for (int x = 0; x < 11; x++) ans[x] = period[x];
						//printf("%d l \n", l);

						//printf("%d prev \n", prev_len);
						prev_len = l;
						//for (int j1 = 0; j1 < prev_len - 1; j1++) printf("%d", ans[j1]);
						//printf("\n");
						i = 22;
					}
					i++;
				}
				else i++;
			}
			/*
			for (int i = 1; i < 21 - l_p; i++) {
				int j = i + l_p;
				if (c[i] == c[j] && j - i < 20) {
					l = 0; int t = j;
					//printf("%d", l_p);
					while (c[i] == c[j] && l <= l_p) { period[l] = c[i]; l++; i++; j++;}
					if (l == l_p) {
						for (int x = 0; x < 11; x++) ans[x] = period[x];
						printf("%d l \n", l);

						printf("%d prev \n", prev_len);
						prev_len = l;
						for (int j1 = 0; j1 < prev_len - 1; j1++) printf("%d", ans[j1]);
						printf("\n");
						break;
					}
				}
			}
			*/
			if (prev_len > 0) for (int j = 0; j < prev_len; j++) printf("%d", ans[j]);
			else printf("%d", 0);
		}
	}
}