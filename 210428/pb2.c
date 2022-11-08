#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef enum { false, true } boolean;
typedef struct tt {
    boolean leftThread, rightThread;
    struct tt* left, * right;
    element data;
}thread_tree;

thread_tree* insucc(thread_tree* ptr) {
    thread_tree* temp = ptr->right;

    if (!ptr->rightThread)
        while (!temp->leftThread)
            temp = temp->left;

    return temp;
}

thread_tree* inpre(thread_tree* ptr) { //inorder_predecessor
    thread_tree* temp = ptr->left;

    if (!ptr->leftThread)
        while (!temp->rightThread)
            temp = temp->right;

    return temp;
}

thread_tree* newTT() {
    thread_tree* head = (thread_tree*)malloc(sizeof(thread_tree));
    head->leftThread = true;
    head->rightThread = false;
    head->left = head;
    head->right = head;
    return head;
}

void leftTT(thread_tree* cur, element value) {
    thread_tree* child = (thread_tree*)malloc(sizeof(thread_tree));
    child->leftThread = cur->leftThread;
    child->left = cur->left;
    child->rightThread = true;
    child->right = cur;
    child->data = value;
    cur->left = child;
    cur->leftThread = false;
    if (!child->leftThread) {
        thread_tree* temp = inpre(child);
        temp->right = child;
    }
}

void rightTT(thread_tree* cur, element value) {
    thread_tree* child = (thread_tree*)malloc(sizeof(thread_tree));
    child->leftThread = true;
    child->left = cur;
    child->rightThread = cur->rightThread;
    child->right = cur->right;
    child->data = value;
    cur->right = child;
    cur->rightThread = false;
    if (!child->rightThread) {
        thread_tree* temp = insucc(child);
        temp->left = child;
    }
}

thread_tree* makeTT() {
    thread_tree* head = newTT();
    char i = 'A';
    leftTT(head, i++);
    leftTT(head->left, i++);
    rightTT(head->left, i++);
    leftTT(head->left->left, i++);
    rightTT(head->left->left, i++);
    leftTT(head->left->right, i++);
    rightTT(head->left->right, i++);
    leftTT(head->left->left->left, i++);
    rightTT(head->left->left->left, i++);
    // leftTT(head->left->left, 'X');
    return head;
}

void tinorder(thread_tree* head) {
    thread_tree* temp = head;

    while (1) {
        temp = insucc(temp);
        if (temp == head)
            break;

        printf("%3c", temp->data);
    }
}

void re_tinorder(thread_tree* head) {
    thread_tree* temp = head;

    while (1) {
        temp = inpre(temp);
        if (temp == head)
            break;

        printf("%3c", temp->data);
    }
}


void main() {
    thread_tree* head = makeTT();
    tinorder(head);
}