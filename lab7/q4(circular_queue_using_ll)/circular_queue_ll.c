#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *ptr=NULL;
Node *front=NULL;
Node *rear=NULL;

void enqueue_frwd(int item){
    ptr=(Node*)malloc(sizeof(Node));

    if(ptr==NULL){
        printf("Queue Overflow\n");
    }
    else{
        ptr->data=item;

        //  insertion for the first time
        if(rear==NULL && front==NULL){
            ptr->next=NULL;
            ptr->prev=NULL;

            rear=front=ptr;
        }
        else{
            ptr->next=NULL;
            ptr->prev=rear;
            rear->next=ptr;
            rear=ptr;
        }
    }

    //printf("%d\n",rear->data);
}

void enqueue_bkwd(int item){
    ptr=(Node*)malloc(sizeof(Node));

    if(ptr==NULL)
        printf("Queue Overflow\n");
    else{
        ptr->data=item;
        
        //  insertion for the first time
        if(front==NULL && rear==NULL){
            ptr->next=NULL;
            ptr->prev=NULL;

            front=rear=ptr;
        }
        else{
            ptr->next=front;
            ptr->prev=NULL;
            front->prev=ptr;
            front=ptr;
        }
        
    }
}

void dequeue_frwd(){
    Node *temp=front;
    (front->next)->prev=NULL;
    front=front->next;
    free(temp);
}

void dequeue_bkwd(){
    Node *temp2=rear;
    (rear->prev)->next=NULL;
    rear=rear->prev;
    free(temp2);
}

void display(){
    Node *trav=front;
    while(trav!=NULL){
        printf("%d",trav->data);
        trav=trav->next;
    }printf("\n\n");
}

int main()
{
    enqueue_frwd(1);
    display();

    enqueue_frwd(2);
    display();

    enqueue_frwd(3);
    display();

    dequeue_frwd();
    display();

    enqueue_frwd(4);
    display();

    enqueue_bkwd(5);
    display();

    dequeue_bkwd();
    display();

    enqueue_bkwd(6);
    display();

    dequeue_bkwd();
    display();

    enqueue_bkwd(7);
    display();

    return 3;
}