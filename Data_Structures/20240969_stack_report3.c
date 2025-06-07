#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

// 연산자 우선수위 설정
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1; // 여는 괄호는 우선순위 비교 대상이 아님
}

// 스택 초기화 함수
void initStack(Stack* s) {
    s->top = -1;
}

// 스택이 비었는지 확인
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 스택이 가득 찼는지 확인
int isFull(Stack* s) {
    return s->top == MAX - 1;
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
        return -1;  // 에러 값
    }
    return s->data[(s->top)--];
}

// 스택의 최상단 요소를 확인 (peek)
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return -1;  // 에러 값
    }
    return s->data[s->top];
}

// 스택 내용 출력
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
        if (isalpha(ch) || isdigit(ch)) {   // 피연산자 - 숫자, 문자
            postfix[j++] = ch;
        }
        else if (ch == '(') {               // 여는 괄호
            push(&s, ch);
        }
        else if (ch == ')') {               // 닫는 괄호
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else {                              // 연산자
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

    printf("중위표기식 입력 : ");
    scanf("%s", infix);
    result = infixToPostfix(infix, postfix);
    
    printf("후위표기식 : %s\n", postfix);
    printf("후위표기식 계산 결과 : %d\n", result);

    return 0;
}