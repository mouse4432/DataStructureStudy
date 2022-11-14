// weighted union/ simple Union 수행 후 각각 Collapsing find
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void simpleUnion(int i, int j);
void weightedUnionint(int i, int j);
int collapsingFind(int i);
void printParent(int n);
int *parent;
int main(void){
  int n,i1,i2;
  char instructor[2];
  FILE* fp = fopen("in.txt","r");
  if(!fp){
    fprintf(stderr,"Error : Cannot Find The File");
    exit(EXIT_FAILURE);
  }
  printf("Input size:");
  scanf("%d",&n);
  parent = (int*)malloc(sizeof(int)*(n+1));
  printf("Weighted Union...\n");
  for(int i =0;i<=n;i++){
    parent[i] = -1;
  }
  while(!feof(fp)){
    fscanf(fp,"%s",instructor);
    if(!strcmp(instructor,"U")){
      fscanf(fp,"%d %d",&i1,&i2);
      weightedUnionint(i1,i2);
      printf("U %d %d:",i1,i2);
      printParent(n);
      
    }
    else if(!strcmp(instructor,"F")){
      fscanf(fp,"%d",&i1);
      printf("F %d:",i1);
      printParent(n);
      printf("\nRoot of %d: %d",i1,collapsingFind(i1));
    }
    printf("\n");
  }
  fclose(fp);

  fp = fopen("in.txt","r");
  printf("\nSimple Union...\n");
  for(int i =0;i<=n;i++){
    parent[i] = -1;
  }
  if(!fp){
    fprintf(stderr,"Error : Cannot Find The File");
    exit(EXIT_FAILURE);
  }
  while(!feof(fp)){
    fscanf(fp,"%s",instructor);
    if(!strcmp(instructor,"U")){
      fscanf(fp,"%d %d",&i1,&i2);
      simpleUnion(i1,i2);
      printf("U %d %d:",i1,i2);
      printParent(n);
    }
    else if(!strcmp(instructor,"F")){
      fscanf(fp,"%d",&i1);
      printf("F %d:",i1);
      printParent(n);
      printf("\nRoot of %d: %d",i1,collapsingFind(i1));
    }
    printf("\n");
  }
  fclose(fp);

  return 0;
}

void simpleUnion(int i, int j){
  parent[j] = i;
}
void weightedUnionint(int i, int j){
  int temp = parent[i] + parent[j];
	if(parent[i] > parent[j]){
		parent[i] = j;
		parent[j] = temp;
	}
	else{
		parent[j] = i;
		parent[i] = temp;
	}
}
int collapsingFind(int i){
  int root, trail, lead;
	for(root = i; parent [root] >= 0;root = parent[root])
		;
	for(trail = i; trail != root; trail = lead){
		lead = parent[trail];
		parent[trail] = root;
	}
	return root;
}

void printParent(int n){
  for(int i = 0;i<=n;i++){
    printf("%3d",parent[i]);
  }
}