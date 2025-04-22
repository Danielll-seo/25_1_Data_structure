#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �Լ� ����
double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option);

int main() {
    int scores[30]; // 30���� �л� ���� ����
    int studentNumber;
    double average;

    // ���� ���� �ʱ�ȭ
    srand(time(0));

    // ���� ������ �ʱ�ȭ
    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101; // 0 ~ 100 ���� ����
    }

    // ��� ���
    average = calculateAverage(scores, 30);
    printf("�б� ��� ����: %.2f\n\n", average);

    // Ư�� �л� ���� �˻�
    printf("�л� ��ȣ�� �Է��ϼ��� (1 ~ 30): ");
    scanf("%d", &studentNumber);

    int score = getStudentScore(scores, 30, studentNumber);
    if (score != -1) {
        printf("%d�� �л��� ����: %d\n\n", studentNumber, score);
    }
    else {
        printf("��ȿ���� ���� �л� ��ȣ�Դϴ�.\n\n");
    }

    // �׽�Ʈ: printScore �Լ� ȣ��
    printf("��ü �л� ���� ��� (�ɼ� 0):\n");
    printScore(scores, 30, average, 0);

    printf("\n��� �̻� �л� ���� ��� (�ɼ� 1):\n");
    printScore(scores, 30, average, 1);

    printf("\n��� �̸� �л� ���� ��� (�ɼ� 2):\n");
    printScore(scores, 30, average, 2);

    return 0;
}

// ��� ��� �Լ�
double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}

// Ư�� �л� ���� �˻� �Լ�
int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size) {
        return scores[studentNumber - 1];
    }
    else {
        return -1; // ��ȿ���� ���� ��ȣ
    }
}

// �л� ���� ��� �Լ�
void printScore(int scores[], int size, double average, int option) {
    for (int i = 0; i < size; i++) {
        int score = scores[i];
        int studentNumber = i + 1;

        if (option == 0) {
            printf("%2d�� �л�: %3d��\n", studentNumber, score);
        }
        else if (option == 1 && score >= average) {
            printf("%2d�� �л�: %3d�� (��� �̻�)\n", studentNumber, score);
        }
        else if (option == 2 && score < average) {
            printf("%2d�� �л�: %3d�� (��� �̸�)\n", studentNumber, score);
        }
    }
}
