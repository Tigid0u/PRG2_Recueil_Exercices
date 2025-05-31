#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 256
#define MAXSTOCK 80

struct stockItem {
    char brand[MAXLEN];
    char item[MAXLEN];
    int qty;
    float unit, total;
};

int main(int argc, char *argv[]) {
    int retval = 0, count = 0;
    FILE *f = NULL, *out = NULL;
    const char out_file_name[] = "out";
    struct stockItem stock[MAXSTOCK];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        retval = 1;
        goto end0;
    }

    if ((f = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Failed to open file %s\n", argv[1]);
        retval = 1;
        goto end1;
    }

    if ((out = fopen(out_file_name, "wb")) == NULL) {
        printf("Failed to open out file ! \n");
        retval = 1;
        goto end2;
    }

    while (fscanf(f, "%99s %99s %f %d %f", stock[count].brand, stock[count].item, &stock[count].unit, &stock[count].qty, &stock[count].total) != EOF) {
        printf("importing %s %s %.2f %d %.2f\n", stock[count].brand, stock[count].item, stock[count].unit, stock[count].qty, stock[count].total);
        count++;
    }

    if (fwrite(&count, sizeof(int), 1, out) != 1) {
        printf("Could not write correctly to outfile !\n");
        goto end2;
    }

    if (fwrite(stock, sizeof(struct stockItem), count, out) != count) {
        printf("Could not write correctly to outfile ! \n");
    }

end2:
    fclose(out);
end1:
    fclose(f);
end0:
    return retval;
}
