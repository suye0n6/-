#include <stdio.h>
#define MAX 300

typedef int element;
typedef struct {
    element data[MAX];
    int top;
} Stack;

void initStack(Stack* s)

void initStack(Stack* s){
    s->top=-1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s){
    return s->top == MAX - 1;
}

void push(Stack8 s, element c){
    if(isFull(s)){
        printf("스택이 가득 찼습니다./n ")
    }
}

