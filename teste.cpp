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
	int t10;
	int t11;
	int t12;
	int t13;
	int t14;
	Var* t15;
	int t16;
	bool t17;
	bool t18;
	bool t19;
	char *t2;
	bool t20;
	bool t21;
	int t22;
	int t23;
	int t24;
	Var* t25;
	int t26;
	bool t27;
	bool t28;
	bool t29;
	int t3;
	bool t30;
	bool t31;
	int t32;
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
	float t45;
	float t46;
	float t47;
	float t48;
	float t49;
	int t5;
	float t50;
	char *t51;
	int t52;
	char *t53;
	int t54;
	int t55;
	int t56;
	int t57;
	int t58;
	int t59;
	int t6;
	int t60;
	int t61;
	char *t7;
	int t8;
	int t9;
	Var *__v0;
	Var *__v1;
	Var *__v2;
	Var *__v3;
	t1 = 30;
	__v0 = (Var *) malloc(sizeof(Var));
	__v0->tipo = 1;
	__v0->i = t1;
	char *origem;
	origem = (char *) malloc(300); 
	strcpy(origem, "touh");
	t3 = 0;
	t4 = 0;
label_inicio_0:
	t5 = origem[t3] == '\0';
	if (t5) goto label_fim_0;
	t4 = t4 + 1;
	t3 = t3 + 1;
	goto label_inicio_0;
label_fim_0:
	free(origem);
	t6 = t4 + 1;
	t2 = (char *) malloc(t6);
	strcpy(t2,"touh");
	__v1 = (Var *) malloc(sizeof(Var));
	__v1->tipo = 5;
	__v1->s = (char *) malloc(t6);
	strcpy(__v1->s,t2);
	origem = (char *) malloc(300); 
	strcpy(origem, "pericles");
	t8 = 0;
	t9 = 0;
label_inicio_1:
	t10 = origem[t8] == '\0';
	if (t10) goto label_fim_1;
	t9 = t9 + 1;
	t8 = t8 + 1;
	goto label_inicio_1;
label_fim_1:
	free(origem);
	t11 = t9 + 1;
	t7 = (char *) malloc(t11);
	strcpy(t7,"pericles");
	__v2 = (Var *) malloc(sizeof(Var));
	__v2->tipo = 5;
	__v2->s = (char *) malloc(t11);
	strcpy(__v2->s,t7);
	t13 = 0;
	t14 = 10;
	__v3 = (Var *) malloc(sizeof(Var));
	__v3->tipo = 1;
	__v3->i = t13;
for_inicio_1:
	t60 = t14 - 1;
	t61 = __v3->i > t60;
	if (t61) goto for_fim_1;
	t15 = (Var *) malloc(sizeof(Var));
	t16 = __v0->tipo;
	t17 = t16 == 1;
	if (t17) goto tipo_int_0;
	t18 = t16 == 2;
	if (t18) goto tipo_float_1;
	t19 = t16 == 3;
	if (t19) goto tipo_bool_2;
	t20 = t16 == 4;
	if (t20) goto tipo_char_3;
	t21 = t16 == 5;
	if (t21) goto tipo_str_4;
	goto tipo_default_5;

tipo_int_0:
	t15->tipo = __v0->tipo;
	t15->i    = __v0->i;
	goto fim_tipo_6;

tipo_float_1:
	t15->tipo = __v0->tipo;
	t15->f    = __v0->f;
	goto fim_tipo_6;

tipo_bool_2:
	t15->tipo = __v0->tipo;
	t15->b    = __v0->b;
	goto fim_tipo_6;

tipo_char_3:
	t15->tipo = 4;
	t15->c    = __v0->c;
	goto fim_tipo_6;

tipo_str_4:
	t15->tipo = 5;
	t22 = 0;
	t23 = 0;
label_inicio_2:
	t24 = __v0->s[t22] == '\0';
	if (t24) goto label_fim_2;
	t23 = t23 + 1;
	t22 = t22 + 1;
	goto label_inicio_2;
label_fim_2:
	t15->s = (char *) malloc(t23);
	strcpy(t15->s , __v0->s);
	goto fim_tipo_6;

tipo_default_5:
	/* tratamento de tipo inesperado, se necessário */
	goto fim_tipo_6;

fim_tipo_6:
	t25 = (Var *) malloc(sizeof(Var));
	t26 = __v3->tipo;
	t27 = t26 == 1;
	if (t27) goto tipo_int_7;
	t28 = t26 == 2;
	if (t28) goto tipo_float_8;
	t29 = t26 == 3;
	if (t29) goto tipo_bool_9;
	t30 = t26 == 4;
	if (t30) goto tipo_char_10;
	t31 = t26 == 5;
	if (t31) goto tipo_str_11;
	goto tipo_default_12;

tipo_int_7:
	t25->tipo = __v3->tipo;
	t25->i    = __v3->i;
	goto fim_tipo_13;

