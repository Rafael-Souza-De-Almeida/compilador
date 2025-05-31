/* Compilador hahaha */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std; 
int main(void) {
	char *t1;
	int t10;
	char *t11;
	int t12;
	int t13;
	int t14;
	int t15;
	char *t16;
	int t17;
	int t18;
	int t19;
	int t2;
	int t20;
	char *t21;
	int t22;
	int t23;
	int t24;
	int t25;
	int t3;
	int t4;
	int t5;
	char *t6;
	int t7;
	int t8;
	int t9;
	char *__v0;
	char *__v1;
	char *__v2;
	char *__v3;
	char *__v4;
	char *origem;
	origem = (char *) malloc(300); 
	strcpy(origem, "string");
	t2 = 0;
	t3 = 0;
label_inicio_0:
	t4 = origem[t2] == '\0';
	if (t4) goto label_fim_0;
	t3 = t3 + 1;
	t2 = t2 + 1;
	goto label_inicio_0;
label_fim_0:
	free(origem);
	t5 = t3 + 1;
	t1 = (char *) malloc(t5);
	strcpy(t1,"string");
	__v0 = (char *) malloc(t5);
	strcpy(__v0,t1);
	origem = (char *) malloc(300); 
	strcpy(origem, "rafita");
	t7 = 0;
	t8 = 0;
label_inicio_1:
	t9 = origem[t7] == '\0';
	if (t9) goto label_fim_1;
	t8 = t8 + 1;
	t7 = t7 + 1;
	goto label_inicio_1;
label_fim_1:
	free(origem);
	t10 = t8 + 1;
	t6 = (char *) malloc(t10);
	strcpy(t6,"rafita");
	__v1 = (char *) malloc(t10);
	strcpy(__v1,t6);
	origem = (char *) malloc(300); 
	strcpy(origem, "testando");
	t12 = 0;
	t13 = 0;
label_inicio_2:
	t14 = origem[t12] == '\0';
	if (t14) goto label_fim_2;
	t13 = t13 + 1;
	t12 = t12 + 1;
	goto label_inicio_2;
label_fim_2:
	free(origem);
	t15 = t13 + 1;
	t11 = (char *) malloc(t15);
	strcpy(t11,"testando");
	__v2 = (char *) malloc(t15);
	strcpy(__v2,t11);
	origem = (char *) malloc(300); 
	strcpy(origem, "");
	t17 = 0;
	t18 = 0;
label_inicio_3:
	t19 = origem[t17] == '\0';
	if (t19) goto label_fim_3;
	t18 = t18 + 1;
	t17 = t17 + 1;
	goto label_inicio_3;
label_fim_3:
	free(origem);
	t20 = t18 + 1;
	t16 = (char *) malloc(t20);
	strcpy(t16,"");
	__v3 = (char *) malloc(t20);
	strcpy(__v3,t16);
	origem = (char *) malloc(300); 
	strcpy(origem, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	t22 = 0;
	t23 = 0;
label_inicio_4:
	t24 = origem[t22] == '\0';
	if (t24) goto label_fim_4;
	t23 = t23 + 1;
	t22 = t22 + 1;
	goto label_inicio_4;
label_fim_4:
	free(origem);
	t25 = t23 + 1;
	t21 = (char *) malloc(t25);
	strcpy(t21,"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	__v4 = (char *) malloc(t25);
	strcpy(__v4,t21);
	 cout << t1 << endl;
	 cout << t6 << endl;
	 cout << t11 << endl;
	 cout << t16 << endl;
	 cout << t21 << endl;
	free(t1);
	free(t11);
	free(t16);
	free(t21);
	free(t6);
	return 0;
}