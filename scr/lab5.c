#include <stdio.h>
#include "../include/lab5.h"

void lab5_basic() {
    int arr[10];
    int addr[10];
    int i;
    int even_count = 0;
    int odd_count = 0;

    printf("Enter 10 integers: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++) {
        addr[i] = (int)&arr[i];
        printf("%d", &addr[i]);
    }

    for (i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    if (odd_count < even_count) {
        for (i = 0; i < 10; i++) {
            if (arr[i] % 2 == 1) {
                arr[i] = 0;
            }
        }
    } else {
        for (i = 0; i < 10; i++) {
            if (arr[i] % 2 == 0) {
                arr[i] = 0;
            }
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}

void lab5_additional() {
    int arr[10];
    int i;
    int even_count = 0;
    int odd_count = 0;

    int obnul_znach[10];
    unsigned int obnul_adres[10];
    int skolko = 0;

    printf("Enter 10 integers: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    if (odd_count < even_count) {
        for (i = 0; i < 10; i++) {
            if (arr[i] % 2 == 1) {
                obnul_znach[skolko] = arr[i];
                obnul_adres[skolko] = (unsigned int)&arr[i];
                skolko++;
                arr[i] = 0;
            }
        }
    } else {
        for (i = 0; i < 10; i++) {
            if (arr[i] % 2 == 0) {
                obnul_znach[skolko] = arr[i];
                obnul_adres[skolko] = (unsigned int)&arr[i];
                skolko++;
                arr[i] = 0;
            }
        }
    }

    printf("Obnulennye znacheniya: ");
    for (i = 0; i < skolko; i++) {
        printf("%d ", obnul_znach[i]);
    }
    printf("\n");

    printf("Obnulennye adresa (hex): ");
    for (i = 0; i < skolko; i++) {
        printf("%p ", (void*)obnul_adres[i]);
    }
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}
