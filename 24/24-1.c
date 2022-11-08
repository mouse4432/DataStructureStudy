#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef struct _node {
    int data;
    struct _node* lchild;
    struct _node* rchild;
} Node ;

int front, rear = 0;
Node * queue[MAX_QUEUE_SIZE];

Node * makeTree(int max, int data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    if (data * 2 <= max)
        newNode->lchild = makeTree(max, data*2);
    if (data * 2 + 1 <= max)
        newNode->rchild = makeTree(max, data*2+1);
    return newNode;
}

void addq(Node * ptr)
{
    queue[rear++] = ptr;
}

Node * deleteq()
{
    return queue[front++];
}

void levelOrder(Node * ptr)
{
    if (!ptr) return;
    addq(ptr);
    for (;;)
    {
        ptr = deleteq();
        if (ptr)
        {
            printf("%4d", ptr->data);
            if (ptr->lchild)
                addq(ptr->lchild);
            if (ptr->rchild)
                addq(ptr->rchild);
        }
        else break;
    }
    puts("");
}

void inorder(Node * root)
{
    if (root)
    {
        inorder(root->lchild);
        printf("%4d", root->data);
        inorder(root->rchild);
    }
}

int main(void)
{
    int n;
    printf("Input number: ");
    scanf("%d", &n);
    Node * head = makeTree(n , 1);

    printf("level order:");
    levelOrder(head);

    printf("Inorder:");
    inorder(head);
    puts("");

    return 0;
}