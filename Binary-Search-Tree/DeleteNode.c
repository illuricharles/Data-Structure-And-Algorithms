#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node *root = NULL;

struct node *createBinaryTree(struct node *p, int x){
    if(p == NULL){
        struct node *t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->lchild = t->rchild = NULL;
        return t;
    }
    else if(x < p->data){
        p->lchild = createBinaryTree(p->lchild, x);
    }
    else {
        p->rchild = createBinaryTree(p->rchild, x);
    }
    return p;
}

void postorder(struct node *p){
    if(p){
        
        postorder(p->lchild);
        printf("%d ", p->data);
        postorder(p->rchild);
        
        
    }
}

int height(struct node *p){
    int x,y;
    if(p==NULL) {
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    return x>y? x+1: y+1;
}

struct node * inPre(struct node *p){
    while(p && p->rchild != NULL){
        p = p->rchild;
    }
    return p;
}

struct node * inSucc(struct node *p){
    while(p && p->lchild != NULL){
        p = p->lchild;
    }
    return p;
}

struct node *deleteNode(struct node *p, int key){
    struct node *q;
    if(p == NULL){
        return NULL;
    }
    if(p->lchild == NULL && p->rchild == NULL){
        if(p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }
    if(key < p->data){
        p->lchild = deleteNode(p->lchild, key);
    }
    else if(key > p->data){
        p->rchild = deleteNode(p->rchild, key);
    }
    else {
        if(height(p->lchild) > height(p->rchild)){
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = deleteNode(p->lchild, key);
        }
        else {
            q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = deleteNode(p->rchild, key);
        }
    }
    return p;
}

int main() {
    struct node *root = createBinaryTree(root, 10);
    root = createBinaryTree(root, 5);
    root = createBinaryTree(root, 13);
    root = createBinaryTree(root, 7);
   deleteNode(root, 5);
    postorder(root);
    
    return 0;
}