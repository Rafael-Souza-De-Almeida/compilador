#include <string.h>
#include <stdio.h>
int main(void) {
        int t1;
        float t2;
        float t3;
        int t4;
        float t5;
        float t6;
        int __v0;
        float __v2;
        float __v1;
        t1 = 5;
        __v0 = t1;
        t2 = 2.0;
        __v1 = t2;
        t3 = (float) __v0;
        t4 = 2;
        t5 = (float) t4;
        t6 = t3 + t5;
        __v2 = t6;

        printf("%f", __v2);

        return 0;
}