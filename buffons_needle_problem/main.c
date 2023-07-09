#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned int)time(NULL));
    const double r = 1. / ((long)RAND_MAX + 1);
    const double t = 2 * M_PI * r;
    int n; scanf("%d", &n);
    int a = 0;
    for (int i = 0; i < n; i++) {
        double h = rand() * r;
        double d = sin(rand() * t) * .5;
        a += h - d < 0 || 1 <= h + d;
    }
    printf("%lf\n", ((double)n - 1) / a);
    return 0;
}
