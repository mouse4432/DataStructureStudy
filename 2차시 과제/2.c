#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct graphnode {
	int vertex;
	struct graphnode* link;
}graphnode;

typedef graphnode* LINK;

LINK makenode(int vertex);
void insert_edge(LINK Alist, int u, int v);
void print_list(LINK Alist, int n);
LINK MALLOC(int size);
void cntdegree(LINK Alist, LINK ind, LINK outd, int n);

int main(void) {
	FILE* fp;
	if ((fp = fopen("in.txt", "r")) == NULL) {
		printf("can't open this file\n");
		exit(1);
	}
	int n;
	int row, col;
	fscanf(fp, "%d", &n);
	LINK Alist[MAX]={NULL,};
	LINK ind[MAX];
	LINK outd[MAX];
	for (int i = 0; i < n; i++) {
		LINK cur1 = makenode(0);
		LINK cur2 = makenode(0);
		ind[i] = cur1;
		outd[i] = cur2;
	}
	while ((fscanf(fp, "%d %d", &row, &col)) != EOF) {
		insert_edge(&Alist, row, col);
	}
	printf("\n\nLinked adjacency list...\n");
	print_list(&Alist, n);
	cntdegree(&Alist, &ind, &outd,n);
	printf("Indegree...\n");
	print_list(&ind, n);
	printf("Outdegree...\n");
	print_list(&outd, n);
}

LINK makenode(int vertex) {
	LINK cur = (LINK)malloc(sizeof(graphnode));
	cur->vertex = vertex;
	cur->link = NULL;
	return cur;
}
void insert_edge(LINK* Alist, int u, int v) {
	LINK cur = makenode(v);
	LINK link = Alist[u];
	Alist[u] = cur;
	cur->link = link;
}
void print_list(LINK* Alist, int n) {
	LINK cur;
	for (int i = 0; i < n; i++) {
		cur = Alist[i];
		printf("[%2d]", i);
		while (cur) {
			printf("%3d", cur->vertex);
			cur = cur->link;
		}
		puts(" ");
	}
	puts(" ");
}

void cntdegree(LINK* Alist, LINK* ind, LINK* outd, int n) {
	LINK cur;
	for (int i = 0; i < n; i++) {
		cur = Alist[i];
		while (cur) {
			ind[cur->vertex]->vertex++;
			outd[i]->vertex++;
			cur = cur->link;
		}
	}
}