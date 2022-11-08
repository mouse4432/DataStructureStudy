#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct root {
	struct n* left;
	int data;
	struct n* right;
}r;

typedef r* R;

typedef struct que {
	R data;
	struct que* next;
}q;
q* front;
q* rear;

typedef struct stack {
	R data;
	struct stack* next;
}s;
s* top;


void addq(R d) {
	q* tmp = (q*)malloc(sizeof(q));
	tmp->data = d;
	tmp->next = NULL;
	if (front) {
		rear->next = tmp;
	}
	else {
		front = tmp;
	}
	rear = tmp;
}

R deleteq() {
	if (!front)
		return NULL;
	q* tmp = front;
	R item = tmp->data;
	front = front->next;
	free(tmp);
	return item;
}

R make_ctree(int input) {
	int i = 1;
	int c = 1;
	R root = (R)malloc(sizeof(r));
	addq(root);
	c++;
	for (i; i <= input; i++) {
		R cur = deleteq(root);
		cur->data = i;
		cur->left = NULL;
		cur->right = NULL;
		if (c <= input) {
			cur->left = (R)malloc(sizeof(r));
			addq(cur->left);
			c++;
		}
		if (c <= input) {
			cur->right = (R)malloc(sizeof(r));
			addq(cur->right);
			c++;
		}
	}
	
	return root;
}

void print_level(R root) {
	if (!root)
		return;
	addq(root);
	while (1) {
		root = deleteq();
		if (root) {
			printf("%d ", root->data);
			if (root->left) {
				addq(root->left);
			}
			if (root->right) {
				addq(root->right);
			}
		}
		else
			break;
	}

}

void push(R node) {
	s* tmp = (s*)malloc(sizeof(*tmp));
	tmp->data = node;
	tmp->next = top;
	top = tmp;
}

R pop() {
	s* tmp = top;
	top = tmp->next;
	return tmp->data;
}

void print_inorder(R root) {
	top = NULL;
	while (1) {
		while (root) {
			push(root);
			root = root->left;
		}
		root = pop();
		if (!root)
			break;
		printf("%d ", root->data);
		root = root->right;
	}

}

void main() {

	int num;
	R root;
    printf("Input Number: ");
    scanf("%d", &num);
	

	root = make_ctree(num);

	printf("Level order: ");
	print_level(root);
	printf("\n");

	printf("Inorder: ");
	print_inorder(root);
	printf("\n");
}