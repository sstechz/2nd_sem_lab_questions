#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    //  front index(fi)
    //  back index(bi)
    int fi;
    int bi;
    int capacity;
    int *arr;
}Queue;

//Queue *queue;

Queue *create_queue(int size){
    Queue *queue=(Queue*)malloc(sizeof(Queue));
    queue->fi=-1;
    queue->bi=-1;
    queue->capacity=size;
    queue->arr=(int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

void enqueue(Queue *queue, int data){
    //  case when for first time enqueuing
    if(queue->fi==-1 && queue->bi!=queue->capacity-1){
        ++queue->fi;
        ++queue->bi;
        queue->arr[queue->bi]=data;
        return;
    }

    //  case when queue is full
    else if(queue->bi==queue->capacity-1){
        printf("Queue Overflow\n");
        return;
    }

    //  case when normal enqueuing
    ++queue->bi;
    queue->arr[queue->bi]=data;
}

void dequeue(Queue *queue){
    if(queue->fi==queue->bi){
        printf("Queue Underflow\n");
        return;
    }
    ++queue->fi;
}

void display(Queue queue){
    for(int i=queue.fi;i<=queue.bi;++i){
        printf("%d",queue.arr[i]);
    }printf("\n\n");
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

    dequeue(queue);
    display(*queue);

    return 3;
}