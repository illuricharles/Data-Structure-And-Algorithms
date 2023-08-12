#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct queue {
    int size;
    int rear;
    int front;
    struct node **qArr;
};

struct stack{
    int top;
    int size;
    struct node **sArr;
};

struct node *root = NULL;

struct queue* createQueue(int size){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = size;
    q->rear = q->front = 0;
    q->qArr = (struct node **)malloc(sizeof(struct node*)*size);
    return q;
}

void enqueue(struct queue *q, struct node *x){
    if((q->rear+1)%q->size == q->front){
        printf("Full\n");
        return;
    }
    q->rear = (q->rear+1)%q->size;
    q->qArr[q->rear] = x;
    
}


struct node* dequeue(struct queue *q){
    struct node *x = NULL;
    if(q->front == q->rear){
        printf("Empty\n");
        return x;
    }
    q->front = (q->front + 1)%q->size;
    x = q->qArr[q->front];
    return x;
}

int isQueueEmpty(struct queue *q){
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}

void createTree() {
    struct node *p,*t;
    int x;
    struct queue *q = createQueue(10);
    printf("\nEnter root: ");
    scanf("%d", &x);
    root = (struct node*)malloc(sizeof(struct node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(q, root);
    
    while(!isQueueEmpty(q)){
        p = dequeue(q);
        int child_data;
        printf("\nEnter left child of %d: ", p->data);
        scanf("%d", &child_data);
        if(child_data != -1){
            t = (struct node *)malloc(sizeof(struct node));
            t->data = child_data;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(q, t);
        }
        
        printf("\nEnter right child of %d: ", p->data);
        scanf("%d", &child_data);
        if(child_data != -1){
            t = (struct node *)malloc(sizeof(struct node));
            t->data = child_data;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(q, t);
        }
    }
}

void preorder(struct node *p) {
    if(p){
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

struct stack * createStack(int size){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = size;
    s->sArr = (struct node**)malloc(sizeof(struct node*)*size);
    return s;
}

void push(struct stack *s, struct node *p){
    s->top+=1;
    s->sArr[s->top] = p;
}

struct node * pop(struct stack *s){
    struct node *p = s->sArr[s->top];
    s->top = s->top-1;
    return p;
}

void inPreorder(struct node *p){
    struct node *temp;
    struct stack *s = createStack(15);
    while(p || s->top != -1){
        if(p){
            printf("%d ", p->data);
            push(s, p);
            p = p->lchild;
        }
        else {
            p = pop(s);
            p = p->rchild;
        }
    }
    
}

int main() {
    createTree();
    inPreorder(root);
    
    return 0;
}