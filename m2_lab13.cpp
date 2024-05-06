#include <stdio.h>//підключення бібліотек 
#include <math.h>
#include <locale.h>

#define Na 3
#define Ma 4//визначення розмірів масивів 
#define Nb 2
#define Mb 5
//прототип ф. для вводу масиву 
void input(float* a, int m, int n, char q);
//прототип ф. для роздрукування масиву
void vuvid(float* a, int m, int n, char q);
//прототип ф. для обрахунків
void sum(float* a, int m, int n, float* res);

int main() {
    //встановлення локалізації
    setlocale(LC_CTYPE, "ukr");
    //оголошення масивів 
    float a[Ma][Na], b[Mb][Nb];
    //масиви для збереження результатів
    float res_a[Ma] = { 0.0 };
    float res_b[Mb] = { 0.0 };

    //використання ф. для заповнення масивів 
    input((float*)a, Ma, Na, 'a');
    input((float*)b, Mb, Nb, 'b');
    //використання ф. для роздкування масивів 
    vuvid((float*)a, Ma, Na, 'a');
    vuvid((float*)b, Mb, Nb, 'b');
    //використання ф. для обрахунків сум для кожного масиву 
    sum((float*)a, Ma, Na, &res_a);
    sum((float*)b, Mb, Nb, &res_b);
    //виведення результатві для масиву а
    printf("Сума позитивних елементiв у рядках матрицi a:\n");
    for (int i = 0; i < Ma; i++) {
        printf("  Рядок %i: %.2f\n", i + 1, res_a[i]); // Use %.2f to display with 2 decimal places
    }
    //виведення результатві для масиву b
    printf("Сума позитивних елементiв у рядках матрицi b:\n");
    for (int i = 0; i < Mb; i++) {
        printf("  Рядок %i: %.2f\n", i + 1, res_b[i]);
    }

    return 0;
}
//визначенння ф. для заповнення масиву
void input(float* a, int m, int n, char q) {
    printf("Масив %c \n", q);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Введiть %c [%i][%i] = ", q, i + 1, j + 1);
            scanf_s("%f", &a[i * n + j]); // Changed from scanf_s to scanf
        }
    }
}
//визначенння ф. для обрахунку сум позитивних елементів кожного рядка
void sum(float* a, int m, int n, float* res) {
    for (int i = 0; i < m; i++) {
        res[i] = 0; 
        for (int j = 0; j < n; j++) {
            if (a[i * n + j] > 0) {
                res[i] += a[i * n + j];
            }
        }
    }
}
//визначення ф. для роздрукування масивів
void vuvid(float* a, int m, int n, char q) {
    printf("Масив %c \n", q);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", a[i * n + j]);
        }
        printf("\n");
    }
}
