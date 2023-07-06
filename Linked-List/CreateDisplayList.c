#include<stdio.h>
#include<stdlib.h>

struct node {
    int data ;
    struct node *next;
}*first = NULL;

void create(int a[], int n) {
    struct node *last, *t;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    
    for(int i=1;i<n;i++){
        t = (struct node *) malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display() {
    struct node *p = first;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int a[] = {1,2,3,4,5};
    
    int n = 5;
    create(a, n);
    display();
    
    
    return 0;
}