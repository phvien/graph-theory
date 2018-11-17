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
void add_edge(Graph* G, int x, int y){
	
//	G->A[x][y]=1;	// y ke voi x
//	G->A[y][x]=1;	// x ke voi y
	
	// Truong hop da cung.
	G->A[x][y] += 1;
	G->A[y][x] += 1;
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

int main(){
	Graph G;
	int n=4, i;
	init_graph(&G, n);
	add_edge(&G, 1, 2);
	add_edge(&G, 1, 3);
	add_edge(&G, 1, 3);
	add_edge(&G, 4, 3);
	add_edge(&G, 1, 4);
	
	for(i=1; i<=n; i++){
		printf("deg(%d) = %d\n", i, degree(&G, i));
	}
	return 0;
}




