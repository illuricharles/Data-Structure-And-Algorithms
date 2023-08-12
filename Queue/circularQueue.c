#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int *arr;
};

struct queue *create(int size){
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = size;
    q->front = q->rear = 0;
    q->arr = (int *)malloc(sizeof(int)*size);
    return q;
}

void enqueue(struct queue *q, int x){
    if((q->rear+1)%q->size == q->front){
        printf("Full\n");
        return;
    }
    
    q->rear = (q->rear+1)%q->size;
    q->arr[q->rear] = x;
}

int dequeue(struct queue *q){
    if(q->front==q->rear){
        printf("Empty\n");
        return -1;
    }
    
    q->front = (q->front+1)%q->size;
    return q->arr[q->front];
}

void display(struct queue *q){
    int i = (q->front+1)%q->size;
    while(i != (q->rear+1)%q->size){
        printf("%d ", q->arr[i]);
        i = (i+1)%q->size;
    }
}

int main() {
    struct queue *q = create(3);
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    enqueue(q, 10);
    enqueue(q, 20);
    display(q);

    return 0;
}