#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
char* f(long long v, int base, char arr[], char t[]) {
	char res[100] = "";
	int i = 0;
	while (v > 0) {
		res[i] = arr[(long long)(v) % base];
		v /= base;
		i++;
	}
	//printf("%s %d", res,i);
	for (int j = 0; j < i; j++) t[j] = res[i - j - 1];
	//printf("%s", t);
	return t;
}
int main() {
	char arr[] = "0123456789abcdefghijklmnopqrstuvwxyz";

	short v1 = 0X4EDE; char m1[100] = "";
	int v2 = 0X5A5188B2; char m2[100] = "";
	unsigned int v3 = 0X44609454; char m3[100] = "";
	long v4 = 0X1A7F00FC; char m4[100] = "";
	unsigned long v5 = 0X2FD28DB; char m5[100] = "";

	char* t1 = f(v1, 31, arr, m1);
	printf("short;%x=%s;31\n", v1, t1);
	char* t2 = f(v2, 14, arr, m2);
	printf("int;%x=%s;14\n", v2, t2);
	char* t3 = f(v3, 24, arr, m3);
	printf("unsigned int;%x=%s;24\n", v3, t3);
	char* t4 = f(v4, 18, arr, m4);
	printf("long;-%x=-%s;18\n", v4, t4);
	char* t5 = f(v5, 13, arr, m5);
	printf("unsigned long;%x=%s;13\n", v5, t5);
}

