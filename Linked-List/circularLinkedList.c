#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*head=NULL;

void createCircularList(int a[], int len){
    struct node *temp = NULL, *last = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = a[0];
    head ->next = head;
    last = head;
    for(int i=1;i<len;i++){
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->next=head;
        last->next=temp;
        last = temp;
    }
}

void display(struct node *p){
    do{
        printf("%d ", p->data);
        p->data;
        p = p->next;
    }while(p != head);
}

void Rdisplay(struct node *p){
    static int flag = 0;
    while(p != head || flag==0){
        flag = 1;
        printf("%d ", p->data);
        p = p->next;
    }
    flag = 0;
}

int count(struct node *p) {
    if(p == NULL){
        return 0;
    }
    int count = 0;
    do{
        count = count + 1;
        p = p->next;
    }while(p != head);
    return count;
}

void insertElement(struct node* p,int x, int pos){
    struct node *temp=NULL;
    
    int cnt = count(head);
    
    if(pos <1 || pos>cnt){
        return;
    }
    
    if(pos == 1){
        while(p->next != head){
            p = p->next;
        }
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x;
        p->next = temp;
        temp->next = head;
        head=temp;
    }
    else {
        for(int i=1;i<pos-1;i++){
            p = p->next;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data = x;
        temp->next = p->next;
        p->next = temp;
    }
}

int deleteElement(int pos){
    struct node *p=head;
    struct node *q = NULL;
    
    int cnt = count(head);
    
    if(pos <1 || pos > cnt){
        return -1;
    }
    
    if(pos == 1){
        while(p->next !=head){
            p = p->next;
        }
        q = head;
        p->next = head->next;
        int x = head->data;
        free(head);
        head = p->next;
        return x;
    }
    for(int i=1;i<pos-1;i++){
        p = p->next;
    }
    q = p->next;
    int x = q->data;
    p->next = q->next;
    free(q);
    return x;
}

int main() {
    int a[] = {1,2,3,4,5};
    int len = 5;
    createCircularList(a, len);
    deleteElement(6);
    display(head);
    return 0;
}