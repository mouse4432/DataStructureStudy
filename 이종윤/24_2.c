#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define N_DATA 20
#define TRUE 1
#define FALSE 0

typedef struct THREADEDNODE* LINK;
typedef struct THREADEDNODE {
	LINK linkleft, linkright;
	short int isleft, isright;
	char d;
}THREADEDNODE;

LINK createthreadednode(char d);
LINK appendleft(LINK h, char d);
LINK appendright(LINK h, char d);
LINK findsuccessor(LINK p);
void threadinorder(LINK p);

int main() {
	LINK root = createthreadednode('0');
	LINK A = appendleft(root, 'A');
	LINK B = appendleft(A, 'B');
	LINK D = appendleft(B, 'D');
	LINK E = appendright(B, 'E');
	LINK H = appendleft(D, 'H');
	LINK I = appendright(D, 'I');
	LINK C = appendright(A, 'C');
	LINK F = appendleft(C, 'F');
	LINK G = appendright(C, 'G');
	root->linkright = root;
	H->linkright = D;
	I->linkleft = D;
	I->linkright = B;
	E->linkleft = B;
	E->linkright = A;
	F->linkleft = A;
	F->linkright = C;
	G->linkleft = C;
	threadinorder(root);
}

LINK createthreadednode(char d) {
	LINK new = malloc(sizeof(THREADEDNODE));
	new->linkleft = NULL;
	new->linkright = NULL;
	new->isleft = TRUE;
	new->isright = TRUE;
	new->d = d;
	return new;
}
LINK appendleft(LINK h, char d) {
	LINK new = createthreadednode(d);
	h->linkleft = new;
	h->isleft = FALSE;
	return new;
}
LINK appendright(LINK h, char d) {
	LINK new = createthreadednode(d);
	h->linkright = new;
	h->isright = FALSE;
	return new;
}
LINK findsuccessor(LINK p) {
	LINK q = p->linkright;
	if (q == NULL || p->isright) return q;
	while (!q->linkleft || !q->isleft) {
		q = q->linkleft;
	}
	return q;
}
void threadinorder(LINK p) {
	LINK q = p;
	while (q->linkleft)
		q = q->linkleft;
	do {
		printf(" %c", q->d);
		q = findsuccessor(q);
	} while (q);
}
