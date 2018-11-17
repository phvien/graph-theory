#include<stdio.h>

#define MAX_VESTICES 100
typedef struct{
	int u, v, w;
}Edge;
typedef struct{
	int n, m;
	Edge edge[MAX_VESTICES];
}Graph;

// Khoi tao do thi voi n dinh
void init_graph(Graph* G, int n){
	G->n = n;
	G->m = 0;
}

// Them phan tu vao do thi
void add_edge(Graph* G, int u, int v, int w){
	if(u>=1 && v<=G->n && v>=1 && u<=G->n)
		G->edge[G->m].u = u;
		G->edge[G->m].v = v;
		G->edge[G->m].w = w;
	G->m++;
}

void Swap(Edge* a, Edge* b){
	Edge tmp;
	tmp = *a;
	*a 	= *b;
	*b 	= tmp;
}

void Bubble_Sort(Edge e[], int n){
	int i, j;
	for(i=0; i<=n-2; i++)	
		for(j=n-1; j>=i+1; j--)
			if(e[j].w < e[j-1].w)
				Swap(&e[j], &e[j-1]);
}

int parent[MAX_VESTICES];
// Tim nut goc
int FindRoot(int u){
	if(parent[u] == u)	
		return u;
	return FindRoot(parent[u]);
}

// Giai huat Kruskal
int Kruskal(Graph* G, Graph* T){
	int e, u;
	// Sap xep cung truoc khi chay giai thuat.
	Bubble_Sort(G->edge, G->m);
	init_graph(T, G->n);
	// Gan cac moi dinh la moi bo phan lien thong.
	for(u=0; u<G->n; u++)
		parent[u] = u;
	int sum_w = 0;
	// Duyet cac cung cua G (da duoc sap xep)
	for(e=0; e<G->m; e++){
		int u = G->edge[e].u;
		int v = G->edge[e].v;
		int w = G->edge[e].w;
		int root_u = FindRoot(u);
		int root_v = FindRoot(v);
		// Neu root_u khac root_v tuc thuoc 2 bo phan lien thong khac nhau, them cung u, v vao cay T
		if(root_u != root_v){
			add_edge(T, u, v, w);
			// Gop hai bo phan lien thong lai voi nhau
			parent[root_v] = root_u;
			sum_w += w;
		}
	}
	return sum_w;
}

int main(){
	Graph G, T;
	int n, m, e, u, v, w;
	freopen("dothi.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(e=1; e<=m; e++){
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	
	// In trong luong cua cay T
	int sum_w = Kruskal(&G, &T);
	printf("%d", sum_w);
	
	// In cung theo thu tu tang dan.
	for(e=0; e<T.m; e++){
		if(T.edge[e].u > T.edge[e].v)
			printf("\n%d %d %d", T.edge[e].v, T.edge[e].u, T.edge[e].w);
		else
			printf("\n%d %d %d", T.edge[e].u, T.edge[e].v, T.edge[e].w);
	}
	return 0;
}
