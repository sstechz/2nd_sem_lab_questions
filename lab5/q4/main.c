#include <stdio.h>
#include <stdlib.h>
struct node
{
    int HouseID;
    float price;
    struct node *next;
};
struct node *head;
void initialize()
{
    head = NULL;
}
void insert(int id, float rate)
{
    struct node *newNode =NULL;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->HouseID = id;
    newNode->price = rate;
    newNode->next = head;
    head = newNode;
}
void List_Bsort(struct node *head)
{
    // struct node *ptr= head;
    // struct node *p1= ptr->next;
    int i, j;
    float tp;
    int tid;
    for (i = 1; i <= 4; i++)
    {
        struct node *ptr = head;
        for (j = 0; j < 4; j++)
        {
            // struct node *ptr= head;
            struct node *p1 = ptr->next;
            if (ptr->price < p1->price)
            {
                tp = ptr->price;
                ptr->price = p1->price;
                p1->price = tp;
                tid = ptr->HouseID;
                ptr->HouseID = p1->HouseID;
                p1->HouseID = tid;
            }
            ptr = ptr->next;
            p1 = ptr->next;
        }
    }
}
void printLinkedList(struct node *nodePtr)
{
    printf("HouseID Price\n");
    while (nodePtr != NULL)
    {
        printf("%d %f\n", nodePtr->HouseID, nodePtr->price);
        nodePtr = nodePtr->next;
    }
}
int main()
{
    initialize();
    insert(111, 2050);
    insert(112, 2500);
    insert(101, 3045);
    insert(102, 1500);
    insert(105, 4500);
    printf("Inserted list:\n");
    printLinkedList(head);
    List_Bsort(head);
    printf("\n\nList in decending order of price:\n");
    printLinkedList(head);
    return 0;
}
