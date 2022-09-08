#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *top;

int isempty(node *top){
    if(top==NULL)
        return 1;
    return 0;
}

void push(int item){
    node *ptr=(node*)malloc(sizeof(node));
    ptr->data=item;
    ptr->next=top;
    top=ptr;
}

void pop(){
    if(isempty(top)){
        printf("Stack Underflow\n");
        return;
    }

    //  simply move the top(ie head) node to the next node
    //  and delete the previous node
    node *temp=top;
    top=top->next;
    free(temp);
}

void pop_all(){
    if(top->next==NULL){
        printf("%d",top->data);
        return;
    }
    top=top->next;
    pop_all(top);
}

void display(){
    node *n=top;
    while(n!=NULL){
        printf("%d",n->data);
        n=n->next;
    }printf("\n\n");
}

int main()
{   node *top=NULL;

    push(1);
    display();

    push(2);
    display();

    push(3);
    display();

    pop();
    display();

    push(4);
    display();

    pop();
    display();

    pop();
    display();

    push(5);
    display();

    //  function for pop all
    pop_all();
    

    return 3;
}