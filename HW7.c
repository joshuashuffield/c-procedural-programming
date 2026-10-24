#include <stdio.h>

int globalCounter;

void test();

int main() {
    test();
    test();
    test();
    printf("\nglobal = %d\n", globalCounter);
    return 0;
}

void test() {
    int x;
    static int y;

    globalCounter++;
    x++;
    y++;

    printf("\nx = %d, y = %d, global = %d\n", x, y, globalCounter);
}
