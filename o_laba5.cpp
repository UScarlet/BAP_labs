#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

FILE* file;

void shekerSort(int* a, int n) {
	int left = 0, right = n - 1; // левая и правая границы сортируемой области массива
	int flag = 1; // флаг наличия перемещений
	int sravn = 0, perem = 0;
	// Выполнение цикла пока левая граница не сомкнётся с правой
	// или пока в массиве имеются перемещения
	while ((left < right) && flag > 0) {
		flag = 0;
		for (int i = left; i < right; i++) //двигаемся слева направо
		{
			sravn++;
			if (a[i] > a[i + 1]) // если следующий элемент меньше текущего,
			{ // меняем их местами
				int t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
				flag = 1; // перемещения в этом цикле были
				perem++;
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--) //двигаемся справа налево
		{
			sravn++;
			if (a[i - 1] > a[i]) // если предыдущий элемент больше текущего,
			{ // меняем их местами
				int t = a[i];
				a[i] = a[i - 1];
				a[i - 1] = t;
				flag = 1; // перемещения в этом цикле были
				perem++;
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
	fprintf(file, "Number of compairings: %d, Number of swaps: %d\n", sravn, perem);
}
void InsertionSort(int* a, int n) {
	int newElement, location;
	int sravn1 = 0, perem1 = 0;
	for (int i = 1; i < n; i++) {
		newElement = a[i];
		location = i - 1;

		sravn1++;
		int s = sravn1;
		while (location >= 0 && a[location] > newElement) {
			if (s == sravn1) sravn1--;
			sravn1++;
			a[location + 1] = a[location];
			perem1++;
			location = location - 1;
		}
		a[location + 1] = newElement;
	}
	fprintf(file, "Number of compairings: %d, Number of swaps: %d\n", sravn1, perem1);
}
void Shellsort(int* a, int n) {
	int step = n / 2;
	int sravn = 0, perem = 0;

	while (step > 0) {
		for (int i = 0; i < n; i++) {
			int j = i;
			int temp = a[j];

			sravn++;
			int s = sravn;
			while (j >= step && a[j - step] > temp) {
				if (sravn == s) sravn--;
				sravn++;
				a[j] = a[j - step];
				j = j - step;
				perem++;
			}
			a[j] = temp;
			//perem++;
		}
		step /= 2;
	}

	fprintf(file, "Number of compairings: %d, Number of swaps: %d\n", sravn, perem);
}
/*void shell_sort(int* array, int size) {
	int cnt = 0;
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; ++i) {
			
            for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
				
                int temp = array[j];
                array[j] = array[j + s];
                array[j + s] = temp;
            }
        }
    }
	printf("%d", cnt);
}*/
void sort_bin_insert(int* a, int n) // Сортировка бинарными вставками
{
	int x, left, right, sred;
	int sravn = 0, perem = 0;
	for (int i = 1; i < n; i++) {
		sravn++;
		if (a[i - 1] > a[i]) {
			x = a[i]; // x – включаемый элемент
			left = 0; // левая граница отсортированной части массива
			right = i - 1; // правая граница отсортированной части массива

			do {
				sred = (left + right) / 2; // sred – новая "середина" последовательности
				//sravn++;
				if (a[sred] < x) { left = sred + 1; }
				else right = sred - 1;

			} while (left <= right); // поиск ведется до тех пор, пока левая граница не окажется правее правой границы

			for (int j = i - 1; j >= left; j--) {
				a[j + 1] = a[j];
				perem++;
			}
			a[left] = x;
		}
	}
	fprintf(file, "Number of compairings: %d, Number of swaps: %d\n", sravn, perem);
}
int* quick_sort(int* a, int n) {
	int* i;
	int* j;
	int ans[2] = { 0 };
	int sravn = 0, perem = 0;
	int x, t, s;
	i = a;
	j = a + n - 1;
	x = *(a + (n - 1) / 2); // это pivot - стержень
	while (i <= j) {
		sravn++;
		s = sravn;
		while (*i < x) {
			if (s == sravn) sravn--;
			i++; sravn++;  
		}

		sravn++;
		s = sravn;
		while (*j > x) { 
			if (s == sravn) sravn--;
			j--; sravn++; 
		}
		if (i <= j) {
			t = *i;
			*i = *j;
			*j = t;
			i++;
			j--;
			perem++;
		}
	}

	if (j > a) quick_sort(a, j - a + 1);
	if (i < a + n - 1) quick_sort(i, a + n - i);

	ans[0] = sravn; ans[1] = perem;
	return ans;
	//fprintf(file, "Number of compairings: %d, Number of swaps: %d\n", sravn, perem);
}

int main() {
	int N = 10;

	int* a1 = (int*)malloc(N * sizeof(int));
	if (!a1) return NULL;
	srand(time(NULL));

	file = fopen("input.txt", "w");
	for (int i = 0; i < N; i++) {
		a1[i] = rand();
		fprintf(file, "%d ", a1[i]);
	}
	fclose(file);

	int* b = (int*)malloc(N * sizeof(int));
	if (!b) return NULL;
	file = fopen("input.txt", "r");
	for (int i = 0; i < N; i++)
		fscanf(file, "%d", &b[i]);
	fclose(file);

	int* c = (int*)malloc(N * sizeof(int));
	if (!c) return NULL;
	file = fopen("input.txt", "r");
	for (int i = 0; i < N; i++)
		fscanf(file, "%d", &c[i]);
	fclose(file);

	int* d = (int*)malloc(N * sizeof(int));
	if (!d) return NULL;
	file = fopen("input.txt", "r");
	for (int i = 0; i < N; i++)
		fscanf(file, "%d", &d[i]);
	fclose(file);

	int* e = (int*)malloc(N * sizeof(int));
	if (!e) return NULL;
	file = fopen("input.txt", "r");
	for (int i = 0; i < N; i++)
		fscanf(file, "%d", &e[i]);
	fclose(file);

	int* f = (int*)malloc(N * sizeof(int));
	if (!f) return NULL;
	file = fopen("input.txt", "r");
	for (int i = 0; i < N; i++)
		fscanf(file, "%d", &f[i]);
	fclose(file);


	file = fopen("output.txt", "w");

	fprintf(file, "1) Insertion sort: \n");
	clock_t st = clock();
	InsertionSort(b, N);
	clock_t en = clock();
	fprintf(file, "Time of work: %.3lf seconds.\n", (double)(en - st) / CLOCKS_PER_SEC);

	fprintf(file, "2) Shakersort: \n");
	clock_t st1 = clock();
	shekerSort(c, N);
	clock_t en1 = clock();
	fprintf(file, "Time of work: %.3lf seconds.\n", (double)(en1 - st1) / CLOCKS_PER_SEC);

	fprintf(file, "3) Shellsort: \n");
	clock_t st2 = clock();
	Shellsort(d, N);
	clock_t en2 = clock();
	fprintf(file, "Time of work: %.3lf seconds.\n", (double)(en2 - st2) / CLOCKS_PER_SEC);
	
	//shell_sort(d, N);

	fprintf(file, "4) Binary Insertion sort: \n");
	clock_t st3 = clock();
	sort_bin_insert(e, N);
	clock_t en3 = clock();
	fprintf(file, "Time of work: %.3lf seconds.\n", (double)(en3 - st3) / CLOCKS_PER_SEC);

	fprintf(file, "5) Quick sort: \n");
	clock_t st4 = clock();
	int* ans = quick_sort(f, N);
	fprintf(file, "Number of compairings: %d, Number of swaps: %d\n", ans[0], ans[1]);
	clock_t en4 = clock();
	fprintf(file, "Time of work: %.3lf seconds.\n", (double)(en4 - st4) / CLOCKS_PER_SEC);

	fclose(file);
	
	free(a1);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);
	return 0;
}
