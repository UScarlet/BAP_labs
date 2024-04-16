#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//Пояснения к сложению и вычитанию
/*
* пусть есть 2 числа, они либо равны, либо одно из них по модулю больше другого
* если они равны, то будем считать что первое число по модулю больше
* (будем отнимать от него, ничего не изменится, ведь а-а = 0)
*
* !для сложения не важно, модуль какого числа больше, это важно для умножения
*
* находим число большее по модулю
* пусть есть два числа, модули которых равны 2 и 5
* напишем программы, которые считают 5+2 = X и 5-2 = Y
* всевозможные комбинации знаков:
* (и сочетания модулей: большлй-малый и малый-большой
*	+5 + +2	= (5+2)	= X				+5 - +2 = (5-2)	 = Y
*	+2 + +5	= (5+2)	= X				+2 - +5 = -(5-2) = -Y
*	+5 + -2	= (5-2)	= Y				+5 - -2 = (5+2)  = X
*	+2 + -5	=-(5-2) = -Y			+2 - -5 = (5+2)  = X
*	-5 + +2	=-(5-2) = -Y			-5 - +2 = -(5+2) = -X
*	-2 + +5	= (5-2) = Y				-2 - +5 = -(5+2) = -X
*	-5 + -2	=-(5+2) = -X			-5 - -2 = -(5-2) = -Y
*	-2 + -5	=-(5+2) = -X			-2 - -5 = (5-2)  = Y
*
*/

//Пояснения к прогрессии
/*
* -6 -3 ==> -18
* -6  3 ==> -15
*  6 -3 ==> err
*  6  3 ==> err
* -3 -6 ==> err
* -3  6 ==> 15
*  3 -6 ==> err
*  3  6 ==> 18
*/

//Полезное
/*
for (int i = 0; i < l1; i++) printf("%c", *(numa + i));
printf("\n");
for (int i = 0; i < l2; i++) printf("%c", *(numb + i));
printf("\n");
*/

void hello() {
	printf("Calculator\n");
	printf("\tOperations:\n");
	printf("\t+\t- a+b\n");
	printf("\t-\t- a-b\n");
	printf("\t*\t- a*b\n");
	printf("\t^\t- a^b\n");
	printf("\t!\t- a!\n");
	printf("\tS\t- Sum of nums from a to b\n");
	printf("\tE\t- Exit\n");
	printf("\n");
	printf("Choose operation\t");
}
char* sign_(char a[1001]) {
	char znak = a[0];
	//у 0 знак +, тк перед ним минуса нет, у -0 знак -
	if (znak != '-') {
		//раздвижка 
		int t = a[0];
		int t1 = a[1];
		a[0] = '+';
		a[1] = t;
		for (int i = 2; i < 1000; i++) {
			t = a[i];
			a[i] = t1;
			t1 = t;
		}
		return a;
	}
	else {
		int i = 1;
		int cnt = 1; //один минус уже был считан

		while (a[i] == '-') {
			cnt++; i++;
		}

		char* a1 = (char*)calloc(1001, sizeof(char));
		if (!a1) { return NULL; }
		(cnt % 2 == 0) ? a1[0] = '+' : a1[0] = '-';
		int l = strlen(a);
		for (int j = 0; j < l - i; j++) a1[j + 1] = a[i + j];

		return a1;
	}

}
int len_in_mem(char* p, int l) {
	int len = -1;
	for (int i = 0; i < l; i++) if (*(p + i) == '\n') {
		len = i; break;
	}
	return len;
}
int greater_module(char* a, int l1, char* b, int l2) {

	if (l1 == l2) {
		int t = l1;
		for (int i = 1; i < t; i++) {
			if (int(a[i]) > int(b[i])) l1++;
			if (int(a[i]) < int(b[i])) l2++;
			if (l1 != l2) break;
		}
		if (l1 == l2) return 1;
	}
	if (l1 != l2) {
		if (l1 < l2) return 2;
		else if (l1 > l2) return 1;
	}

	return 0;
}
int len_of_pstr(char* a) {
	int i = 0;
	while (*(a + i) != '\0' && i < 1001) i++;
	return i;
}
int is_equal(char* pa, int l1, char *pb, int l2) {
	if (l1 != l2) return 0;
	for (int i = 0; i < l1; i++) {
		if (*(pa + i) != *(pb + i)) return 0;
	}
	return 1;
}
int is_equal_not_sign(char* pa, int l1, char* pb, int l2) {
	if (l1 != l2) return 0;
	for (int i = 1; i < l1; i++) {
		if (*(pa + i) != *(pb + i)) return 0;
	}
	return 1;
}

