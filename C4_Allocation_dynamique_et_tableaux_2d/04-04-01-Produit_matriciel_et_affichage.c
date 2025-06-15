#include <stdio.h>
#include <stdarg.h>

#define LINE_COL_SIZE 3

typedef double vec3[LINE_COL_SIZE];
typedef vec3 mat3x3[LINE_COL_SIZE];

void print_mat(const char *format, ...) {
    size_t i = 0;
    va_list args;
    va_start(args, format);
    while (format[i] != '\0') {
        switch (format[i]) {
        case '%':
            switch (format[++i]) {
            case 'm':
                mat3x3 * m = va_arg(args, mat3x3 *);
                printf("[");
                for (int i = 0; i < 3; i++) {
                    if (i) printf(", ");
                    print_mat("%v", m[i]);
                }
                printf("]");
                break;
            case 'v':
                vec3 * v = va_arg(args, vec3 *);
                printf("[");
                for (int i = 0; i < LINE_COL_SIZE; i++) {
                    if (i) printf(", ");
                    printf("%.0lf", v[i]);
                }
                printf("]");
                break;

            default:
                break;
            }
            break;

        default:
            putchar(format[i]);
            break;
        }
        i++;
    }
    va_end(args);
}

int main() {
    mat3x3 m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vec3 v = { 1, 2, 3 };
    vec3 w = { 5, 6, 7 };

    //mat_vec_mult(m, v, w);
    print_mat("%m * %v = %v\n", m, v, w);
}
