#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* left, * right;
}NODE;

typedef NODE* treePointer;

treePointer newNode(int data);
treePointer search(treePointer root, int key);
treePointer insert(treePointer* node, int k);
void inorder(treePointer ptr);

void main(void) {
	treePointer head = NULL, cur;

	FILE* fp;
	if ((fp = fopen("in.txt", "r")) == NULL) {
		printf("can't open this file\n");
		exit(1);
	}

	int item;
	while ((fscanf(fp, "%d", &item) != EOF)) {
		head=insert(head, item);
	}
	printf("Inorder traversal...\n");
	inorder(head);
	fclose(fp);

	printf("\n\n");

	if ((fp = fopen("search.txt", "r")) == NULL) {
		printf("can't open this file\n");
		exit(1);
	}
	while ((fscanf(fp, "%d", &item)) != EOF) {
		cur = search(head, item);
		if (!cur) printf("%4d: X\n", item);
		else printf("%4d: O\n", item);
	}
	fclose(fp);
}
treePointer newNode(int data) {
	treePointer cur = (treePointer)malloc(sizeof(NODE));
	cur->data = data;
	cur->left = cur->right = NULL;
	return cur;
}
treePointer search(treePointer root, int key) {
	while (root) {
		if (key == root->data) return root;
		if (key < root->data) root = root->left;
		else root = root->right;
	}
	return NULL;
}
treePointer insert(treePointer node, int k) {
	if (!node) {
		return newNode(k);
	}
	if (k < (node)->data) {
		(node)->left = insert((node)->left, k);
	}
	else
		node->right = insert(node->right, k);

	return node;
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("%d ", ptr->data);
		inorder(ptr->right);
	}
}