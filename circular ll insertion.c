//  insertion of the element
//  in circular linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct node *next;
}node;

void printll(node *head){
    node *n =head;
    do{
        printf("%d ",n->data);
        n=n->next;
    }
    while(n!=head);
}

void insertBeg(node *head){
    int n;
    printf("Element : ");
    scanf("%d ",&n);

    //creating a new node

    node *beg = NULL;
    beg = (node*)malloc(sizeof(node));

    beg->data=n;
    beg->next=head->next;
    head->next=beg;

    fflush(stdout);
    printf("Elements after insertion at beginning : ");
    printll(head);

}

void insert(node *head){
    int k;
    printf("\nPress -1||0||1 for insertion at beginning||position||ending of the circular linked lists : ");
    scanf("%d",&k);

    if(k==-1){
        insertBeg(head);
    }
}

int main()
{
    node *first = NULL;
    node *second = NULL;
    node *third = NULL;

    first=(node*)malloc(sizeof(node));
    second=(node*)malloc(sizeof(node));
    third=(node*)malloc(sizeof(node));

    node *head=first;

    first->next=second;
    first->data=4;
    second->data=8;
    second->next=third;
    third->data=12;
    third->next=head;

    printf("Initial elements of linked lists : ");
    printll(head);

    insert(head);

    return 3;
}
