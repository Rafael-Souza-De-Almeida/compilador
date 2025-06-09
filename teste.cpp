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
	char t16;
	char *t17;
	char *t18;
	int t19;
	int t2;
	int t20;
	float t21;
	float t22;
	float t23;
	char *t24;
	int t25;
	int t26;
	int t27;
	int t28;
	char *t29;
	int t3;
	int t30;
	int t31;
	int t32;
	char *t33;
	int t34;
	int t35;
	int t36;
	char *t37;
	int t38;
	char *t39;
	int t4;
	int t40;
	int t41;
	int t42;
	int t43;
	char *t44;
	int t45;
	int t46;
	int t47;
	int t48;
	char *t49;
	int t5;
	int t50;
	char *t51;
	int t52;
	int t53;
	int t54;
	int t55;
	char *t56;
	int t57;
	char *t6;
	int t7;
	int t8;
	int t9;
	char *__v0;
	char *__v1;
	char *__v2;
	float __v3;
	char *__v4;
	char *__v5;
	char *__v6;
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
	strcpy(origem, "Hello world");
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
	strcpy(t11,"Hello world");
	t16 = 'b';
	t18 = (char *) malloc(2);
	t18[0] = t16;
	t18[1] = '\0';
	t19 = t15 + 2;
	t19 = t19 + 1;
	t17 = (char *) malloc(t19);
	strcpy(t17, t11);
	strcat(t17, t18);
	__v2 = (char *) malloc(t19);
	strcpy(__v2,t17);
	t20 = 10;
	t21 = 10.5;
	t23 = (float) t20;
	t22 = t23 + t21;
	__v3 = t22;
	origem = (char *) malloc(300); 
	strcpy(origem, "leo e genio do escopo");
	t25 = 0;
	t26 = 0;
label_inicio_3:
	t27 = origem[t25] == '\0';
	if (t27) goto label_fim_3;
	t26 = t26 + 1;
	t25 = t25 + 1;
	goto label_inicio_3;
label_fim_3:
	free(origem);
	t28 = t26 + 1;
	t24 = (char *) malloc(t28);
	strcpy(t24,"leo e genio do escopo");
	__v4 = (char *) malloc(t28);
	strcpy(__v4,t24);
	 cout << __v4 << endl;
	t30 = 0;
	t31 = 0;
label_inicio_4:
	t32 = __v0[t30] == '\0';
	if (t32) goto label_fim_4;
	t31 = t31 + 1;
	t30 = t30 + 1;
	goto label_inicio_4;
label_fim_4:
	t29 = (char *) malloc(t31);
	strcpy(t29,__v0);
	t34 = 0;
	t35 = 0;
label_inicio_5:
	t36 = __v1[t34] == '\0';
	if (t36) goto label_fim_5;
	t35 = t35 + 1;
	t34 = t34 + 1;
	goto label_inicio_5;
label_fim_5:
	t33 = (char *) malloc(t35);
	strcpy(t33,__v1);
	t38 = t31 + t35;
	t38 = t38 + 1;
	t37 = (char *) malloc(t38);
	strcpy(t37, t29);
	strcat(t37, t33);
	__v5 = (char *) malloc(t38);
	strcpy(__v5,t37);
	origem = (char *) malloc(300); 
	strcpy(origem, "hello world");
	t40 = 0;
	t41 = 0;
label_inicio_6:
	t42 = origem[t40] == '\0';
	if (t42) goto label_fim_6;
	t41 = t41 + 1;
	t40 = t40 + 1;
	goto label_inicio_6;
label_fim_6:
	free(origem);
	t43 = t41 + 1;
	t39 = (char *) malloc(t43);
	strcpy(t39,"hello world");
	origem = (char *) malloc(300); 
	strcpy(origem, "rafita");
	t45 = 0;
	t46 = 0;
label_inicio_7:
	t47 = origem[t45] == '\0';
	if (t47) goto label_fim_7;
	t46 = t46 + 1;
	t45 = t45 + 1;
	goto label_inicio_7;
label_fim_7:
	free(origem);
	t48 = t46 + 1;
	t44 = (char *) malloc(t48);
	strcpy(t44,"rafita");
	t50 = t43 + t48;
	t50 = t50 + 1;
	t49 = (char *) malloc(t50);
	strcpy(t49, t39);
	strcat(t49, t44);
	origem = (char *) malloc(300); 
	strcpy(origem, "hello");
	t52 = 0;
	t53 = 0;
label_inicio_8:
	t54 = origem[t52] == '\0';
	if (t54) goto label_fim_8;
	t53 = t53 + 1;
	t52 = t52 + 1;
	goto label_inicio_8;
label_fim_8:
	free(origem);
	t55 = t53 + 1;
	t51 = (char *) malloc(t55);
	strcpy(t51,"hello");
	t57 = t50 + t55;
	t57 = t57 + 1;
	t56 = (char *) malloc(t57);
	strcpy(t56, t49);
	strcat(t56, t51);
	__v6 = (char *) malloc(t57);
	strcpy(__v6,t56);
	 cout << __v1 << endl;
	 cout << __v3 << endl;
	 cout << __v2 << endl;
	 cout << __v5 << endl;
	 cout << __v6 << endl;
	free(__v0);
	free(__v1);
	free(__v2);
	free(__v4);
	free(__v5);
	free(__v6);
	free(t1);
	free(t11);
	free(t17);
	free(t18);
	free(t24);
	free(t29);
	free(t33);
	free(t37);
	free(t39);
	free(t44);
	free(t49);
	free(t51);
	free(t56);
	free(t6);
	return 0;
}