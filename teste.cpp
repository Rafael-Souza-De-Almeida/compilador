/* Compilador hahaha */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std; 
int main(void) {
	int t1;
	int t10;
	int t2;
	int t3;
	int t4;
	int t5;
	int t6;
	int t7;
	int t8;
	int t9;
	int __v0;
	int __v1;
	t2 = 0;
	t3 = 10;
	__v0 = t2;
	t9 = t3 - 1;
for_inicio_2:
	t10 = __v0 > t9;
	if (t10) goto for_fim_2;
	 cout << __v0 << endl;
	t5 = 0;
	t6 = 3;
	__v1 = t5;
	t7 = t6 - 1;
for_inicio_1:
	t8 = __v1 > t7;
	if (t8) goto for_fim_1;
	 cout << __v1 << endl;
	__v1 = __v1 + 1;
	goto for_inicio_1;
for_fim_1:
	__v0 = __v0 + 1;
	goto for_inicio_2;
for_fim_2:
	return 0;
}