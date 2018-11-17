#include<stdio.h>

typedef struct{
	int u, v; 
	int w;
}Edge;

typedef struct{
	int n, m;
	Edge edges[1000];
}Graph;

void init_graph(Graph* G, int n){
	G->n = n;
	G->m = 0;
}

void add_edge(Graph* G, int u, int v, int w){
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
	G->m++;
}

#define INFINITY 9999
#define MAX_N 100
int pi[MAX_N];
int p[MAX_N];

void BellmanFord(Graph* G, int s){
	int j, it, u, v, w, k;
	
	for(u=1; u<=G->n; u++){
		pi[u] = INFINITY;
	}
	pi[s]=0;
	p[s]=-1;
	
	for(it=1; it<G->n; it++){
		for(j=0; j<G->m; j++){
			u = G->edges[j].u;
			v = G->edges[j].v;
			w = G->edges[j].w;
			if(pi[u] + w < pi[v]){
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
	for(k = 0; k<G->m; k++){
		int u = G->edges[k].u;
		int v = G->edges[k].v;
		int w = G->edges[k].w;
        if(pi[u] + w < pi[v]){}
    }
}

int main(){
	freopen("dothi.txt", "r", stdin);
	Graph G;
	int n, m, u, v, w, e, i, j;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(e=1; e<=m; e++){
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	BellmanFord(&G, 1);
	if(pi[n]<0)
		printf("-1");
	else 
		printf("%d", pi[n]);
}
