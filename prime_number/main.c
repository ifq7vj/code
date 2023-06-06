#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void prime(int*, int);

int main(void) {
    int n;
    scanf("%d", &n);
    int* p = malloc(n * sizeof(int));
    prime(p, n);

    for (int i = 0; i < n; i++) {
        printf("%d%c", p[i], (i + 1) % 16 && i < n - 1? ' ': '\n');
    }

    return 0;
}

void prime(int* p, int n) {
    p[0] = 2;
    p[1] = 3;

    for (int i = 5, j = 2; j < n; i += 2) {
        bool f = true;

        for (int k = 0, l = sqrt(i); p[k] <= l; k++) {
            if (i % p[k] == 0) {
                f = false;
                break;
            }
        }

        if (f) {
            p[j++] = i;
        }
    }

    return;
}