char* sum(char* pa, int l1, char* pb, int l2, int gm) {
	//где-то 1001 знак + запас
	char answer[1003] = { 0 };
	int overflow = 0;
	int sm = 0;

	int len_g = (gm == 1) ? l1 : l2;

	int* numa = (int*)calloc(len_g, sizeof(int));
	if (!numa) return NULL;
	for (int i = 1; i < l1; i++) *(numa + (i - 1)) = int(*(pa + l1 - i)) - 48;

	int* numb = (int*)calloc(len_g, sizeof(int));
	if (!numb) return NULL;
	for (int i = 1; i < l2; i++) *(numb + (i - 1)) = int(*(pb + l2 - i)) - 48;

	//там был знак, а мы убрали
	for (int i = 0; i < len_g; i++) {
		sm = overflow + int(*(numa + i)) + int(*(numb + i));
		answer[i] = char(sm % 10 + 48);
		overflow = sm / 10;
	}

	int l = strlen(answer);
	
	//сохранение ответа
	char* ans = (char*)calloc((l + 1), sizeof(char));
	if (!ans) return NULL;
	for (int i = 0; i < l; i++) ans[i] = answer[l - 1 - i];
	ans[l] = '\0';

	return ans;
}

char* dif(char* pa, int lena, char* pb, int lenb, int gm) {
	char answer[1003] = { 0 };
	int len_g = (gm == 1) ? lena : lenb;

	int* numa = (int*)calloc(len_g, sizeof(int));
	if (!numa) return NULL;
	for (int i = 1; i < lena; i++) *(numa + (i - 1)) = int(*(pa + lena - i)) - 48;

	int* numb = (int*)calloc(len_g, sizeof(int));
	if (!numb) return NULL;
	for (int i = 1; i < lenb; i++) *(numb + (i - 1)) = int(*(pb + lenb - i)) - 48;

	int* big = (gm == 1) ? numa : numb;
	int* little = (gm == 1) ? numb : numa;

	for (int i = 0; i < len_g-1; i++) {
		if (big[i] - little[i] < 0) {
			big[i + 1]--; big[i] += 10;
		}
		answer[i] = char(big[i] - little[i] + 48);
	}

	int l = strlen(answer);

	//сохранение ответа
	char* ans = (char*)calloc((l + 1), sizeof(char));
	if (!ans) return NULL;
	for (int i = 0; i < l; i++) ans[i] = answer[l - 1 - i];
	ans[l] = '\0';

	return ans;
}

