#include<stdio.h>
#include<vector>

using namespace std;

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

//  Truong hop da cung.
	G->A[x][y]+=1;
	G->A[y][x]+=1;
}

// Kiem tra y co ke voi x hay khong
int adjacent(Graph* G, int x, int y){
	return G->A[x][y]!=0;
}

// Tinh bac cua dinh x
int degree(Graph* G, int x){
//	int i, deg=0;
//	for(i=1; i<=G->n; i++)
//		if(G->A[x][i]>0)
//		deg++;
	// Truong hop da cung
	int y, deg=0;
	for(y=1; y<=G->n;y++)
		deg+=G->A[x][y];
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

// Lay danh sach dinh ke.
//List neighbors(Graph* G, int x){
//	int y;
//	List list;
//	make_null(&list);
//	for(y=1; y<= G->n; y++)
//		if(adjacent(G, x, y))
//			push_back(&list, y);
//	return list;
//}

vector<int> neighbors(Graph* G, int x){
	int y;
	vector<int> list;
	for(y=1; y<=G->n; y++)
		if(adjacent(G, x, y))
			list.push_back(y);
	return list;
}


int main(){
	Graph G;
	int n, m, e, u, v, y, x;
	FILE* file = fopen("dothi.txt", "r");
	fscanf(file, "%d%d", &n, &m);
	init_graph(&G, n);
	for(e=1; e<=m; e++){
		fscanf(file, "%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	for(x=1; x<=n; x++){
		vector<int> list = neighbors(&G, x);
		printf("Dinh ke cua %d: [", x);
		for(y=0; y<list.size(); y++)
			printf("%d ", list[y]);
		printf("]\n");
	}
	return 0;
}


