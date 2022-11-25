#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}NODE;

typedef NODE* treePointer;

treePointer makeTree(int n);
void inorder(treePointer ptr);
void levelOrder(treePointer ptr);
void addq(treePointer ptr);
treePointer deleteq();
void push(treePointer node);
treePointer pop();


int front = 0;
int rear = 0;
treePointer queue[MAX];
int top = -1;
treePointer stack[MAX];

void main(void) {
	int num;
	treePointer head;
	printf("Input number: ");
	scanf("%d", &num);
	head = makeTree(num);
	levelOrder(head);
	printf("inorder: ");
	inorder(head);
	puts(" ");

}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("%d ", ptr->data);
		inorder(ptr->right);
	}//LVR¼øÀ¸·Î Å½»ö
	
}

treePointer makeTree(int n) {
	treePointer head = NULL;
	head = (treePointer)malloc(sizeof(NODE));
	int i = 1;
	head->data = i++;
	head->left = NULL;
	head->right = NULL;
	addq(head);
	treePointer cur;
	while (1) {
		cur = deleteq();
		if (!cur)
			break;
		if (cur->left == NULL && i <= n) {
			cur->left = (treePointer)malloc(sizeof(NODE));
			cur->left->data = i++;
			cur->left->right = NULL;
			cur->left->left = NULL;
			addq(cur->left);
		}
		if (cur->right == NULL && i <= n) {
			cur->right = (treePointer)malloc(sizeof(NODE));
			cur->right->data = i++;
			cur->right->left = NULL;
			cur->right->right = NULL;
			addq(cur->right);
		}
	}
	return head;

}

void levelOrder(treePointer ptr) {

	if (!ptr) return;
	printf("level order:");
	addq(ptr);
	for (;;) {
		ptr = deleteq();
		if (ptr) {
			printf(" %d", ptr->data);
			if (ptr->left) {
				addq(ptr->left);
			}
			if (ptr->right) {
				addq(ptr->right);
			}
		}
		else break;
	}
	printf("\n");
}


void addq(treePointer ptr) {
	treePointer temp = (treePointer)malloc(sizeof(NODE));
	temp = ptr;
	if (rear == MAX - 1) {
		printf("queue is full\n");
		return;
	}
	queue[rear++] = ptr;
}
treePointer deleteq() {
	if (front == rear) {
		return NULL;
	}
	return queue[front++];
}


