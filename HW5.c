#include <stdio.h>
#define SIZE 10

int main(){
    int array [SIZE][SIZE];

    for (int row=0; row<SIZE; row++){
        for (int col=0; col<SIZE; col++){
            array [row][col] = (3*row)-col;
        }
    }

    for (int row=0; row<SIZE; row++){
        for (int col=0; col<SIZE; col++){
            printf("%4d", array[row][col]);
        }
         putchar('\n');
    }
    return 0;
}
