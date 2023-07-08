#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

char *getstr(void);

int main(void) {
    char *str = getstr();
    puts(str);
    free(str);
    return 0;
}

char *getstr(void) {
    char *str = malloc(sizeof(char) << 4);
    assert(str != NULL);
    size_t len = 0, cap = 16; int chr;
    while ((chr = getchar()) != '\n') {
        if (len == cap) {
            str = realloc(str, sizeof(char) * (cap <<= 1));
            assert(str != NULL);
        }
        str[len++] = chr;
    }
    str = realloc(str, sizeof(char) * (len + 1));
    assert(str != NULL);
    str[len] = '\0';
    return str;
}
