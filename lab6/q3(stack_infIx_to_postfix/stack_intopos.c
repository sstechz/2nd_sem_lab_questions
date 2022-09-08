#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    int top;
    int capacity;
    char *arr;
}Stack;

Stack *stack;

Stack *create_stack(int size){
    stack = (Stack*)malloc(sizeof(Stack));
    stack->top=-1;
    stack->capacity=size;
    stack->arr=(char*)malloc(stack->capacity * sizeof(char));

    return stack;
}

int isoperator(char ch){
    if(ch=='^'||ch=='*'||ch=='/'||ch=='+'||ch=='-') 
        return 1;
    else
        return 0;
}

int isoperand(char ch){
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) 
        return 1;
    return 0;
}

int prec(char ch){
    if(ch=='^') return 3;
    else if(ch=='*'||ch=='/') return 2;
    else if(ch=='+'||ch=='-') return 1;    
    else return 0;
}

int isempty(Stack *stack){
    if(stack->top==-1) return 1;
    return 0;
}

void push(char data){
    stack->arr[++stack->top]=data;
}

char pop(){
    if(isempty(stack)){
        printf("Stack Underflow\n");
        return '$';
    }
    char ch=stack->arr[stack->top];
    --stack->top;
    return ch;
}

char stack_top(){
    return stack->arr[stack->top];
}

char *in_to_pos(char *exp){
    //  creating a stack of given string size(let suppose)
    stack = create_stack(strlen(exp));
    
    //  created an array for postfix expression
    char *pos = (char*)malloc((strlen(exp)+1)*sizeof(char));

    //  i is used for infix indexing
    //  j is used for postfix indexing
    int i=0;
    int j=0;

    while(exp[i]!='\0'){
        if(exp[i]=='('){
            push(exp[i]);
            i++;
        }
        if(exp[i]==')'){
            //  pop the operators until '(' is detected 
            //  and then pop '(' as well
            while(stack_top()!='('){
                pos[j]=pop();
                j++;
            }

            //  removing the '(' from the stack as well
            --stack->top;
            i++;
        }
        if(isoperand(exp[i])){
            pos[j]=exp[i];
            j++;
            i++;
        }
        else{
            if(prec(exp[i])>prec(stack_top())){
                push(exp[i]);
                i++;
            }
            else{
                pos[j]=pop();
                j++;
            }
        }
    }

    while(!isempty(stack)){
        pos[j]=pop();
        j++;
    }
    pos[j]='\0';
    return pos;
}

int main()
{
    char *exp="x+(y-(z*t)^w)/u-a";

    printf("Infix to Postfix form is : %s",in_to_pos(exp));

    return 3;
}