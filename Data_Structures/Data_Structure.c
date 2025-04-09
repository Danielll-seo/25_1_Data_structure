#include <stdio.h>
#include <ctype.h>  // isdigit(), isalpha() ���
#include <string.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

// ���� �ʱ�ȭ
void initStack(Stack* s) {
    s->top = -1;
}

// ������ ������� Ȯ��
int isEmpty(Stack* s) {
    return s->top == -1;
}

// ���ÿ� ��� �߰�
void push(Stack* s, int value) {
    s->data[++(s->top)] = value;
}

// ���ÿ��� ��� ����
int pop(Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->data[(s->top)--];
}

// ���� �ֻ�� ��� ��ȯ
int peek(Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->data[s->top];
}

// ������ �켱���� ����
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;  // ���� ��ȣ�� �켱���� �� ��� �ƴ�
}

// ����ǥ����� ����ǥ������� ��ȯ
void infixToPostfix(char* infix) {
    Stack s;
    initStack(&s);
    char postfix[MAX] = "";
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // 1. �ǿ����� (���ĺ� �Ǵ� ����)
        if (isalpha(ch) || isdigit(ch)) {
            postfix[j++] = ch;
        }
        // 2. ���� ��ȣ '('
        else if (ch == '(') {
            push(&s, ch);
        }
        // 3. �ݴ� ��ȣ ')'
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);  // ���� ��ȣ '(' ������ pop
            }
            pop(&s);  // ���� ��ȣ '(' ����
        }
        // 4. ������
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);  // �켱������ ���� �����ڵ��� pop
            }
            push(&s, ch);  // ���� ������ push
        }
    }

    // ���ÿ� ���� �����ڸ� ����ǥ��Ŀ� �߰�
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';

    printf("����ǥ���: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("����ǥ����� �Է��ϼ���: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    return 0;
}