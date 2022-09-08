//deletion of elements in double ll

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

void deletePos(node *head){
    int n;
    printf("\nNode to be deleted : ");
    scanf("%d",&n);

    node *temp=head;

    //  previous <-> temp <-> after
    //  arrangement order

    for(int i=1;i<n;++i){
        temp=temp->next;
    }

    //  condition for deletion from beginning
    //  i.e. from 1st node

    if(n==1){
        node *after=head;

        for(int i=1;i<=n;++i){
            after=after->next;
        }

        head=after;
        after->prev=NULL;
        free(temp);

        printf("\nElements after deletion : ");
        printll(head);
        return;
    }

    //  check whether given value of n is the
    //  last node or not

    if(temp->next==NULL){
        node *previous=head;

        for(int i=1;i<n-1;++i){
            previous=previous->next;
        }

        previous->next=NULL;
        free(temp);

        printf("\nElements after deletion : ");
        printll(head);
        return;
    }

    node *previous=head;
    node *after=head;

    for(int i=1;i<=n;++i){
        after=after->next;
    }
    for(int i=1;i<n-1;++i){
        previous=previous->next;
    }

    previous->next=after;
    after->prev=previous;
    free(temp);

    printf("\nElements after deletion : ");
    printll(head);

}

void deleteEnd(node *head){
    node *trav=head;
    node *temp=head;
    node *previous=head;

    //temp is at the last position

    while(temp->next!=NULL){
        temp=temp->next;
    }
    while((trav->next)->next!=NULL){
        trav=trav->next;
    }
    while(((previous->next)->next)->next!=NULL){
        previous=previous->next;
    }

    trav->next=NULL;
    trav->prev=previous;
    previous->next=trav;
    free(temp);

    printf("\nElements after deletion : ");
    printll(head);

    printf("\n\nDeletion at middle....");
    deletePos(head);

}

void deleteBeg(node *head){
    node *temp=head;
    node *trav=head;

    trav=trav->next;
    trav->prev=NULL;
    head=trav;

    free(temp);

    printf("\nElements after deletion : ");
    printll(head);

    printf("\n\nDeletion from ending....");
    deleteEnd(head);
}

int main()
{
    node *head=NULL;
    node *first=NULL;
    node *second=NULL;
    node *third=NULL;
    node *fourth=NULL;
    node *fifth=NULL;

    first=(node *)malloc(sizeof(node));
    second=(node *)malloc(sizeof(node));
    third=(node *)malloc(sizeof(node));
    fourth=(node *)malloc(sizeof(node));
    fifth=(node *)malloc(sizeof(node));


    first->data=3;
    first->next=second;
    first->prev=NULL;

    second->data=6;
    second->next=third;
    second->prev=first;

    third->data=9;
    third->next=fourth;
    third->prev=second;

    fourth->data=12;
    fourth->next=fifth;
    fourth->prev=third;

    fifth->data=15;
    fifth->next=NULL;
    fifth->prev=fourth;

    head=first;

    printf("Elements before deletion : ");
    printll(head);
    printf("\n\nDeletion from beginning....");
    deleteBeg(head);





    return 3;
}
