#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert_pos(struct node *h,int new_data,int pos){

    struct node *p=h;

    struct node *new_node=NULL;

    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;

    int c=1;
    while(c<pos){
        p=p->next;
        ++c;
    }
    if(p==NULL){
        printf("The given previous node cannot be NULL");
        return;
    }
    new_node->next=p->next;
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

    head->data=5;
    head->next=second;

    second->data=10;
    second->next=third;

    third->data=15;
    third->next=NULL;

    printf("The elements before insertion : ");
    printll(head);

    int k,l;
    printf("\nEnter the element to be inserted : ");
    scanf("%d",&k);
    printf("Enter the node after which element is to be inserted : ");
    scanf("%d",&l);

    insert_pos(head,k,l);
    printll(head);

    return 3;
}