#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node {
    int data;
    struct node *next;
}*first = NULL, *second = NULL;

void display(){
    struct node *p = first;
    while(p != NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

void create(int a[], int length){
    struct node *last = NULL, *temp = NULL;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for(int i=1;i<length;i++){
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

int countNode(){
    struct node *p = first;
    int count = 0;
    while(p != NULL){
        count = count + 1;
        p = p->next;
    }
    return count;
}

void insertNode(int x, int pos){
    int count = countNode();
    struct node *p = first;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp ->data = x;
    temp ->next = NULL;
    if(pos > count+1 || pos < 1){
        return;
    }
    if(pos == 1){
        temp->next = first;
        first = temp;
        return;
    }
    for(int i=1;i<pos-1;i++){
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
}

int delete(int pos){
    int count = countNode();
    struct node *p=first,*q=NULL;
    q=(struct node*)malloc(sizeof(struct node));
    int x = -1;
    if(pos > count || pos < 1){
        return x;
    }
    
    if(pos == 1){
        first = first->next;
        x = first->data;
        free(p);
    }
    else{
    
    for(int i=1;i<pos;i++){
        q = p;
        p = p->next;
    }

    
    q->next = p->next;
    x = p->data;
    free(p);
    }
    
    return x;
}

int checkSorted() {
    struct node *p = first;
    int current = p->data;
    p = p->next;
    while(p != NULL){
        if(current > p->data){
            return 0;
        }
        current = p->data;
        p = p->next;
    }
    return 1;
}

void removeDuplicatesSorted() {
    struct node *p = first->next;
    struct node *q = first; 
    
    while(p != NULL){
    
    if(q->data != p->data){
        q=p;
        p = p->next;
    }
    else {
        q->next = p->next;
        p = p->next;
    }
    }
    
}

void reverse(){
    struct node *p = first, *q=NULL, *r = NULL;
    
    
    while(p != NULL){
        r = q;
        q= p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverseUsingArray(){
    int *a = (int *)malloc(sizeof(int)*countNode(first));
    int i=0;
    struct node *p = first;
    while(p != NULL){
        a[i] = p->data;
        p = p->next;
        i = i + 1;
    }
    p = first;
    i = i-1;
    while(i>=0){
        p->data  = a[i];
        p = p->next;
        i = i -1;
    }
    
}

void reverseUsingRecursion(struct node*q, struct node *p){
    
    if(p != NULL){
        reverseUsingRecursion(p, p->next);
        p->next = q;
    }
    else {
        first = q;
    }
    
}



int main() {
    int a[] = {10,30,30,40,40,40,50,80};
    int length = 8;
    
    
    
    removeDuplicatesSorted();
    reverseUsingRecursion(NULL, first);
    display();
    
    return 0;
}