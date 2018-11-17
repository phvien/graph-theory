#define MAX_ELEMENTS 100
#define MAX_EDGES 100
#define MAX_VERTEXES 100
#define MAX_N 100
#define NO_EDGE 0
#define INFINITY 9999999
#include <stdio.h>
typedef struct {
	int n,m;
	int L[MAX_N][MAX_N];
} Graph;
int mark[MAX_N];
int pi[MAX_N];
int p[MAX_N];
int cnt[MAX_N];
typedef struct {
 int data[MAX_N];
 int size;
} List;
void make_null(List* pL) {
	pL->size = 0;
}
void push_back(List* pL, int x) {
	pL->data[pL->size] = x;
	pL->size++;
}
int element_at(List* pL, int p) {
	return pL->data[p-1];
}
void init_graph(Graph* G, int n){
	int i,j;
	G->n=n;
	G->m=0;
	for(i=1;i<=n;i++){
		for (j=1;j<=n;j++)
			G->L[i][j]=NO_EDGE;
		}
}
void add_edge(Graph *G, int u, int v, int w){
	G->m++;
	G->L[u][v]=w;
}
void Dijkstra(Graph* G, int s){
	int i,j,k;
	for(i=1;i<=G->n;i++){
		pi[i]=INFINITY;
		mark[i]=0;
		cnt[i]=0;
	}
	pi[s]=0;
	cnt[s]=1;
	p[s]=-1;
	for(k=1;k<G->n;k++){
		int min_pi=INFINITY;
		for(j=1;j<=G->n;j++){
			if(mark[j]==0 && pi[j]<min_pi){
				min_pi=pi[j];
				i=j;
			}
		}
		mark[i]=1;
		for(j=1;j<=G->n;j++){
			if(G->L[i][j] != NO_EDGE && mark[j]==0)
				if (pi[i]+G->L[i][j]<pi[j]){
					pi[j]=pi[i]+G->L[i][j];
					cnt[j]=cnt[i];
					p[j]=i;
				}
				else if (pi[i]+G->L[i][j]==pi[j])
					cnt[j]++;	
		}
	}
	for (i=1;i<=G->n;i++)
		if(pi[i]==INFINITY)
			pi[i]=-1;
}

int main(){
	Graph G;
	int i, n, m, u, v, w, e;
	//freopen("dt.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n);	
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	Dijkstra(&G,1);
	printf("%d %d",pi[n],cnt[n]);
}
