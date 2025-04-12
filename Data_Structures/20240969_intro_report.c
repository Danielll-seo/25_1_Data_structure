#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STUDENT_COUNT 10

int main() {
    int scores[STUDENT_COUNT];
    int sum = 0;
    float average;

    // 난수 초기화
    srand(time(NULL));

    printf("학생들의 성적:\n");

    // 성적 입력 및 합계 계산
    for (int i = 0; i < STUDENT_COUNT; i++) {
        scores[i] = rand() % 101; // 0 ~ 100 사이의 난수
        printf("학생 %d: %d점\n", i + 1, scores[i]);
        sum += scores[i];
    }

    // 평균 계산
    average = (float)sum / STUDENT_COUNT;
    printf("\n전체 학생의 평균 점수: %.2f점\n", average);

    return 0;
}
