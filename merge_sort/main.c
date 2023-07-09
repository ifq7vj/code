#include <stdio.h>
#include <stdlib.h>

void merge(double *, int);

int main(void) {
    int n; scanf("%d", &n);
    double *x = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }
    merge(x, n);
    for (int i = 0; i < n; i++) {
        printf("%lf%c", x[i], i < n - 1? ' ': '\n');
    }
    return 0;
}

void merge(double *x, int n) {
    if (n == 1) {
        return;
    }
    int n1 = n >> 1;
    int n2 = n - n1;
    double *x1 = malloc(n1 * sizeof(double));
    double *x2 = malloc(n2 * sizeof(double));
    for (int i = 0; i < n1; i++) {
        x1[i] = x[i];
    }
    for (int i = 0; i < n2; i++) {
        x2[i] = x[i + n1];
    }
    merge(x1, n1);
    merge(x2, n2);
    for (int i = 0, i1 = 0, i2 = 0; i < n; i++) {
        x[i] = i1 == n1? x2[i2++]: i2 == n2? x1[i1++]:
               x1[i1] <= x2[i2]? x1[i1++]: x2[i2++];
    }
    free(x1);
    free(x2);
    return;
}
