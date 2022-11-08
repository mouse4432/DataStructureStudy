#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
} element ;

typedef struct _tree {
    element data;
    struct _tree* leftChild;
    struct _tree* rightChild;
} tree ;

typedef tree* treePointer;

element * Search(treePointer root, int key)
{
    if (!root) return NULL;
    if (key == root->data.key) return &(root->data);
    if (key < root->data.key)
        return Search(root->leftChild, key);
    return Search(root->rightChild, key);
}

element * iterSearch(treePointer tree, int k)
{
    while (tree)
    {
        if (k == tree->data.key) return &(tree->data);
        if (k < tree->data.key)
            tree = tree->leftChild;
        else
            tree = tree->rightChild;
    }
    return NULL;
}


tree* insert(tree* root, int num){
    if(root==NULL){
        tree* tmp = (tree*)malloc(sizeof(tree));
        tmp->data.key = num;
        tmp->leftChild = tmp->rightChild = NULL;
        return tmp;
    }

    if(num < root->data.key)
        root->leftChild = insert(root->leftChild, num);
    else
        root->rightChild = insert(root->rightChild, num);
    
    return root;
}

void inorder(tree * root)
{
    if (root)
    {
        inorder(root->leftChild);
        printf("%4d", root->data.key);
        inorder(root->rightChild);
    }
}

int main(void)
{
    FILE * f1 = fopen("in.txt", "r"), *f2 = fopen("search.txt", "r");
    int num;
    tree * head = NULL;

    if (!f1 || !f2)
    {
        fprintf(stderr, "cannot open file!!\n");
        exit(EXIT_FAILURE);
    }

    printf("Inorder traversal...\n");
    while (!feof(f1))
    {
        fscanf(f1, "%d", &num);
        head = insert(head, num);
    }
    inorder(head);
    puts("\n");

    while (!feof(f2))
    {
        fscanf(f2, "%d", &num);
        printf("%4d: ", num);
        if (Search(head, num))
            printf("O\n");
        else
            printf("X\n");
    }
    fclose(f1);
    fclose(f2);

    return 0;
}

