#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printll(struct node *n){
    while(n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
}

void insert_end(struct node *h,int new_data){
    struct node *new_node=NULL;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=NULL;

    while(h->next!=NULL){
        h=h->next;
    }
    h->next=new_node;
}

int main()
{
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 3;
    head->next = second;

    second->data = 6;
    second->next = third;

    third->data = 9;
    third->next = NULL;

    int k;
    printf("Enter the element to be inserted at the end : ");
    scanf("%d",&k);

    insert_end(head,k);
    printll(head);

    return 3;
}