char* multiply(char* pa, int lena, char* pb, int lenb, int gm) {
	int len_g = (gm == 1) ? lena : lenb;
	int len_l = (gm == 1) ? lenb : lena;
	int ll = len_g + len_l;

	int* numa = (int*)calloc(1001, sizeof(int));
	if (!numa) return NULL;
	for (int i = 1; i < lena; i++) *(numa + (i - 1)) = int(*(pa + lena - i)) - 48;

	int* numb = (int*)calloc(1001, sizeof(int));
	if (!numb) return NULL;
	for (int i = 1; i < lenb; i++) *(numb + (i - 1)) = int(*(pb + lenb - i)) - 48;

	int* big = (gm == 1) ? numa : numb;
	int* little = (gm == 1) ? numb : numa;
	// big len_g  little len_l
	int overflow = 0;
	int sm = 0;
	int k = 0;

	char* ans = (char*)calloc(ll+1, sizeof(char));
	if (!ans) return NULL;
	for (int i = 0; i < ll; i++) ans[i] = '0';

	char* sum_p = (char*)calloc(ll + 1, sizeof(char));
	if (!sum_p) return NULL;
	for (int i = 0; i < ll; i++) sum_p[i] = '0';

	char* sum_itog = (char*)calloc(ll + 1, sizeof(char));
	if (!sum_itog) return NULL;
	for (int i = 0; i < ll; i++) sum_itog[i] = '0';

	while (k < len_l-1) {

		overflow = 0;
		sm = 0;
		for (int i = 0; i < ll; i++) sum_p[i] = '0';

		for (int i = 0; i < len_g; i++) {
			sm = big[i] * little[k] + overflow;
			sum_p[i + k] = char(sm % 10 + 48);
			overflow = sm / 10;
		}

		int o = 0, sm1 = 0;
		for (int i = 0; i < ll; i++) {
			sm1 = o + int(*(sum_p + i)) - 48 + int(*(sum_itog + i)) - 48;
			ans[i] = char(sm1 % 10 + 48);
			o = sm1 / 10;
		}

		for (int i = 0; i < ll; i++) sum_itog[i] = ans[i];

		k++;
	}

	sum_itog[ll] = '\0';
	for (int i = 0; i < ll; i++) ans[i] = sum_itog[ll - 1 - i];
	ans[ll] = '\0';

	return ans;
}

char* sum_from_to(char* pa, int l1, char* pb, int l2, int gm, char zna, char znb) {

	int len_g = (gm == 1) ? l1 : l2;

	char* numa = (char*)calloc(len_g +1, sizeof(char));
	if (!numa) return NULL;
	numa[0] = '+';
	for (int i = 1; i < l1; i++) *(numa + i) = *(pa + i);
	numa[l1] = '\0';
	//ok
	char* numb = (char*)calloc(len_g + 1, sizeof(char));
	if (!numb) return NULL;
	numb[0] = '+';
	for (int i = 1; i < l2; i++) *(numb + i) = *(pb + i);
	numb[l2] = '\0';
	//ok

	char* big_m = (gm == 1) ? numa : numb;
	int lbigm = (gm == 1) ? l1 : l2;
	char* lit_m = (gm == 1) ? numb : numa;
	int llitm = (gm == 1) ? l2 : l1;

	//gm: я сама поставила, что 1-ый больший, не надо определять
	char* m1 = sum(big_m, lbigm, lit_m, llitm, 1);
	char* m = dif(big_m, lbigm, lit_m, llitm, 1);

	char* m2 = (char*)calloc(lbigm + 1, sizeof(char));
	if (!m2) return NULL;
	m2[0] = '+';
	for (int i = 1; i < l2; i++) *(m2 + i) = *(m + i-1);
	m2[lbigm] = '\0';

	char ed[] = "+1";
	char* e = ed;
	int gm1 = greater_module(e, 2, m2, lbigm);
	char* m3 = sum(e, 2, m2, lbigm, gm1);

	int len_g2 = len_g + 1;
	char* n1 = (char*)calloc(len_g2+1, sizeof(char));
	if (!n1) return NULL;
	for (int i = 0; i < len_g2; i++) n1[i] = '0';
	n1[0] = '+';
	for (int i = 1; i < len_g2; i++) *(n1 + (i)) = (*(m1 + i - 1));
	n1[len_g2] = '\0';

	char* n2 = (char*)calloc(len_g2 + 1, sizeof(char));
	if (!n2) return NULL;
	for (int i = 0; i < len_g2; i++) n2[i] = '0';
	n2[0] = '+';
	for (int i = 1; i < len_g2; i++) *(n2 + (i)) = (*(m3 + i - 1));
	n2[len_g2] = '\0';

	int gmm = greater_module(n1, len_g2, n2, len_g2);
	char* ans2 = multiply(n1, len_g2, n2, len_g2, gmm);
	ans2[len_g2 * 2] = '\0';

	int overf = 0;
	char* ans = (char*)calloc((len_g2 * 2 + 1), sizeof(char));
	if (!ans) return NULL;
	for (int i = 0; i < len_g2 * 2; i++) ans[i] = '0';
	int l8, l9, l10;
	for (int i = 0; i < len_g2 * 2; i++) {
		l8 = (int(ans2[i]) - 48);
		l9 = (10 * overf + l8);
		l10 = l9 / 2;
		overf = l9 % 2;
		ans[i] = char(l10 + 48);
	}

	ans[len_g2 * 2] = '\0';

	if (zna == znb) return ans;
	else {
		char* s = (char*)calloc(len_g2 * 2 + 2, sizeof(char));
		if (!s) return NULL;
		for (int i = 0; i < len_g2 * 2+1; i++) s[i] = '0';
		s[0] = '+';
		for (int i = 1; i < len_g2 * 2 + 1; i++) *(s + (i)) = (*(ans + i - 1));
		s[len_g2 * 2 + 1] = '\0';
		char* o = dif(s, len_g2 * 2 + 2, lit_m, llitm, 1);
		return (o);
	}
}

