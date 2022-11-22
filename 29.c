#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INT_MAX 10000000 // 최대 정수

#define TRUE 1

#define FALSE 0

#define MAX_VERTICES 6 //정점의 수

#define INF 1000 //무한대(연결이 없는 경우)



int cost[MAX_VERTICES][MAX_VERTICES] = { 

{ 0, 50,45,10,1000,1000},

{ 1000, 0, 10, 15, 1000,1000},

{1000,1000, 0,1000,30,1000},

{20,1000,1000, 0, 15,1000},

{1000, 20,35, 1000, 0,1000},

{ 1000, 1000,1000, 1000,3, 0}

};



int distance[MAX_VERTICES]; //시작 정점으로부터의 최단 경로 거리

int found[MAX_VERTICES]; //방문한 정점 표시

int path[MAX_VERTICES][MAX_VERTICES]; //최단거리 정점까지 거치는 노드들을 저장

int check[MAX_VERTICES];//한 정점으로 가는 정점을 표시



void path_init(int path[][MAX_VERTICES]); //path 인접행렬 초기화

int choose(int distance[], int n, int found[]); // 최단거리에 있는 정점을 찾는 함수

void shortest_path(int start, int n);//최단 경로 알고리즘



void main() {

	int i, j;

	int start;

	path_init(path);

	printf("Input start node:");

	scanf("%d", &start);

	printf("[Cost Path from vertex %d]", start);

	printf("\n");

	shortest_path(start, MAX_VERTICES);



	for (i = 0; i < MAX_VERTICES; i++) { 

		
		
		if (distance[i] == INF)
			printf("[to %d]no path", i);
		else printf("[to %d]Length: %d, Path: ", i, distance[i]);

		for (j = 0; j < MAX_VERTICES; j++) {

			if (path[i][j] != INF) {

				printf("(%2d) ", path[i][j]);

			}

		}
		
		printf("(%2d)\n", i);

	}

}



//path 인접행렬 초기화

void path_init(int path[][MAX_VERTICES]) {

	int i, j;

	for (i = 0; i < MAX_VERTICES; i++)

		for (j = 0; j < MAX_VERTICES; j++)

			path[i][j] = INF;

}

// 최단거리에 있는 정점을 찾기

int choose(int distance[], int n, int found[]) {

	int i, min, minpos;

	min = INT_MAX;

	minpos = -1;



	for (i = 0; i < n; i++)

		if (distance[i] < min && !found[i]) {

			min = distance[i];

			minpos = i;

		}

	return minpos;

}

//최단 경로 알고리즘

void shortest_path(int start, int n)

{

	int i, j, u, w;

	for (i = 0; i < n; i++) {

		distance[i] = cost[start][i];

		found[i] = FALSE;

		check[i] = 1;

		path[i][0] = start;

	}



	found[start] = TRUE;//시작 정점 방문 표시

	distance[start] = 0;



	for (i = 0; i < n - 2; i++) {

		u = choose(distance, n, found);

		found[u] = TRUE;

		for (w = 0; w < n; w++) {

			if (!found[w]) {

				if (distance[u] + cost[u][w] < distance[w]) {

					if (i == 0) {

						path[w][check[w]] = u; 

						check[w]++;

					}

					else {

						for (j = 0; j < (check[u] + 1); j++) {

							path[w][j] = path[u][j]; 

							path[w][j + 1] = u; 

							check[w]++;

						}

					}

					distance[w] = distance[u] + cost[u][w];

				}

			}

		}

	}

}