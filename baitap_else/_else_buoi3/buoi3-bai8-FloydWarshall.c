#define MAXN 100 
#define INFINITY 999999999 
#include <stdio.h>
#define NO_EDGE 0
int mark[MAXN]; 
int pi[MAXN][MAXN];
int next[MAXN][MAXN];

typedef struct { 
	int n;
	int L[MAXN][MAXN];

} Graph;
void init_graph(Graph *G,int n) {
	int i,j;
	G->n = n;
	for (i = 1; i <=G->n;i++)
		for (j = 1;j <=G->n; j++)
			G->L[i][j] = NO_EDGE;
}
void add_edge(Graph* G,int u,int v,int w) {
	
	G->L[u][v] = w;
}

void Floyd_warshall(Graph* G) {
	int u,v,k;
	for(u=1; u<=G->n; u++)
		for(v=1;v<=G->n;v++) {
			pi[u][v] = INFINITY;
			next[u][v] = -1;
		}
		
		for(u=1; u<=G->n; u++) {
			pi[u][u] = 0;
		}
		for(u=1; u<=G->n;u++) 
			for(v=1;v<=G->n;v++) {
				if(G->L[u][v] != NO_EDGE) {
					pi[u][v] = G->L[u][v];
					next[u][v] = v;
				}
			}
		for(k=1;k<=G->n;k++) {
			for(u=1;u<=G->n;u++) {
				for(v=1;v<=G->n;v++) {
					if(pi[u][v] > pi[u][k] + pi[k][v]) {
						pi[u][v] = pi[u][k] +pi[k][v];
						next[u][v] = next[u][k];
					}
				}
			}
		}
}
void main() {
//	freopen("dt.txt", "r", stdin);
	Graph G;
	int n,m,u,v,w,e;
	int i;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for(e =1; e <= m; e++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G, u, v, w);
	}
	Floyd_warshall(&G);
	for(u = 1;u <= G.n; u++)
		for(v = 1; v <= G.n; v++)
			if (pi[u][v] > INFINITY/2) printf("%d -> %d: oo\n",u,v);
			 else printf("%d -> %d: %d\n", u,v,pi[u][v]);	
}

