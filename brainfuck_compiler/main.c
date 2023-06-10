#include <stdio.h>

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
        if (ptr == '>' || ptr == '<') {
            int count = 0;

            while (ptr != EOF && ptr != '+' && ptr != '-' && ptr != '.' && ptr != ',' && ptr != '[' && ptr != ']') {
                if (ptr == '>') count++;
                if (ptr == '<') count--;
                ptr = fgetc(sfp);
            }

            fprintf(ofp, "ptr %c= %d;\n", count < 0? '-': '+', count < 0? -count: count);
            continue;
        }

        if (ptr == '+' || ptr == '-') {
            int count = 0;

            while (ptr != EOF && ptr != '>' && ptr != '<' && ptr != '.' && ptr != ',' && ptr != '[' && ptr != ']') {
                if (ptr == '+') count++;
                if (ptr == '-') count--;
                ptr = fgetc(sfp);
            }

            fprintf(ofp, "*ptr %c= %d;\n", count < 0? '-': '+', count < 0? -count: count);
            continue;
        }

        if (ptr == '.') {
            ptr = fgetc(sfp);
            fprintf(ofp, "putchar(*ptr);\n");
            continue;
        }

        if (ptr == ',') {
            ptr = fgetc(sfp);
            fprintf(ofp, "*ptr = getchar();\n");
            continue;
        }

        if (ptr == '[') {
            ptr = fgetc(sfp);
            fprintf(ofp, "while (*ptr) {\n");
            continue;
        }

        if (ptr == ']') {
            ptr = fgetc(sfp);
            fprintf(ofp, "}\n");
            continue;
        }

        ptr = fgetc(sfp);
    }

    fprintf(ofp, "return 0;\n");
    fprintf(ofp, "}\n");
    return 0;
}
