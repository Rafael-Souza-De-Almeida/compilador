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
	int __v0;
	int __v1;
	goto label_main;
label_foo:
	t1 = 50;
	__v0 = t1;
	 cout << __v0 << endl;
goto end_foo;

label_main:
	cin >> __v1;
	goto label_foo;
end_foo:
	 cout << __v1 << endl;
end_main:
	return 0;
}