char* stepen(char* pa, int l1, char* pb, int l2, int gm, char *e) {
	
	char* numa = (char*)calloc(1001, sizeof(char));
	if (!numa) return NULL;
	numa[0] = '+';
	for (int i = 1; i < l1; i++) *(numa + (i)) = ((*(pa + i)));
	numa[l1] = '\0';
	//ok

	char* numb = (char*)calloc(1001, sizeof(char));
	if (!numb) return NULL;
	numb[0] = '+';
	for (int i = 1; i < l2; i++) *(numb + i) = *(pb + i);
	numb[l2] = '\0';
	//ok
	
	char* stepen = (char*)calloc(1001, sizeof(char));
	if (!stepen) return NULL;
	stepen[0] = '+';
	for (int i = 1; i < l2; i++) *(stepen + i) = *(numb + i);
	numb[l2] = '\0';

	int overf = 0;
	int l8, l9, l10;

	int int_sum_num = 0;
	int* lenta = (int*)calloc(l2 * 4, sizeof(int));
	if (!lenta) return NULL;
	int lental = 0;
	//1000 - need 3400 я посчитатла это на глаз

	int l = l1;
	char* n2 = (char*)calloc(1001, sizeof(char));
	if (!n2) return NULL;
	n2[0] = '+';
	for (int i = 1; i < l1; i++) *(n2 + (i)) = (*(numa + i));
	n2[l1] = '\0';

	while (int_sum_num != 1 && lental<l2*4) {
		int_sum_num = 0;
		overf = 0;
		for (int i = 1; i < l2; i++) {
			l8 = (int(stepen[i]) - 48);
			l9 = (10 * overf + l8);
			l10 = l9 / 2;
			overf = l9 % 2;
			int y = l10;
			for (int j = l2 - i; j > 1; j--) y *=10;
			int_sum_num += y;
			stepen[i] = char(l10 + 48);
		}
		
		lenta[lental] = overf; lental++;
	}
	//for (int k = 0; k < lental; k++) printf("%d", lenta[k]);
	char* n1 = (char*)calloc(1001, sizeof(char));
	if (!n1) return NULL;
	char* k;
	for (int i = lental - 1; i >= 0; i--) {
		{
		
		n1[0] = '+';
		for (int i = 1; i < l1; i++) *(n1 + (i)) = (*(numa + i));
		n1[l1] = '\0';

		k = multiply(n1, l1, n1, l1, 1);
		k[l1 * 2] = '\0';
		int j = 0; while (k[j] == '0') { j++; };
		int p = 0;
		for (p = j; p < l1 * 2; p++) {numa[p - j + 1] = k[p];}
		l1 = l1 * 2 - j + 1;
		if (l1 > 1001) return e;
		}
		if (lenta[i]) {
			
			n1[0] = '+';
			for (int i = 1; i < l1; i++) *(n1 + (i)) = (*(numa + i));
			n1[l1] = '\0';

			k = multiply(n1, l1, n2, l, 1);
			//1ый по модулю больше всегда тк числа целые
			k[l1 + l] = '\0';
			int j = 0; while (k[j] == '0') { j++; };
			int p = 0;
			for (p = j; p < l1 + l; p++) {numa[p - j + 1] = k[p];}
			l1 = (l1 + l) - j + 1;
		}
	}

	numa[0] = '0';
	numa[l1] = '\0';
	
	if (l1 > 1001) return e;
	else return(numa);
}

