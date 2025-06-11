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
	char *t12;
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
	char *__v4;
	t1 = 0;
	__v0 = t1;
	t2 = 10;
	__v1 = t2;
	t4 = 0;
	t5 = 10;
	__v2 = t4;
for_inicio_1:
	t22 = t5 - 1;
	t23 = __v2 > t22;
	if (t23) goto for_fim_1;
	t7 = 1;
	t8 = 5;
	__v3 = t7;
for_inicio_2:
	t17 = t8 - 1;
	t18 = __v3 > t17;
	if (t18) goto for_fim_2;
	t9 = __v3;
	t10 = 1;
	t11 = t9 + t10;
	__v0 = t11;
	 cout << __v0 << endl;
	char *origem;
	origem = (char *) malloc(300); 
	strcpy(origem, "rafael");
	t13 = 0;
	t14 = 0;
label_inicio_0:
	t15 = origem[t13] == '\0';
	if (t15) goto label_fim_0;
	t14 = t14 + 1;
	t13 = t13 + 1;
	goto label_inicio_0;
label_fim_0:
	free(origem);
	t16 = t14 + 1;
	t12 = (char *) malloc(t16);
	strcpy(t12,"rafael");
	__v4 = (char *) malloc(t16);
	strcpy(__v4,t12);
	 cout << __v4 << endl;
for_incremento_2:
	__v3 = __v3 + 1;
	goto for_inicio_2;
for_fim_2:
	t19 = __v1;
	t20 = 10;
	t21 = t19 + t20;
	__v1 = t21;
for_incremento_1:
	__v2 = __v2 + 1;
	goto for_inicio_1;
for_fim_1:
	free(__v4);
	free(t12);
	return 0;
}