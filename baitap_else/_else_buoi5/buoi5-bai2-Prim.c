#include<stdio.h>

#define MAX_VERTICES 100
typedef struct{
	int n, m;
	int A[MAX_VERTICES][MAX_VERTICES];
}Graph;

// Khoi tao do thi voi n dinh 
void init_graph(Graph* G, int n){
	int u, v;
	G->n=n;
	for(u=1; u<=n; u++)	
		for(v=1; v<n; v++)
			G->A[u][v]=0;
}

// Them cung vao do thi
void add_edge(Graph* G, int u, int v, int w){
	G->A[u][v]=w;
	G->A[v][u]=w;
}

// CTDL Danh sach
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct{
	ElementType data[MAX_ELEMENTS];
	int size;
}List;

// Khoi tao danh sach rong
void make_null_list(List* L){
	L->size=0;
}

// Them phan tu vao danh sach
void push_back(List* L, int i){
	L->data[L->size]=i;
}

// Lay phan tu tai vi tri thu i
ElementType element_at(List* L, int i){
	return L->data[i-1];
}

// Lay phan tu khong nam trong S nhung gan voi s nhat
#define INFINITY 9999
#define NO_EDGE 0
int distaneFrom(int u, List* L, Graph* G){
	int min_dist = INFINITY;
	int min_v = -1;
	int i;
	for(i=1; i<=L->size; i++){
		int v = element_at(L, i);
		if(G->A[u][v] != NO_EDGE && min_dist > G->A[u][v])
			min_dist = G->A[u][v];
			min_v = v;
	}
	return min_v;
}

// Giai thuat Prim
int mark[MAX_ELEMENTS];
int Prim(Graph* G, Graph* T){
	List L;
	make_null_list(&L);
	init_graph(T, G->n);
	// Khoi tao cac mark[u]=0
	int u, v;
	for(u=1; u<=G->n; u++)	
		mark[u]=0;
	// Cho dinh dau tien vao danh sach de duyet
	push_back(&L, 1);
	mark[1]=1;
	int sum_w=0;
	for(u=1; u<G->n; u++){
		int min_dist = INFINITY;
		int min_u, min_v;
	}
}

int main(){
	return 0;
}





