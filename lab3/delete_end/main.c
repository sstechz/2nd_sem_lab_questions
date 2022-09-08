//deleting an element from the end

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

void delete_end(struct node *h){
    if(h==NULL){
        printf("The linked list must not be empty in order to perform deletion operation ");
        return;
    }

    //keep record of previous node
    //will be needed to change the ->next.

    struct node *p=h;
    struct node *prev=h;
    while(p->next!=NULL){
        prev=p;
        p=p->next;
    }
    free(p);
    prev->next=NULL;

    printf("\nThe elements after deletion are : ");
    printll(h);
}

int main()
{
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third= NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    printf("The elements before deletion are : ");
    printll(head);
    delete_end(head);


    return 3;
}
