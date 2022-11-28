#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_SIZE 20


typedef struct{
  char name[MAX_NAME_SIZE];
  int score;
}student;


void quick(student* res,int left, int right);
student* QuickSort(student* list,int number);
void printList(student* list,int n);


int main(void){
  student* list; // 동적할당할 포인터
  student* Quick; // 저장할 포인터

  int number; // record number
  int check =0; // check

  FILE* fp = fopen("in.txt","r");
  fscanf(fp,"%d",&number);

  list = (student*)malloc(sizeof(student)*number);

  while(!feof(fp)){
    fscanf(fp,"%s %d",list[check].name,&list[check++].score);
  }

  Quick = QuickSort(list,number);
  printf("before quick sort>>\n");
  printList(list,number);
  printf("after quick sort>>\n");
  printList(Quick,number);

  free(list);


}

void printList(student* list,int n){ 
  for(int i=0;i<n;i++){
    printf("%9s: %4d\n",list[i].name,list[i].score);
  }
  printf("\n");
}


student* QuickSort(student* list,int number){ // qucik sort
  student* res = (student *)malloc(sizeof(student)*number); // 동적할당
  int left = 0,right = number-1;
  for(int i=0;i<number;i++){
    res[i] = list[i];
  }

  quick(res,left,right);

  return res;
}

void quick(student* res,int left, int right){
  int pivot, low,high;
  student temp;
  if(left<right){
    low=left-1; // low -1 미리 처리
    high=right; // right
    pivot=res[right].score;
    do{
      do{
        low++;
      }while(res[low].score<pivot);
      do{
        high--;
      }while(res[high].score>pivot);
      if(low<high){ // low가 high 보다 작을시에 스왑
        temp = res[low];
        res[low]= res[high];
        res[high] = temp;
      }
    }while(low<high);

    temp = res[right];
    res[right]= res[low];
    res[low] = temp; // 오른쪽이랑 low랑 위치 스왑

    quick(res,left,low-1); //low를 넘김
    quick(res,low+1,right);
  }



}
