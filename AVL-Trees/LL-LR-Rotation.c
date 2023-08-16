#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
}*root = NULL;

int nodeHeight(struct node *p){
    int hl, hr;
    hl = p && p->lchild? p->lchild->height: 0;
    hr = p && p->rchild? p->rchild->height:0;
    
    return hl>hr?hl+1:hr+1;
}

struct node *lrRotation(struct node *p){
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    
    pl->rchild = plr->lchild;
    p ->lchild = plr->rchild;
    
    plr->rchild = p;
    plr->lchild = pl;
    
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    plr->height = nodeHeight(plr);
    if(p == root){
        root = plr;
    }
    return plr;
}

struct node *llRotation(struct node *p){
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    
    
    
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    if( p == root){
        root = pl;
    }
    return pl;
}

int balancedFactor(struct node *p){
    int hl, hr;
    hl = p && p->lchild? p->lchild->height: 0;
    hr = p && p->rchild? p->rchild->height: 0;
    return hl-hr;
}

struct node* createTree(struct node *p, int x){
    if(p == NULL){
        struct node *t = (struct node*)malloc(sizeof(struct node));
        t->data = x;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(x < p ->data){
        p->lchild = createTree(p->lchild, x);
    }
    else {
        p->rchild = createTree(p->rchild, x);
    }
    
    p->height = nodeHeight(p);
    if(balancedFactor(p) == 2 && balancedFactor(p->lchild)  == 1){
        return llRotation(p);
    }
    if(balancedFactor(p) == 2 && balancedFactor(p->lchild) == -1){
        return lrRotation(p);
    }
    return p;
}

void preorder(struct node *p){
    if(p){
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main() {
    root = createTree(root, 50);
    createTree(root, 10);
    createTree(root, 20);
    
    preorder(root);
    printf("\n%d %d", balancedFactor(root), balancedFactor(root->lchild));
    return 0;
    
}