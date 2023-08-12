#include<stdio.h>
#include<stdlib.h>

struct stack {
    int top;
    int size;
    int *arr;
};


struct stack *create(int size){
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = size;
    s->arr = (int *)malloc(sizeof(int) * size);
    return s;
}

void enqueue(struct stack *s1, int x) {
    s1->top++;
    s1->arr[s1->top] = x;
}

int dequeue(struct stack *s1, struct stack *s2){
    int x = -1;
    if(s1->top == -1 && s2->top == -1){
        return -1;
    }
    if(s2->top != -1){
        x = s2->arr[s2->top];
        s2->top--;
        return x;
    }
    
    while(s1->top != -1){
        int temp = s1->arr[s1->top];
        s1->top--;
        s2->top++;
        s2->arr[s2->top] = temp;
    }
    
    x = s2->arr[s2->top] ;
    s2->top--;
    return x;
}


int main() {
    
    struct stack *s1 = create(5);
    struct stack *s2 = create(5);
    
    enqueue(s1, 10);
    enqueue(s1, 20);
    enqueue(s1, 30);
    enqueue(s1, 40);
    enqueue(s1, 50);
    printf("%d", dequeue(s1, s2));
    printf("%d", dequeue(s1, s2));
    printf("%d", dequeue(s1, s2));
    printf("%d", dequeue(s1, s2));
    printf("%d", dequeue(s1, s2));
    printf("%d", dequeue(s1, s2));
    return 0;
}