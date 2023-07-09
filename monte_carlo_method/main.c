#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned int)time(NULL));
    const double r = 1 / (RAND_MAX + 1.);
    int n; scanf("%d", &n);
    int a = 0;
    for (int i = 0; i < n; i++) {
        double x = rand() * r;
        double y = rand() * r;
        a += hypot(x, y) <= 1;
    }
    printf("%lf\n", (double)a * 4 / n);
    return 0;
}
