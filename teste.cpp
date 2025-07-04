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
	char *t17;
	int t2;
	int t20;
	int t21;
	int t22;
	char *t23;
	int t24;
	int t25;
	int t26;
	int t27;
	char *t28;
	int t29;
	int t3;
	int t30;
	int t31;
	int t32;
	char *t33;
	int t36;
	int t37;
	int t38;
	int t39;
	int t4;
	int t5;
	int t6;
	char *t7;
	int t8;
	int t9;
	int __v0;
	int __v1;
	int __v2;
	char *__v3;
	char *__v4;
	int __v5;
	goto label_main;
label_main:
	t1 = 30;
	__v0 = t1;
	t2 = 20;
	__v1 = t2;
	t3 = 1;
	__v2 = t3;
	t4 = __v0;
	t5 = 20;
	t6 = t4 < t5;
	char *origem;
	origem = (char *) malloc(300); 
	strcpy(origem, "A é menor que 20");
	t8 = 0;
	t9 = 0;
label_inicio_0:
	t10 = origem[t8] == '\0';
	if (t10) goto label_fim_0;
	t9 = t9 + 1;
	t8 = t8 + 1;
	goto label_inicio_0;
label_fim_0:
	free(origem);
	t11 = t9 + 1;
	t7 = (char *) malloc(t11);
	strcpy(t7,"A é menor que 20");
	origem = (char *) malloc(300); 
	strcpy(origem, "A é maior que 20");
	t13 = 0;
	t14 = 0;
label_inicio_1:
	t15 = origem[t13] == '\0';
	if (t15) goto label_fim_1;
	t14 = t14 + 1;
	t13 = t13 + 1;
	goto label_inicio_1;
label_fim_1:
	free(origem);
	t16 = t14 + 1;
	t12 = (char *) malloc(t16);
	strcpy(t12,"A é maior que 20");
	if (t6) goto tern_true_17;
	t17 = (char *) malloc(t16);
	strcpy(t17, t12);
	goto tern_end_18;
tern_true_17:
	t17 = (char *) malloc(t11);
	strcpy(t17, t7);
tern_end_18:
	__v3 = (char *) malloc(t16);
	strcpy(__v3, t17);
	 cout << __v3 << endl;
	t20 = __v1;
	t21 = 10;
	t22 = t20 > t21;
	origem = (char *) malloc(300); 
	strcpy(origem, "B é maior que 10");
	t24 = 0;
	t25 = 0;
label_inicio_2:
	t26 = origem[t24] == '\0';
	if (t26) goto label_fim_2;
	t25 = t25 + 1;
	t24 = t24 + 1;
	goto label_inicio_2;
label_fim_2:
	free(origem);
	t27 = t25 + 1;
	t23 = (char *) malloc(t27);
	strcpy(t23,"B é maior que 10");
	origem = (char *) malloc(300); 
	strcpy(origem, "B é menor que 10");
	t29 = 0;
	t30 = 0;
label_inicio_3:
	t31 = origem[t29] == '\0';
	if (t31) goto label_fim_3;
	t30 = t30 + 1;
	t29 = t29 + 1;
	goto label_inicio_3;
label_fim_3:
	free(origem);
	t32 = t30 + 1;
	t28 = (char *) malloc(t32);
	strcpy(t28,"B é menor que 10");
	if (t22) goto tern_true_33;
	t33 = (char *) malloc(t32);
	strcpy(t33, t28);
	goto tern_end_34;
tern_true_33:
	t33 = (char *) malloc(t27);
	strcpy(t33, t23);
tern_end_34:
	__v4 = (char *) malloc(t32);
	strcpy(__v4, t33);
	 cout << __v4 << endl;
	t36 = __v2;
	t37 = 1;
	t38 = 0;
	if (t36) goto tern_true_39;
	t39 = t38;
	goto tern_end_40;
tern_true_39:
	t39 = t37;
tern_end_40:
	__v5 = t39;
	 cout << __v5 << endl;
end_main:
	free(__v3);
	free(__v4);
	free(t12);
	free(t17);
	free(t23);
	free(t28);
	free(t33);
	free(t7);
	return 0;
}