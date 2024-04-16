#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
#include <ctype.h>


int main()
{
    char s[81] = { 0 };
    //scanf("%[^\n]s", s);
    fgets(s, 81, stdin);
    int count[256] = { 0 };
    unsigned char s1[81];
    //русские буквы кодируются отрицат числами
    for (int i = 0; i < 81; i++) s1[i] = s[i];
    for (int i = 0; i < sizeof(s1); i++) count[(int)s1[i]]++;
    for (int i = 0; i < 256; i++) if (count[i] != 0 && i != 0 && i != 10) printf("%c=%d\n", i, count[i]);
}