tipo_float_8:
	t25->tipo = __v3->tipo;
	t25->f    = __v3->f;
	goto fim_tipo_13;

tipo_bool_9:
	t25->tipo = __v3->tipo;
	t25->b    = __v3->b;
	goto fim_tipo_13;

tipo_char_10:
	t25->tipo = 4;
	t25->c    = __v3->c;
	goto fim_tipo_13;

tipo_str_11:
	t25->tipo = 5;
	t32 = 0;
	t33 = 0;
label_inicio_3:
	t34 = __v3->s[t32] == '\0';
	if (t34) goto label_fim_3;
	t33 = t33 + 1;
	t32 = t32 + 1;
	goto label_inicio_3;
label_fim_3:
	t25->s = (char *) malloc(t33);
	strcpy(t25->s , __v3->s);
	goto fim_tipo_13;

tipo_default_12:
	/* tratamento de tipo inesperado, se necessário */
	goto fim_tipo_13;

fim_tipo_13:
	t35 = t15->tipo == 1;
	t36 = t25->tipo == 1;
	if (t35) if (t36) goto op_int_14;
	t37 = t15->tipo == 2;
	t38 = t25->tipo == 2;
	if (t37) if (t38) goto op_float_float_15;
	if (t35) if (t38) goto op_int_float_16;
	if (t37) if (t36) goto op_float_int_17;
	t39 = t15->tipo == 5;
	t40 = t25->tipo == 5;
	if (t39) if (t40) goto op_string_string_18;
	t41 = t15->tipo == 4;
	if (t41) if (t40) goto op_char_string_19;
	t42 = t25->tipo == 4;
	if (t39) if (t42) goto op_string_char_20;
	goto tipo_default_21;

op_int_14:
	t15->tipo = 1;
	t43 = t15->i;
	t44 = t25->i;
	t15->i = t43 + t44;
	goto fim_22;

op_float_float_15:
	t15->tipo = 2;
	t45 = t15->f;
	t46 = t25->f;
	t15->f = t45 + t46;
	goto fim_22;

op_int_float_16:
	t15->tipo = 2;
	t47 = (float)t15->i;
	t48 = t25->f;
	t15->f = t47 + t48;
	goto fim_22;

op_float_int_17:
	t15->tipo = 2;
	t49 = t15->f;
	t50 = (float)t25->i;
	t15->f = t49 + t50;
	goto fim_22;

op_string_string_18:
	t52 = strlen(t15->s) + strlen(t25->s) + 1;
	t51 = (char *) malloc(t52);
	strcpy(t51, t15->s);
	strcat(t51, t25->s);
	free(t15->s);
	t15->s = (char *) malloc(t52);
	t15->tipo = 5;
	t15->s = t51;
	goto fim_22;

op_char_string_19:
	t53 = (char *) malloc(2);
	t53[0] = t15->c;
	t53[1] = '\0';
	t52 = strlen(t53) + strlen(t25->s) + 1;
	t51 = (char *) malloc(t52);
	strcpy(t51, t53);
	strcat(t51, t25->s);
	t15->tipo = 5;
	t15->s = t51;
	goto fim_22;

op_string_char_20:
	t53 = (char *) malloc(2);
	t53[0] = t25->c;
	t53[1] = '\0';
	t52 = strlen(t15->s) + strlen(t53) + 1;
	t51 = (char *) malloc(t52);
	strcpy(t51, t15->s);
	strcat(t51, t53);
	t15->tipo = 5;
	t15->s = t51;
	goto fim_22;

tipo_default_21:
	printf("Erro: tipos incompatíveis na operação\n");
	exit(1);

fim_22:
	__v0->tipo = 0;
	t54 = t15->tipo;
	t55 = t15->tipo == 1;
	if (t55) goto tipo_int_23;
	t56 = t54 == 2;
	if (t56) goto tipo_float_24;
	t57 = t54 == 3;
	if (t57) goto tipo_boolean_25;
	t58 = t54 == 4;
	if (t58) goto tipo_char_26;
	t59 = t54 == 5;
	if (t59) goto tipo_string_27;
	goto fim_tipo_28;

tipo_int_23:
	__v0->tipo = 1;
	__v0->i = t15->i;
	goto fim_tipo_28;

tipo_float_24:
	__v0->tipo = 2;
	__v0->f = t15->f;
	goto fim_tipo_28;

tipo_boolean_25:
	__v0->tipo = 3;
	__v0->b = t15->b;
	goto fim_tipo_28;

tipo_char_26:
	__v0->tipo = 4;
	__v0->c = t15->c;
	goto fim_tipo_28;

tipo_string_27:
	__v0->tipo = 5;
	__v0->s = t15->s;
	goto fim_tipo_28;

fim_tipo_28:
for_incremento_1:
	__v3->i = __v3->i + 1;
	goto for_inicio_1;
for_fim_1:
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
	free(__v1->s);
	free(__v2->s);
	free(__v0);
	free(__v1);
	free(__v2);
	free(__v3);
	return 0;
}