#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void fft(double complex *, int);
void ifft(double complex *, int);

int main(void) {
    int n;
    scanf("%d", &n);
    double complex *x = malloc(n * sizeof(double complex));

    for (int i = 0; i < n; i++) {
        double re;
        double im;
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

void fft(double complex *x, int n) {
    if (n == 1) {
        return;
    }

    double complex *e = malloc(n / 2 * sizeof(double complex));
    double complex *o = malloc(n / 2 * sizeof(double complex));

    for (int i = 0; i < n / 2; i++) {
        e[i] = x[2 * i];
        o[i] = x[2 * i + 1];
    }

    fft(e, n / 2);
    fft(o, n / 2);

    for (int i = 0; i < n / 2; i++) {
        double complex w = cexp(-2 * M_PI * I * i / n);
        double complex t = w * o[i];
        x[i] = e[i] + t;
        x[i + n / 2] = e[i] - t;
    }

    free(e);
    free(o);
    return;
}

void ifft(double complex *x, int n) {
    if (n == 1) {
        return;
    }

    double complex *e = malloc(n / 2 * sizeof(double complex));
    double complex *o = malloc(n / 2 * sizeof(double complex));

    for (int i = 0; i < n / 2; i++) {
        e[i] = x[2 * i];
        o[i] = x[2 * i + 1];
    }

    ifft(e, n / 2);
    ifft(o, n / 2);

    for (int i = 0; i < n / 2; i++) {
        double complex w = cexp(2 * M_PI * I * i / n);
        double complex t = w * o[i];
        x[i] = (e[i] + t) / 2;
        x[i + n / 2] = (e[i] - t) / 2;
    }

    free(e);
    free(o);
    return;
}
