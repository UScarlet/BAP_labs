#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int main() {
	int m, n; scanf("%d %d", &m, &n);
	int ar[100][100];
	int m_s = INT_MIN, s = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &ar[i][j]);
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) s += ar[i][j];
		if (m_s < s) m_s = s;
		s = 0;
	}
	printf("%d", m_s);
}