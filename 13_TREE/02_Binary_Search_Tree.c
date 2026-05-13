#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};

struct node* createNode(int data){
    struct node *new;
    new = (struct node *) malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node * insertnode(struct node *root,int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insertnode(root->left,data);
    }
    else if(data > root->data){
        root->right = insertnode(root->right,data);
    }
    return root;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    struct node *root = createNode(50);
    root = insertnode(root, 40);
    root = insertnode(root, 60);
    root = insertnode(root, 70);
    root = insertnode(root, 80);
    root = insertnode(root, 30);
    root = insertnode(root, 20);

    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");

    return 0;
}


//OUTPUT:

// Inorder: 20 30 40 50 60 70 80 
// Preorder: 50 40 30 20 60 70 80 
// Postorder: 20 30 40 80 70 60 50 