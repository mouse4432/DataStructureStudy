#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 6

int cost[][MAX_VERTICES] = { {0,50,45,10,1000,1000},{1000,0,10,15,1000,1000},
	{1000,1000,0,1000,30,1000},{20,1000,1000,0,15,1000},
	{1000,20,35,1000,0,1000},{1000,1000,1000,1000,3,0} };
short int found[MAX_VERTICES];
int distance[MAX_VERTICES];
int TRUE = 1, FALSE = 0;
int Path[MAX_VERTICES][MAX_VERTICES];

int choose( int n) {
	int i, min, minpos;
	min = 1000;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}


int shortestPath(int v, int n, int path, int fin) {
	int i, u, w;
	for (i = 0; i < n; i++) {//초기회
		found[i] = FALSE;
		distance[i] = cost[v][i];
	}
	found[v] = TRUE;//시작 정점 방문 표
	distance[v] = 0;
	path = 0;
	for (i = 0; i < n-1; i++) {
		//print_status1();
		u = choose(n);
		found[u] = TRUE;
		for (w = 0; w < n; w++)
			if (!found[w])
				if (distance[u] + cost[u][w] < distance[w]) {
					distance[w] = distance[u] + cost[u][w];
				}
		/*printf("distance: %d ", distance[i]);
		for (int k = 0; k <= path; k++) {
			printf("%d ", Path[k]);
		}
		puts(" ");*/
	}
	return path;
}
int main(void) {
	int v;
	printf("Input start node:");
	scanf("%d", &v);
	printf("[Cost: Path from vertex %d]\n", v);
	int cnt = 0;
	while (cnt < MAX_VERTICES) {
		int path = 0;
		if (cnt == v) cnt++;
		else {
			printf("[to %d]", cnt);
			if (distance[cnt] == 1000) {
				printf("no path\n");
				cnt++;
				continue;
			}
			path = shortestPath(v,MAX_VERTICES , path, cnt);
			printf("Length: %d, ", distance[cnt]);
			printf("Path:");
			for (int i = 0; i <= path; i++) {
				printf(" (%2d)", Path[i]);
			}
			puts(" ");
			cnt++;
		}
	}
}
