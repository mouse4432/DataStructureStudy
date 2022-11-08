#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 200 /* maximum heap size + 1 */
#define HEAP_FULL(n) (n==MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

int heap[MAX_ELEMENTS];
int n = 0;

void push(int item, int* n){
    int i;
    i = ++(*n);
    while((i!=1) && item < heap[i/2]){
        heap[i] = heap[i/2];
        i /=2;
    }   
    heap[i] = item; 
}

int pop(int* n){
    int p, c;
    int item, tmp;

    item = heap[1];
    tmp = heap[(*n)--];
    p = 1;
    c = 2;
    while(c <= *n){
        if((c<*n) && (heap[c] > heap[c+1]))
            c++;
        if(tmp <= heap[c])
            break;
        heap[p] = heap[c];
        p = c;
        c *= 2; 
    }
    heap[p] = tmp;
    return item;
}
int main(){
    int num;
    while(1){
        scanf("%d", &num);
        if(num==-1)
            break;
        push(num, &n);
    }
    printf("before deleting...\n");
   for(int i=1; i<=n; i++)
        printf("%d ", heap[i]);
    
    printf("\ninput delete number: ");
    int del_num;
    scanf("%d", &del_num);
    for(int i=1; i<=del_num; i++){
        printf("item(deleted): %d\n", pop(&n));
    }
    printf("after deleting...\n");
    for(int i=1; i<=n-del_num; i++)
        printf("%d ", heap[i]);
}