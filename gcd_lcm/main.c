#include <stdbool.h>
#include <stdio.h>

int _gcd(int, int);

int gcd(int, int);
int lcm(int, int);

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("LCM(%d, %d) = %d\n", a, b, lcm(a, b));
    return 0;
}

int _gcd(int a, int b) {
    if (a < b) while (true) {
        if (!a) return b; b %= a;
        if (!b) return a; a %= b;
    } else while (true) {
        if (!b) return a; a %= b;
        if (!a) return b; b %= a;
    }
}

int gcd(int a, int b) {
    a = a < 0? -a: a;
    b = b < 0? -b: b;
    int g = _gcd(a, b);
    return g;
}

int lcm(int a, int b) {
    a = a < 0? -a: a;
    b = b < 0? -b: b;
    int l = a || b? a / _gcd(a, b) * b: 0;
    return l;
}
