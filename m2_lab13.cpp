#include <stdio.h>//���������� ������� 
#include <math.h>
#include <locale.h>

#define Na 3
#define Ma 4//���������� ������ ������ 
#define Nb 2
#define Mb 5
//�������� �. ��� ����� ������ 
void input(float* a, int m, int n, char q);
//�������� �. ��� ������������� ������
void vuvid(float* a, int m, int n, char q);
//�������� �. ��� ���������
void sum(float* a, int m, int n, float* res);

int main() {
    //������������ ����������
    setlocale(LC_CTYPE, "ukr");
    //���������� ������ 
    float a[Ma][Na], b[Mb][Nb];
    //������ ��� ���������� ����������
    float res_a[Ma] = { 0.0 };
    float res_b[Mb] = { 0.0 };

    //������������ �. ��� ���������� ������ 
    input((float*)a, Ma, Na, 'a');
    input((float*)b, Mb, Nb, 'b');
    //������������ �. ��� ����������� ������ 
    vuvid((float*)a, Ma, Na, 'a');
    vuvid((float*)b, Mb, Nb, 'b');
    //������������ �. ��� ��������� ��� ��� ������� ������ 
    sum((float*)a, Ma, Na, &res_a);
    sum((float*)b, Mb, Nb, &res_b);
    //��������� ���������� ��� ������ �
    printf("���� ���������� �������i� � ������ ������i a:\n");
    for (int i = 0; i < Ma; i++) {
        printf("  ����� %i: %.2f\n", i + 1, res_a[i]); // Use %.2f to display with 2 decimal places
    }
    //��������� ���������� ��� ������ b
    printf("���� ���������� �������i� � ������ ������i b:\n");
    for (int i = 0; i < Mb; i++) {
        printf("  ����� %i: %.2f\n", i + 1, res_b[i]);
    }

    return 0;
}
//����������� �. ��� ���������� ������
void input(float* a, int m, int n, char q) {
    printf("����� %c \n", q);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("����i�� %c [%i][%i] = ", q, i + 1, j + 1);
            scanf_s("%f", &a[i * n + j]); // Changed from scanf_s to scanf
        }
    }
}
//����������� �. ��� ��������� ��� ���������� �������� ������� �����
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
//���������� �. ��� ������������� ������
void vuvid(float* a, int m, int n, char q) {
    printf("����� %c \n", q);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", a[i * n + j]);
        }
        printf("\n");
    }
}
