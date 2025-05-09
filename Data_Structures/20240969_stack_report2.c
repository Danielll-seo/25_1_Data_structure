#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // ������ �ִ� ũ�� ����

typedef struct {
	int* data; // �����͸� ������ �迭 (���� �Ҵ�)
	int top; // ������ �ֻ�� ��� �ε���
	int capacity; // ������ ���� �뷮
} Stack;

// ���� �ʱ�ȭ �Լ�
void initStack(Stack* s, int initialSize) {
	s->data = (int*)malloc(initialSize * sizeof(int));
	if (s->data == NULL) {
		printf("�޸� �Ҵ� ����!\n");
		exit(1);
	}
	s->top = -1;
	s->capacity = initialSize;
}

// ������ ������� Ȯ��
int isEmpty(Stack* s) {
	return s->top == -1;
}

// ������ ���� á���� Ȯ��
int isFull(Stack* s) {
	return s->top == MAX - 1;
}

// ���� ũ�� Ȯ��
void expandStack(Stack* s) {
	int newCapacity = s->capacity + 5; // 5���� ũ�� ����
	int* newData = (int*)realloc(s->data, newCapacity * sizeof(int));
	if (newData == NULL) {
		printf("�޸� ���Ҵ� ����!\n");
		exit(1);
	}
	s->data = newData;
	s->capacity = newCapacity;
	printf("���� �뷮�� %d�� �����߽��ϴ�.\n", s->capacity);
}

// ���ÿ� ��Ҹ� �߰� (push)
void push(Stack* s, int value) {
	if (isFull(s)) {
		printf("Stack overflow! Cannot push %d\n", value);
		return;
	}
	s->data[++(s->top)] = value;
}

// ���ÿ��� ��Ҹ� ���� (pop)
int pop(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack underflow! Cannot pop\n");
		return -1; // ���� ��
	}
	return s->data[(s->top)--];
}

// ������ �ֻ�� ��Ҹ� Ȯ�� (peek)
int peek(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is empty!\n");
	}
	return s->data[s->top];
}

// ���� ���� ���
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
	printf("���ڿ� �Է�: ");
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

	if (isValid) printf("��ȿ�� ��ȣ\n");
	else printf("��ȿ���� ���� ��ȣ\n");

	return 0;
}