#include<stdio.h>

#define MAX_ELEMENTS 100
typedef int ElementType;

typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
}List;

// Tao danh sach rong
void make_null(List* L){
	L->size=0;
}

// Them phan tu vao cuoi danh sach
void push_back(List* L, ElementType x){
	L->data[L->size]=x;
	L->size++;
}

// Lay phan tu tai vi tri i, phan tu bat dau tai vi tri 1
ElementType element_at(List* L, int i){
	return L->data[i-1];
}

// Tra ve so phan tu cua danh sach
int count_list(List* L){
	return L->size;
}

#define MAX_VERTICES 100
// CTDL danh sach dinh ke.
typedef struct{
	int n;	
	List adj[MAX_VERTICES];
}Graph;

// Khoi tao danh sach.
void init_graph(Graph* G, int n){
	int i, j;
	G->n=n;
	for(i=1; i<=n; i++)
		make_null(&G->adj[i]);
}

// Them cung e(x, y) vao do thi G.
void add_edge(Graph* G, int x, int y){
	push_back(&G->adj[x], y);
	push_back(&G->adj[y], x);
}

// Kiem tra y co ke voi x khong.
int adjacent(Graph* G, int x, int y){
	int j;
	for(j=1; j<=G->adj[x].size; j++)	
		if(element_at(&G->adj[x], j)==y)
			return 1;
	return 0;
}

//Tinh bac cua dinh x: deg(x).
int degree(Graph* G, int x){
	return G->adj[x].size;
}


