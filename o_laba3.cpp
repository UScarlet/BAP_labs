#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void correct(int count_br, int c, FILE* ifp) {                              //потому что \t был перед комментом
    for (int i = 0; i < count_br; i++) { c = getc(ifp); }
}

void filecopy(FILE* ifp, FILE* ofp) {                                     /* filecopy: копирует файл ifp в файл ofp */
    int c;
    int count_br = 0, kav = 0, resh = 0, tsz = 0;
    int kon = 0; char a = '1';
    int any_else_chars = 0;
    int last_one = 0;

    while ((c = getc(ifp)) != EOF) {                                        //прочитали с значение
        
        (c == '{') ? count_br++ : (c == '}') ? count_br-- : count_br += 0;  //счётчик скобок
        if (c == '"') {                                                     //счётчик кавычек
            if (kav == 0) kav++;                                
            else kav--;
        }
        if (c == '#') resh = 1; if (c == ';') tsz = 1;                      // символы # и ; ожидаем новую строку
        if (c == '\n') { resh = 0; tsz = 0; }


        if (c != '/' || kav>0) {
            putc(c, ofp); last_one = c;
        }
        else {
            kon = ((c = getc(ifp)) == EOF);                                 //прочитали с
            switch (c) {
            case '/':
                while (c != '\n') {
                    kon = ((c = getc(ifp)) == EOF);
                    if (kon) break;
                }
                if (resh == 1 || tsz == 1) { ungetc(c, ifp);break; }
                /*if (last_one == '\n') {
                    if (c == '}') for (int i = 0; i < count_br - 1; i++) { putc('\t', ofp); }
                    else for (int i = 0; i < count_br; i++) { putc('\t', ofp); }
                }*/
                //?
                correct(count_br, c, ifp);
                break;
            case '*':
                a = '1';
                while (a != '/') {
                    c = getc(ifp);
                    if (c == '*') a = getc(ifp);
                }
                c = getc(ifp);
                if (c != '\n' || resh == 1 || tsz == 1) ungetc(c, ifp);
                else {
                    while (c == '\n' || c == '\t') {
                        c = getc(ifp);
                        switch (c)
                        {
                        case '\n':
                            putc(c, ofp); last_one = '\n';
                            break;
                        case '\t':
                            break;
                        case '}':
                            putc('\n', ofp); last_one = '\n';
                        default:
                            ungetc(c, ifp);
                            break;
                        }
                    }
                    if (last_one == '\n') {
                        if (c == '}') for (int i = 0; i < count_br - 1; i++) { putc('\t', ofp); }
                        else for (int i = 0; i < count_br; i++) { putc('\t', ofp); }
                    }
                }
                break;
            default: putc('/', ofp); putc(c, ofp); break;
            }
        }
        //printf("%c", c);
    }
}

int main()
{
    system("chcp 1251"); system("cls");
    FILE* file, * out;
    char name[] = "input.c";
    char nout[] = "out.c";

    if ((file = fopen(name, "r")) == NULL || (out = fopen(nout, "w")) == NULL)
    {
        //если что, он всё равно создаст out
        printf("Невозможно открыть файл\n");
        return 1;
    }
    else {
        filecopy(file, out);
        fclose(file);
    }
}