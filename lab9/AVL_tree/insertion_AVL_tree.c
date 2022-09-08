#include <stdio.h>

typedef struct Node{
    int data;
    struct Node* l;
    struct Node* r;
}Node;

Node *create(int item){
    Node *root=(Node*)malloc(sizeof(Node));
    root->data=item;
    root->l=root->r=NULL;

    return root;
}

//some utility functions 

//  left of left
Node *right_rotate(Node *a){
    //  new root will be b

    Node *b=a->r;
    Node *c=b->l;

    b->l=a;
    a->r=c;

    return b;
}

Node *left_rotate(Node *x){
    //  new root will be y;

    Node *y=x->l;
    Node *z=y->r;

    y->r=x;
    x->l=z;

    return y;
}

Node* insert(Node *root, int num){
    if(root==NULL){
        Node *root=create(num);
        return root;
    }
    if(num<root->data){
        insert(root->l,num);
        check_level(root);
    }
        
    else if(num>root->data){
        insert(root->r,num);
        check_level(root);
    }
        
    
    return root;

}

int main(){
    Node *root=create(7);
    root=insert(root,9);
    root=insert(root,12);
    root=insert(root,2);
    root=insert(root,25);
    root=insert(root,64);
    root=insert(root,43);

    return 3;
}