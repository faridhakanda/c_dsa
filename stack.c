// Stack data structure using c language

#include <stdio.h>
#define MAX 5

typedef struct stact {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int data) {
    if (s->top < MAX) {
        s->data[s->top] = data;
        s->top = s->top + 1;
    } else {
        printf("Stack is Full!");
    }
}

int pop(Stack *s) {
    int a;
    if (s->top == 0) {
        printf("Stack is empty ");
        return -1;
    } else {
        s->top = s->top - 1;
        a = s->data[s->top];
    } 
    return a;
}

int main() {
    int a;
    Stack my;
    my.top = 0;

    push(&my, 1);
    push(&my, 2);
    push(&my, 3);
    push(&my, 4);
    push(&my, 5);

    a = pop(&my);
    printf("%d\n", a);

    a = pop(&my);
    printf("%d\n", a);

    a = pop(&my);
    printf("%d\n", a);

    a = pop(&my);
    printf("%d\n", a);

    a = pop(&my);
    printf("%d\n", a);

    return 0;
}