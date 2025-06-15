/* Compilador hahaha */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;
struct Var {
    int tipo;
    int i;
    float f;
    int b;
    char c;
    char *s;
};
int main(void) {
	int t1;
	float t10;
	int t11;
	int t12;
	float t13;
	bool t14;
	Var* t15;
	int t16;
	int t17;
	float t18;
	bool t19;
	float t2;
	float t20;
	Var* t21;
	int t22;
	int t23;
	int t24;
	int t25;
	int t26;
	float t27;
	float t28;
	float t29;
	Var* t3;
	float t30;
	float t31;
	float t32;
	int t33;
	int t34;
	int t35;
	int t36;
	int t37;
	int t38;
	int t39;
	int t4;
	int t40;
	int t41;
	int t42;
	int t43;
	int t44;
	int t45;
	int t46;
	int t47;
	char *t48;
	int t49;
	int t5;
	int t50;
	int t51;
	int t52;
	char t53;
	char *t54;
	char *t55;
	int t56;
	int t57;
	char *t58;
	int t59;
	float t6;
	int t60;
	int t61;
	int t62;
	bool t7;
	int t8;
	int t9;
	Var *__v0;
	Var *__v1;
	Var *__v2;
	t1 = 20;
	__v0 = (Var *) malloc(sizeof(Var));
	__v0->tipo = 1;
	__v0->i = t1;
	t2 = 20.5;
	__v1 = (Var *) malloc(sizeof(Var));
	__v1->tipo = 2;
	__v1->f = t2;
while_inicio_1:
	t3 = (Var *) malloc(sizeof(Var));
	t4 = __v0->tipo;
	t5 = t4 == 1;
	if (t5) goto tipo_int_0;
	t6 = t4 == 2;
	if (t6) goto tipo_float_1;
	t7 = t4 == 3;
	if (t7) goto tipo_bool_2;
	goto tipo_default_3;

tipo_int_0:
	t3->tipo = __v0->tipo;
	t3->i = __v0->i;
	goto fim_tipo_4;

tipo_float_1:
	t3->tipo = __v0->tipo;
	t3->f = __v0->f;
	goto fim_tipo_4;

tipo_bool_2:
	t3->tipo = __v0->tipo;
	t3->b = __v0->b;
	goto fim_tipo_4;

tipo_default_3:
	t3->f = 0.0;
	goto fim_tipo_4;

fim_tipo_4:
	t8 = 50;
	t11 = t3->tipo;
	t12 = t11 == 1;
	if (t12) goto tipo_int_5;
	t13 = t11 == 2;
	if (t13) goto tipo_float_6;
	goto tipo_default_8;

tipo_int_5:
	t10 = (float)t3->i;
	goto fim_tipo_9;

tipo_float_6:
	t10 = t3->f;
	goto fim_tipo_9;

tipo_default_8:
	t10 = 0.0;
	goto fim_tipo_9;

fim_tipo_9:
	t9 = t10 < t8;
	t57 = !t9;
	if (t57) goto while_fim_1;
	t15 = (Var *) malloc(sizeof(Var));
	t16 = __v0->tipo;
	t17 = t16 == 1;
	if (t17) goto tipo_int_10;
	t18 = t16 == 2;
	if (t18) goto tipo_float_11;
	t19 = t16 == 3;
	if (t19) goto tipo_bool_12;
	goto tipo_default_13;

tipo_int_10:
	t15->tipo = __v0->tipo;
	t15->i = __v0->i;
	goto fim_tipo_14;

tipo_float_11:
	t15->tipo = __v0->tipo;
	t15->f = __v0->f;
	goto fim_tipo_14;

tipo_bool_12:
	t15->tipo = __v0->tipo;
	t15->b = __v0->b;
	goto fim_tipo_14;

tipo_default_13:
	t15->f = 0.0;
	goto fim_tipo_14;

fim_tipo_14:
	t20 = 20.2;
	t21 = (Var *) malloc(sizeof(Var));
	t21->tipo = 2;
	t21->f = t20;
	t22 = t15->tipo == 1;
	t23 = t21->tipo == 1;
	t24 = 0;
	if (t22) if (t23) t24 = 1;
	if (t24) goto operacao_int_15;
	t33 = t15->tipo == 2;
	t34 = t21->tipo == 2;
	t35 = 0;
	if (t33) if (t34) t35 = 1;
	if (t35) goto operacao_float_float_16;
	t36 = t15->tipo == 1;
	t37 = t21->tipo == 2;
	t38 = 0;
	if (t36) if (t37) t38 = 1;
	if (t38) goto operacao_int_float_16;
	t39 = t15->tipo == 2;
	t40 = t21->tipo == 1;
	t41 = 0;
	if (t39) if (t40) t41 = 1;
	if (t41) goto operacao_float_int_16;
	goto tipo_default_17;
operacao_int_15:
	t15->tipo = 1;
	t25 = t15->i;
	t26 = t21->i;
	t15-> i = t25 + t26;
	goto fim_tipo_18;

operacao_float_float_16:
	t15->tipo = 2;
	t27 = t15->f;
	t28 = t21->f;
	t15->f = t27 + t28;
	goto fim_tipo_18;

operacao_float_int_16:
	t15->tipo = 2;
	t29 = t15->f;
	t30 = (float)t21->i;
	t15->f = t29 + t30;
	goto fim_tipo_18;

operacao_int_float_16:
	t15->tipo = 2;
	t31 = (float)t15->i;
	t32 = t21->f;
	t15->f = t31 + t32;
	goto fim_tipo_18;

tipo_default_17:
	printf("Erro: Tipos incompatíveis na soma\n");
	exit(1);

fim_tipo_18:
	__v0->tipo = 0;
	t42 = t15->tipo;
	t43 = t15->tipo == 1;
	if (t43) goto tipo_int_19;
	t44 = t42 == 2;
	if (t44) goto tipo_float_20;
	t45 = t42 == 3;
	if (t45) goto tipo_boolean_21;
	t46 = t42 == 4;
	if (t46) goto tipo_char_22;
	t47 = t42 == 5;
	if (t47) goto tipo_string_23;
	goto fim_tipo_24;

tipo_int_19:
	__v0->tipo = 1;
	__v0->i = t15->i;
	goto fim_tipo_24;

tipo_float_20:
	__v0->tipo = 2;
	__v0->f = t15->f;
	goto fim_tipo_24;

tipo_boolean_21:
	__v0->tipo = 3;
	__v0->b = t15->b;
	goto fim_tipo_24;

tipo_char_22:
	__v0->tipo = 4;
	__v0->c = t15->c;
	goto fim_tipo_24;

tipo_string_23:
	__v0->tipo = 5;
	__v0->s = t15->s;
	goto fim_tipo_24;

fim_tipo_24:
	char *origem;
	origem = (char *) malloc(300); 
	strcpy(origem, "rafael");
	t49 = 0;
	t50 = 0;
label_inicio_0:
	t51 = origem[t49] == '\0';
	if (t51) goto label_fim_0;
	t50 = t50 + 1;
	t49 = t49 + 1;
	goto label_inicio_0;
label_fim_0:
	free(origem);
	t52 = t50 + 1;
	t48 = (char *) malloc(t52);
	strcpy(t48,"rafael");
	t53 = 'c';
	t55 = (char *) malloc(2);
	t55[0] = t53;
	t55[1] = '\0';
	t56 = t52 + 2;
	t56 = t56 + 1;
	t54 = (char *) malloc(t56);
	strcpy(t54, t48);
	strcat(t54, t55);
	__v1 = (Var *) malloc(sizeof(Var));
	__v1->tipo = 5;
	__v1->s = (char *) malloc(t56);
	strcpy(__v1->s,t54);
	switch (__v0->tipo) {
		case 1: cout << __v0->i << endl; break;
		case 2: cout << __v0->f << endl; break;
		case 3: cout << __v0->b << endl; break;
		case 4: cout << __v0->c << endl; break;
		case 5: cout << __v0->s << endl; break;
		default: cout << "[ERRO: tipo desconhecido]" << endl; break;
	}
	goto while_inicio_1;
while_fim_1:
	switch (__v0->tipo) {
		case 1: cout << __v0->i << endl; break;
		case 2: cout << __v0->f << endl; break;
		case 3: cout << __v0->b << endl; break;
		case 4: cout << __v0->c << endl; break;
		case 5: cout << __v0->s << endl; break;
		default: cout << "[ERRO: tipo desconhecido]" << endl; break;
	}
	switch (__v1->tipo) {
		case 1: cout << __v1->i << endl; break;
		case 2: cout << __v1->f << endl; break;
		case 3: cout << __v1->b << endl; break;
		case 4: cout << __v1->c << endl; break;
		case 5: cout << __v1->s << endl; break;
		default: cout << "[ERRO: tipo desconhecido]" << endl; break;
	}
	origem = (char *) malloc(300); 
	strcpy(origem, "rafeize");
	t59 = 0;
	t60 = 0;
label_inicio_1:
	t61 = origem[t59] == '\0';
	if (t61) goto label_fim_1;
	t60 = t60 + 1;
	t59 = t59 + 1;
	goto label_inicio_1;
label_fim_1:
	free(origem);
	t62 = t60 + 1;
	t58 = (char *) malloc(t62);
	strcpy(t58,"rafeize");
	__v2 = (Var *) malloc(sizeof(Var));
	__v2->tipo = 5;
	__v2->s = (char *) malloc(t62);
	strcpy(__v2->s,t58);
	switch (__v2->tipo) {
		case 1: cout << __v2->i << endl; break;
		case 2: cout << __v2->f << endl; break;
		case 3: cout << __v2->b << endl; break;
		case 4: cout << __v2->c << endl; break;
		case 5: cout << __v2->s << endl; break;
		default: cout << "[ERRO: tipo desconhecido]" << endl; break;
	}
	free(__v2->s);
	free(t48);
	free(t54);
	free(t55);
	free(t58);
	free(__v0);
	free(__v1);
	free(__v2);
	return 0;
}