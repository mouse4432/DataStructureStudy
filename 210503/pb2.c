#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* left, *right;
}tree;

tree* insert(tree* root, int num){
    if(root==NULL){
        tree* tmp = (tree*)malloc(sizeof(tree));
        tmp->data = num;
        tmp->left = tmp->right = NULL;
        return tmp;
    }

    if(num < root->data)
        root->left = insert(root->left, num);
    else
        root->right = insert(root->right, num);
    
    return root;

}

void inorder(tree* root){
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int search(tree* node, int n){
    if(node==NULL)
        return 0;
    if(node->data == n)
        return 1;
    else if(node->data > n)
        return search(node->left, n);
    else
        return search(node->right, n);
}

int main(){
    int num;
    tree* root = NULL;
    while(1){
        scanf("%d", &num);
        if(num==-1)
            break;
        root = insert(root, num);
    }
    printf("inorder traversal...\n");
    inorder(root);
    while(1){
        scanf("%d", &num);
        if(num==-1)
            break;
        if(search(root, num))
            printf("%d : O\n", num);
        else   
            printf("%d : X\n", num); 
    }
}