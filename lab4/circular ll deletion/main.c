//  deletion in circular linked lists

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

void deletePos(node *head){
    int n;
    printf("\nNode to be deleted : ");
    scanf("%d",&n);

    node *temp=head;
    node *previous=head;

    for(int i=1;i<n;++i){
        temp=temp->next;
    }
    for(int i=1;i<n-1;++i){
        previous=previous->next;
    }

    if(n==1){
        //moved previous pointer to the last node
        //of the circular ll.
        do{
            previous=previous->next;
        }
        while(previous->next!=head);

        previous->next=temp->next;
        head=temp->next;
        free(temp);

        printf("\nElements after deletion : ");
        printll(head);
        return;
    }

    previous->next=temp->next;
    free(temp);

    printf("\nElements after deletion : ");
    printll(head);
}

void deleteEnd(node *head){
    node *temp=head;
    node *previous=head;

    do{
        temp=temp->next;
    }
    while(temp->next!=head);

    while((previous->next)->next!=head){
        previous=previous->next;
    }

    previous->next=temp->next;
    free(temp);

    printf("\nElements after deletion : ");
    printll(head);

    printf("\n\nDeletion at middle....");
    deletePos(head);
}

void deleteBeg(node *head){
    //we need 1st node & last node

    node *temp=head;
    node *last=head;

    do{
        last=last->next;
    }
    while(last->next!=head);

    last->next=temp->next;
    head=temp->next;
    free(temp);


    printf("\nElements after deletion : ");
    printll(head);

    printf("\n\nDeletion at ending....");
    deleteEnd(head);
}

int main()
{
    node *head = NULL;
    node *first = NULL;
    node *second = NULL;
    node *third = NULL;
    node *fourth = NULL;
    node *fifth= NULL;

    first=(node*)malloc(sizeof(node));
    second=(node*)malloc(sizeof(node));
    third=(node*)malloc(sizeof(node));
    fourth=(node*)malloc(sizeof(node));
    fifth=(node*)malloc(sizeof(node));

    head=first;

    first->data=4;
    first->next=second;
    second->data=8;
    second->next=third;
    third->data=12;
    third->next=fourth;
    fourth->data=16;
    fourth->next=fifth;
    fifth->data=20;
    fifth->next=head;


    printf("\n\nElements before deletion : ");
    printll(head);
    printf("\n\nDeletion from beginnig....");
    deleteBeg(head);

    return 3;
}
