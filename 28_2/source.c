#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VISITED 100

typedef struct queue{
  int vertex;
  struct queue* next;
}queue; 

queue* front, *rear;
int visited[MAX_VISITED];

void dfs(int v, int ** matrix,int vertex_num);
void bfs(int v, int** matrix, int vertex_num);
void addq(int v);
int deleteq();

int main(void){
  int** matrix;
  FILE* fp = fopen("in.txt","r");
  int vertex_num,tem;
  int count = 1;
	if(!fp){
		fprintf(stderr,"Error : Cannot Find The File");
		exit(EXIT_FAILURE);
	}

  fscanf(fp,"%d",&vertex_num);
  matrix = (int**)malloc(sizeof(int*)*vertex_num);

  for(int i=0;i<vertex_num;i++){
    matrix[i] = (int*)malloc(sizeof(int)*vertex_num);
		visited[i] = FALSE;
  }
	for(int i =0;i<vertex_num;i++){
		for(int j=0;j<vertex_num;j++){
			fscanf(fp,"%d",&tem);
			matrix[i][j] = tem;
		}
	}
	printf("by DFS:\n");
  for(int i=0;i<vertex_num;i++){
    if(!visited[i]){
      printf("Component #%d:",count++);
      dfs(i, matrix,vertex_num);
      printf("\n");
    }
  }
  for(int i=0;i<vertex_num;i++){
    visited[i]= FALSE;
  }
  count = 1;
  printf("\nby BFS:\n");
  for(int i=0;i<vertex_num;i++){
    if(!visited[i]){
      printf("Component #%d:",count++);
      bfs(i, matrix,vertex_num);
      printf("\n");
    }
  }
	
	for(int i=0;i<vertex_num;i++){
		free(matrix[i]);
	}
	free(matrix);

	return 0;
}

void dfs(int v, int** matrix,int vertex_num){
  int i =v;
	visited[v] = TRUE;
	printf("%5d",v);
	for(int j=0;j<vertex_num;j++){
		if(!visited[j]&&matrix[i][j]){
			dfs(j,matrix,vertex_num);	
		}
	}
}

void bfs(int v,int** matrix,int vertex_num){
	front =NULL;
	rear = NULL;
	printf("%5d",v);
	visited[v] = TRUE;
	addq(v);
	while(front){
		v = deleteq();
		for(int j = 0; j<vertex_num; j++){
			if(!visited[j] && matrix[v][j]){
				printf("%5d",j);
				addq(j);
				visited[j] = TRUE;
			}
		}
	}
}

void addq(int v){
	queue* tem = malloc(sizeof(queue));
	tem->vertex =v;
	tem->next=NULL;
	if(front == NULL){
		front = tem;
		rear = tem;
		return;
	}
	rear->next =tem;
	rear = rear->next;

}
int deleteq(){
	queue* delnode = front;
	int res = front->vertex;
	front = front->next;
	free(delnode);
	return res;
}
