#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STUDENT_COUNT 10

int main() {
    int scores[STUDENT_COUNT];
    int sum = 0;
    float average;

    // ���� �ʱ�ȭ
    srand(time(NULL));

    printf("�л����� ����:\n");

    // ���� �Է� �� �հ� ���
    for (int i = 0; i < STUDENT_COUNT; i++) {
        scores[i] = rand() % 101; // 0 ~ 100 ������ ����
        printf("�л� %d: %d��\n", i + 1, scores[i]);
        sum += scores[i];
    }

    // ��� ���
    average = (float)sum / STUDENT_COUNT;
    printf("\n��ü �л��� ��� ����: %.2f��\n", average);

    return 0;
}
