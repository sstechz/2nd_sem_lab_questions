#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Stack{
    int top;
    char *arr;
    int capacity;
}Stack;

Stack *create_stack(char *exp){
    Stack *stack=(Stack*)malloc(sizeof(Stack));
    stack->top=-1;
    stack->capacity=strlen(exp);
    stack->arr=(char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

void push(Stack *stack, char *exp){
    if(stack->top+1==strlen(exp)){
        printf("Stack Overflow\n");
    }
    else
        stack->arr[++stack->top]=*exp;
}

void push_int(Stack *stack,char num){
    stack->arr[++stack->top]=(char)num;
}

char pop(Stack *stack){
    if(stack->top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    char data=stack->arr[stack->top];
    --stack->top;
    return data;
}

int evaluate(char a,char op,char b){
    if(op=='+'){
       //printf("%d\n\n",a+b);
       return (a+b);
    }
    else if(op=='-')
        return a-b;
    else if(op=='*')
        return a*b;
    else if(op=='/')
        return a/b;
    else
        return pow(a,b);
}

int is_operator(char ch){
    if(ch=='^'||ch=='*'||ch=='/'||ch=='+'||ch=='-')
        return 1;
    return 0;
}

int pos_eval(Stack *stack, char *exp){
    int i=0;
    char result;
    while(exp[i]!='#'){
        if(is_operator(exp[i])){
            char b=pop(stack);
            //printf("%d\n\n",b);

            char a=pop(stack);
            //printf("%d\n\n",a);

            result=evaluate(a,exp[i],b);
            //printf("%d\n\n",result);

            push_int(stack,result);
            ++i;        
        }
        else{
            push(stack,&exp[i]);
            ++i;
        }
    }
    return result;
}

int main()
{   //  *****The way of writing the string plays the major role*****    // 
    //  *****It differentiates between the number and the characters*****   //
    char str[] ={1,2,4,'^','*',6,7,'+',8,9,'/',3,'-','*','+','#','\0'};
    char *exp = str;

    Stack *stack = create_stack(exp);

    printf("\nThe postfix evaluation of the given expression is : %d\n\n",pos_eval(stack,exp));

    return 3;
}