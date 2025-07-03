/* Compilador hahaha */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std; 
int main(void) {
	int t1;
	int t2;
	int t3;
	int t4;
	int t5;
	int t6;
	int t7;
	int t8;
	int t9;
	int __v0;
	int __v1;
	goto label_main;
label_main:
	t1 = 20;
	__v0 = t1;
while_inicio_1:
	t2 = __v0;
	t3 = 40;
	t4 = t2 < t3;
	t8 = !t4;
	if (t8) goto while_fim_1;
	t5 = __v0;
	t6 = 20;
	t7 = t5 + t6;
	__v1 = t7;
	goto while_inicio_1;
while_fim_1:
	t9 = __v0;
	 cout << t9 << endl;
end_main:
	return 0;
}