/* Compilador hahaha */
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std; 
int main(void) {
	int t1;
	float t10;
	float t13;
	int t14;
	int t2;
	int t3;
	float t4;
	float t5;
	float t6;
	int t7;
	float t8;
	float t9;
	int __v0;
	float __v1;
	int __v2;
	t1 = 9;
	__v0 = t1;
	t2 = 4;
	__v1 = t2;
	t3 = __v0;
	t4 = __v1;
	t5 = (float) t3;
	t6= t3>t4;
	t7 = __v0;
	t8 = __v1;
	if (t6) goto tern_true_10;
	t13 = t8;
	goto tern_end_11;
tern_true_10:
	t9 = (float) t7;
	t10 = (float) t7;
	t13 = t7;
tern_end_11:
	__v2 = t13;
	t14 = __v2;
	 cout << t14 << endl;
	return 0;
}