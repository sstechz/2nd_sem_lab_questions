//insertion of elements in double ll

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

void printll(node *n){
    while(n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
}

void insertPos(node *head){
    int x,n;
    printf("\nElement : ");
    scanf("%d",&x);
    printf("Node after position : ");
    scanf("%d",&n);

    node *temp=head;
    node *previous=head;

    //traversing to find the previous element

    for(int i=1;i<n;++i){
        previous=previous->next;
    }

    temp=(node*)malloc(sizeof(node));

    temp->data=x;
    temp->next=previous->next;
    temp->prev=previous;

    previous->next=temp;

    printf("Elements after insertion : ");
    printll(head);

}

void insertEnd(node *head){
    int x;
    printf("\nElements : ");
    scanf("%d",&x);

    node *temp=head;
    node *previous=head;

    temp=(node*)malloc(sizeof(node));

    //traversing to find the last element

    while(previous->next!=NULL){
        previous=previous->next;
    }

    temp->data=x;
    temp->next=NULL;
    temp->prev=previous;

    previous->next=temp;

    printf("Elements after insertion : ");
    printll(head);

    printf("\n\nInsertion at middle....");
    insertPos(head);
}

void insertBeg(node *head){
    int x;
    printf("\nElement : ");
    scanf("%d",&x);

    node *temp=NULL;
    temp=(node*)malloc(sizeof(node));

    temp->data=x;
    temp->next=head;
    temp->prev=NULL;

    head->prev=temp;
    head=temp;

    printf("Elements after insertion : ");
    printll(head);

    printf("\n\nInsertion at end....");
    insertEnd(head);

}

int main()
{
    node *head=NULL;
    node *first=NULL;
    node *second=NULL;
    node *third=NULL;

    first=(node *)malloc(sizeof(node));
    second=(node *)malloc(sizeof(node));
    third=(node *)malloc(sizeof(node));

    first->data=3;
    first->next=second;
    first->prev=NULL;

    second->data=6;
    second->next=third;
    second->prev=first;

    third->data=9;
    third->next=NULL;
    third->prev=second;

    head=first;

    printf("Elements before insertion : ");
    printll(head);
    printf("\n\nInsertion at beginning....");
    insertBeg(head);

    return 3;
}
