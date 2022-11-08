#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define N_DATA 20
#define TRUE 1
#define FALSE 0

typedef struct NODE* LINK;
typedef struct NODE {
	int d;
	LINK linkleft, linkright;
}NODE;

int heap(LINK* h, int n, int count);
void levelorder(LINK h);
int deletenode(LINK* h, int n, int count);

int main() {
	LINK link[N_DATA] = { NULL };
	FILE* pfrom = fopen("heap.txt", "r");
	int n, count = 0;
	while (!feof(pfrom)) {
		fscanf(pfrom, "%d", &n);
		count = heap(link, n, count);
	}
	fclose(pfrom);
	printf("before deleting...\n");
	levelorder(link[1]);
	printf("\ninput delete number : ");
	scanf("%d", &n);
	count = deletenode(link, n, count);
	printf("after deleting...\n");
	levelorder(link[1]);
}

int heap(LINK* h, int n, int count) {
	count += 1;
	int index = count;
	if (!h[1]) {
		h[index] = malloc(sizeof(NODE));
		h[index]->linkleft = NULL;
		h[index]->linkright = NULL;
		h[index]->d = n;
		return count;
	}

	h[index] = malloc(sizeof(NODE));
	h[index]->linkleft = NULL;
	h[index]->linkright = NULL;
	h[index]->d = n;
	int finder = index / 2;
	if (index % 2) {
		h[finder]->linkright = h[index];
	}
	else {
		h[finder]->linkleft = h[index];
	}

	while (h[finder]->d > h[index]->d) {
		int t = h[index]->d;
		h[index]->d = h[finder]->d;
		h[finder]->d = t;
		if (finder == 1) continue;
		finder /= 2;
		index /= 2;
	}
	return count;
}
void levelorder(LINK h) {
	LINK linkqueue[N_DATA];
	int open = -1, close = -1;
	linkqueue[++close] = h;
	while (TRUE) {
		if (open == close) {
			break;
		}
		h = linkqueue[++open];
		printf("%4d", h->d);
		if (h->linkleft) linkqueue[++close] = h->linkleft;
		if (h->linkright) linkqueue[++close] = h->linkright;
	}
}
int deletenode(LINK* h, int n, int count) {
	for (int loop = 0; loop < 4; loop++) {
		printf("item(deleted) : %d\n", h[1]->d);
		h[1]->d = h[count]->d;
		if (count % 2) {
			h[count / 2]->linkright = NULL;
		}
		else {
			h[count / 2]->linkleft = NULL;
		}
		count--;

		int location = 1;
		while (2 * location + 1 <= count) {
			int up, down;
			if (h[2 * location]->d < h[2 * location + 1]->d) {
				up = h[2 * location + 1]->d;
				down = h[2 * location]->d;
				if (down > h[location]->d) break;
				else {
					int t = h[2 * location]->d;
					h[2 * location]->d = h[location]->d;
					h[location]->d = t;
					location = location * 2;
				}
			}
			else if (h[2 * location]->d > h[2 * location + 1]->d) {
				up = h[2 * location]->d;
				down = h[2 * location + 1]->d;
				if (down > h[location]->d) break;
				else {
					int t = h[2 * location + 1]->d;
					h[2 * location + 1]->d = h[location]->d;
					h[location]->d = t;
					location = location * 2 + 1;
				}
			}
			else {
				up = h[2 * location + 1]->d;
				down = h[2 * location]->d;
				if (down > h[location]->d) break;
				else {
					int t = h[2 * location]->d;
					h[2 * location]->d = h[location]->d;
					h[location]->d = t;
					location = location * 2;
				}
			}
		}
	}
	return count;
}
