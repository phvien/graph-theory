#include<stdio.h>

#define MAX_VERTICES 100
#define MAX_EDGES 200

// Khai bao kieu cau truc 
typedef struct{
	int n, m; 						// n la dinh, m la cung
	int A[MAX_VERTICES][MAX_EDGES]; // dung mang luu tru dinh - cung
}Graph;

// Khoi tao do thi
void init_graph(Graph *G, int n, int m){
	int i, j;
	G->n=n;
	G->m=m;
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
		G->A[i][j]=0;
}

// Them cung e(x, y) vao do thi
void add_edge(Graph *G, int e, int x, int y){
	G->A[x][e]=1;
	G->A[y][e]=1;
}

//Tinh bac cua dinh x	
int degree(Graph *G, int x){
	int e, deg=0;
	for(e=1; e<=G->m; e++)
		if(G->A[x][e]==1)
			deg++;
	return deg;
}

// Ham kiem tra y co ke voi x khong
int adjacent(Graph* G, int x, int y){
	int e;
	for(e=1; e<=G->m; e++)
		if(G->A[x][e]==1 && G->A[y][e]==1)
			return 1;
		return 0;
}

// Ham in danh sach dinh ke voi x
void neighbours(Graph* G, int x){
	int y; 
	for(y=1; y<=G->m; y++)
		if(adjacent(G, x, y))
			printf("%d ", y);
}

int main(){
	Graph G;
	int n, m, u, v, e;
	FILE* file = fopen("dothi.txt", "r");
	fscanf(file, "%d%d", &n, &m);
	init_graph(&G, n, m);
	for(e=1; e<=m; e++){
		fscanf(file, "%d%d", &u, &v);
		add_edge(&G, e, u, v);
	}
	int i, j;
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++)
			printf("%d ", G.A[i][j]);
		printf("\n");
	}
	
	for(i=1; i<=n; i++){
		printf("%d = {", i);
		neighbours(&G, i);
		printf("}\n");
	}
		
		
	return 0;
}


