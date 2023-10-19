#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20

typedef char element;

typedef struct {
    element data[STACK_SIZE];
    int top;
} Stack;

// 스택 초기화 함수
void initStack(Stack *s) {
    s->top = -1;
}

// 스택이 가득 찼는지 확인하는 함수
int isFull(Stack *s) {
    return (s->top+1) == STACK_SIZE;
}

// 스택이 비어 있는지 확인하는 함수
int isEmpty(Stack *s) {
    return s->top == -1;
}

// 스택에 데이터를 추가하는 함수
void push(Stack *s, element c) {
    if (isFull(s)) {
        printf("스택이 가득 차 있습니다.\n");
        return;
    }
    s->data[++s->top] = c;
}

// 스택에서 데이터를 꺼내는 함수
element pop(Stack *s) {
    if (isEmpty(s)) {
        printf("스택이 비어 있습니다.\n");
        return '\0'; // 스택이 비어 있을 경우 널 문자를 반환합니다.
    }
    return s->data[s->top--];
}

int main() {
    int i;
    Stack s;
    char str[20];
    printf("문자열 입력 : ");
    scanf("%s", str);

    // 스택 초기화
    initStack(&s);

    // 입력한 문자열을 스택에 문자 단위로 넣기
    for (i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }

    // 스택에서 문자를 빼내어 역순 출력
    printf("거꾸로 출력 : ");
    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
    }

    return 0;
}
