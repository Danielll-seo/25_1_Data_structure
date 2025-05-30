#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // 스택의 최대 크기 정의

typedef struct {
	int* data; // 데이터를 저장할 배열 (동적 할당)
	int top; // 스택의 최상단 요소 인덱스
	int capacity; // 스택의 현재 용량
} Stack;

// 스택 초기화 함수
void initStack(Stack* s, int initialSize) {
	s->data = (int*)malloc(initialSize * sizeof(int));
	if (s->data == NULL) {
		printf("메모리 할당 실패!\n");
		exit(1);
	}
	s->top = -1;
	s->capacity = initialSize;
}

// 스택이 비었는지 확인
int isEmpty(Stack* s) {
	return s->top == -1;
}

// 스택이 가득 찼는지 확인
int isFull(Stack* s) {
	return s->top == MAX - 1;
}

// 스택 크기 확장
void expandStack(Stack* s) {
	int newCapacity = s->capacity + 5; // 5개식 크기 증가
	int* newData = (int*)realloc(s->data, newCapacity * sizeof(int));
	if (newData == NULL) {
		printf("메모리 재할당 실패!\n");
		exit(1);
	}
	s->data = newData;
	s->capacity = newCapacity;
	printf("스택 용량이 %d로 증가했습니다.\n", s->capacity);
}

// 스택에 요소를 추가 (push)
void push(Stack* s, int value) {
	if (isFull(s)) {
		printf("Stack overflow! Cannot push %d\n", value);
		return;
	}
	s->data[++(s->top)] = value;
}

// 스택에서 요소를 제거 (pop)
int pop(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack underflow! Cannot pop\n");
		return -1; // 에러 값
	}
	return s->data[(s->top)--];
}

// 스택의 최상단 요소를 확인 (peek)
int peek(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is empty!\n");
	}
	return s->data[s->top];
}

// 스택 내용 출력
void display(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is empty\n");
		return;
	}
	printf("Stack contents: ");
	for (int i = 0; i <= s->top; i++) {
		printf("%d", s->data[i]);
	}
	printf("\n");
}

int isMatching(char open, char close) {
	if (open == '(' && close == ')') return 1;
	if (open == '[' && close == ']') return 1;
	if (open == '{' && close == '}') return 1;
	return 0;
}

int main() {
	Stack s;
	char str[MAX];
	initStack(&s, 5);
	int isValid = 1;
	printf("문자열 입력: ");
	fgets(str, MAX, stdin);
	str[strcspn(str, "\n")] = '\0';

	for (int i = 0; str[i] != '\0'; i++) {
		char ch = str[i];
		if (ch == '(' || ch == '[' || ch == '{') {
			push(&s, ch);
		}
		else if (ch == ')' || ch == ']' || ch == '}') {
			if (isEmpty(&s) || !isMatching(pop(&s), ch)) {
				isValid = 0;
				break;
			}
		}
	}
	if (!isEmpty(&s)) isValid = 0;

	if (isValid) printf("유효한 괄호\n");
	else printf("유효하지 않은 괄호\n");

	return 0;
}