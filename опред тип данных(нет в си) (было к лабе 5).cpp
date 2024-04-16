#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <typeinfo>
#include <iostream>


int main() {
	int i = 23;
	unsigned long long b = 23;
	printf("%d %llu\n", (i * i * i * i * i * i * i * i), (b * b * b * b * b * b * b * b));
	std::cout << typeid(i * i * i * i * i * i * i * i).name()<< std::endl;
	std::cout << typeid(b * b * b * b * b * b * b * b).name() << std::endl;
	return 0;
}
//output
//1001573953 78310985281
//int
//unsigned __int64

//D : \C& C++\try\Debug\try1.exe(процесс 16124) завершил работу с кодом 0.
//Нажмите любую клавишу, чтобы закрыть это окно :
//