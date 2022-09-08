#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int front;
    int rear;
    int *arr;
    int capacity;
}Queue;

Queue *create_queue(int size){
    Queue *queue=(Queue*)malloc(sizeof(Queue));
    queue->capacity=size;
    queue->front=queue->rear=0;
    queue->arr=(int *)malloc(queue->capacity * sizeof(int));
    
    return queue;
}

int isfull(Queue *queue){
    int rear_next=((queue->rear)+1)%(queue->capacity);
    if(rear_next==queue->front)
        return 1;
    return 0;
}

int isempty(Queue *queue){
    if(queue->front==queue->rear)
        return 1;
    return 0;
}

void enqueue(Queue *queue,int item){
    //  check condition for queue full
    if(isfull(queue)){
        printf("Queue Overflow\n");
    }

    else{
        queue->arr[queue->rear]=item;

        //  *****(i+1)%size*****
        //  important formula for reseting of the rear index
        int rear_next=((queue->rear)+1)%(queue->capacity);
        queue->rear=rear_next;
    }
}

void dequeue(Queue *queue){
    //  check condition for queue empty
    if(isempty(queue)){
        printf("Queue Underflow\n");
    }
    else{
        queue->front=((queue->front)+1)%(queue->capacity);
    }
}

void display(Queue queue){

    while(queue.front!=queue.rear){

        //  case when the front_index is at the last element
        if(queue.front==queue.capacity-1){
            printf("%d",queue.arr[queue.front]);
            queue.front=(queue.front+1)%(queue.capacity);
        }

        //  normal case when the front_index < rear_index
        else{
            printf("%d",queue.arr[queue.front]);
            ++queue.front;
        }
    }
    printf("\n\n");
}

int main()
{
    int n;
    printf("Enter the size of the queue : ");
    scanf("%d",&n);

    Queue *queue=create_queue(n);

    enqueue(queue,1);
    display(*queue);

    enqueue(queue,2);
    display(*queue);

    enqueue(queue,3);
    display(*queue);

    enqueue(queue,4);
    display(*queue);

    dequeue(queue);
    display(*queue);

    enqueue(queue,5);
    display(*queue);

    dequeue(queue);
    display(*queue);

    enqueue(queue,6);
    display(*queue);

    dequeue(queue);
    display(*queue);
    
    dequeue(queue);
    display(*queue);
    
    enqueue(queue,7);
    display(*queue);

    return 3;
}