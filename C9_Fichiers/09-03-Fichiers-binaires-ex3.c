#include <stdio.h>

#define MAXLEN 256
#define MAXSTOCK 80

struct stockItem {
    char brand[MAXLEN];
    char item[MAXLEN];
    int qty;
    float unit, total;
};

int main(int argc, char *argv[]) {
    FILE *f = NULL;
    int count;
    struct stockItem stock[MAXSTOCK];
    if (argc != 2) {
        printf("Usage: %s db_file\n", argv[0]);
        return 1;
    }

    if ((f = fopen(argv[1], "rb")) == NULL) {
        printf("Failed to open %s\n", argv[1]);
        fclose(f);
        return 1;
    }

    if (fread(&count, sizeof(int), 1, f) != 1) {
        printf("Could not read from file !\n");
        fclose(f);
        return 1;
    }

    if (fread(stock, sizeof(struct stockItem), count, f) != count) {
        printf("Could not read from file !\n");
        fclose(f);
        return 1;
    }

    printf("[i] The stock contains %d products:\n", count);
    for (int i = 0; i < count; i++) {
        printf("[i] - row %d: [%s],[%s],[%.2f],[%d],[%.2f]\n", i, stock[i].brand, stock[i].item, stock[i].unit, stock[i].qty, stock[i].total);
    }

    fclose(f);
    return 0;
}
