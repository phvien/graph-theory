#include<stdio.h>

#define MAX_N 9999
#define NO_EDGE 0
// CTDL Do thi
typedef struct{
	int n, m;
	int L[MAX_N][MAX_N];
}Graph;

void init_graph(Graph* G, int n, int m){
	G->n = n;
	G->m = m;
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			G->L[i][j]=NO_EDGE;
}

void add_edge(Graph* G, int x, int y){
	G->L[x][y]=1;
}

#define INFINITY 9999
int mark[MAX_N];
int pi[MAX_N];
int p[MAX_N];

void Dijkstra(Graph* G, int s){
	int u, v, it;
	for(u=1; u<=G->n; u++){
		pi[u]=INFINITY;
		mark[u]=0;
	}
	pi[s]=0;
	mark[s]=-1;
	
	for(it=1; it<G->n; it++){
		int j, min_pi=INFINITY;
		for(j=1; j<=G->n; j++)
			if(mark[j]==0 && pi[j]<min_pi){
				min_pi=pi[j];
				p[j]=u;
			}
			mark[u]=1;
			for(v=1; v<=G->n; v++)
				if(G->L[u][v]+pi[u]<pi[v]){
					pi[v] = pi[u] + G->L[u][v];
					p[v]=u;
				}
	}
}

int u[MAX_N];
int w[MAX_N][MAX_N];

int main(){
	Graph* G;
	int n, m, u, v, i, j;
	freopen("dothi-mecung.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	printf("%d%d", n, m);
	init_graph(G, n, m);
	
//	for(i=1; i<=G->n; i++)
//		for(j=1; j<=G->m; j++){
//			u = i*n+j+1;
//			w[i][j] = u;
////			G->L[i][j]=w;
//			printf("%d", w);
//			printf("%d %d", i, j);
//		}
//	
			
}













