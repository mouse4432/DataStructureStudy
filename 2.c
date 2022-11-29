#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[10];
    int key;
}element;


void qsort1(element a[], int left, int right);


int main()
{
    int size, i = 1;
    FILE* fp = fopen("in.txt", "r");
    fscanf(fp, "%d", &size);
    element* e, * e1;
    e = (element*)malloc(sizeof(element) * (size + 1));
    e1 = (element*)malloc(sizeof(element) * (size + 1));
    if (!fp) {
        printf("Cannot open the file");
        exit(1);
    }
    do {
        fscanf(fp, "%s %d", e[i].name, &e[i].key);
        e1[i - 1] = e[i];
        i++;
    } while (!feof(fp));


    
    printf("after quick sort\n");
    qsort1(e1, 0, size-1 );
    for (int j = 0; j < size; j++)
        printf("%s %d\n", e1[j].name, e1[j].key);

    free(e);
    free(e1);


}

void qsort1(element a[], int left, int right)
{
    int pivot, i, j;
    element temp;
    if (left < right) {
        i = left; j = right + 1;
        pivot = a[left].key;
        do {
            do i++; while (a[i].key > pivot);
            do j--; while (a[j].key < pivot);
            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        } while (i < j);
        temp = a[left];
        a[left] = a[j];
        a[j] = temp;
        qsort1(a, left, j - 1);
        qsort1(a, j + 1, right);
    }
}

