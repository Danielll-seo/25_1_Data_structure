#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

// ������ �켱���� ����
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1; // ���� ��ȣ�� �켱���� �� ����� �ƴ�
}

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
        return -1;  // ���� ��
    }
    return s->data[(s->top)--];
}

// ������ �ֻ�� ��Ҹ� Ȯ�� (peek)
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return -1;  // ���� ��
    }
    return s->data[s->top];
}

// ���� ���� ���
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int evalueatePostfix(char* postfix) {
    Stack s;
    initStack((&s));
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            push(&s, ch - '0');
        }
        else {
            int b = pop(&s);
            int a = pop(&s);
            int result;
            switch (ch) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            default:
                printf("error...\n");
                exit(1);
            }
            push(&s, result);
        }
    }
    return pop(&s);
}

int infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalpha(ch) || isdigit(ch)) {   // �ǿ����� - ����, ����
            postfix[j++] = ch;
        }
        else if (ch == '(') {               // ���� ��ȣ
            push(&s, ch);
        }
        else if (ch == ')') {               // �ݴ� ��ȣ
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else {                              // ������
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    while (!isEmpty(&s)) postfix[j++] = pop(&s);
    postfix[j] = '\0';

    return evalueatePostfix(postfix);
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    int result;

    printf("����ǥ��� �Է� : ");
    scanf("%s", infix);
    result = infixToPostfix(infix, postfix);
    
    printf("����ǥ��� : %s\n", postfix);
    printf("����ǥ��� ��� ��� : %d\n", result);

    return 0;
}