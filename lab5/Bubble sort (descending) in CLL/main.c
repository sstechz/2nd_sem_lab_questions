//  q4. Bubble sort (descending order) in simple linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int House_id;
    int price;
    struct node *next;
}node;

void insert(node **head){
    int x,y;
    printf("HouseId : ");
    scanf("%d",&x);
    printf("Price : ");
    scanf("%d",&y);

    node *temp=NULL;
    temp=(node*)malloc(sizeof(node));

    if(*head==NULL){
        temp->next=NULL;
        temp->House_id=x;
        temp->price=y;
        *head=temp;
    }
    else{
        temp->next=*head;
        *head=temp;
        temp->House_id=x;
        temp->price=y;
    }

}

void printll(node *head){
    node *h=head;

    printf("\n\nSorted list...");
    while(h!=NULL){
        printf("\n\nHouse_id : %d\n",h->House_id);
        printf("Price : %d",h->price);
        h=h->next;
    }
}

void bubble_sort(node **head,int n){
    int temp1;
    int temp2;
    for(int i=0;i<n-1;++i){
        node *ptr=*head;
        for(int j=0;j<n-i-1;++j){
            node *p1=ptr->next;
            if(ptr->price<p1->price){
                temp1=ptr->price;
                ptr->price=p1->price;
                p1->price=temp1;

                temp2=ptr->House_id;
                ptr->House_id=p1->House_id;
                p1->House_id=temp2;
            }
           ptr=ptr->next;
           p1=p1->next;
        }

    }

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

    bubble_sort(&head,n);

    printll(head);

    return 3;
}
