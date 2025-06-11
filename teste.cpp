/* Compilador hahaha */
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std; 
int main(void) {
	int t1;
	int t2;
	int t3;
	int t4;
	int t5;
	int t6;
	int __v0;
	int __v1;
	cin >> __v0;
	if (cin.fail()) {
		cerr << "Entrada inválida para tipo int!" << endl;
		exit(1);
	}
	t1 = 1;
	__v1 = t1;
	t2 = __v0;
	t3 = 3;
	t4= t2==t3;
if (!t4) goto fim_else_1;
	t5 = __v0;
	 cout << t5 << endl;
goto fim_if_1;
fim_else_1:
	t6 = __v1;
	 cout << t6 << endl;
fim_if_1:
	return 0;
}