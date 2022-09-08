#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int top;
    int *arr;
    int capacity;
}Stack;

int isfull(Stack *stack){
    if(stack->top+1==stack->capacity) 
        return 1;
    return 0;
}

int isempty(Stack *stack){
    if(stack->top==-1)
        return 1;
    return 0;
}

void push(Stack *stack, int data){
    if(!isfull(stack)){
        ++stack->top;
        stack->arr[stack->top]=data;
    }
    else{
        printf("Stack Overflow\n");
    }
}

void pop(Stack *stack){
    if(!isempty(stack)){
        --stack->top;
    }
    else{
        printf("Stack Underflow\n");
        return;
    }
}

void display(Stack stack){
    while(stack.top!=-1){
        printf("%d",stack.arr[stack.top]);
        --stack.top;
    }printf("\n\n");

}

Stack *create_stack(int size){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top=-1;
    stack->capacity=size;    
    stack->arr=(int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int main()
{   int n;
    printf("Entert the size of the stack : ");
    scanf("%d",&n);

    Stack *stack=create_stack(n);
    push(stack,1);
    display(*stack);

    push(stack,2);
    display(*stack);

    push(stack,3);
    display(*stack);

    pop(stack);
    display(*stack);

    push(stack,4);
    display(*stack);

    pop(stack);
    display(*stack);

    pop(stack);
    display(*stack);

    push(stack,5);
    display(*stack);

    while(stack->top!=-1){
        pop(stack);
        display(*stack);
        --stack->top;
    }

    return 3;
}