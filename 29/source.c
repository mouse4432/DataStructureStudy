#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 6
#define TRUE 1
#define FALSE 0
#define INF 1000

int cost[][MAX_VERTICES] = {{0,50,45,10,INF,INF},{INF,0,10,15,INF,INF},{INF,INF,0,INF,30,INF},{20,INF,INF,0,15,INF},{INF,20,35,INF,0,INF},{INF,INF,INF,INF,3,0}};

void shortestPath(int search,int* distance, short int* found,int* start); // 가장 짧은 길을 찾아주는 함수
int choose(int* distance, short int* found,int n); //가장 작은 길을 알려주는 함수(?)
void printpath(int* start, int to,int search); // 길을 출력해주는 함수

int main(void){
  int distance[MAX_VERTICES]={0}; //거리 변수
  short int found[MAX_VERTICES]= {0}; // 길이 있는지 알려주는 불린 변수
  int start[MAX_VERTICES]={0}; // startpos 변수
  int search; //start node

  printf("Input start node:");
  scanf("%d",&search);
  printf("[Cost: Path from vertex %d]\n",search);
  shortestPath(search,distance,found,start);

  for(int i =0;i<MAX_VERTICES;i++){
    if(i==search){ // search 면 굳이 출력하지 않아도 됨
      continue;
    }

    printf("[to %d]",i); // to 노드
    if(distance[i]==INF){
      printf("no path\n");
      continue;
    }

    printf("Length: %d, Path:",distance[i]); // 길이 노드
    printpath(start,i,search);
    printf("\n");
  }
}

void shortestPath(int search,int* distance, short int* found,int* start){
  int i, u, w;
  for(i=0;i<MAX_VERTICES;i++){
    found[i]=FALSE;
    start[i]= search;
    distance[i] = cost[search][i];
  }
  found[search] = TRUE;
  distance[search] = 0;

  for(i = 0; i<MAX_VERTICES-2;i++){
    u=choose(distance,found,i);
    found[u] = TRUE;
    for(w=0;w<MAX_VERTICES;w++){
      if(!found[w]){
        if(distance[u]+cost[u][w]<distance[w]){
          distance[w] = distance[u] + cost[u][w];
          start[w]= u;
        }
      }
    }
  }
}

int choose(int* distance, short int* found,int n){
  int i, min, minpos;
  min = INT_MAX;
  minpos= -1;
  for(i=0;i<MAX_VERTICES;i++){
    if(distance[i]<min && !found[i]){
      min = distance[i];
      minpos=i;
    }
  }
  return minpos;
}

void printpath(int* start, int to,int search){ // 재귀함수와 startpos를 활용하여 출력하는 함수
  if(to==search){
    printf(" (%2d)",to);
    return;
  }
  printpath(start,start[to],search);
  printf(" (%2d)",to);
}