#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_VERTICES 100
#define MAX_ELEMENTS 100
typedef int ElementType;

typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
} List;
/* Tao danh sach rong */
void make_null(List* L) {
	L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
ElementType element_at(List* L, int i) {
	return L->data[i-1];
}

typedef struct {
	int A[100][100];
	int n;
} Graph;

void init_graph(Graph *G, int n) {
	G->n = n;
	memset(G->A,0,sizeof(G->A));
	}

int adjacent(Graph *G, int x, int y) {
	return G->A[x][y] != 0;
}

List neighbors(Graph *G, int x) {
	List L;
	make_null(&L);
	int y;
	for (y = 1; y <= G->n; y++){
		if (adjacent(G, x, y))
			push_back(&L, y);
	}
	return L;
}

int mark[MAX_VERTICES];
//duyet de qui dinh x
void Traversal(Graph* G, int x){
	// neu x da duyet, khong lam gi ca
	if(mark[x]==1)
	  return;
	mark[x]=1; 
	//lay dinh ke, duyet dinh ke
	List list = neighbors(G,x);
	int i;
	for(i=1;i<=list.size; i++){
		int y = element_at(&list, i);
		Traversal(G,y);
	}
}

int Test(Graph* G,int mark[]){
	int i,k =0;
	for(i=1;i<=G->n; i++){
		if(mark[i]==1)
			k++;
	}
	return k;
}

int Connected(Graph* G){
	int i;
	for(i=1;i<=G->n; i++){
		mark[i] = 0;
	}
	Traversal(G,1);
	if(Test(G,mark)== G->n ){
		return 1;
	}
	return 0;
}
 int main(){
	Graph G;
	int n, m,u,v, e;
	FILE* f = fopen("dothi.txt","r");
	fscanf(f,"%d %d", &n, &m);
	init_graph(&G, n);
	for (e = 1; e <= m; e++) {
		fscanf(f,"%d%d", &u, &v);
		G.A[u][v] = G.A[v][u] = 1;
	}
	if(Connected(&G)==1)
		printf("DUOC");
	else
		printf("KHONG");
}