char* factorial(char* pa, int l1, char *error) {

	char ed[] = "+1";
	char* e = ed;
	int le = 2;

	char* numa = (char*)calloc(1001, sizeof(char));
	if (!numa) return NULL;
	numa[0] = '+';
	for (int i = 1; i < l1; i++) *(numa + i) = *(pa + i);
	numa[l1] = '\0';
	//ok

	char* m = dif(numa, l1, ed, 2, 1);
	//len of n = l1

	int l = l1;
	char* n = (char*)calloc(1001, sizeof(char));
	if (!n) return NULL;
	n[0] = '+';
	for (int i = 1; i < l1; i++) *(n + (i)) = (*(m + i - 1));
	n[l1] = '\0';

	int int_sum_num = 0;

	//мы убрали знак, значение разности вернулось без знака
	for (int razryad = 0; razryad < l1 - 1; razryad++) {
		int r = m[(l1 - 1) - 1 - razryad] - 48;
		for (int i = 0; i < razryad; i++) r*=10;
		int_sum_num += r;

	}

	char *k = (char*)calloc(1001, sizeof(char));
	if (!k) return NULL;

	while (int_sum_num != 1) {
		int_sum_num = 0;

		if (l1 > 1002) return error;

		char* n2 = multiply(numa, l1, n, l, 1);
		if (!n2) return NULL;
		int j = 0; while (n2[j] == '0') j++;

		int l2 = l1 + l;
		for (int i = 0; i < l2; i++) *(k + i) = *(n2 + i + j);

		for (int i = 0; i < l2 - j; i++) numa[i + 1] = k[i];
		l1 = l2 - j + 1; //ещё на знак
		numa[l1] = '\0';

		m = dif(n, l, ed, 2, 1);

		for (int razryad = 0; razryad < l - 1; razryad++) {
			int r = m[(l - 1) - 1 - razryad] - 48;
			for (int i = 0; i < razryad; i++) r*=10;
			int_sum_num += r;
		}

		n[0] = '+';
		for (int i = 1; i < l; i++) *(n + (i)) = (*(m + i - 1));
		n[l] = '\0';
	}
	numa[0] = '0';
	numa[l1] = '\0';

	char* ans = (char*)calloc(1001, sizeof(char));
	if (!ans) return NULL;
	for (int i = 1; i < l1; i++) ans[i - 1] = numa[i];
	ans[l1] = '\0';

	if (l1 > 1002) return error;
	else return (ans);
}

