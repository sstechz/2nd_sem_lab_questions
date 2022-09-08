#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printll(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

void delete(struct node *h){
    if(h == NULL) return;
    else if(h->next == NULL){
        struct node *ptr=h;
        h=NULL;
        free(ptr);
    }
    else{
        struct node* p=h;
        h=h->next;
        free(p);
    }
    printf("\nThe elements after deletion are : ");
    printll(h);
}

int main()
{
    struct node *head=NULL;    
    struct node *second=NULL;
    struct node *third=NULL;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=4;
    head->next=second;

    second->data=8;
    second->next=third;

    third->data=12;
    third->next=NULL;

    printf("The elements before deletion are : ");
    printll(head);
    //delete the first node
    delete(head);
    //printll(head);

    return 3;
}