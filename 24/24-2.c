#include <stdio.h>
#include <stdlib.h>

typedef struct threadedTree *threadedPointer;
typedef struct threadedTree {
    short int leftThread;
    threadedPointer leftChild;
    char data;
    threadedPointer rightChild;
    short int rightThread;
} threadedTree ;

threadedPointer makeTree()
{
    threadedPointer root = (threadedPointer)malloc(sizeof(threadedTree));
    root->rightChild = root;

    threadedPointer nodeA = (threadedPointer)malloc(sizeof(threadedTree));
    nodeA->data = 'A';
    threadedPointer nodeB = (threadedPointer)malloc(sizeof(threadedTree));
    nodeB->data = 'B';
    threadedPointer nodeC = (threadedPointer)malloc(sizeof(threadedTree));
    nodeC->data = 'C';
    threadedPointer nodeD = (threadedPointer)malloc(sizeof(threadedTree));
    nodeD->data = 'D';
    threadedPointer nodeE = (threadedPointer)malloc(sizeof(threadedTree));
    nodeE->data = 'E';
    threadedPointer nodeF = (threadedPointer)malloc(sizeof(threadedTree));
    nodeF->data = 'F';   
    threadedPointer nodeG = (threadedPointer)malloc(sizeof(threadedTree));
    nodeG->data = 'G'; 
    threadedPointer nodeH = (threadedPointer)malloc(sizeof(threadedTree));
    nodeH->data = 'H';
    threadedPointer nodeI = (threadedPointer)malloc(sizeof(threadedTree));
    nodeI->data = 'I';

    root->leftChild = nodeA;
    nodeA->leftChild = nodeB;
    nodeA->rightChild = nodeC;
    nodeB->leftChild = nodeD;
    nodeB->rightChild = nodeE;
    nodeD->leftChild = nodeH;
    nodeD->rightChild = nodeI;
    nodeC->leftChild = nodeF;
    nodeC->rightChild = nodeG;

    nodeH->leftChild = root;
    nodeH->leftThread = 1;
    nodeH->rightChild = nodeD;
    nodeH->rightThread = 1;

    nodeI->leftChild = nodeD;
    nodeI->leftThread = 1;
    nodeI->rightChild = nodeB;
    nodeI->rightThread = 1;
    
    nodeE->leftChild = nodeB;
    nodeE->leftThread = 1;
    nodeE->rightChild = nodeA;
    nodeE->rightThread = 1;
    
    nodeF->leftChild = nodeA;
    nodeF->leftThread = 1;
    nodeF->rightChild = nodeC;
    nodeF->rightThread = 1;
    
    nodeG->leftChild = nodeC;
    nodeG->leftThread = 1;
    nodeG->rightChild = root;
    nodeG->rightThread = 1;
    
    return root;
}

threadedPointer insucc(threadedPointer tree)
{
    threadedPointer temp;
    temp = tree->rightChild;
    if (!tree->rightThread)
        while (!temp->leftThread)
            temp = temp->leftChild;
    return temp;
}

void tinorder(threadedPointer tree)
{
    threadedPointer temp = tree;
    for (;;)
    {
        temp = insucc(temp);
        if (temp == tree) break;
        printf("%3c", temp->data);
    }
    puts("");
}

int main(void)
{
    threadedPointer head = makeTree();
    tinorder(head);

    return 0;
}