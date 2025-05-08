#include <stdio.h>
#include <string.h>
#define MAX 100 // ������ �ִ� ũ�� ����

typedef struct {
	int *data; // �����͸� ������ �迭 (���� �Ҵ�)
	int top; // ������ �ֻ�� ��� �ε���
	int capacity // ������ ���� �뷮
} Stack;

// ���� �ʱ�ȭ �Լ�
void initStack(Stack* s) {
	s->top = -1;
}

// ������ ������� Ȯ��
int isEmpty(Stack* s) {
	return s->top == -1;
}

// ������ ���� á���� Ȯ��
int isFull(Stack* s) {
	return s->top == MAX - 1;
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

int main() {
	Stack s;
	char str[MAX];
	initStack(&s);

	printf("���ڿ� �Է�: ");
	fgets(str, MAX, stdin);
	return 0;
}