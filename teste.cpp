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
	char *t11;
	int t12;
	int t13;
	int t14;
	int t15;
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
	t3 = 0;
	t4 = 10;
	__v1 = t3;
for_inicio_1:
	t9 = t4 - 1;
	t10 = __v1 > t9;
	if (t10) goto for_fim_1;
	t5 = __v0;
	t6 = 20;
	t7 = t5 + t6;
	__v0 = t7;
	t8 = __v0;
	 cout << t8 << endl;
for_incremento_1:
	__v1 = __v1 + 1;
	goto for_inicio_1;
for_fim_1:
	char *origem;
	origem = (char *) malloc(300); 
	strcpy(origem, "rafael");
	t12 = 0;
	t13 = 0;
label_inicio_0:
	t14 = origem[t12] == '\0';
	if (t14) goto label_fim_0;
	t13 = t13 + 1;
	t12 = t12 + 1;
	goto label_inicio_0;
label_fim_0:
	free(origem);
	t15 = t13 + 1;
	t11 = (char *) malloc(t15);
	strcpy(t11,"rafael");
	__v2 = (char *) malloc(t15);
	strcpy(__v2, t11);
	 cout << __v2 << endl;
	free(__v2);
	free(t11);
	return 0;
}