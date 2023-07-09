#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void fft(double complex *, register int);
void ifft(double complex *, register int);

int main(void) {
    int n; scanf("%d", &n);
    double complex *x = malloc(n * sizeof(double complex));
    for (int i = 0; i < n; i++) {
        double re, im;
        scanf("%lf%lf", &re, &im);
        x[i] = re + im * I;
    }
    fft(x, n);
    for (int i = 0; i < n; i++) {
        printf("%lf %lf\n", creal(x[i]), cimag(x[i]));
    }
    ifft(x, n);
    for (int i = 0; i < n; i++) {
        printf("%lf %lf\n", creal(x[i]), cimag(x[i]));
    }
    return 0;
}

void fft(double complex *x, register int n) {
    if (n == 1) {
        return;
    }
    n >>= 1;
    double complex *e = malloc(n * sizeof(double complex));
    double complex *o = malloc(n * sizeof(double complex));
    for (int i = 0; i < n; i++) {
        e[i] = x[2 * i];
        o[i] = x[2 * i + 1];
    }
    fft(e, n);
    fft(o, n);
    for (int i = 0; i < n; i++) {
        double complex t = cexp(-M_PI * i * I / n) * o[i];
        x[i] = e[i] + t;
        x[i + n] = e[i] - t;
    }
    free(e);
    free(o);
    return;
}

void ifft(double complex *x, register int n) {
    if (n == 1) {
        return;
    }
    n >>= 1;
    double complex *e = malloc(n * sizeof(double complex));
    double complex *o = malloc(n * sizeof(double complex));
    for (int i = 0; i < n; i++) {
        e[i] = x[2 * i];
        o[i] = x[2 * i + 1];
    }
    ifft(e, n);
    ifft(o, n);
    for (int i = 0; i < n; i++) {
        double complex t = cexp(M_PI * i * I / n) * o[i];
        x[i] = (e[i] + t) / 2;
        x[i + n] = (e[i] - t) / 2;
    }
    free(e);
    free(o);
    return;
}
