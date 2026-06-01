#include <stdio.h>
#include "../include/lab4.h"

int isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }
    return 0;
}

int Delete(char word[], int length) {
    int vowels = 0;
    int consonants = 0;

    for (int i = 0; i < length; i++) {
        if (isVowel(word[i])) {
            vowels++;
        } else {
            consonants++;
        }
    }

    if (vowels > consonants) {
        return 1;  // удалить
    }
    return 0;  // оставить
}

void lab4_basic() {
    char str[999];
    char result[999];
    char word[999];
    int resultPos = 0;
    int wordPos = 0;
    int inWord = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            if (!inWord) {
                inWord = 1;
                wordPos = 0;
            }
            word[wordPos] = str[i];
            wordPos++;
        }
        else {
            if (inWord) {
                inWord = 0;

                if (!Delete(word, wordPos)) {
                    for (int j = 0; j < wordPos; j++) {
                        result[resultPos] = word[j];
                        resultPos++;
                    }
                }
                result[resultPos] = str[i];
                resultPos++;
            }
            else {
                result[resultPos] = str[i];
                resultPos++;
            }
        }
    }
    if (inWord) {
        if (!Delete(word, wordPos)) {
            for (int j = 0; j < wordPos; j++) {
                result[resultPos] = word[j];
                resultPos++;
            }
        }
    }

    result[resultPos] = '\0';
    printf("result: %s", result);
}

void lab4_additional() {
    char str[999];
    char result[999];
    char word[999];
    int resultPos = 0;
    int wordPos = 0;
    int inWord = 0;

    FILE *infile;
    FILE *outfile;

    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        printf("Error opening input.txt\n");
        return;
    }
    outfile = fopen("output.txt", "w");
    if (outfile == NULL) {
        printf("Error opening output.txt\n");
        fclose(infile);
        return;
    }

    fgets(str, 999, infile);

    printf("delete: ");

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            if (!inWord) {
                inWord = 1;
                wordPos = 0;
            }
            word[wordPos] = str[i];
            wordPos++;
        }
        else {
            if (inWord) {
                inWord = 0;
                word[wordPos] = '\0';

                if (!Delete(word, wordPos)) {
                    for (int j = 0; j < wordPos; j++) {
                        result[resultPos] = word[j];
                        resultPos++;
                    }
                } else {
                    printf("%s ", word);
                }
                result[resultPos] = str[i];
                resultPos++;
            }
            else {
                result[resultPos] = str[i];
                resultPos++;
            }
        }
    }

    if (inWord) {
        word[wordPos] = '\0';
        if (!Delete(word, wordPos)) {
            for (int j = 0; j < wordPos; j++) {
                result[resultPos] = word[j];
                resultPos++;
            }
        } else {
            printf("%s ", word);
        }
    }

    result[resultPos] = '\0';
    fprintf(outfile, "%s", result);

    fclose(infile);
    fclose(outfile);
}
