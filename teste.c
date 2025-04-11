#include <string.h>
#include <stdio.h>
int main(void) {
        int t1;
        float t10;
        float t2;
        float t3;
        float t4;
        float t5;
        float t6;
        float t7;
        float t8;
        float t9;
        float __v1;
        int __v0;
        float __v2;
        t1 = 3;
        __v0 = t1;
        t2 = 2.0;
        t3 = 3.0;
        t4 = t2 + t3;
        __v1 = t4;
        t5 = __v1;
        t6 = 5.0;
        t7 = t5 + t6;
        __v2 = t7;
        t8 = __v2;
        t9 = 8.0;
        t10 = t8 + t9;
        __v2 = t10;

        printf("%d\n %f\n %f\n ", __v0, __v1, __v2);
        return 0;
}