#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct {
	int key;
}element;

element heap[MAX];
element queue[MAX];
int rear = -1, front = -1;
int n = 0;

void push(element item);
element pop();
void levelOrder(element ptr[]);

void main(void) {
	element data;
	int num;

	FILE* fp;
	if ((fp = fopen("heap.txt", "r")) == NULL) {
		printf("can't open this file\n");
		exit(1);
	}

	while ((fscanf(fp, "%d", &data.key)) != EOF) {
		push(data);
	}
	puts(" ");
	printf("before deleting...\n");
	levelOrder(heap);
	printf("\ninput delete number: ");
	scanf("%d", &num);
	int i = 0;
	while (i < num) {
		printf("item(deleted): ");
		data = pop();
		printf("%d\n", data.key);
		i++;
	}
	printf("after deleting...\n");
	levelOrder(heap);

}
void push(element item) {
	int i = 0;
	if (n == MAX - 1) {
		printf("The heap is full.\n");
		exit(1);
	}
	i = ++n;
	while ((i != 1) && (item.key < heap[i / 2].key)) {//부모노드와 값비교
		heap[i] = heap[i / 2];
		i /= 2;
	}//부모노드와 비교하여 key값이 부모보다 작을 동안 부모를 자식노드로 보냄
	heap[i] = item;
}
element pop() {
	int parent, child;
	element item, temp;
	if (n == 0) {
		printf("The heap is empty\n");
		exit(1);
	}
	item = heap[1];
	temp = heap[n--];
	parent = 1;
	child = 2;
	while (child <= n) {
		if ((child < n) && heap[child].key > heap[child + 1].key) child++;
		if (temp.key <= heap[child].key) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}

void levelOrder(element ptr[]) {

	for (int i = 1; i <= n; i++) {
		printf("%d ", ptr[i].key);
	}
	printf("\n");
}
void addq(element ptr) {
	if (rear == MAX - 1) {
		printf("queue is full\n");
		return;
	}
	queue[rear++] = ptr;
}
element deleteq() {
	element data;
	if (front == rear) {
		data.key=0;
		return data;
	}
	return queue[front++];
}