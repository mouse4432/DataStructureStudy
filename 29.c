#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INT_MAX 10000000 // �ִ� ����

#define TRUE 1

#define FALSE 0

#define MAX_VERTICES 6 //������ ��

#define INF 1000 //���Ѵ�(������ ���� ���)



int cost[MAX_VERTICES][MAX_VERTICES] = { 

{ 0, 50,45,10,1000,1000},

{ 1000, 0, 10, 15, 1000,1000},

{1000,1000, 0,1000,30,1000},

{20,1000,1000, 0, 15,1000},

{1000, 20,35, 1000, 0,1000},

{ 1000, 1000,1000, 1000,3, 0}

};



int distance[MAX_VERTICES]; //���� �������κ����� �ִ� ��� �Ÿ�

int found[MAX_VERTICES]; //�湮�� ���� ǥ��

int path[MAX_VERTICES][MAX_VERTICES]; //�ִܰŸ� �������� ��ġ�� ������ ����

int check[MAX_VERTICES];//�� �������� ���� ������ ǥ��



void path_init(int path[][MAX_VERTICES]); //path ������� �ʱ�ȭ

int choose(int distance[], int n, int found[]); // �ִܰŸ��� �ִ� ������ ã�� �Լ�

void shortest_path(int start, int n);//�ִ� ��� �˰���



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



//path ������� �ʱ�ȭ

void path_init(int path[][MAX_VERTICES]) {

	int i, j;

	for (i = 0; i < MAX_VERTICES; i++)

		for (j = 0; j < MAX_VERTICES; j++)

			path[i][j] = INF;

}

// �ִܰŸ��� �ִ� ������ ã��

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

//�ִ� ��� �˰���

void shortest_path(int start, int n)

{

	int i, j, u, w;

	for (i = 0; i < n; i++) {

		distance[i] = cost[start][i];

		found[i] = FALSE;

		check[i] = 1;

		path[i][0] = start;

	}



	found[start] = TRUE;//���� ���� �湮 ǥ��

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