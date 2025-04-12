#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Main 함수에 전부 작성
/*
int main() {
    int scores[30]; // 30명의 학생 성적 저장
    int sum = 0;
    double average;
    int studentNumber;

    // 난수 생성 초기화
    srand(time(0));

    // 성적 데이터 초기화
    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101; // 0 ~ 100 사이의 난수 생성
        sum += scores[i];
    }

    // 평균 계산
    average = sum / 30.0;
    printf("학급 평균 점수: %.2f\n", average);

    // 특정 학생 점수 검색
    printf("학생 번호를 입력하세요 (1 ~ 30): ");
    scanf("%d", &studentNumber);

    if (studentNumber >= 1 && studentNumber <= 30) {
        printf("%d번 학생의 점수: %d\n", studentNumber, scores[studentNumber - 1]);
    }
    else {
        printf("유효하지 않은 학생 번호입니다.\n");
    }

    return 0;
}
*/

// 함수를 분리
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수 선언
double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option);

int main() {
    int scores[30];
    int studentNumber;
    double average;

    srand(time(0));

    // 성적 데이터 초기화
    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101; // 0 ~ 100 사이 난수
    }

    // 평균 계산
    average = calculateAverage(scores, 30);
    printf("학급 평균 점수: %.2f\n\n", average);

    // 특정 학생 점수 검색
    printf("학생 번호를 입력하세요 (1 ~ 30): ");
    scanf("%d", &studentNumber);

    int score = getStudentScore(scores, 30, studentNumber);
    if (score != -1) {
        printf("%d번 학생의 점수: %d\n\n", studentNumber, score);
    }
    else {
        printf("유효하지 않은 학생 번호입니다.\n\n");
    }

    // 테스트: printScore 함수 호출
    printf("전체 학생 정보 출력 (옵션 0):\n");
    printScore(scores, 30, average, 0);

    printf("\n평균 이상 학생 정보 출력 (옵션 1):\n");
    printScore(scores, 30, average, 1);

    printf("\n평균 미만 학생 정보 출력 (옵션 2):\n");
    printScore(scores, 30, average, 2);

    return 0;
}

// 평균 계산 함수
double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}

// 특정 학생 점수 검색 함수
int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size) {
        return scores[studentNumber - 1];
    }
    else {
        return -1; // 유효하지 않은 번호
    }
}

// 학생 점수 출력 함수
void printScore(int scores[], int size, double average, int option) {
    for (int i = 0; i < size; i++) {
        int score = scores[i];
        int studentNumber = i + 1;

        if (option == 0) {
            printf("%2d번 학생: %3d점\n", studentNumber, score);
        }
        else if (option == 1 && score >= average) {
            printf("%2d번 학생: %3d점 (평균 이상)\n", studentNumber, score);
        }
        else if (option == 2 && score < average) {
            printf("%2d번 학생: %3d점 (평균 미만)\n", studentNumber, score);
        }
    }
}
