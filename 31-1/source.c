#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_SIZE 20
#define MAX_SIZE 100


typedef struct{
  char name[MAX_NAME_SIZE];
  int score;
}student;

student sorted[MAX_SIZE];

void MergeSort(student* list,int low,int high);
void merge(student* list,int low, int middle, int high);
void printList(student* list,int n);

int main(void){
  student* list;

  int number;
  int check =0;

  FILE* fp = fopen("in.txt","r");
  fscanf(fp,"%d",&number);

  list = (student*)malloc(sizeof(student)*number);

  while(!feof(fp)){
    fscanf(fp,"%s %d",list[check].name,&list[check++].score);
  }

  printf("before merge sort>>\n");
  printList(list,number);

  MergeSort(list,0,number-1);

  printf("after merge sort>>\n");
  printList(list,number);


}

void MergeSort(student* list,int low,int high){
  int middle;
  if(low<high){
    middle = (low+high)/2;
    MergeSort(list,low,middle); // low~middle
    MergeSort(list,middle+1,high); // middle +1 ~ high
    merge(list,low,middle,high); // low~high sort
  }
}

void merge(student* list,int low, int middle, int high){
  int i=low,j=middle+1,k=low;
  while(i<=middle && j<=high){
    if(list[i].score>=list[j].score){ //왼쪽에 있는게 작으면 i쪽 저장 아니면 j쪽 저장 
      sorted[k++] = list[i++];
      continue;
    }
    sorted[k++] = list[j++]; //
  }
  while(i<=middle){ // i ~ middle까지 끝까지 저장
    sorted[k++] = list[i++];
  }
  while(j<=high){ // j~ high 까지 끝까지 저장
    sorted[k++]= list[j++];
  }
  for(int count =low; count<=high; count++){ // 다시 list에 옮기기
    list[count] = sorted[count];
  }

}

// mergesort

void printList(student* list,int n){
  for(int i=0;i<n;i++){
    printf("%9s: %4d\n",list[i].name,list[i].score);
  }
  printf("\n");
}