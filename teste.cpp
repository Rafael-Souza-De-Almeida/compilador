/* Compilador hahaha */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std; 
int main(void) {
	int t1;
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
	int __v2;
	t1 = 10;
	__v0 = t1;
	t3 = 0;
	t4 = __v0;
	__v1 = t3;
	t8 = t4 - 1;
for_inicio_1:
	t9 = __v1 > t8;
	if (t9) goto for_fim_1;
	t5 = __v1;
	t6 = __v0;
	t7 = t5 * t6;
	__v2 = t7;
	 cout << __v2 << endl;
	__v1 = __v1 + 1;
	goto for_inicio_1;
for_fim_1:
	 cout << __v0 << endl;
	return 0;
}