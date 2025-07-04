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
	int t2;
	int t3;
	int t4;
	int t5;
	int t6;
	int t9;
	int __v0;
	int __v1;
	goto label_main;
label_main:
	t1 = 10;
	__v0 = t1;
	t2 = __v0;
	t3 = 5;
	t4 = t2 < t3;
	t5 = __v0;
	t6 = 20;
	if (t4) goto tern_true_6;
	t9 = t6;
	goto tern_end_7;
tern_true_6:
	t9 = t5;
tern_end_7:
	__v1 = t9;
	t10 = __v1;
	 cout << t10 << endl;
	t11 = __v0;
	 cout << t11 << endl;
end_main:
	return 0;
}