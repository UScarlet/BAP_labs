#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    char s[162] = { 0 };

    char s1[81] = { 0 };
    fgets(s1, 81, stdin);
     
    char s2[81] = { 0 };
    fgets(s2, 81, stdin);

    char* s_1, * s_2, * s_;
    int l1 = strlen(s1), l2 = strlen(s2);

    for (int i = 0; i < l1; i++) if (s1[i] == '\n') s1[i] = 0;
    for (int i = 0; i < l2; i++) if (s2[i] == '\n') s2[i] = 0;

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
    unsigned char ans[162] = {0};
    for (int i = 0; i < 162; i++) ans[i] = s[i];
    printf("%s", ans);

    return 0;
}