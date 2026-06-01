#include <stdio.h>
#include "../include/lab2.h"

float calculate_sum(int N, float e) {
    float sum = 0.0f;
    float x;
    float y = 1.0f;
    int i = 1;

    do {
        if (i % 2 == 0) {
            x = -(float)i / y;
        } else {
            x = (float)i / y;
        }

        if (i > 1) {
            float abs_x = (x < 0) ? -x : x;
            if (abs_x < e) {
                break;
            }
        }

        sum += x;
        y *= 2.0f;
        i++;

    } while (i <= N);

    return sum;
}

void lab2_basic() {
    float e;
    printf("Vychyslenie summy ryada (float): 1 - 2/2 + 3/4 - 4/8 + ...\n");
    printf("Enter e: ");
    scanf("%f", &e);

    float x = 1;
    float y = 1;
    int i = 1;
    float summa = 0;
    float n = x/y;

    while (n > e)
    {
        n = x/y;
        if (i % 2 ==0)
            summa -= n;
        else
            summa += n;
        x++;
        y*=2;
        i++;
    }
    printf("Result: %f\n", summa);
}

void lab2_additional() {
    int N;
    float e;

    printf("Vychyslenie summy ryada (float): 1 - 2/2 + 3/4 - 4/8 + ...\n");
    printf("Vvedite maksimalnoe colichestvo chlenov N: ");
    scanf("%d", &N);
    printf("Vvedite e: ");
    scanf("%f", &e);

    float result = calculate_sum(N, e);
    printf("\nSumma ryada: %.10f\n", result);
}
