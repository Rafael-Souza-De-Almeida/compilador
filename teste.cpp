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
	int t2;
	int t3;
	int t4;
	int t5;
	int t6;
	int t7;
	char *t8;
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
	t6 = t4 - 1;
	t7 = __v1 > t6;
	if (t7) goto for_fim_1;
	t5 = __v1;
	 cout << t5 << endl;
for_incremento_1:
	__v1 = __v1 + 1;
	goto for_inicio_1;
for_fim_1:
	char *origem;
	origem = (char *) malloc(300); 
	strcpy(origem, "rafael");
	t9 = 0;
	t10 = 0;
label_inicio_0:
	t11 = origem[t9] == '\0';
	if (t11) goto label_fim_0;
	t10 = t10 + 1;
	t9 = t9 + 1;
	goto label_inicio_0;
label_fim_0:
	free(origem);
	t12 = t10 + 1;
	t8 = (char *) malloc(t12);
	strcpy(t8,"rafael");
	__v2 = (char *) malloc(t12);
	strcpy(__v2, t8);
	 cout << __v2 << endl;
	free(__v2);
	free(t8);
	return 0;
}