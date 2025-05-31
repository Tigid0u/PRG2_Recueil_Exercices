#include <stdio.h>

// *** TODO: counting functions

int countc(FILE *stream) {
    int count = 0;
    while (fgetc(stream) != EOF) count++;
    return count;
}

int countw(FILE *stream) {
    int count = 0;
    char c;
    while ((c = fgetc(stream)) != EOF) {
        if (c == ' ' || c == '\n') count++;
    }
    return count + 1;
}

int countl(FILE *stream) {
    int count = 0;
    char c;
    while ((c = fgetc(stream)) != EOF) {
        if (c == '\n') count++;
    }
    return count + 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

    FILE *fin;

    // *** TODO: open file
    if ((fin = fopen((const char *)argv[1], "r")) == NULL) {
        fprintf(stderr, "File %s not found ! \n", argv[1]);
        return 1;
    }

    // count characters in file
    printf("%s contains %d characters\n", argv[1], countc(fin));

    fseek(fin, 0, SEEK_SET); //put cursor back to begining

    printf("%s contains %d word(s)\n", argv[1], countw(fin));

    fseek(fin, 0, SEEK_SET); //put cursor back to begining

    printf("%s contains %d line(s)\n", argv[1], countl(fin));

    fclose(fin);
    return 0;
}
