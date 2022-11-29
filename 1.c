#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
# define MAX_SIZE 100

typedef struct {
    char name[50];
    int score;
}lionking;
lionking sorted[MAX_SIZE]; 


void merge(lionking* list, int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    
    while (i <= mid && j <= right) {
        if (list[i].score <= list[j].score)
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    while (i <= mid) sorted[k++] = list[i++];
    while (j <= right) sorted[k++] = list[j++];
    for (int a = left; a <= right; a++) list[a] = sorted[a];
   
}


void merge_sort(lionking* list, int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(list, left, mid); 
        merge_sort(list, mid + 1, right); 
        merge(list, left, mid, right); 
    }
}

int main() {
    
    lionking* list;
    int num;
    int tmp = 0;
    
    FILE* fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &num);
    list = (lionking*)malloc(sizeof(lionking) * num);
    while (!feof(fp)) 
    {
        fscanf(fp, "%s %d", list[tmp].name, &list[tmp++].score);
    }
    
    printf("before merge sort>>\n");
    for (int i = 0; i < num; i++) {
        printf("%5s: %4d\n", list[i].name, list[i].score);
    }
    printf("\n");
    
    merge_sort(list, 0, num - 1);
    printf("after merge sort>>\n");
    
    for (int i = 0; i < num; i++) {
        printf("%5s: %4d\n", list[i].name,list[i].score);
    }

    return 0;
}