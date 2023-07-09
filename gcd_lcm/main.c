#include <stdbool.h>
#include <stdio.h>

int gcd(int, int);
int lcm(int, int);

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("LCM(%d, %d) = %d\n", a, b, lcm(a, b));
    return 0;
}

int gcd(int, int);
int lcm(int, int);
static int impl(int, int);

int gcd(int a, int b) {
    a = a < 0? -a: a;
    b = b < 0? -b: b;
    int g = impl(a, b);
    return g;
}

int lcm(int a, int b) {
    a = a < 0? -a: a;
    b = b < 0? -b: b;
    int l = a || b? a / impl(a, b) * b: 0;
    return l;
}

int impl(int a, int b) {
    if (a < b) do {
        if (!a) return b; b %= a;
        if (!b) return a; a %= b;
    } while (true); else do {
        if (!b) return a; a %= b;
        if (!a) return b; b %= a;
    } while (true);
}
