#include <stdio.h>
#include "../include/lab3.h"

int is_vowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }
    return 0;
}

int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

void lab3_basic() {
    char c;
    int flag = 0;
    int found = 0;
    int count = 0;

    printf("Enter text (Ctrl+Z to end): ");
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (flag == 1) {
                if (found == 0) {
                    count++;
                }
                flag = 0;
                found = 0;
            }
        } else {
            flag = 1;
            if (is_vowel(c) == 1) {
                found = 1;
            }
        }
    }
    if (flag == 1 && found == 0) {
        count++;
    }
    printf("\n Count of vowel-less words: %d\n", count);
}

void lab3_additional() {
    char c;
    char first_char;
    char last_char;
    int flag = 0;
    int found_vowel = 0;
    int count = 0;

    printf("Enter text (Ctrl+Z to end): ");
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (flag == 1) {
                if (found_vowel == 0 && is_uppercase(first_char) && is_uppercase(last_char)) {
                    count++;
                }
                flag = 0;
                found_vowel = 0;
            }
        } else {
            if (flag == 0) {
                first_char = c;
            }
            flag = 1;
            last_char = c;
            if (is_vowel(c) == 1) {
                found_vowel = 1;
            }
        }
    }
    if (flag == 1 && found_vowel == 0 && is_uppercase(first_char) && is_uppercase(last_char)) {
        count++;
    }
    printf("\n Count: %d\n", count);
}
