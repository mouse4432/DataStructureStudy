#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[10];
	int num;
}element;



void merge(element* list, element* temp, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {//두 정렬된 리스트를 첫 원소부터 비교하여 작은 것 부터 temp에 차례대로 복사
		if (list[i].num >= list[j].num) {
			temp[k] = list[i];
			i++;
			k++;
		}
		else if (list[i].num < list[j].num) {
			temp[k] = list[j];
			j++;
			k++;
		}
	}
	for (i; i <= mid; i++) {//남아 있는 원소 복사
		temp[k++] = list[i];
	}
	for (j; j <= right; j++) {//남아 있는 원소 복사
		temp[k++] = list[j];
	}
	for (int l = left; l <= right; l++) {//정렬된 리스트를 list로 재복사
		list[l] = temp[l];
	}
}

void mergesort(element* list, element* temp, int left, int right) {
	if (right<=left) return;
	int mid = (left + right) / 2;//리스트 균등분할
	mergesort(list, temp, left, mid);//분할 하였을 때 왼쪽 배열 분할
	mergesort(list, temp, mid + 1, right);//분할 하였을 때 오른쪽 배열 분할
	merge(list, temp, left, mid, right);//합병
}

void adjust(element a[], int root, int n) {
	int child, rootnum;
	element temp;
	temp = a[root];
	rootnum = a[root].num;
	child = 2 * root;
	while (child <= n) {
		if ((child < n) && (a[child].num < a[child + 1].num)) child++;//더 큰 child 선택
		if (rootnum > a[child].num) break;//부모노드가 child보다 크다면 break;
		else {
			a[child / 2] = a[child];//child 중 큰 노드를 부모로 옮김
			child *= 2;
		}
	}
	a[child / 2] = temp;
}

void heapsort(element a[], int n) {
	int i, j;
	element temp;

	for (i = n / 2; i > 0; i--) {
		adjust(a, i, n); printf("%d\n", i);
	}
	for (i = n - 1; i > 0; i--) {
		temp = a[1];
		a[1] = a[i + 1];
		a[i + 1] = temp;
		adjust(a, 1, i);
	}
}


void printarr(element* list, int start, int n) {
	for (int i = start; i < n; i++) {
		printf("%8s: %4d\n", list[i].name, list[i].num);
	}
}

void main(void) {
	FILE* fp;
	if ((fp = fopen("in.txt", "r")) == NULL) {
		printf("can't open this file\n");
		exit(1);
	}
	int n;
	fscanf(fp, "%d", &n);
	element* infor = (element*)malloc(sizeof(element) * n);
	element* temp = (element*)malloc(sizeof(element) * n);
	element* heap = (element*)malloc(sizeof(element) * (n + 1));
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%s %d", infor[i].name, &infor[i].num);
		printf("%s %d\n", infor[i].name, infor[i].num);
		heap[i + 1] = infor[i];
	}
	puts(" ");
	mergesort(infor, temp, 0, n - 1);
	printf("after merge sort>>\n");
	printarr(infor, 0, n);
	printf("after heap sort\n");
	heapsort(heap, n);
	printarr(heap, 1, n+1);

	free(infor);
	free(temp);
	free(heap);
}