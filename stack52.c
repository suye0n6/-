#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10
typedef int element;

// Stack 구조체 정의
typedef struct {
    element data[STACK_SIZE];
    int top;
} Stack;

int isFull( Stack* s);
int isEmpty( Stack* s);
int push( Stack *s, element data);
int pop( Stack* s);
void initStack( Stack* s);

// 스택을 생성하고 초기화
void createStack(Stack *s) {
    s->top = -1;
}

// top 포인터를 -1로 초기화
void initStack(Stack *s) {
    s->top = -1;
}

// 스택이 가득 차 있으면 true 리턴, 아니면 false 리턴
int isFull(Stack *s) {
    return (s->top+1) == STACK_SIZE;
}

// 스택이 비어 있으면 true 리턴, 아니면 false 리턴
int isEmpty(Stack *s) {
    return s->top == -1;
}

// 스택에 데이터를 추가 (Push)
void Push(Stack *s, element data) {
    if (isFull(s)) {
        printf("스택이 가득 차 있습니다.\n");
        return;
    }
    s->data[++s->top] = data;
}

// 스택에서 데이터를 꺼냄 (Pop)
element Pop(Stack *s) {
    if (isEmpty(s)) {
        printf("스택이 비어 있습니다.\n");
        return 0;
    }
    return s->data[s->top--];
}

int main() {
    int menu;
    element data;
    Stack s;
    initStack(&s);

    do {
        printf("1:push, 2:pop, 0:exit : ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("데이터 입력 : ");
                scanf("%d", &data);
                Push(&s, data); // 데이터를 스택에 추가
                break;
            case 2:
                data = Pop(&s); // 스택에서 데이터를 꺼냄
                if (data)
                    printf("pop 데이터 : %d\n", data);
                break;
            case 0:
                break;
            default:
                printf("잘못된 입력입니다.\n");
                break;
        }
    } while (menu);

    return 0;
}
