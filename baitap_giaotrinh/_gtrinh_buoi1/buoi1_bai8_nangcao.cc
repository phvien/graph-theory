#include<stdio.h>
#include<vector>

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
	vector<int> list;
	return list.size();
}

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
	int n, m, x, y, u, v;
	FILE* file = fopen("dothi.txt","r");
	fscanf(file,"%d%d",&n,&m);
	init_graph(&G,n);
	for(x=1; x<=m; x++){
		fscanf(file,"%d%d",&u,&v);
		add_edge(&G,u,v);
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









