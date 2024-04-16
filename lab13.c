#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
	int hmt = 3;
	scanf("%d\n", &hmt);
	

	for (int n = 0; n < hmt; n++) {
		char s_in[70] = { 0 };
		fgets(s_in, 70, stdin);
		//scanf("%s", s_in);
		char s[70] = { 0 };
		int index = -1;					//недостижимое
		int end_of_second_word = 100;	//недостижимое
		for (int i = 0; i < 70; i++) {
			if (s_in[i] == 32) index = i;
			if (s_in[i] == 10 && end_of_second_word > i) end_of_second_word = i;
		}

		//index - длина первого слова - индекс пробела
		//end_of_second_word-index-1 - длина 2ого слова

		//printf("%d %d\n", index, end_of_second_word);
		int cnt = 0;
		for (int i = 0; i < index; i++) {
			cnt = 0;
			if (s_in[i] == s_in[index + 1]) {
				for (int j = i; j < index; j++) {
					//printf("j%d i%d\n", i, j);
					//printf("%c %c %d\n", s_in[j], s_in[(index +1)+ (j - i)], index + (j - i));
					if (s_in[j] == s_in[(index + 1) + (j - i)]) cnt++;
					else break;
				}
				if (cnt + i == index) break;
			}

		}
		for (int i = index - cnt; i <= index; i++) { s_in[i] = '\0'; }

		for (int i = 0; i < 70; i++) { if (s_in[i] != '\0') printf("%c", s_in[i]); }

	}


}