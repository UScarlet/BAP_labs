#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Создайте программу, вычисляющую седьмую степень числа i в диапазоне, 
	определяемом размером переменной unsigned long. Проведите тестирование 
	на переполнение и покажите, как меняются результаты в зависимости от разрядности архитектуры.
*/

int main() {
	unsigned long a = 0;
	for(unsigned long i = 0; (sizeof(a) == 4) ? i <= 23 : i <= 565; i++) {
		a = i * i * i * i * i * i * i;
		printf("%lu\n", a);
	}	
}
