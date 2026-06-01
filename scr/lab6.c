#include <stdio.h>
#include "../include/lab6.h"

void lab6_basic() {
    int N, K;

    // Ввод размеров массива
    printf("Vvedite stroki N: ");
    scanf("%d", &N);
    printf("Vvedite stolbiki K: ");
    scanf("%d", &K);

    int matrix[N][K];  // двумерный массив размера N x K

    // Заполнение массива
    printf("\nVvedite massiv:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Находим все диагонали и их суммы
    int max_diag = N + K - 1;    // максимальное количество диагоналей в массиве
    int summa[max_diag];         // массив для хранения сумм каждой диагонали
    int start_rows[max_diag];    // координата строки начала каждой диагонали
    int start_cols[max_diag];    // координата столбца начала каждой диагонали
    int lengths[max_diag];       // длина каждой диагонали
    int diag_count = 0;          // счетчик найденных диагоналей

    // Диагонали, начинающиеся с первой строки (строка 0, все столбцы)
    for (int start_col = 0; start_col < K; start_col++) {
        int sum_diag = 0;    // сумма текущей диагонали
        int length = 0;      // длина текущей диагонали
        int i = 0, j = start_col;  // начальные координаты

        // Идем по диагонали вниз-вправо
        while (i < N && j < K) {
            sum_diag = sum_diag + matrix[i][j];
            length++;
            i++;
            j++;
        }

        // Сохраняем данные о найденной диагонали
        summa[diag_count] = sum_diag;
        start_rows[diag_count] = 0;
        start_cols[diag_count] = start_col;
        lengths[diag_count] = length;
        diag_count++;
    }

    // Диагонали, начинающиеся с первого столбца (столбец 0, все строки, кроме первой)
    for (int start_row = 1; start_row < N; start_row++) {
        int sum_diag = 0;        // сумма текущей диагонали
        int length = 0;          // длина текущей диагонали
        int i = start_row, j = 0;  // начальные координаты

        // Идем по диагонали вниз-вправо
        while (i < N && j < K) {
            sum_diag = sum_diag + matrix[i][j];
            length++;
            i++;
            j++;
        }

        // Сохраняем данные о найденной диагонали
        summa[diag_count] = sum_diag;
        start_rows[diag_count] = start_row;
        start_cols[diag_count] = 0;
        lengths[diag_count] = length;
        diag_count++;
    }

    // Поиск диагонали с максимальной суммой
    int max_index = 0;  // индекс диагонали с максимальной суммой (пока первая)
    for (int i = 1; i < diag_count; i++) {
        if (summa[i] > summa[max_index]) {
            max_index = i;  // нашли диагональ с большей суммой
        }
    }

    // Вывод максимальной суммы
    printf("\nmax sum diagonali: %d\n", summa[max_index]);

    // Обнуление диагонали с максимальной суммой
    int row = start_rows[max_index];  // строка начала диагонали
    int col = start_cols[max_index];  // столбец начала диагонали

    for (int i = 0; i < lengths[max_index]; i++) {
        matrix[row + i][col + i] = 0;  // обнуляем каждый элемент диагонали
    }

    // Вывод измененного массива
    printf("\nmassiv posle obnul:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
