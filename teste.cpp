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
	int t2;
	int t3;
	char *t4;
	int t5;
	int t6;
	int t7;
	int t8;
	int t9;
	int __v0;
	int __v1;
	int __v2;
	char *__v3;
	int __v4;
	int __v5;
	t1 = 0;
	__v0 = t1;
	t2 = 10;
	__v1 = t2;
	t3 = 1;
	__v2 = t3;
	char *origem;
	origem = (char *) malloc(300); 
	strcpy(origem, "olá");
	t5 = 0;
	t6 = 0;
label_inicio_0:
	t7 = origem[t5] == '\0';
	if (t7) goto label_fim_0;
	t6 = t6 + 1;
	t5 = t5 + 1;
	goto label_inicio_0;
label_fim_0:
	free(origem);
	t8 = t6 + 1;
	t4 = (char *) malloc(t8);
	strcpy(t4,"olá");
	__v3 = (char *) malloc(t8);
	strcpy(__v3,t4);
	t10 = 0;
	t11 = 4;
	__v4 = t10;
for_inicio_1:
	t16 = t11 - 1;
	t17 = __v4 > t16;
	if (t17) goto for_fim_1;
	cin >> __v5;
	if (cin.fail()) {
		cerr << "Entrada inválida para tipo int!" << endl;
		exit(1);
	}
	t13 = __v5;
	t14 = 0;
	t15 = t13 == t14;
if (!t15) goto fim_if_1;
	goto for_fim_1;
fim_if_1:
for_incremento_1:
	__v4 = __v4 + 1;
	goto for_inicio_1;
for_fim_1:
	free(__v3);
	free(t4);
	return 0;
}