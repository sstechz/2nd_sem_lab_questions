//deleting an element after the given position

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

void delete_pos(struct node *h,int pos){
    if(h==NULL){
        printf("The linked list must not be empty in order to perform deletion operation ");
        return;
    }
    if(pos==1){
        struct node *temp = h;
        h=h->next;
        free(temp);
        printf("The elements of the linked list after deletion are : ");
        printll(h);
        return;
    }

    //keep record of previous node
    //will be needed to change the ->next.

    struct node *prev = h;
    struct node *p = h;
    int c=1;
    for(c=1;c<pos;++c){
        prev=p;
        p=p->next;
    }
    prev->next=p->next;
    free(p);
    printf("The elements of the linked list after deletion are : ");
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

    int k;
    printf("\nEnter the position of linked list to be deleted : ");
    scanf("%d",&k);
    delete_pos(head,k);


    return 3;
}
