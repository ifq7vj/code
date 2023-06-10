#include <stdio.h>

float rsqrt(float);

int main(void) {
    float x;
    scanf("%f", &x);
    float y = rsqrt(x);
    printf("%f\n", y);
    return 0;
}

float rsqrt(float x) {
    const float h = x * .5f;
    long i = *(long *)&x;
    i = 0x5f3759df - (i >> 1);
    x = *(float *)&i;
    x *= 1.5f - h * x * x;
    x *= 1.5f - h * x * x;
    return x;
}
