//insertion in circular ll

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void printll(node *head){
    node *temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);
    printf("\n");
}

void insertBeg(node *q,int data){
    node *temp=q;
    temp=(node*)malloc(sizeof(node));

    temp->data=data;
    temp->next=q->next;
    q->next=temp;

}

void insertPos(node *p,int data,int k){
    if(k==1){
        insertBeg(p,data);
        printf("Linked list after insertion : ");
        printll(p);
        return;
    }

    node *temp=p;
    node *prev=p;

    temp=(node*)malloc(sizeof(node));

    int c=1;
    while(c!=k){
        temp=temp->next;
        prev=prev->next;
        ++c;
    }

    temp->data=data;
    temp->next=prev->next;
    prev->next=temp;

    printf("Linked list after insertion : ");
    printll(p);
    
}

int main()
{
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;

    head = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));

    head->data=3;
    head->next=second;
    second->data=6;
    second->next=third;
    third->data=9;
    third->next=head;

    printf("The linked list before insertion : ");
    printll(head);

    int x,k;
    printf("\nInsert Element : ");
    scanf("%d",&x);

    printf("Position : ");
    scanf("%d",&k);

    insertPos(head,x,k);

    return 3;
}