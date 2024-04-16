#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
#include <ctype.h>


int main()
{
    char s[81] = {0};
    //scanf("%[^\n]s", s);
    fgets(s, 81, stdin);
    //char s[81] = "to easy, peace a cake";
    int count[256] = { 0 };
    //printf("%d\n", strlen(s));
    for (int i = 0; i < strlen(s); i++) count[(int)s[i]]++;

    for (int i = 0; i < 256; i++) if (count[i] != 0 && i != 0 && i != 10) printf("%c=%d\n", i, count[i]);
}