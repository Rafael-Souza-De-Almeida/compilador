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
	char *__v2;
	t1 = 10;
	__v0 = t1;
	t2 = 0;
	__v1 = t2;
for_inicio_1:
	t3 = __v1;
	t4 = 10;
	t5 = t3 < t4;
	t11 = t5;
	if (!t11) goto for_fim_1;
	t6 = __v1;
	t7 = 5;
	t8 = t6 == t7;
if (!t8) goto fim_if_1;
	goto for_fim_1;
fim_if_1:
	t9 = __v1;
	 cout << t9 << endl;
for_incremento_1:
	__v1 = __v1 + 1;
	goto for_inicio_1;
for_fim_1:
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
	__v2 = (char *) malloc(t16);
	strcpy(__v2, t12);
	 cout << __v2 << endl;
	free(__v2);
	free(t12);
	return 0;
}