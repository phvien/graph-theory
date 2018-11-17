#include<stdio.h>

#define MAX_VERTICES 100
typedef struct{
	int n; // n la dinh
	int A[MAX_VERTICES][MAX_VERTICES];	// mang A luu tru dinh - dinh
}Graph;

// Khoi tao do thi G co n dinh
void init_graph(Graph* G, int n){
	int i, j;
	G->n=n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			G->A[i][j]=0;
}

// Them cung e(x, y) vao do thi
void add_graph(Graph* G, int e, int x, int y){
	G->A[x][y]=1;	// y ke voi x
	G->A[y][x]=1;	// x ke voi y
}

// Kiem tra y co ke voi x hay khong
int adjacent(Graph* G, int x, int y){
	return G->A[x][y]!=0;
}

// Tinh bac cua dinh x
int degree(Graph* G, int x){
	int i, deg=0;
	for(i=1; i<=G->n; i++)
		if(G->A[x][i]>0)
		deg++;
	return deg;
}

// Tinh bac truong hop da cung
int degree_second(Graph* G, int x){
	int i, deg=0;
	for(i=1; i<=G->n; i++)
		if(G->A[x][i]>0)
		deg += G->A[x][i];
	return deg;
}

// Tim dinh ke cua x 
void neighbours(Graph* G, int x){
	int y;
	for(y=1; y<=G->n; y++)
		if(adjacent(G, x, y))
			printf("%d ", y);
}

int main(){
	Graph G;
	int n, m, e, u, v;
	FILE* file = fopen("dothi.txt", "r");
	fscanf(file, "%d%d", &n, &m);
	init_graph(&G, n);
	for(e=1; e<=n; e++){
		fscanf(file, "%d%d", &u, &v);
		add_graph(&G, e, u, v);
	}
	int i, j;
	for(i=1; i<=G.n; i++){
		for(j=1; j<=G.n; j++)
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



