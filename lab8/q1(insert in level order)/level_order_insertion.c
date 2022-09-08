#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node*l;
    struct Node*r;
}Node;

Node* create_node(int item){
    Node *root=(Node*)malloc(sizeof(Node));
    root->data=item;
    root->l=root->r=NULL;

    return root;
}

void left(Node *root,int item){
    root->l=create_node(item);
}

void right(Node* root,int item){
    root->r=create_node(item);
}

void preorder_traversal(Node *root){
    if(root==NULL)
        return;
    //  root->left->right
    printf("%d ",root->data);
    preorder_traversal(root->l);
    preorder_traversal(root->r);
}

void inorder_traversal(Node *root){
    if(root==NULL)
        return;
    //  left->root->right
    inorder_traversal(root->l);
    printf("%d ",root->data);
    inorder_traversal(root->r);
}

void postorder_traversal(Node *root){
    if(root==NULL)
        return;
    //  left->right->root
    postorder_traversal(root->l);
    postorder_traversal(root->r);
    printf("%d ",root->data);
}

int L,R;
int isBST(Node* root) 
    {
        if(root==NULL || (root->l==NULL &&  root->r==NULL))
            return 1;
        if((root->l->data >= root->data) && (root->r == NULL)) 
            return 0;
        else if((root->r->data <= root->data) && (root->l == NULL)) 
            return 0;
        else if((root->l->data >= root->data) || (root->r->data <= root->data))
            return 0;
        
        L=isBST(root->l);
        R=isBST(root->r);
        
        return (L&R);
    }

int main(){

    Node *root=create_node(7);
    left(root,4);
    right(root,15);

    left(root->l,1);
    right(root->l,5);
    left(root->r,10);
    right(root->r,16);

    printf("\nPre_order_traversal : \n");
    preorder_traversal(root);
    printf("\n\n");

     printf("In_order_traversal : \n");
     inorder_traversal(root);
     printf("\n\n");

    printf("Post_order_traversal : \n");
    postorder_traversal(root);
    printf("\n\n");

    printf("%d \n",isBST(root));

    return 3;
}