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

int main() {
    struct node *root = createBinaryTree(root, 10);
    root = createBinaryTree(root, 11);
    root = createBinaryTree(root, 13);
   
    postorder(root);
    return 0;
}