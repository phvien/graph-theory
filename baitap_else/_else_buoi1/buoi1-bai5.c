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

#define MAX_EDGES 100

typedef struct  {
	 int x, y;
} Edge;
typedef struct {
	int n, m; 				// n la dinh -m la cung
	Edge edges[MAX_EDGES]; 	// mang luu tru cung
} Graph;

// Khoi tao do thi
void init_graph(Graph* G, int n){
	G->n = n;
	G->m = 0;
}

// Them cung vao do thi
void add_edge(Graph* G, int x, int y) {
//   	int i;
//   	for(i=1; i<=G->n; i++){
//   		if(x<=1 && y>=G->n)
//   			if(x>=G->n && y<=1)
//	   		continue;
//	}
//		G->edges[G->m].x=x;
//		G->edges[G->m].y=y;
//		G->m++;
	if(x>=1 && y<=G->n && x<=G->n && y>=1){
		G->edges[G->m].x=x;
		G->edges[G->m].y=y;
		G->m++;
	}	   
	
}

// Kiem tra y co ke voi x.
int adjacent(Graph* G, int x, int y){
	int e;
	for(e=0; e<G->m; e++)
		if((G->edges[e].x==x) && (G->edges[e].y==y) || (G->edges[e].y==x) && (G->edges[e].x==y))
			return 1;
	return 0;
}

void neighbors(Graph* G, int v){
	int y;
	for(y=0; y<G->n; y++)
		if(adjacent(G, v, y))
			printf("%d ", y);
}
			
//		for(e=1; e<=G->m; e++)
//			if(x==1 && G->edges[e].y==1){
//				push_back(&list, e);
//			break;
//			}
		

int main(){
	Graph G; 
	Edge edge;
	int n, m, e, u, v;
	FILE* file = fopen("dothi.txt", "r");
	fscanf(file, "%d%d", &n, &m);
	init_graph(&G, n);
	for(e=1; e<=m; e++){
		fscanf(file, "%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	int i, j;
	for(i=0; i<G.m; i++){
//		for(j=1; j<=G.m; j++)
			printf("%d %d", G.edges[i].x, G.edges[i].y);
		printf("\n");
	}
	printf("\n");

	for(i=1; i<=G.n; i++){
		printf("%d = {", i);
		neighbors(&G, i);
		printf("}\n");
		
	}
	return 0;
}
