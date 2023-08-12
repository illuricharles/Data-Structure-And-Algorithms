#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*first=NULL,*second=NULL, *third = NULL;

void display(struct node *p){
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void createFirst(int a[], int len){
    struct node *temp=NULL,*last=NULL;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for(int i=1;i<len;i++){
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void createSecond(int a[], int len){
    struct node *temp=NULL,*last=NULL;
    second = (struct node*)malloc(sizeof(struct node));
    second->data = a[0];
    second->next = NULL;
    last = second;
    for(int i=1;i<len;i++){
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void merge(struct node *p, struct node *q){
    struct node *last = NULL;
    if(p->data < q->data){
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else {
        third = last = q;
        q = q->next;
        last ->next = NULL;
    }
    
    while(p && q){
        if(p->data<q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    
    if(p){
        last->next = p;
    }
    if(q){
        last->next = q;
    }
}

int main() {
    int a[] = {10,20,40,50,60,1};
    int b[] = {15,18,25,30,55,40,20};
    createFirst(a, 6);
    createSecond(b, 7);
    display(first);
    display(second);
    merge(first, second);
    display(third);
    return 0;
}