#include <stdio.h>
int main(void) {
    for (int i = 32; i < 64; ++i) {
        for (int j = i; j < 127; j += 32) {
            printf("hex: '%02x', dec: '%03d', char: '%c'%c",
                   j, j, j, j < 95? '\t': '\n');
        }
    }
    return 0;
}
