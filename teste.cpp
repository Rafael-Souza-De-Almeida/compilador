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
	int t11;
	int t12;
	int t13;
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
	goto label_main;
label_main:
	t1 = 30;
	__v0 = t1;
	t2 = 20;
	__v1 = t2;
while_inicio_1:
	t3 = __v0;
	t4 = 50;
	t5 = t3 < t4;
	t13 = !t5;
	if (t13) goto while_fim_1;
	t6 = 30;
	__v2 = t6;
	t7 = __v0;
	t8 = 10;
	t9 = t7 + t8;
	__v0 = t9;
	t10 = __v2;
	t11 = 50;
	t12 = t10 + t11;
	__v2 = t12;
	 cout << __v0 << endl;
	 cout << __v2 << endl;
	goto while_inicio_1;
while_fim_1:
	 cout << __v1 << endl;
end_main:
	return 0;
}