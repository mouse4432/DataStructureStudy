#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n==MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
    int key;
} element ;

element heap[MAX_ELEMENTS];
int n = 0;

void push(element item, int *n)
{
    int i;
    if (HEAP_FULL(*n))
    {
        fprintf(stderr, "The heap is full\n");
        exit(EXIT_FAILURE);
    }
    i = ++(*n);
    while ((i != 1) && (item.key < heap[i/2].key))
    {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}

element pop(int *n)
{
    int parent, child;
    element item, temp;
    if (HEAP_EMPTY(*n)) {
        fprintf(stderr, "The heap is empty\n");
        exit(EXIT_FAILURE);
    }
    item = heap[1];
    temp = heap[(*n)--];
    parent = 1;
    child = 2;
    while (child <= *n) {
        if ((child < *n) && (heap[child].key > heap[child+1].key))
            child++;
        if (temp.key <= heap[child].key) break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}

void print()
{
    for (int i = 1; i <= n; i++)
        printf("%3d", heap[i].key);
    puts("");
}

int main(void)
{
    element item;
    int num, del;
    FILE *f = fopen("heap.txt", "r");
    if (!f)
    {
        fprintf(stderr, "cannot open file!!\n");
        exit(EXIT_FAILURE);
    }
    while (!feof(f))
    {
        fscanf(f, "%d", &item.key);
        push(item, &n);
    }
    
    printf("before deleting...\n");
    print();

    printf("input delete number:");
    scanf("%d", &del);
    for (int i = 0; i < del; i++)
        printf("item(deleted): %d\n", pop(&n).key);

    printf("after deleting...\n");
    print();

    fclose(f);
    return 0;
}