#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stack {
    int top;
    int size;
    int* arr;
};

struct stack* create(int size){
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = size;
    s->arr = (int *)malloc(sizeof(int)*s->size);
    return s;
}

void display(struct stack* s){
    printf("\n");
    for(int i=s->top;i>=0;i--){
        printf("%d " , s->arr[i]);
    }
}

int isFull(struct stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    
    return 0;
}

void push(struct stack *s, int x){
    if(isFull(s)){
        printf("Full\n");
        return;
    }
    s->top = s->top+1;
    s->arr[s->top] = x;
}

void peek(struct stack *s){
    if(s->top == -1){
        printf("Empty\n");
        return;
    }
    printf("%d", s->arr[s->top]);
}

int isEmpty(struct stack *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

int pop(struct stack *s){
    if(isEmpty(s)){
        printf("Empty\n");
        return -1;
    }
    int x = s->arr[s->top];
    s->top=s->top-1;
    return x;
}

int main() {
    struct stack *s = create(5);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    display(s);
    pop(s);
    display(s);
    pop(s);
    pop(s);
    pop(s);
    display(s);
    pop(s);
    peek(s);
    return 0;
}