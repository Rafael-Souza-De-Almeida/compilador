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
	int t14;
	int t15;
	int t16;
	int t17;
	int t18;
	int t19;
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
	int __v3;
	t1 = 10;
	__v0 = t1;
	t2 = 40;
	__v1 = t2;
	t3 = 0;
	__v2 = t3;
while_inicio_2:
	t4 = __v2;
	t5 = __v0;
	t6 = 40;
	t7 = t5 < t6;
	t8 = t4 || t7;
	t19 = !t8;
	if (t19) goto while_fim_2;
while_inicio_1:
	t9 = __v1;
	t10 = 50;
	t11 = t9 <= t10;
	t15 = !t11;
	if (t15) goto while_fim_1;
	t12 = __v1;
	t13 = 10;
	t14 = t12 + t13;
	__v1 = t14;
	 cout << __v1 << endl;
	goto while_inicio_1;
while_fim_1:
	t16 = __v0;
	t17 = 10;
	t18 = t16 + t17;
	__v3 = t18;
	goto while_inicio_2;
while_fim_2:
	return 0;
}