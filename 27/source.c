#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct node{
  int num;
  struct node* link;
}node;

int main(void){
  int ver;
  int a1,a2;
  node** list;
  int** vermatrix;
  int outdegree[MAX_SIZE]={0},indegree[MAX_SIZE]={0};
  FILE* fp=fopen("in.txt","r");
  if(!fp){
    fprintf(stderr,"Error : Cannot Find The File");
    exit(EXIT_FAILURE);
  }

  fscanf(fp,"%d",&ver);

  vermatrix = (int**)malloc(sizeof(int*)*ver);
  for(int i =0;i<ver;i++){
    vermatrix[i] = (int*)malloc(sizeof(int)*ver);
  }
  for(int i=0;i<ver;i++){
    for(int j=0;j<ver;j++){
      vermatrix[i][j]=0;
    }
  }

  list = (node**)malloc(sizeof(node*)*ver);
  for(int i =0;i<ver;i++){
    list[i] = (node*)malloc(sizeof(node));
    list[i]->num=i;
    list[i]->link = NULL;
  }

  while(!feof(fp)){
    fscanf(fp,"%d %d",&a1,&a2);
    node* tem=malloc(sizeof(node));
    tem->num = a2;
    tem->link=list[a1]->link;
    list[a1]->link = tem;
    vermatrix[a1][a2]= 1;
    outdegree[a1] +=1;
    indegree[a2]+=1;
  }

  printf("Adjacency matrix...\n");
  for(int i=0;i<ver;i++){
    for(int j=0;j<ver;j++){
      printf("%2d",vermatrix[i][j]);
    }
    printf("\n");
  }  
  printf("\n\n");
  
  printf("Linked adjacency list...\n");
  for(int i=0;i<ver;i++){
    node*p = list[i];
    printf("[%2d]",i);
    while(p->link !=NULL){
      p = p->link;
      printf("%2d",p->num);
    }
    printf("\n");
  }

  printf("\n\nIndegree..\n");
  for(int i=0;i<ver;i++){
    printf("[%2d] %2d\n",i,indegree[i]);
  }

  printf("\n\nOutdegree..\n");
  for(int i=0;i<ver;i++){
    printf("[%2d] %2d\n",i,outdegree[i]);
  }

}