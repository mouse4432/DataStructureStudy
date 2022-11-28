// InsertSort QuickSort

#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_SIZE 20

typedef struct{
  char name[MAX_NAME_SIZE];
  int score;
}student;

void quick(student* res,int left, int right);
student* InsertSort(student* list,int n);
student* QuickSort(student* list,int nuber);
void printList(student* list,int n);

int main(void){
  student* list;
  student* Quick;
  student* Insert;
  int number;
  int check =0;

  FILE* fp = fopen("in.txt","r");
  fscanf(fp,"%d",&number);

  list = (student*)malloc(sizeof(student)*number);

  while(!feof(fp)){
    fscanf(fp,"%s %d",list[check].name,&list[check++].score);
  }
  Insert = InsertSort(list,number);
  Quick = QuickSort(list,number);

  printf("before insert sort>>\n");
  printList(list,number);
  printf("after insert sort>>\n");
  printList(Insert,number);

  printf("before quick sort>>\n");
  printList(list,number);
  printf("after quick sort>>\n");
  printList(Quick,number);

  free(list);
  free(Quick);
  free(Insert);

}

student* InsertSort(student* list,int n){
  student* res = (student *)malloc(sizeof(student)*n);
  student tem;
  int i,j;
  for(i=0;i<n;i++){
    res[i] = list[i];
  }

  for(i=1;i<n;i++){
    tem = res[i];
    for(j=i-1;j>=0 && tem.score<res[j].score;j--){
      res[j+1] = res[j];
    }
    res[j+1] = tem;
  }


  return res;
}


void printList(student* list,int n){
  for(int i=0;i<n;i++){
    printf("%9s: %4d\n",list[i].name,list[i].score);
  }
  printf("\n");
}

student* QuickSort(student* list,int n){
  student* res = (student *)malloc(sizeof(student)*n);
  int left = 0,right = n-1;
  for(int i=0;i<n;i++){
    res[i] = list[i];
  }

  quick(res,left,right);

  return res;
}

void quick(student* res,int left, int right){
  int pivot, i,j;
  student temp;
  if(left<right){
    i=left;
    j=right+1;
    pivot=res[left].score;
    do{
      do{
        i++;
      }while(res[i].score>pivot);
      do{
        j--;
      }while(res[j].score<pivot);
      if(i<j){
        temp = res[i];
        res[i]= res[j];
        res[j] = temp;
      }
    }while(i<j);
    temp = res[left];
    res[left]= res[j];
    res[j] = temp;
    quick(res,left,j-1);
    quick(res,j+1,right);
  }
}
