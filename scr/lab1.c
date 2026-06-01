#include <stdio.h>
#include "../include/lab1.h"
#include "../include/additional.h"

void lab1_basic() {
    int x;
    int P;

    printf("Enter value x: ");
    scanf("%d", &x);

    P = x*x*x*x - 3*x*x + 11*x - 8;

    printf("result: %d\n", P);
}

void lab1_additional() {
    int x;
    int P;

    printf("Enter value x: ");
    scanf("%d", &x);

    P = cube_of_square(x) - 3*x*x + 11*x - 8;

    printf("result: %d\n", P);
}