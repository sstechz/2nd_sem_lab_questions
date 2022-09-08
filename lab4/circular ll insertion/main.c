//  insertion in circular linked lists

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

void printll(node *head){
    node *arrow=head;
    
    do{
        printf("%d ",arrow->data);
        arrow=arrow->next;
    }
    while(arrow!=head);
}

void insertPos(node *head){
    int x;
    printf("\nElement : ");
    scanf("%d",&x);

    int n;
    printf("Position After : ");
    scanf("%d",&n);

    node *trav=head;
    node *temp=NULL;
    temp=(node *)malloc(sizeof(node));

    for(int i=1;i<n;++i){
        trav=trav->next;
    }
    temp->data=x;
    temp->next=trav->next;
    trav->next=temp;

    printf("\nElements after insertion : ");
    printll(head);
}

void insertEnd(node *head){
    int x;
    printf("\nElement : ");
    scanf("%d",&x);

    node *trav=head;
    while(trav->next!=head){
        trav=trav->next;
    }

    node *temp=NULL;
    temp=(node *)malloc(sizeof(node));

    temp->data=x;
    temp->next=trav->next;
    trav->next=temp;

    printf("\nElements after insertion : ");
    printll(head);

    printf("\n\nInsertin at position....");
    insertPos(head);
}

void insertBeg(node *head){
    int x;
    printf("\nElement : ");
    scanf("%d",&x);

    node *trav=head;
    while(trav->next!=head){
        trav=trav->next;
    }

    node *temp=NULL;
    temp=(node *)malloc(sizeof(node));

    temp->data=x;
    temp->next=head;
    trav->next=temp;
    head=temp;

    printf("\nElements after insertion : ");
    printll(head);

    printf("\n\nInsertion at ending....");
    insertEnd(head);
}

int main()
{
    node *head = NULL;
    node *first = NULL;
    node *second = NULL;
    node *third = NULL;

    first=(node*)malloc(sizeof(node));
    second=(node*)malloc(sizeof(node));
    third=(node*)malloc(sizeof(node));

    head=first;
    first->data=4;
    first->next=second;
    second->data=8;
    second->next=third;
    third->data=12;
    third->next=head;

    printf("\n\nElements before insertion : ");
    printll(head);
    printf("\n\nInsertion at beginnig....");
    insertBeg(head);

    return 3;
}
