#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 6

int cost[][MAX] = { {0,50,45,10,1000,1000},{1000,0,10,15,1000,1000},{1000,1000,0,1000,30,1000},{20,1000,1000,0,15,1000},{1000,20,35,1000,0,1000},{1000,1000,1000,1000,3,0} };
int min;
int sum = 0;

int findmin(int num);
int visit[100] = { 0 };

int findpath(int num);

int main(void) {
	int num;int cnt = 0;
	
	printf("Input start node: ");
	scanf("%d", &num);
	printf("[Const: path from vertex %d]", num);

	for (int i = 0; i < MAX; i++) {
		
		if (num != i) {
			printf("\n[to %d] Length: %d, Path: (%d) ",i, findmin(num), num);
		}
		findpath(num);

		for (int i = 0; i < MAX; i++) {
			visit[i] = 0;
		}
	}
	
	
}

int findmin(int num) {
	
		/*for (int j = 0; j < MAX; j++) {
				min = cost[num][0];
				if (visit[j] != 1) {
					if (cost[num][j] < min && cost[num][j] != 0) {
						min = cost[num][j];
						findmin(j);

					}
				}
		}*/

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (i == num) {
				min = cost[i][0];
				if (visit[j] != 1) {
					if (cost[i][j] < min && cost[i][j] != 0) {
						min = cost[i][j];
						findmin(j);
					}
				}

			}
		}
		
	}
	sum += min;
	
	return sum;
}

int findpath(int num) {

	/*for (int i = 0; i < MAX; i++) {
		if (findmin(num) == cost[num][i]) {
			if (visit[i] ==0) {
				visit[i] = 1;
				printf("(%d) ", i);
			}
		}
	}*/
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (i == num) {
				min = cost[i][0];
				if (visit[j] != 1) {
					if (cost[i][j] < min && cost[i][j] != 0) {
						min = cost[i][j];
						visit[j] = 1;
						printf("(%d) ", j);
						findpath(j);
					}
				}

			}
		}
	}
}