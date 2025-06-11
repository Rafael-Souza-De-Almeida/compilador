/* Compilador hahaha */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std; 
int main(void) {
	int t1;
	char t10;
	char *t11;
	int t12;
	int t13;
	int t14;
	int t15;
	char *t16;
	char *t17;
	int t18;
	int t2;
	int t3;
	char *t4;
	int t5;
	int t6;
	int t7;
	int t8;
	char t9;
	int __v0;
	int __v1;
	int __v2;
	char *__v3;
	char __v4;
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
	cin >> __v4;
	if (cin.fail()) {
		cerr << "Entrada inválida para tipo char!" << endl;
		exit(1);
	}
	free(__v3);
	t10 = __v4;
	origem = (char *) malloc(300); 
	strcpy(origem, "rafael");
	t12 = 0;
	t13 = 0;
label_inicio_1:
	t14 = origem[t12] == '\0';
	if (t14) goto label_fim_1;
	t13 = t13 + 1;
	t12 = t12 + 1;
	goto label_inicio_1;
label_fim_1:
	free(origem);
	t15 = t13 + 1;
	t11 = (char *) malloc(t15);
	strcpy(t11,"rafael");
	t17 = (char *) malloc(2);
	t17[0] = t10;
	t17[1] = '\0';
	t18 = 2 + t15;
	t18 = t18 + 1;
	t16 = (char *) malloc(t18);
	strcpy(t16, t17);
	strcat(t16, t11);
	__v3 = (char *) malloc(t18);
	strcpy(__v3,t16);
	 cout << __v3 << endl;
	free(__v3);
	free(t11);
	free(t16);
	free(t17);
	free(t4);
	return 0;
}