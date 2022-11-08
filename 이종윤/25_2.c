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

LINK createnode(int d);
void inorder(LINK link);
LINK extendtree(LINK link, int d);
void isthere(LINK r, int d);

int main() {
	LINK root = NULL;
	FILE* pfrom = fopen("in1.txt", "r");
	int onetime;
	fscanf(pfrom, "%d", &onetime);
	root = extendtree(root, onetime);
	while (!feof(pfrom)) {
		int n;
		fscanf(pfrom, "%d", &n);
		extendtree(root, n);
	}
	fclose(pfrom);
	printf("Inorder traversal...\n");
	inorder(root);
	printf("\n\n");
	
	FILE* filesearch = fopen("search.txt", "r");
	while (!feof(filesearch)) {
		int n;
		fscanf(filesearch, "%d", &n);
		isthere(root, n);
	}
	fclose(filesearch);
}

LINK createnode(int d) {
	LINK new = malloc(sizeof(NODE));
	new->d = d;
	new->linkleft = NULL;
	new->linkright = NULL;
	return new;
}
void inorder(LINK link) {
	if (!link) return;
	inorder(link->linkleft);
	printf("%4d", link->d);
	inorder(link->linkright);
}
LINK extendtree(LINK link, int d) {
	if (!link) return createnode(d);
	LINK toreturn = link;
	while (TRUE) {
		if (link->d < d) {
			if (!link->linkright) {
				link->linkright = createnode(d);
				return link->linkright;
			}
			link = link->linkright;
		}
		else {
			if (!link->linkleft) {
				link->linkleft = createnode(d);
				return link->linkleft;
			}
			link = link->linkleft;
		}
	}
}
void isthere(LINK r, int d) {
	if (!r) {
		printf("%4d : X\n", d);
		return;
	}
	else if (r->d == d) {
		printf("%4d : O\n", d);
		return;
	}
	if (r->d < d) isthere(r->linkright, d);
	else isthere(r->linkleft, d);
}
