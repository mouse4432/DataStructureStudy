#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;


typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void ViewIndegree(GraphType* g);
void ViewOutdegree(GraphType* g);

// 그래프 초기화 0으로
void init(GraphType* g) {
    int k;
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;

    for (k = 0; k < MAX_VERTICES; k++)
        g->adj_list[k] = NULL;
}


//Vertex 삽입
void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "overflow");
        return;
    }
    g->n++;
}

//Edge 삽입
void insert_edge(GraphType* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "vertex key error");
        return;
    }
    g->adj_mat[start][end] = 1;
    GraphNode* node;
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = end;
    node->link = g->adj_list[start];
    g->adj_list[start] = node;

    
}

// 인접 행렬 출력 함수
void print_adj_mat(GraphType* g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%2d", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

//
void print_adj_list(GraphType* g) {
    for (int i = 0; i < g->n; i++) 
    {
        GraphNode* p = g->adj_list[i];
        printf("[%2d]", i);
        while (p != NULL) 
        {
            printf("%3d", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

void main()
{
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 9; i++)
        insert_vertex(g, i);
    printf("Adjacency matrix...\n");
    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);
    insert_edge(g, 5, 8);
    insert_edge(g, 4, 5);
    insert_edge(g, 1, 7);
    insert_edge(g, 2, 6);
    insert_edge(g, 2, 8);
    insert_edge(g, 8, 7);
    insert_edge(g, 4, 0);
    print_adj_mat(g);  //인접행렬 출력
    printf("\n");
    printf("Linked adjacency list...\n");
    print_adj_list(g);  //list 출력
    printf("\n");
    printf("Indegree...\n");
    ViewIndegree(g);   //Indegree
    printf("\n");
    printf("Outdegree...\n");
    ViewOutdegree(g);  //Outdegree
    free(g);


}

void ViewIndegree(GraphType* g)

{

    int i, j;

    int degree;

    for (i = 0; i < g->n; i++)

    {

        degree = 0;//0으로 설정
        printf("[%2d]", i);
        for (j = 0; j < g->n; j++)

        {
           
            if (g->adj_mat[j][i])//올 수 있는 곳이 있으면(화살 들어옴)

            {

                degree++;//차수 1 증가

            }

        }

        printf("%2d\n", degree);//차수 출력

    }

    printf("\n");
}


void ViewOutdegree(GraphType* g)

{

    int i, j;

    int degree;
    
    

    for (i = 0; i < g->n; i++)

    {

        degree = 0;//0으로 설정
        printf("[%2d]", i);
        for (j = 0; j < g->n; j++)

        {

            if (g->adj_mat[i][j])//갈 수 있는 곳이 있으면(화살 나감)

            {

                degree++;//차수 1 증가

            }

        }

        printf("%2d\n", degree);//차수 출력

    }

    printf("\n");

}

