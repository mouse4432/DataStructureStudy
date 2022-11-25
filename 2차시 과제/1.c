#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int Amatrix[MAX][MAX];

typedef struct graphnode {
	int vertex;
	struct graphnode* link;
}graphnode;

typedef graphnode* LINK;
LINK makenode(int vertex);
LINK Alist;
void insert_edge(LINK Alist, int u, int v);
void print_matrix(int n);
void print_list(LINK Alist, int n);

int main(void) {
	FILE* fp;
	if ((fp = fopen("in.txt", "r")) == NULL) {
		printf("can't open this file\n");
		exit(1);
	}
	LINK cur;
	int n;
	int row, col;
	fscanf(fp, "%d", &n);
	Alist = NULL;
	while ((fscanf(fp, "%d %d", &row, &col)) != EOF) {
		Amatrix[row][col] = 1;
		insert_edge(&Alist,row, col);
	}
	print_matrix(n);
	print_list(&Alist, n);
}

LINK makenode(int vertex) {
	LINK cur = (LINK)malloc(sizeof(graphnode));
	cur->vertex = vertex;
	cur->link = NULL;
	return cur;
}
void insert_edge(LINK* Alist,int u, int v) {
	LINK cur = makenode(v);
	LINK link = Alist[u];
	Alist[u] = cur;
	cur->link = link;
}
void print_list(LINK* Alist,int n) {
	LINK cur;
	printf("\n\nLinked adjacency list...\n");
	for (int i = 0; i < n; i++) {
		cur = Alist[i];
		printf("[%2d]", i);
		while (cur) {
			printf("%3d", cur->vertex);
			cur = cur->link;
		}
		puts(" ");
	}
}
void print_matrix(int n) {
	printf("Adjacency matrix...\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%2d ", Amatrix[i][j]);
		}
		puts(" ");
	}
}