int main(int argc, char* argv[])
{
	hello();
	char op;

	char a[1001] = { 0 };
	char b[1001] = { 0 };
	char* pa = a, * pb = b;

	char error[] = "error";
	char* e = error;

	do {
		op = getchar();
		int check = 0;
		getchar();

		if (op == '+' || op == '-' || op == '*' || op == '^' || op == 'S') {
			check = 1;

			fflush(stdin);
			fgets(a, 1000, stdin);
			pa = sign_(a);
			fgets(b, 1000, stdin);
			pb = sign_(b);

			char nol[] = "+0";
			char* n = nol;

			int l1 = strlen(a); //a
			int l2 = strlen(b); //b

			int lmem1 = len_in_mem(pa, l1);
			int lmem2 = len_in_mem(pb, l2);

			char zna = *pa;
			char znb = *pb;
			int gm = greater_module(pa, lmem1, pb, lmem2);

			char* s = sum(pa, lmem1, pb, lmem2, gm); int ls = len_of_pstr(s);
			char* d = dif(pa, lmem1, pb, lmem2, gm); int ld = len_of_pstr(d);
			
			//варианты вывода
			if (op == '+') {
				if (zna == '-' && znb == '-') {
					if(!is_equal_not_sign(s,ls,n,2)) printf("-"); 
					zna = '+'; znb = '+';
				}
				if (zna == '+' && znb == '+')
				{
					char* k = sum(pa, lmem1, pb, lmem2, gm);
					int lk = len_of_pstr(k);
					int j = 0;
					while (k[j] == '0' && j + 1 < lk) j++;
					for (int i = j; i < lk; i++) printf("%c", *(k + i));
				}
				if (zna == '+' && znb == '-') {
					int flag = 0;
					if (gm == 2) {
						if (!is_equal_not_sign(d, ld, n, 2)) printf("-");  
						flag = 1;
					}
					if (gm == 1 || flag) {
						char* k = dif(pa, lmem1, pb, lmem2, gm);
						int lk = len_of_pstr(k);
						int j = 0;
						while (k[j] == '0' && j + 1 < lk) j++;
						for (int i = j; i < lk; i++) printf("%c", *(k + i));
					}

				}
				if (zna == '-' && znb == '+') {
					int flag = 0;
					if (gm == 1) {
						char mol[] = "0";
						char* m = mol;
						if (!is_equal(d,ld,m,1)) printf("-"); 
						flag = 1;
					}
					if (gm == 2 || flag) {
						char* k = dif(pa, lmem1, pb, lmem2, gm);
						int lk = len_of_pstr(k);
						int j = 0;
						while (k[j] == '0' && j + 1 < lk) j++;
						for (int i = j; i < lk; i++) printf("%c", *(k + i));
					}
				}
			}

			if (op == '-') {
				int flag = 0;
				if (zna == '-' && znb == '+') {
					char mol[] = "0";
					char* m = mol;
					if (!is_equal(d, ld, m, 1)) printf("-"); ; flag = 1;
				}
				if ((zna == '+' && znb == '-') || flag) {
					char* k = sum(pa, lmem1, pb, lmem2, gm);
					int lk = len_of_pstr(k);
					int j = 0;
					//while (k[j] == '0') j++;
					while (k[j] == '0' && j + 1 < lk) j++;
					for (int i = j; i < lk; i++) printf("%c", *(k + i));
				}
				if (zna == '+' && znb == '+') {
					flag = 0;
					if (gm == 2) {
						if (!is_equal_not_sign(d, ld, n, 2)) printf("-"); flag = 1;
					}
					if (gm == 1 || flag) {
						char* k = dif(pa, lmem1, pb, lmem2, gm);
						int lk = len_of_pstr(k);
						int j = 0;
						while (k[j] == '0' && j + 1 < lk) j++;
						for (int i = j; i < lk; i++) printf("%c", *(k + i));
					}
				}
				if (zna == '-' && znb == '-') {
					flag = 0;
					if (gm == 1) {
						char mol[] = "0";
						char* m = mol;
						if (!is_equal(d, ld, m, 1)) printf("-"); 
						flag = 1;
					}
					if (gm == 2 || flag) {
						char* k = dif(pa, lmem1, pb, lmem2, gm);
						int lk = len_of_pstr(k);
						int j = 0;
						while (k[j] == '0' && j + 1 < lk) j++;
						for (int i = j; i < lk; i++) printf("%c", *(k + i));
					}
				}
			}

			if (op == '*') {
				//проверка на 0
				
				if(is_equal_not_sign(pa,lmem1, n,2)||
					is_equal_not_sign(pb, lmem2, n, 2)) {
					printf("0");
				}
				else {
					if (zna != znb) printf("-");
					char* k = multiply(pa, lmem1, pb, lmem2, gm);
					int lk = len_of_pstr(k);
					int j = 0;
					while (k[j] == '0' && j + 1 < lk) j++;
					for (int i = j; i < lk; i++) printf("%c", *(k + i));
				}
			}

			if (op == 'S') {
				if (gm == 1 && zna == '+' or gm == 2 && znb == '-')
					printf("The first number must be less than the second one");
				else {
					if (is_equal_not_sign(pa, lmem1, pb, lmem2)) printf("0");
					else {
						char zn = (gm == 1) ? zna : znb;
						if (zn == '-') printf("-");

						char* k = sum_from_to(pa, lmem1, pb, lmem2, gm, zna, znb);
						int lk = len_of_pstr(k);
						int j = 0;
						while (k[j] == '0' && j + 1 < lk) j++;
						for (int i = j; i < lk; i++) printf("%c", *(k + i));
					}

				}
			}

			if (op == '^') {
				int t = 1;

				char ed_p[] = "+1"; char nol_p[] = "+0";
				char ed_n[] = "-1"; char nol_n[] = "-0";

				char* k = nol_p; //недостижимое
				//printf("%d %d", lmem2, strlen(ed_n));

				if (is_equal(pb, lmem2, ed_p, 2)
					|| is_equal(pb, lmem2, ed_n, 2)) {
					pa[0] = '0';
					pa[lmem1] = '\0';
					k = pa;
					t = 0;
				}
				if (is_equal(pb, lmem2, nol_n, 2)
					|| is_equal(pb, lmem2, nol_p, 2)) {
					if (!(is_equal(pa, lmem2, nol_n, 2)
						|| is_equal(pa, lmem2, nol_p, 2))) {
						k = ed_p;
						k[0] = '0';
						k[2] = '\0';
					}
					t = 0;
				}

				if (t) k = stepen(pa, lmem1, pb, lmem2, gm, e);
				if (is_equal(k, lmem2, nol_p, 2))
					printf("We will never know...");
				else {
					int lk = len_of_pstr(k);
					int j = 0;
					while (k[j] == '0' && j + 1 < lk) j++;
					if (k[0] == 'e') printf("More than 1000 signs. Stack overflow");
					else {
						int nechet = ((int(pb[lmem2 - 1]) - 48) % 2 != 0);
						if (nechet && zna == '-') printf("-");
						int format = 0;
						if (znb == '-') format = 1;
						if (format) printf("(");
						for (int i = j; i < lk; i++) printf("%c", *(k + i));
						if (format) printf(")^-1");
					}
				}
			}
		}

		if (op == '!') {
			check = 1;

			fgets(a, 1000, stdin);
			pa = sign_(a);

			int l1 = strlen(a); //a

			int lmem1 = len_in_mem(pa, l1);

			char zna = *pa;

			int t = 1;
			char ed_p[] = "+1"; char nol_p[] = "+0";
			char ed_n[] = "-1"; char nol_n[] = "-0";
			if (zna == '-') {
				printf("The number must be positive or 0");
				t = 0;
			}
			if (is_equal(pa, lmem1, nol_p, 2)
				|| is_equal(pa, lmem1, nol_n, 2)) {
				printf("1");
				t = 0;
			}
			if (t) {
				char* k = factorial(pa, lmem1,e);
				int lk = len_of_pstr(k);
				int j = 0;
				while (k[j] == '0' && j + 1 < lk) j++;
				if (k[0] == 'e') printf("More than 1000 signs. Stack overflow");
				else for (int i = j; i < lk; i++) printf("%c", *(k + i));
			}
		}

		if (op == 'E') { printf("\nHave a nice day!\n"); break; };

		if (!check) {
			getchar();
			printf("Try again or press E to exit");
		}

		check = 0;
		printf("\nChoose operation\t");

	} while (1);

}