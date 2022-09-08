//  q2. linear search in double linked list if the tail is given

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int InternId;
    char name[20];
    struct node *next;
    struct node *prev;
}node;

//  very important function for insertion in
//  double linked list
void insert(node **head){
    node *temp=NULL;
    node *previous=*head;
    temp=(node *)malloc(sizeof(node));

    int x;
    printf("InternId : ");
    scanf("%d",&x);

    char y[20];
    printf("Name : ");
    fflush(stdin);
    gets(y);

    temp->InternId=x;
    strcpy(temp->name,y);
    temp->next=*head;
    temp->prev=NULL;

    if(*head!=NULL){
        previous->prev=temp;
    }

    *head=temp;
}

void printll(node *n){
    while(n!=NULL){
        printf("InternId : %d\n",n->InternId);
        printf("Name : ");
        puts(n->name);
        n=n->next;
    }
}

void search(node *tail){
    int x;
    printf("Enter the InternId to be searched for : ");
    scanf("%d",&x);

    while(tail->InternId!=x && tail->prev!=NULL){
        tail=tail->prev;
    }
    if(tail->InternId==x){
        printf("\nIntern Id : %d",tail->InternId);
        printf("\nName : ");
        puts(tail->name);
        return;
    }
    printf("Element not found...");
    return;
}

int main()
{
    node *head=NULL;

    int n;
    printf("Enter the number of nodes to be inserted : ");
    scanf("%d",&n);

    for(int i=0;i<n;++i){
        insert(&head);
    }

    node *tail=head;
    //  here we are at the last tail node
    while(tail->next!=NULL){
        tail=tail->next;
    }

    //  searching if the tail is given
    search(tail);
    //printll(head);

    return 3;
}
