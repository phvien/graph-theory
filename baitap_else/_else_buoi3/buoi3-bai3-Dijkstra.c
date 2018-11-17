#include<stdio.h>

// do thi

#define MAXN 100
#define NO_EDGE -999

typedef struct{
	int n;
	int L[MAXN][MAXN];
}Graph;

void init_graph(Graph* G, int n){
	G->n=n;
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			G->L[i][j] = NO_EDGE;
}

void add_edge(Graph* G, int u, int v, int w){
	//vo huong
	G->L[u][v]=w;
	G->L[v][u]=w;	
	
	/*co huong
	G->L[u][v]=w;
	*/
}


// tim duong di ngan nhat

#define INFINITY 999999

int mark[MAXN];
int pi[MAXN];
int p[MAXN];

void Dijkstra(Graph* G, int s){
	int i, j, it;
	for(i=1; i<=G->n; i++){
		pi[i] = INFINITY;
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
			if(G->L[i][j]!=NO_EDGE && mark[j]==0){
				if(pi[i] + G->L[i][j] < pi[j]){
					pi[j] = pi[i] + G->L[i][j];
					p[j] = i;
				}
			}
	} 
}

void walk(Graph* G, int u){
	int path[MAXN];
	int k = 0;
	int current = u;
	
	while(current != -1){
		path[k] = current;
		k++;
		current = p[current];
	}
	
	int i;
	for(i=k-1; i>=0; i--)
		printf("%d -> ",path[i]);
}

int main(){
	Graph G;
	int m, n, x, y, w, i;
	FILE* f = fopen("dothi.txt","r");
	fscanf(f,"%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1; i<=m; i++){
		fscanf(f,"%d%d%d",&x,&y,&w);
		add_edge(&G,x,y,w);
	}
	
	Dijkstra(&G,2);
	printf("%d\n",pi[n]);	
	printf("\n");	
//	walk(&G,2);
	
	return 0;	
}


