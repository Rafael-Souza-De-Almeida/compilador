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
	char *t15;
	int t16;
	int t17;
	int t18;
	char *t19;
	int t2;
	int t20;
	char t21;
	char t22;
	char *t23;
	char *t24;
	int t25;
	char *t26;
	int t27;
	int t28;
	int t29;
	int t3;
	char *t30;
	int t31;
	int t32;
	int t33;
	int t34;
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
	int __v4;
	char *__v5;
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
	t12 = 0;
	t13 = 0;
label_inicio_2:
	t14 = __v0[t12] == '\0';
	if (t14) goto label_fim_2;
	t13 = t13 + 1;
	t12 = t12 + 1;
	goto label_inicio_2;
label_fim_2:
	t11 = (char *) malloc(t13);
	strcpy(t11,__v0);
	t16 = 0;
	t17 = 0;
label_inicio_3:
	t18 = __v1[t16] == '\0';
	if (t18) goto label_fim_3;
	t17 = t17 + 1;
	t16 = t16 + 1;
	goto label_inicio_3;
label_fim_3:
	t15 = (char *) malloc(t17);
	strcpy(t15,__v1);
	t20 = t13 + t17;
	t20 = t20 + 1;
	t19 = (char *) malloc(t20);
	strcpy(t19, t11);
	strcat(t19, t15);
	__v2 = (char *) malloc(t20);
	strcpy(__v2,t19);
	t21 = 'a';
	t22 = 'b';
	t23 = (char *) malloc(2);
	t23[0] = t21;
	t23[1] = '\0';
	t24 = (char *) malloc(2);
	t24[0] = t22;
	t24[1] = '\0';
	t25 = 3;
	t26 = (char *) malloc(t25);
	strcpy(t26, t23);
	strcat(t26, t24);
	__v3 = (char *) malloc(t25);
	strcpy(__v3,t26);
	t27 = 10;
	t28 = 10;
	t29 = t27 + t28;
	__v4 = t29;
	origem = (char *) malloc(300); 
	strcpy(origem, "rafael");
	t31 = 0;
	t32 = 0;
label_inicio_4:
	t33 = origem[t31] == '\0';
	if (t33) goto label_fim_4;
	t32 = t32 + 1;
	t31 = t31 + 1;
	goto label_inicio_4;
label_fim_4:
	free(origem);
	t34 = t32 + 1;
	t30 = (char *) malloc(t34);
	strcpy(t30,"rafael");
	__v5 = (char *) malloc(t34);
	strcpy(__v5,t30);
	 cout << __v5 << endl;
	 cout << __v1 << endl;
	 cout << __v4 << endl;
	 cout << __v3 << endl;
	 cout << __v2 << endl;
	free(__v0);
	free(__v1);
	free(__v2);
	free(__v3);
	free(__v5);
	free(t1);
	free(t11);
	free(t15);
	free(t19);
	free(t23);
	free(t24);
	free(t26);
	free(t30);
	free(t6);
	return 0;
}