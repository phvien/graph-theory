#include<stdio.h>

#define MAX_N 200
#define NO_EDGE 0
// CTDL Do thi
typedef struct{
	int n, m;
	int L[MAX_N][MAX_N];
}Graph;

void init_graph(Graph* G, int n){
	G->n = n;
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			G->L[i][j]=NO_EDGE;
}

void add_edge(Graph* G, int x, int y, int w){
	G->L[x][y]=w;
//	G->L[y][x]=w;
}

#define INFINITY 999
int mark[MAX_N];
int pi[MAX_N];
int p[MAX_N];

void Dijkstra(Graph* G, int s){
	int i, j, it;
	for(i=1; i<=G->n; i++){
		pi[i]=INFINITY;
		mark[i]=0;
	}
	pi[s]=0;
	p[s]=-1;
	
	for(it=1; it<G->n; it++){
		int min_pi = INFINITY;
		for(j=1; j<=G->n; j++)
			if(mark[j]==0 && pi[j] < min_pi){
				min_pi = pi[j];
				i = j;
			}
		mark[i]=1;
		for(j=1; j<=G->n; j++)
			if(G->L[i][j] != NO_EDGE && mark[j]==0){
				if(pi[i] + G->L[i][j] < pi[j]){
					pi[j] = pi[i] + G->L[i][j];
					p[j]=i;
				}
			}
	}
	for(i=1;i<=G->n;i++){
		if(pi[i]==INFINITY)
		pi[i]=-1;
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
		G.L[u][v]=w;
		G.L[v][u]=w;
	}
	Dijkstra(&G, 1);
	printf("%d ", pi[G.n]);
}


