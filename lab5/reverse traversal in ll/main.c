//  q1 reverse traversal using recursion

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int BookId;
    int price;
    struct node *next;
}node;

void input(node **head){
    int x,y;
    printf("BookId : ");
    scanf("%d",&x);
    printf("price : ");
    scanf("%d",&y);

    node *temp=NULL;
    temp=(node *)malloc(sizeof(node));
    temp->BookId=x;
    temp->price=y;
    temp->next=*head;
    *head=temp;
}

void printll(node *n){
    while(n!=NULL){
        printf("BookId : %d\n",n->BookId);
        printf("price : %d\n",n->price);
        n=n->next;
    }
}

void back_traverse(node *n){

    //  in recursion one time return will(one time palti)
    //  repeatedly return the previous iteration
    if(n==NULL){
        return;
    }
    back_traverse(n->next);
    printf("BookId : %d\n",n->BookId);
    printf("Price : %d\n\n",n->price);
}

int main()
{
    node *head=NULL;

    int n;
    printf("Enter the no of nodes to be inserted : ");
    scanf("%d",&n);
    printf("\n");

    for(int i=0;i<n;++i){
        input(&head);
    }

    printf("\nReverse Traversal...\n\n");
    back_traverse(head);

    //printll(head);

    return 3;
}
