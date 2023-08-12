#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct queue {
    int size;
    int front;
    int rear;
    int *arr;
};

struct queue* create(int size){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front=q->rear=-1;
    q->size= size;
    q->arr = (int *)malloc(sizeof(int) * size);
    return q;
}

int isFull(struct queue *q){
    if(q->rear == q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int x){
    if(isFull(q)){
        printf("Full\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = x;
    
}

int isEmpty(struct queue *q){
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}

int dequeue(struct queue *q){
    int x = INT_MIN;
    if(isEmpty(q)){
        printf("Empty\n");
        return x;
    }
    q->front++;
    x = q->arr[q->front];
    return x;
}

int main() {
    struct queue *q = create(3);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    return 0;
}