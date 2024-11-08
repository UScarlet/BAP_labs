// try.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// ar[2]; *  = &ar[0]; short* b = &ar[1];
//int _diap = diap(int(a), int(b));
//printf("\t\t-%.0f to %.0f\t0-%.0f\n", _diap / 2, _diap / 2 - 1, _diap - 1);

#include <stdio.h>
#include <math.h>


int diap(int a1, int a2) {
    int r = (a2 - a1)*8;
    return r;
}

int main(){
    printf("Type\t\tSigned\t\t\t\t\t\tUnsigned\n");

    char ar1[2]; char* a1 = &ar1[0]; char* b1 = &ar1[1]; 
    int ch= diap(int(a1), int(b1));
    printf("Char\t\t%.0f to %.0f\t\t\t\t\t0-%.0f\n", -1 * pow(2, ch - 1), pow(2, ch - 1) - 1, pow(2, ch) - 1);
    
    short ar2[2]; short* a2 = &ar2[0]; short* b2 = &ar2[1];
    int sh = diap(int(a2), int(b2));
    printf("Short\t\t%.0f to %.0f\t\t\t\t\t0-%.0f\n", -1 * pow(2, sh - 1), pow(2, sh - 1) - 1, pow(2, sh) - 1);

    int ar3[2]; int* a3 = &ar3[0]; int* b3 = &ar3[1];
    int i = diap(int(a3), int(b3));
    printf("Int\t\t%.0f to %.0f\t\t\t0-%.0f\n", -1 * pow(2, i - 1), pow(2, i - 1) - 1, pow(2, i) - 1);

    long ar4[2]; long* a4 = &ar4[0]; long* b4 = &ar4[1];
    int l = diap(int(a4), int(b4));
    printf("Long\t\t%.0f to %.0f\t\t\t0-%.0f\n", -1 * pow(2, l - 1), pow(2, l - 1) - 1, pow(2,l) - 1);

    long long ar5[2]; long long* a5 = &ar5[0]; long long* b5 = &ar5[1];
    int ll = diap(int(a5), int(b5)); //64
    printf("Long long\t%.0f to %llu\t0-%llu\n", -1 * pow(2, ll - 1), long long (pow(2, ll-1))-1, long long(0)-1);

}

