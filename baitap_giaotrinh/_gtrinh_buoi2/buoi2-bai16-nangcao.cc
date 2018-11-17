#include <stdio.h>
#include <stack>
#define MAX_VERTICES 100 
#define MAX_ELEMENTS 100
using namespace std;
typedef struct{
	int n; 
	int A[MAX_VERTICES][MAX_VERTICES];
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
	G->A[x][y] = 1; 
	G->A[y][x] = 1;
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
/* Duyet do thi vo huong theo chieu sau dung ngan xep */ 
void depth_first_search(Graph* G, int i) {  
	stack<int> frontier;
	if(frontier.empty()){
		frontier.push(i);  
	while (!frontier.empty()) {     
		int x = frontier.top(); 
		frontier.pop();
		if(mark[x] != 0) continue; 
		printf("%d\n", x);
		mark[x] = 1;
		List list = neighbors(G, x); 
		int j;
		for (j = 1; j <= list.size; j++) {    
			int y = element_at(&list, j);      
			frontier.push(y);    
			}   
		} 
	}
}

void count_graph(Graph* G){
	int j;  
	for (j = 1; j <= G->n; j++)   
		mark[j] = 0; 
	
	for (j = 1; j <= G->n; j++)   
		if(mark[j]==0)
			depth_first_search(G,j);
}

int main() {
 	freopen("dothi.txt", "r", stdin); 
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	count_graph(&G);
	return 0;
}
