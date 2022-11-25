#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct threadedTree* tPointer;
typedef struct threadedTree {
	short int leftt;
	tPointer left;
	char data;
	tPointer right;
	short int rightt;
}NODE;

int TRUE = 1, FALSE = 0;
tPointer insucc(tPointer tree);
void tinorder(tPointer tree);
tPointer makenode(char a, int leftt, int rightt);
tPointer maketree();

void main(void) {
	tPointer  root;
	root = maketree();
	tinorder(root);

}
tPointer insucc(tPointer tree) {

	tPointer temp;
	temp = tree->right;
	if (!tree->rightt) {
		while (!temp->leftt)
			temp = temp->left;
	}//sub트리의 오른쪽자식으로 간 후 leftthread값이 true일때까지 계속이동
	return temp;
}
void tinorder(tPointer tree) {
	tPointer temp = tree;
	for (;;) {
		temp = insucc(temp);//직후 노드 찾기
		if (temp == tree) break;
		printf("%3c", temp->data);
	}
}
tPointer makenode(char a, short int leftt, short int rightt) {
	tPointer node = (tPointer)malloc(sizeof(NODE));
	node->leftt = leftt;
	node->left = NULL;
	node->data = a;
	node->right = NULL;
	node->rightt = rightt;

	return node;
}
tPointer maketree() {
	tPointer root, cur, head, right, left;
	root = makenode('-', FALSE, FALSE);
	root->right = root;

	head = makenode('A', FALSE, FALSE);
	root->left = head;

	cur = makenode('B', FALSE, FALSE);
	head->left = cur;

	cur = makenode('C', FALSE, FALSE);
	head->right = cur;

	cur = makenode('D', FALSE, FALSE);
	head->left->left = cur;

	cur = makenode('E', TRUE, TRUE);
	cur->right = head;
	cur->left = head->left;
	head->left->right = cur;

	cur = makenode('F', TRUE, TRUE);
	cur->right = head->right;
	cur->left = head;
	head->right->left = cur;

	cur = makenode('G', TRUE, TRUE);
	cur->left = head->right;
	cur->right = root;
	head->right->right = cur;

	cur = makenode('H', TRUE, TRUE);
	cur->left = root;
	cur->right = head->left->left;
	head->left->left->left = cur;

	cur = makenode('I', TRUE, TRUE);
	cur->left = head->left->left;
	cur->right = head->left;
	head->left->left->right = cur;


	return root;
}