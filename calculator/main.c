#include <stdbool.h>
#include <stdio.h>

int ptr;

bool consume(int);
int number(void);

int expr(void);    // expr = trem ("+" trem | "-" trem)*
int trem(void);    // trem = unary ("*" unary | "/" unary)*
int unary(void);   // unary = ("+" | "-")? factor
int factor(void);  // factor = number | "(" expr ")"

int main(void) {
    ptr = getchar();
    int num = expr();
    printf("%d\n", num);
    return 0;
}

bool consume(int op) {
    while (ptr == ' ') {
        ptr = getchar();
    }

    if (ptr == op) {
        ptr = getchar();
        return true;
    } else {
        return false;
    }
}

int number(void) {
    while (ptr == ' ') {
        ptr = getchar();
    }

    int num = 0;

    while ('0' <= ptr && ptr <= '9') {
        num = num * 10 + (ptr - '0');
        ptr = getchar();
    }

    return num;
}

int expr(void) {
    int num = trem();

    while (true) {
        if (consume('+')) {
            num += trem();
            continue;
        }

        if (consume('-')) {
            num -= trem();
            continue;
        }

        return num;
    }
}

int trem(void) {
    int num = unary();

    while (true) {
        if (consume('*')) {
            num *= unary();
            continue;
        }

        if (consume('/')) {
            num /= unary();
            continue;
        }

        return num;
    }
}

int unary(void) {
    if (consume('+')) {
        return +factor();
    }

    if (consume('-')) {
        return -factor();
    }

    return factor();
}

int factor(void) {
    if (consume('(')) {
        int num = expr();
        consume(')');
        return num;
    }

    return number();
}
