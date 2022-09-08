#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert_beg(struct node **h,int new_data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data=new_data;
    new_node->next = *h;
    *h = new_node;
}

void printll(struct node *n){
    while(n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
}

int main()
{
    struct node *head =NULL;
    struct node *second =NULL;
    struct node *third =NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data=2;
    head->next=second;

    second->data=4;
    second->next=third;

    third->data=6;
    third->next=NULL;

    int k;
    printf("Enter the element to be inserted : ");
    scanf("%d",&k);

    insert_beg(&head,k);
    printll(head);

    return 3;
}
