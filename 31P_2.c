#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define True 1
#define False 0
#define NLIST 20
#define NLINE 21

typedef struct STUDENT {
	char name[NLINE];
	int score;
}STUDENT;

void printlist(STUDENT* list, int n) {
	for (int i = 0; i < n; i++) {
		printf("%8s:%4d\n", list[i].name, list[i].score);
	}
}
int partition(STUDENT* list, int left, int right) {
	/*
	let's locate the first element of the list behind all of the elements that is smaller than the first element
	let's locate the first element of the list before all of the elements that is bigger than the first element
	*/
	int criterion = list[left].score;
	int bottom = left;
	int top = right + 1;
	do {
		do {
			bottom++;
		} while (list[bottom].score < criterion);
		do {
			top--;
		} while (list[top].score > criterion);
		if (bottom < top) {
			STUDENT t = list[top];
			list[top] = list[bottom];
			list[bottom] = t;
		}
	} while (bottom < top);
	STUDENT t = list[left];
	list[left] = list[top];
	list[top] = t;
	return top;
}
void quicksort(STUDENT* list, int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quicksort(list, left, q - 1);
		quicksort(list, q + 1, right);
	}
}

int main() {
	FILE* pfrom = fopen("in2.txt", "r");
	int n;
	fscanf(pfrom, "%d", &n);
	STUDENT* student = (STUDENT*)malloc(sizeof(STUDENT) * n);
	for (int i = 0; i < n; i++) {
		fscanf(pfrom, "%s %d", student[i].name, &student[i].score);
	}
	fclose(pfrom);

	printf("\nbefore quick sort>>\n");
	printlist(student, n);

	printf("\nafter quick sort>>\n");
	quicksort(student, 0, n - 1);
	printlist(student, n);

	free(student);
}
