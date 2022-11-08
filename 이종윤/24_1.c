#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define N_DATA 20
#define TRUE 1
#define FALSE 0
typedef struct NODE* LINK;
typedef struct NODE {
	int d;
	LINK linkleft, linkright;
}NODE;

LINK createnode(int n);
LINK createbinary(int n);
void levelorder(LINK h);
void inorder(LINK h);

int main() {
	int n;
	printf("Input number : ");
	scanf("%d", &n);

	LINK h = createbinary(n);
	printf("level order :");
	levelorder(h);
	printf("inorder :");
	inorder(h);
	printf("\n");
}

LINK createnode(int n) {
	LINK new = malloc(sizeof(NODE));
	new->d = n;
	new->linkleft = NULL;
	new->linkright = NULL;
	return new;
}
LINK createbinary(int n) {
	int t = 0;
	LINK new = createnode(++t);
	LINK linkqueue[N_DATA];
	int open = -1, close = -1;
	linkqueue[++close] = new;
	while (TRUE) {
		new = linkqueue[++open];
		if (t < n) {
			new->linkleft = createnode(++t);
			linkqueue[++close] = new->linkleft;
		}
		else break;
		if (t < n) {
			new->linkright = createnode(++t);
			linkqueue[++close] = new->linkright;
		}
		else break;
	}
	return linkqueue[0];
}
void levelorder(LINK h) {
	LINK linkqueue[N_DATA];
	int open = -1, close = -1;
	linkqueue[++close] = h;
	while (TRUE) {
		if (open == close) break;
		h = linkqueue[++open];
		printf(" %d", h->d);
		if (h->linkleft) linkqueue[++close] = h->linkleft;
		if (h->linkright) linkqueue[++close] = h->linkright;
	}
	printf("\n");
}
void inorder(LINK h) {
	if (!h) return;
	inorder(h->linkleft);
	printf(" %d", h->d);
	inorder(h->linkright);
}
