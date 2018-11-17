#include <stdio.h>
#include <queue>
using namespace std;
#define MAX_VERTICES 100 
#define MAX_EDGES 200
#define MAX_ELEMENTS 100

typedef struct{	
	int n, m;
	int A[MAX_VERTICES][MAX_EDGES];	
}Graph;

typedef int ElementType;

typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
} List;

void make_null(List* L) {
	L->size = 0;
}

void push_back(List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}

ElementType element_at(List* L, int i) {
	return L->data[i-1];
}

int count_list(List* L) {
return L->size;
}

void init_graph(Graph *G, int n) {
	int i, j;
	G->n = n;
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
		G->A[i][j]=0;
}

void add_edge(Graph *G, int x, int y) {
	G->A[x][y] += 1; 
	G->A[y][x] += 1;
}
int adjacent(Graph *G, int x, int y) {
	return G->A[x][y] != 0;
}

List neighbors(Graph *G, int x) {
	int y;
	List list;
	make_null(&list);
	for(y=1; y <= G->n; y++)
		if(adjacent(G,x,y))
			push_back(&list, y);
	return list;
}

int mark[MAX_VERTICES];	
void breath_first_search(Graph *G, int x){
	queue<int> frontier;
	if(frontier.empty()){
		int j, i;
	for (j = 1; j <= G->n; j++)
		mark[j] = 0;
	for(i=1; i <= G->n; i++)
		if(mark[i]==0){
			frontier.push(i);
			mark[i] = 1;
			while (!frontier.empty()) {
				int x = frontier.front();
				frontier.pop(); 
				printf("%d\n", x);
				List list = neighbors(G, x); 
				for (j = 1; j <= list.size; j++) {
					int y = element_at(&list, j);
					if (mark[y] == 0) { 
						mark[y] = 1; 
						frontier.push(y); 
					}
				}	
			}
		}
	}	
}

int main() {
	freopen("dothi.txt", "r", stdin);
	Graph G;
	int n, m, u, v, w, e, y;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	breath_first_search(&G,n);
	return 0;
}
