#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
}*head = NULL;

void create(int a[], int len){
    struct node *temp = NULL, *last = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = a[0];
    head->next = NULL;
    last = head;
    for(int i=1;i<len;i++){
        temp = (struct node*)malloc(sizeof(struct node));
        temp->prev = last;
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(struct node *p){
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

int count(struct node *p){
    int count = 0;
    while(p != NULL){
        count = count +1;
        p = p->next;
    }
    return count;
}

void insert(int x, int pos){
    struct node *temp = NULL,*p = head;
    
    int cnt = count(head);
    
    if(pos < 1 || pos > cnt+1){
        return;
    }
    
    if(pos == 1){
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x;
        temp->next = head;
        temp->prev = NULL;
        head->prev = temp;
        head=temp;
        return;
    }
    
    if(pos == cnt+1){
        temp = (struct node*)malloc(sizeof(struct node));
        while(p->next != NULL){
            p = p->next;
        }
        temp->data = x;
        temp->prev = p;
        temp->next = NULL;
        p->next = temp;
        return;
    }
    for(int i=1;i<pos-1;i++){
        p = p->next;
    }
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = p->next;
    temp->prev = p;
    p->next->prev=temp;
    p->next = temp;
    return;
    
}

void delete(struct node *p, int pos){
    
    if(pos <1 || pos > count(head)){
        return;
    }
    
    if(pos == 1){
        p = p->next;
        p->prev = NULL;
        head = p;
        return;
    }
    
    int cnt = count(head);
    if(pos == cnt){
        for(int i=1;i<pos-1;i++){
            p = p->next;
        }
        p->next = NULL;
        return;
    }
    
    for(int i=1;i<pos;i++){
        p=p->next;
    }
    
    p->next->prev=p->prev;
    p->prev->next = p->next;
    
}

void reverse(struct node* p){
    struct node *temp = NULL;
    while(p){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p != NULL && p->next == NULL){
            head = p;
        }
    }
    
}

int main() {
    int a[] = {1,2,3,4,5,6};
    int len = 6;
    create(a, len);
    reverse(head);
    display(head);

    return 0;
}

