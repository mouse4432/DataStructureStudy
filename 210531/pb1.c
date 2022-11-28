#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct reportCard{
    char name[20];
    int score;
}RC;

RC S[100];


void merge2(int low, int mid, int high){
    int i = low, j=mid+1, k = 0;
    // int idx = high-low+1;
    RC U[100];
    while(i<=mid && j<=high)
        U[k++] = (S[i].score > S[j].score) ? S[i++] : S[j++];
    if(i>mid)
        while(j<=high)
            U[k++] = S[j++];
    else
        while(i<=mid)
            U[k++] = S[i++];
    
    for(int t = low; t<=high; t++)
        S[t] = U[t-low];

   
}

void mergesort2(int low, int high)
{
    if(low<high){
        int mid = (low+high)/2;
        mergesort2(low, mid);
        mergesort2(mid+1, high);
        merge2(low, mid, high);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%s %d", S[i].name, &S[i].score);
      
    printf("before merge sort>>\niterative\n");
    for(int i=0; i<n; i++)
        printf("%2s:  %2d\n", S[i].name, S[i].score);
     
    mergesort2(0, n-1);
   
    printf("\n\nafter merge sort>>\niterative\n");
    for(int i=0; i<n; i++)
        printf("%2s:  %2d\n", S[i].name, S[i].score);
}