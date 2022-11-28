#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct reportCard{
    char name[20];
    int score;
}RC;

RC S[100];
int n;
int pivot;

int static count;


void partition(int low, int high){
    //swap(S[low], S[high]);
    int pivotitem = S[low].score;
    RC tmp;

    int j = low;
    for(int i=low+1; i<=high; i++){
        if(S[i].score<pivotitem){
            j++;
            tmp = S[i];
            S[i] = S[j];
            S[j] = tmp;
            
        }
    }
    pivot = j;
    tmp = S[low];
    S[low] = S[pivot];
    S[pivot] = tmp;
}

void quicksort(int low, int high){  
    if(low<high){
        partition(low, high);
        quicksort(low, pivot-1);
        quicksort(pivot+1, high);
    }
}

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%s %d", S[i].name, &S[i].score);

    printf("before quick sort>>\n");
    for(int i=1; i<=n; i++)
        printf("%2s:  %2d\n", S[i].name, S[i].score);
   
    quicksort(1, n);
    
    printf("\nafter quick sort>>\n");
    for(int i=1; i<=n; i++)
        printf("%2s:  %2d\n", S[i].name, S[i].score);   
}