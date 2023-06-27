#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: <compiler> <source> <object>\n");
        return 1;
    }

    FILE *sfp = fopen(argv[1], "r");
    FILE *ofp = fopen(argv[2], "w");
    int ptr = fgetc(sfp);
    fprintf(ofp, "#include <stdio.h>\n");
    fprintf(ofp, "int main(void) {\n");
    fprintf(ofp, "char array[256];\n");
    fprintf(ofp, "char *ptr = array;\n");

    while (ptr != EOF) {
        int cnt = 0;

        switch (ptr) {
        case '>':
        case '<':
            do {
                cnt += ptr == '>'? 1: ptr == '<'? -1: 0;
                ptr = fgetc(sfp);
            } while (ptr != EOF && !strchr("+-.,[]", ptr));

            fprintf(ofp, "ptr += %d;\n", cnt);
            break;
        case '+':
        case '-':
            do {
                cnt += ptr == '+'? 1: ptr == '-'? -1: 0;
                ptr = fgetc(sfp);
            } while (ptr != EOF && !strchr("><.,[]", ptr));

            fprintf(ofp, "*ptr += %d;\n", cnt);
            break;
        case '.':
            fprintf(ofp, "putchar(*ptr);\n");
            ptr = fgetc(sfp);
            break;
        case ',':
            fprintf(ofp, "*ptr = getchar();\n");
            ptr = fgetc(sfp);
            break;
        case '[':
            fprintf(ofp, "while (*ptr) {\n");
            ptr = fgetc(sfp);
            break;
        case ']':
            fprintf(ofp, "}\n");
            ptr = fgetc(sfp);
            break;
        default:
            ptr = fgetc(sfp);
            break;
        }
    }

    fprintf(ofp, "return 0;\n");
    fprintf(ofp, "}\n");
    return 0;
}
