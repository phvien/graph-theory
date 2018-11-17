#include <stdio.h>
#include <vector>
using namespace std;

#define MAX_VERTICES 100
// CTDL danh sach dinh ke.
typedef struct{
	int n;	
	vector<int> adj[MAX_VERTICES];
}Graph;

// Khoi tao danh sach.
void init_graph(Graph* G, int n){
	int i, j;
	G->n=n;
	for(i=1; i<=n; i++)
		vector<int> list(G->adj[i]);
}

// Them cung e(x, y) vao do thi G.
void add_edge(Graph* G, int x, int y){
	vector<int> list;
	list.push_back(y);
	list.push_back(x);
}

// Kiem tra y co ke voi x khong.
int adjacent(Graph* G, int x, int y){
	int j;
	vector<int> list;
	for(j=0; j<list.size(); j++)	
		if(list.at(j)==y)
			return 1;
	return 0;
}

//Tinh bac cua dinh x: deg(x).
int degree(Graph* G, int x){
	return G->adj[x].size();
}

int main(){
	Graph G;
	int n, e, u, v, i;
	FILE* file = fopen("dothi.txt", "r");
	fscanf(file, "%d%d", &n);
	init_graph(&G, n);
	for(e=1; e<=n; e++){
		fscanf(file, "%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	for(i=1; i<=n; i++){
		printf("deg(%d) = %d\n", i, degree(&G, i));
	}
	return 0;
}









