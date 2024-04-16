#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    char s[200] = { 0 };

    char s1[100] = { 0 };
    fgets(s1, 82, stdin);

    char s2[100] = { 0 };
    fgets(s2, 82, stdin);

    char* s_1, * s_2, * s_;
    int l1 = strlen(s1), l2 = strlen(s2);
    //printf("%d", l1);
    for (int i = l1-1; i < l1; i++) if (s1[i] == '\n') s1[i] = 0;
    for (int i = l2-1; i < l2; i++) if (s2[i] == '\n') s2[i] = 0;

    s_1 = s1; s_2 = s2; s_ = s;

    while (*s_1 != 0 || *s_2 != 0) {
        if (*s_1 != 0) {
            while ((*s_1 != ' ') && (*s_1 != 0)) *s_++ = *s_1++;
            if ((*s_1 != 0) || (*s_2 != 0)) *s_++ = ' ';
            if (*s_1 != 0) s_1++;
        }
        if (*s_2 != 0) {
            while ((*s_2 != ' ') && (*s_2 != 0)) *s_++ = *s_2++;
            if ((*s_1 != 0) || (*s_2 != 0)) *s_++ = ' ';
            if (*s_2 != 0) s_2++;
        }
    }

    printf("%s", s);

    return 0;
}