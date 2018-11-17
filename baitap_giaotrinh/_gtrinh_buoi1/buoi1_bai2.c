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

int main(){
	Graph G;
	int n=7, m=8, i;
	// Khoi tao do thi voi so dinh = 4 va cung = 5.
	init_graph(&G, n, m);	
	// Them cung e(x, y) vao do thi.
	add_edge(&G, 1, 1, 2);	
	add_edge(&G, 2, 1, 3);
	add_edge(&G, 3, 1, 3);
	add_edge(&G, 4, 3, 6);
	add_edge(&G, 5, 1, 4);
	add_edge(&G, 6, 3, 4);
	add_edge(&G, 7, 5, 6);
	add_edge(&G, 8, 5, 6);
	add_edge(&G, 9, 4, 5);
	add_edge(&G, 0, 7, 7);
	int j;
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++)
			printf("%d ", G.A[i][j]);
		printf("\n");
	}
	
	for(i=1; i<=n; i++){
		printf("deg(%d) = %d\n", i, degree(&G, i));
	}
	return 0;
}



