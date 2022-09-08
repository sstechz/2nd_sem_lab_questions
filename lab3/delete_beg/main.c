//deleting an element from the beginning

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

void delete_beg(struct node *h){
    if(h==NULL){
        printf("The linked list must not be empty in order to perform deletion operation ");
        return;
    }
    struct node *p=h;
    h=h->next;
    free(p);
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
    delete_beg(head);


    return 3;
}
