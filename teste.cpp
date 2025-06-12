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
	int t20;
	int t21;
	float t22;
	int t23;
	int t24;
	float t25;
	bool t26;
	Var* t27;
	int t28;
	int t29;
	Var* t3;
	float t30;
	bool t31;
	Var* t32;
	int t33;
	int t34;
	float t35;
	bool t36;
	int t37;
	int t38;
	float t39;
	int t4;
	float t40;
	int t41;
	int t42;
	float t43;
	float t44;
	float t45;
	int t46;
	Var* t47;
	int t48;
	int t49;
	int t5;
	float t50;
	bool t51;
	Var* t52;
	int t53;
	int t54;
	float t55;
	bool t56;
	int t57;
	int t58;
	float t59;
	float t6;
	float t60;
	int t61;
	int t62;
	float t63;
	float t64;
	float t65;
	int t66;
	char *t67;
	int t68;
	int t69;
	bool t7;
	int t70;
	int t71;
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
	t66 = !t9;
	if (t66) goto while_fim_1;
while_inicio_2:
	t15 = (Var *) malloc(sizeof(Var));
	t16 = __v1->tipo;
	t17 = t16 == 1;
	if (t17) goto tipo_int_10;
	t18 = t16 == 2;
	if (t18) goto tipo_float_11;
	t19 = t16 == 3;
	if (t19) goto tipo_bool_12;
	goto tipo_default_13;

tipo_int_10:
	t15->tipo = __v1->tipo;
	t15->i = __v1->i;
	goto fim_tipo_14;

tipo_float_11:
	t15->tipo = __v1->tipo;
	t15->f = __v1->f;
	goto fim_tipo_14;

tipo_bool_12:
	t15->tipo = __v1->tipo;
	t15->b = __v1->b;
	goto fim_tipo_14;

tipo_default_13:
	t15->f = 0.0;
	goto fim_tipo_14;

fim_tipo_14:
	t20 = 30;
	t23 = t15->tipo;
	t24 = t23 == 1;
	if (t24) goto tipo_int_15;
	t25 = t23 == 2;
	if (t25) goto tipo_float_16;
	goto tipo_default_18;

tipo_int_15:
	t22 = (float)t15->i;
	goto fim_tipo_19;

tipo_float_16:
	t22 = t15->f;
	goto fim_tipo_19;

tipo_default_18:
	t22 = 0.0;
	goto fim_tipo_19;

fim_tipo_19:
	t21 = t22 < t20;
	t46 = !t21;
	if (t46) goto while_fim_2;
	t27 = (Var *) malloc(sizeof(Var));
	t28 = __v1->tipo;
	t29 = t28 == 1;
	if (t29) goto tipo_int_20;
	t30 = t28 == 2;
	if (t30) goto tipo_float_21;
	t31 = t28 == 3;
	if (t31) goto tipo_bool_22;
	goto tipo_default_23;

tipo_int_20:
	t27->tipo = __v1->tipo;
	t27->i = __v1->i;
	goto fim_tipo_24;

tipo_float_21:
	t27->tipo = __v1->tipo;
	t27->f = __v1->f;
	goto fim_tipo_24;

tipo_bool_22:
	t27->tipo = __v1->tipo;
	t27->b = __v1->b;
	goto fim_tipo_24;

tipo_default_23:
	t27->f = 0.0;
	goto fim_tipo_24;

fim_tipo_24:
	t37 = t27->tipo;
	t38 = t37 == 1;
	if (t38) goto tipo_int_30;
	t39 = t37 == 2;
	if (t39) goto tipo_float_31;
	goto tipo_default_32;

tipo_int_30:
	t40 = (float)t27->i;
	goto fim_tipo_33;

tipo_float_31:
	t40 = t27->f;
	goto fim_tipo_33;

tipo_default_32:
	t40 = 0.0;
	goto fim_tipo_33;

fim_tipo_33:
	t32 = (Var *) malloc(sizeof(Var));
	t33 = __v0->tipo;
	t34 = t33 == 1;
	if (t34) goto tipo_int_25;
	t35 = t33 == 2;
	if (t35) goto tipo_float_26;
	t36 = t33 == 3;
	if (t36) goto tipo_bool_27;
	goto tipo_default_28;

tipo_int_25:
	t32->tipo = __v0->tipo;
	t32->i = __v0->i;
	goto fim_tipo_29;

tipo_float_26:
	t32->tipo = __v0->tipo;
	t32->f = __v0->f;
	goto fim_tipo_29;

tipo_bool_27:
	t32->tipo = __v0->tipo;
	t32->b = __v0->b;
	goto fim_tipo_29;

tipo_default_28:
	t32->f = 0.0;
	goto fim_tipo_29;

fim_tipo_29:
	t41 = t32->tipo;
	t42 = t41 == 1;
	if (t42) goto tipo_int_34;
	t43 = t41 == 2;
	if (t43) goto tipo_float_35;
	goto tipo_default_36;

