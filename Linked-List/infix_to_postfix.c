#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    char *c;
};

struct stack* create(int size){
    struct stack *st = (struct stack*)malloc(sizeof(struct stack));
    st->size = size;
    st->top = -1;
    st->c = (char*)malloc(sizeof(char)*size);
    return st;
}

int isFull(struct stack *st){
    if(st->top == st->size-1){
        return 1;
    }
    return 0;
}

void push(char x, struct stack *st){
    if(isFull(st)){
        printf("Full\n");
        return;
    }
    
    st->top++;
    st->c[st->top] = x;
}

int isEmpty(struct stack *st){
    if(st->top == -1){
        return 1;
    }
    return 0;
}

char pop(struct stack *st){
    if(isEmpty(st)){
        printf("\nEmpty\n");
    }
    
    char x = st->c[st->top];
    st->top--;
    return x;
}

  

int isOperand(char ch){
    return (ch >= 'a' && ch <='z') || (ch >='A' && ch<= 'Z');
}

int prece(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    if(ch == '/' || ch == '*'){
        return 2;
    }
    return 0;
}

void convert(struct stack *st, char *prefix){
    int i=0, j=0;
    char *postfix = (char *)malloc(sizeof(char) * st->size);
    
    while(prefix[i] != '\0'){
        if(isOperand(prefix[i])){
            postfix[j] = prefix[i];
            j++;
            i++;
        }
        
        else {
            if(isEmpty(st)){
                push(prefix[i], st);
                i++;
            }
            else {
                char top = st->c[st->top];
                char current = prefix[i];
                if(prece(current)> prece(top)){
                    push(current, st);
                    i++;
                }
                else {
                    char x = pop(st);
                    postfix[j] = x;
                    j++;
                    
                }
                
            }
            
        }
        
        
    }
    
    while(st->top != -1){
        char x = pop(st);
        postfix[j] = x;
        j++;
    }
    postfix[j] = '\0';

    j = 0;
    while(postfix[j] != '\0'){
        printf("%c", postfix[j]);
        j++;
    }
   
}

int main() {
    char prefix[]="a+b*c-d/e";
    int size = sizeof(prefix)/sizeof(char);
    struct stack *st = create(size);
    convert(st, prefix);
    return 0;
}