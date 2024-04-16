#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE* ifp, FILE* ofp) {                                       /* filecopy: копирует файл ifp в файл ofp */
    int c;                                                                  // объявляем всё
    int count_br = 0, kav = 0, resh = 0, tsz = 0;
    int kon = 0; char a = '1';
    int last_one = 0;

    while ((c = getc(ifp)) != EOF) {                                        // прочитали с значение

        (c == '{') ? count_br++ : (c == '}') ? count_br-- : count_br += 0;  // счётчик скобок
        if (c == '"') {                                                     // счётчик кавычек (если в "" - не коммент)
            if (kav == 0) kav++;
            else kav--;
        }
        if (c == '#') resh = 1; if (c == ';') tsz = 1;                      // символы # и ; ожидаем новую строку
        if (c == '\n') { resh = 0; tsz = 0; }                               // если новая строка - сбросить

        if (c != '/' || kav > 0) {                                            // все комменты со знака '/'
            putc(c, ofp); last_one = c;
        }
        else {
            kon = ((c = getc(ifp)) == EOF);                                 // прочитали с
            switch (c) {
            case '/':                                                       // комменты вида    //к
                while (c != '\n') {                                         // до \n
                    last_one = c;
                    kon = ((c = getc(ifp)) == EOF);
                    if (last_one == '\\' && c == '\n') c = '1';             // случай "//1\ 2\\ 3\\\ 4" типа такого
                    if (kon) break;
                }
                if (resh == 1 || tsz == 1) { ungetc(c, ifp); break; }        //если до этого что-то было в строке, то \n нужен
                else {                                                      //иначе \n нет - удаляем строку
                    while (c == '\n' || c == '\t') {
                        c = getc(ifp);
                        switch (c)
                        {
                        case '\n':                                          // \n выводим
                            putc(c, ofp); last_one = '\n';
                            break;
                        case '\t':                                          // \t пропускаем
                            break;
                        case '}':                                           // фича :))))))
                            putc('\n', ofp); last_one = '\n';
                        default:
                            ungetc(c, ifp);
                            break;
                        }
                    }
                    if (last_one == '\n') {                                 // корректируем по \t
                        if (c == '}') for (int i = 0; i < count_br - 1; i++) { putc('\t', ofp); }
                        else for (int i = 0; i < count_br; i++) { putc('\t', ofp); }
                    }
                }
                break;

            case '*':                                                       // комменты вида    /*к*/
                a = '1';                                                    // a!='/'

                while (a != '/') {                                          // c = *
                    c = getc(ifp);                                          // когда с снова *
                    if (c == '*') a = getc(ifp);                            // a = '/' 
                }                                                           // получаем /* ... */ - коммент закрыт

                c = getc(ifp);                                              // если до этого что-то было в строке, то \n нужен
                if (c != '\n' || resh == 1 || tsz == 1) ungetc(c, ifp);     // иначе \n нет - удаляем строку

                else {                                                      // если после /**/ переход на новую строку
                    while (c == '\n' || c == '\t') {
                        c = getc(ifp);
                        switch (c)
                        {
                        case '\n':                                          // \n выводим
                            putc(c, ofp); last_one = '\n';
                            break;
                        case '\t':                                          // \t пропускаем
                            break;
                        case '}':                                           // фича :))))))
                            putc('\n', ofp); last_one = '\n';
                        default:
                            ungetc(c, ifp);
                            break;
                        }
                    }
                    if (last_one == '\n') {                                 // корректируем по \t
                        if (c == '}') for (int i = 0; i < count_br - 1; i++) { putc('\t', ofp); }
                        else for (int i = 0; i < count_br; i++) { putc('\t', ofp); }
                    }
                }
                break;
            default: putc('/', ofp); putc(c, ofp); break;                   //либо это какой-то случайный знак /
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