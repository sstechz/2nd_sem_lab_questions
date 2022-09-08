#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert_last(struct node *p,int new_data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=NULL;

    while(p->next!=NULL){
        p=p->next;
    }
    p->next=new_node;

}

void printll(struct node *n){
    while(n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
}

int main()
{
    struct node *head=NULL;
    struct node *second=NULL;      
    struct node *third=NULL;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=8;
    head->next=second;

    second->data=16;
    second->next=third;

    third->data=24;
    third->next=NULL;

    insert_last(head,77);
    printll(head);

    return 3;
}