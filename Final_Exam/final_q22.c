#include <stdio.h>

int someFunction(int a, int b, int c, int rv) {
    rv = -b + (b * b - 4 * a * c) / (2 * a);
    return 0;
}

int main() {
    int first = 6;
    int second = 11;
    int third = 16;
    int fourth = 21;
    someFunction(first, second, third, fourth);
    printf("%d\n", fourth);
    return 0;
}
