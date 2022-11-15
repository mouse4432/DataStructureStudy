#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 9

typedef struct List{
    int vertex;
    struct List* next;
}ADJList;

typedef struct Type{
    int n; //정점의 개수
    ADJList* adj[MAX_VERTICES];
}Type;

void insert(Type* g, int u, int v){
    g->n++;
    ADJList* node = (ADJList*)malloc(sizeof(ADJList));
    node->vertex = v;
    node->next = g->adj[u];
    g->adj[u] = node;
}

int main(){
    int n; 
    int x, y; //좌표
    int count = 0;
    int dGraph[MAX_VERTICES][MAX_VERTICES] = {0}; //9*9, 0으로 초기화
    int in[MAX_VERTICES] = {0};
    Type* G;
    G = (Type*)malloc(sizeof(Type));
    
    //초기화
    G->n = 0;
    for(int i=0; i<MAX_VERTICES; i++)
        G->adj[i] = NULL;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &x, &y);
        dGraph[x][y] = 1; //x, y 입력받아 좌표 표시
        insert(G, x, y); //G에 insert
    }   

    printf("Adjacency Matrix...\n");

    for(int i=0; i<MAX_VERTICES; i++){
        for(int j=0; j<MAX_VERTICES; j++)
            printf("%2d ", dGraph[i][j]);
        printf("\n");
    }

    printf("\n\n");

    printf("Linked Adjacency List...\n");
    for(int i=0; i<MAX_VERTICES; i++){
        ADJList* tmp = G->adj[i];
        printf("[%2d] ", i);
        while(tmp!=NULL){
            printf("%2d ", tmp->vertex);
            tmp = tmp->next;
        }
        printf("\n");
    }

    printf("\n\n");

    printf("Outdegree...\n");
    for(int i=0; i<MAX_VERTICES; i++){
        ADJList* tmp = G->adj[i];
        printf("[%2d] ", i);
        while(tmp!=NULL){
            count++;
            tmp = tmp->next;
        }
        printf("%2d\n", count);
        count = 0;
    }

    printf("\n\n");

    printf("Indegree...\n");
    for(int i=0; i<MAX_VERTICES; i++){
        ADJList* tmp = G->adj[i];
        while(tmp!=NULL){
            in[tmp->vertex]++;
            tmp = tmp->next;
        }
    }
    for(int i=0; i<MAX_VERTICES; i++)
        printf("[%2d] %2d\n", i, in[i]); 
}