#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *front=NULL;
Node *rear=NULL;

void enqueue(int item){
    Node *node=(Node*)malloc(sizeof(Node));

    //  if the memory is fully occupied(ie queue overflow)
    if(node==NULL){
        printf("Queue Overflow\n");
        return;
    }

    else{
        node->data=item;
        node->next=NULL;

        //  case when for the first time enqueuing
        //  it will only execute for once.
        if(front==NULL){
            front=node;
            rear=node;
        }

        //  condition for normal enqueing
        else{
            rear->next=node;
            rear=node;
        }
        
        //printf("rear->data : %d\n\n",rear->data);
        //printf("front->data : %d\n\n",front->data);
    }
    
}

void dequeue(){
    //  case when Queue is empty.
    if(front==NULL){
        printf("Queue Underflow\n");
    }
    
    else{
        Node *temp=front;
        front=front->next;
        free(temp);
    }
}

void display(){
    Node *ptr=front;
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }printf("\n\n");
}

int main()
{   
    enqueue(1);
    display();

    enqueue(2);
    display();

    enqueue(3);
    display();

    enqueue(4);
    display();

    dequeue();
    display();

    enqueue(5);
    display();

    dequeue();
    display();

    enqueue(6);
    display();

    dequeue();
    display();

    dequeue();
    display();

    enqueue(7);
    display();

    return 3;
}