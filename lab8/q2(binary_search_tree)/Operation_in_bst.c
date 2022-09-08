#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *l;
    struct Node *r;
}Node;

Node* new_node(int item){
    Node *node=(Node*)malloc(sizeof(Node));
    node->data=item;
    node->l=NULL;
    node->r=NULL;

    return node;
}

//  *****IT IS A RECURSIVE FUNCTION*****    //

//  *****FOR EFFICIENT RECURSIVE FUNCTION DON'T PASS ACTUAL PARAMETER AS DONE 
//       IN BELOW COMMENTED FUNCTION, ALWAYS PASS CONNECTION OF THE PARAMETER*****  //

//  HERE PASSING leaf->l || leaf->r and not leaf as done in below case
//  i.e. don't change leaf at any point of time
Node* insert(Node *leaf,int item){  
    if(leaf==NULL)
        return new_node(item);
    if(item<leaf->data)
        leaf->l=insert(leaf->l,item);
    else
        leaf->r=insert(leaf->r,item);
    return leaf;
}

// Node* insert(Node *leaf,int item){
    
//     if(leaf==NULL){
//         return new_node(item);
//     }
//     if(item<leaf->data){
//         prev=leaf;
//         leaf=leaf->l;
//         leaf=insert(leaf,item);
//         prev->l=leaf;
//         return leaf;
//     }
//     else{
//         prev=leaf;
//         leaf=leaf->r;
//         leaf=insert(leaf,item);
//         prev->r=leaf;
//         return leaf;
//     }
// }

void inorder(Node *temp){
    //  for inorder traversal, the order is left->root->right
    if(temp!=NULL){
        inorder(temp->l);
        printf("%d ",temp->data);
        inorder(temp->r);
    }
}

void search(Node *root,int num,int level){
    if(root==NULL){
        printf("\n\nElement not found\n");
        return;
    }
    if(root->data==num){
        printf("\n\n%d is at %dth level\n",num,level);
        return;
    }
    if(num<root->data){
        search(root->l,num,++level);
    }
    else
        search(root->r,num,++level);
}

int in_pre(Node*root){
    int val=root->data;
    while(root->l!=NULL){
        root=root->l;
        val=root->data;
    }
    return val;
}

//      **** IMPORTANT FUNCTION ****       //

Node *delete(Node*root,int item){
    //  element not found
    if(root==NULL)
        return NULL;

    //  searching for the element
    if(item < root->data)
        root->l=delete(root->l,item);
    else if(item > root->data)
        root->r=delete(root->r,item);

    //  when the element is found
    else{
        //  if only right child is present || incase of leaf node
        if(root->l==NULL){
            Node *temp=root;
            free(root);
            return temp->r;
        } 

        //  only left child is present || incase of leaf node   
        else if(root->r==NULL){
            Node *temp=root;
            free(root);
            return temp->l;
        }

        //  both children are present
        root->data=in_pre(root->r);
        root->r=delete(root->r,root->data);
    }
    return root;
}

int main()
{
    Node *root=NULL;
    root = insert(root, 56);
    root = insert(root, 70);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 34);

    //  inorder traversal is user for getting sorted array
    printf("\nInorder traversal -\n");
    inorder(root);

    search(root,5,0);

    root=delete(root,2);
    printf("\nAfter Deleting 2 -\n");
    inorder(root);
    printf("\n");

    root=delete(root,1);
    printf("\nAfter Deleting 1 -\n");
    inorder(root);
    printf("\n");

    root=delete(root,5);
    printf("\nAfter Deleting 5 -\n");
    inorder(root);
    printf("\n");

    root = insert(root,49);
    printf("\nAfter Inserting -\n");
    inorder(root);

    return 3;
}