tipo_int_34:
	t44 = (float)t32->i;
	goto fim_tipo_37;

tipo_float_35:
	t44 = t32->f;
	goto fim_tipo_37;

tipo_default_36:
	t44 = 0.0;
	goto fim_tipo_37;

fim_tipo_37:
	t45 = t40 + t44;
	__v1->tipo = 2;
	__v1->f = t45;
	switch (__v1->tipo) {
		case 1: cout << __v1->i << endl; break;
		case 2: cout << __v1->f << endl; break;
		case 3: cout << __v1->b << endl; break;
		case 4: cout << __v1->c << endl; break;
		case 5: cout << __v1->s << endl; break;
		default: cout << "[ERRO: tipo desconhecido]" << endl; break;
	}
	goto while_inicio_2;
while_fim_2:
	t47 = (Var *) malloc(sizeof(Var));
	t48 = __v0->tipo;
	t49 = t48 == 1;
	if (t49) goto tipo_int_38;
	t50 = t48 == 2;
	if (t50) goto tipo_float_39;
	t51 = t48 == 3;
	if (t51) goto tipo_bool_40;
	goto tipo_default_41;

tipo_int_38:
	t47->tipo = __v0->tipo;
	t47->i = __v0->i;
	goto fim_tipo_42;

tipo_float_39:
	t47->tipo = __v0->tipo;
	t47->f = __v0->f;
	goto fim_tipo_42;

tipo_bool_40:
	t47->tipo = __v0->tipo;
	t47->b = __v0->b;
	goto fim_tipo_42;

tipo_default_41:
	t47->f = 0.0;
	goto fim_tipo_42;

fim_tipo_42:
	t57 = t47->tipo;
	t58 = t57 == 1;
	if (t58) goto tipo_int_48;
	t59 = t57 == 2;
	if (t59) goto tipo_float_49;
	goto tipo_default_50;

tipo_int_48:
	t60 = (float)t47->i;
	goto fim_tipo_51;

tipo_float_49:
	t60 = t47->f;
	goto fim_tipo_51;

tipo_default_50:
	t60 = 0.0;
	goto fim_tipo_51;

fim_tipo_51:
	t52 = (Var *) malloc(sizeof(Var));
	t53 = __v1->tipo;
	t54 = t53 == 1;
	if (t54) goto tipo_int_43;
	t55 = t53 == 2;
	if (t55) goto tipo_float_44;
	t56 = t53 == 3;
	if (t56) goto tipo_bool_45;
	goto tipo_default_46;

tipo_int_43:
	t52->tipo = __v1->tipo;
	t52->i = __v1->i;
	goto fim_tipo_47;

tipo_float_44:
	t52->tipo = __v1->tipo;
	t52->f = __v1->f;
	goto fim_tipo_47;

tipo_bool_45:
	t52->tipo = __v1->tipo;
	t52->b = __v1->b;
	goto fim_tipo_47;

tipo_default_46:
	t52->f = 0.0;
	goto fim_tipo_47;

fim_tipo_47:
	t61 = t52->tipo;
	t62 = t61 == 1;
	if (t62) goto tipo_int_52;
	t63 = t61 == 2;
	if (t63) goto tipo_float_53;
	goto tipo_default_54;

tipo_int_52:
	t64 = (float)t52->i;
	goto fim_tipo_55;

tipo_float_53:
	t64 = t52->f;
	goto fim_tipo_55;

tipo_default_54:
	t64 = 0.0;
	goto fim_tipo_55;

fim_tipo_55:
	t65 = t60 + t64;
	__v0->tipo = 2;
	__v0->f = t65;
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
	char *origem;
	origem = (char *) malloc(300); 
	strcpy(origem, "rafeize");
	t68 = 0;
	t69 = 0;
label_inicio_0:
	t70 = origem[t68] == '\0';
	if (t70) goto label_fim_0;
	t69 = t69 + 1;
	t68 = t68 + 1;
	goto label_inicio_0;
label_fim_0:
	free(origem);
	t71 = t69 + 1;
	t67 = (char *) malloc(t71);
	strcpy(t67,"rafeize");
	__v2 = (Var *) malloc(sizeof(Var));
	__v2->tipo = 5;
	__v2->s = (char *) malloc(t71);
	strcpy(__v2->s,t67);
	switch (__v2->tipo) {
		case 1: cout << __v2->i << endl; break;
		case 2: cout << __v2->f << endl; break;
		case 3: cout << __v2->b << endl; break;
		case 4: cout << __v2->c << endl; break;
		case 5: cout << __v2->s << endl; break;
		default: cout << "[ERRO: tipo desconhecido]" << endl; break;
	}
	free(__v2->s);
	free(t67);
	free(__v0);
	free(__v1);
	free(__v2);
	return 0;
}