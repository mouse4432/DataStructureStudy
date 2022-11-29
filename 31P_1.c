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
void merge(STUDENT* list, int left, int middle, int right) {
	/*
	let's say that the list we have consists of two discrete list
	let's call it x,y
	x,y is already sorted, respectively
	all the thing we have to do therefore is to merge
	*/
	STUDENT use[NLIST];
	int indexleft = left;
	int indexright = middle + 1;
	int t = left;
	while (indexleft <= middle && indexright <= right) {
		if (list[indexleft].score >= list[indexright].score) {
			use[t++] = list[indexleft++];
		}
		else {
			use[t++] = list[indexright++];
		}
	}
	if (indexleft > middle) {
		while (indexright <= right) {
			use[t++] = list[indexright++];
		}
	}
	else {
		while (indexleft <= middle) {
			use[t++] = list[indexleft++];
		}
	}
	for (int i = left; i <= right; i++) list[i] = use[i];
}
void mergesort(STUDENT* list, int left, int right) {
	/*
	split the list into two discrete list
	respectly sort the two list
	put the two list together
	*/
	if (left < right) {
		int middle = (left + right) / 2;
		mergesort(list, left, middle);
		mergesort(list, middle + 1, right);
		merge(list, left, middle, right);
	}
}

int main() {
	FILE* pfrom = fopen("in1.txt", "r");
	int n;
	fscanf(pfrom, "%d", &n);
	STUDENT* student = (STUDENT*)malloc(sizeof(STUDENT) * n);
	for (int i = 0; i < n; i++) {
		fscanf(pfrom, "%s %d", student[i].name, &student[i].score);
	}
	fclose(pfrom);

	printf("\nbefore merge sort>>\n");
	printlist(student, n);
	
	printf("\nafter merge sort>>\niterative\n");
	mergesort(student, 0, n - 1);
	printlist(student, n);

	free(student);
}
