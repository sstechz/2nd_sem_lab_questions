//  q3. Minimum element in circular linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int StudentId;
    char name[20];
    int marks;
    struct node *next;
}node;

void insert(node **head){
    int x,y;
    char z[20];

    printf("StudentId : ");
    scanf("%d",&x);
    printf("Name : ");
    fflush(stdin);
    gets(z);
    printf("Marks : ");
    scanf("%d",&y);

    node *temp=NULL;
    temp=(node*)malloc(sizeof(node));

    node *tail=*head;
    //tail=(node*)malloc(sizeof(node));

    if(*head==NULL){
        temp->next=temp;
        *head=temp;

        //  tail is at the last node
        tail=temp;
        temp->StudentId=x;
        temp->marks=y;
        strcpy(temp->name,z);
    }
    else{
        while(tail->next!=*head){
            tail=tail->next;
        }

        temp->next=*head;
        *head=temp;
        tail->next=*head;

        temp->StudentId=x;
        temp->marks=y;
        strcpy(temp->name,z);
    }

}

void printll(node *head){
    node *n=head;
    do{
        printf("StudentId : %d\n",n->StudentId);
        printf("Name : ");
        puts(n->name);
        printf("Marks : %d",n->marks);
        n=n->next;
    }
    while(n!=head);
}

void min_marks(node *head){
    node *n=head;
    int min=n->marks;
    int id;
    char name[20];
    do{
        if((n->marks)<=min){
            min=n->marks;
            id=n->StudentId;
            strcpy(name,n->name);
        }
        n=n->next;
    }
    while(n!=head);
    printf("\n\nDetails....\n");
    printf("Name : ");
    puts(name);
    printf("Student Id : %d\n",id);
    printf("Min Marks : %d\n",min);
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
    min_marks(head);

    //printll(head);

    return 3;
}
