#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*front = NULL, *rear = NULL;

void enqueue(int x){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    
    if(front == NULL){
        front = rear = temp;
        return;
    }
    
    rear->next = temp;
    rear = temp;
}

int dequeue(){
    if(front == NULL){
        printf("\nEmpty\n");
        return -1;
    }
    
    struct node *p = front;
    front = front->next;
    int x = p->data;
    free(p);
    return x;
    
}


int main() {
    enqueue(10);
    enqueue(20);
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    return 0;
}