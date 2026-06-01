#include "../include/additional.h"

long cube_of_square(int x) {
    long r = x;
    r = r * r;   // x^2
    r = r * r;   // (x^2)^2 = x^4
    return r;
}

int square(int x) {
    return x * x;
}