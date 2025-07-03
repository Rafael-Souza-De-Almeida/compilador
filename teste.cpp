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
	int t20;
	int t21;
	int t22;
	int t23;
	int t24;
	int t25;
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
	goto label_main;
label_main:
	t1 = 10;
	__v0 = t1;
	t2 = 0;
	__v1 = t2;
for_inicio_1:
	t3 = __v1;
	t4 = 20;
	t5 = t3 < t4;
	t24 = t5;
	if (!t24) goto for_fim_1;
while_inicio_2:
	t6 = __v0;
	t7 = 30;
	t8 = t6 < t7;
	t22 = !t8;
	if (t22) goto while_fim_2;
	t10 = 0;
	t11 = 10;
	__v2 = t10;
for_inicio_3:
	t20 = t11 - 1;
	t21 = __v2 > t20;
	if (t21) goto for_fim_3;
	t12 = 50;
	__v3 = t12;
	t13 = __v3;
	t14 = 10;
	t15 = t13 + t14;
	__v0 = t15;
	t16 = __v2;
	t17 = 5;
	t18 = t16 == t17;
if (!t18) goto fim_if_1;
	t19 = __v3;
	 cout << t19 << endl;
	goto for_fim_1;
fim_if_1:
for_incremento_2:
	__v2 = __v2 + 1;
	goto for_inicio_3;
for_fim_3:
	goto while_inicio_2;
while_fim_2:
for_incremento_1:
	__v1 = __v1 + 1;
	goto for_inicio_1;
for_fim_1:
	t25 = __v0;
	 cout << t25 << endl;
end_main:
	return 0;
}