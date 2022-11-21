#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define  VERT 6
#define MAX 1000


int cost[][VERT] = 
{{0, 50, 45, 10, MAX, MAX}, {MAX, 0, 10, 15, MAX, MAX},
{MAX, MAX, 0, MAX, 30, MAX}, {20, MAX, MAX, 0, 15, MAX},
{MAX, 20, 35, MAX, 0, MAX}, {MAX, MAX, MAX, MAX, 3, 0}};
int n = 6;
int found[6];
int distance[6];
int path[6];
int print_path[6];


int choose(){
    int min = MAX;
    int minpos = -1;
    for(int i=0; i<n; i++){
        if(distance[i] < min && !found[i]){
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}

void shortestpath(int v){
    int u;
    int p_count=1;
    for(int i=0; i<n; i++){
        found[i] = 0;
        path[i] = v;
        distance[i] = cost[v][i];
        
    }
    found[v] = 1;
    distance[v] = 0;
    for(int i=0; i<n-2; i++){
        u = choose();
        found[u] = 1;
        for(int w=0; w<n; w++){
            if(!found[w]){
                if(distance[u] + cost[u][w] < distance[w]){
                    distance[w] = distance[u] + cost[u][w];
                    path[w] = u;
                }
            }   
        }
    }
}

int main(){
    int node;
    printf("Input start node:");
    scanf("%d", &node);

    shortestpath(node);
    printf("[Cost: Path from vertex %d]\n", node);
    
    for(int i=0; i<n; i++){
        if(i==node)
            continue;
        else{
            if(distance[i] == MAX){
                printf("[to %d]no path\n", i);
            }
            else{
                printf("[to %d]Length: %d, Path: ", i, distance[i]);
                
                for(int j=0; j<6; j++)
                    print_path[j] = 0;
                print_path[0] = i;
                int idx = 1;
                int tmp = i;
                while(tmp != node){
                    print_path[idx++] = path[tmp];
                    tmp = path[tmp];
                }

                for(int j=idx-1; j>=0; j--)
                    printf("( %d) ", print_path[j]);
                printf("\n");
            }
        }
    }
}