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
	char *t23;
	int t24;
	int t25;
	int t26;
	int t27;
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
	char *__v3;
	t1 = 10;
	__v0 = t1;
	t2 = 0;
	__v1 = t2;
for_inicio_1:
	t3 = __v1;
	t4 = 10;
	t5 = t3 < t4;
	t22 = t5;
	if (!t22) goto for_fim_1;
	t6 = 0;
	__v2 = t6;
for_inicio_2:
	t7 = __v2;
	t8 = 5;
	t9 = t7 < t8;
	t19 = t9;
	if (!t19) goto for_fim_2;
	t10 = __v2;
	 cout << t10 << endl;
	t11 = __v1;
	t12 = 1;
	t13 = t11 == t12;
	t14 = __v2;
	t15 = 3;
	t16 = t14 == t15;
	t17 = t13 && t16;
if (!t17) goto fim_if_1;
	goto for_fim_1;
fim_if_1:
for_incremento_2:
	__v2 = __v2 + 1;
	goto for_inicio_2;
for_fim_2:
	t20 = __v1;
	 cout << t20 << endl;
for_incremento_1:
	__v1 = __v1 + 1;
	goto for_inicio_1;
for_fim_1:
	char *origem;
	origem = (char *) malloc(300); 
	strcpy(origem, "rafael");
	t24 = 0;
	t25 = 0;
label_inicio_0:
	t26 = origem[t24] == '\0';
	if (t26) goto label_fim_0;
	t25 = t25 + 1;
	t24 = t24 + 1;
	goto label_inicio_0;
label_fim_0:
	free(origem);
	t27 = t25 + 1;
	t23 = (char *) malloc(t27);
	strcpy(t23,"rafael");
	__v3 = (char *) malloc(t27);
	strcpy(__v3, t23);
	 cout << __v3 << endl;
	free(__v3);
	free(t23);
	return 0;
}