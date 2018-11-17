#include<stdio.h>
#define MAX_VERTICES 100
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct{
	ElementType data[MAX_ELEMENTS];
	int size;
}List;

void make_null_list(List *L){
	L->size=0;
}
void push_back(List *L, ElementType x){
	L->data[L->size] = x;
	L->size++;
}
ElementType element_at(List *L, int i){
	return L->data[i-1];
}
int count_list(List *L){
	return L->size;
}
void coppy_list(List *L, List *S){
	make_null_list(L);
	*L=*S;
}

typedef struct{
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
}Graph;
void init_graph(Graph *G, int n){
	int i,j;
	G->n=n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			G->A[i][j] = 0;
}

void add_edge(Graph *G, int x, int y){
	G->A[x][y] = 1;
}

int rank[MAX_VERTICES];

void ranking(Graph* G){
	int d[MAX_VERTICES];
	int x, u;
	
	for(u=1; u<=G->n; u++)
		d[u]=0;
		
	for(x=1; x<=G->n; x++)
		for(u=1; u<=G->n; u++)
			if(G->A[x][u]!=0){
				d[u]++;
			}
	
	List S1, S2;
	make_null_list(&S1);
	
	for(u=1; u<=G->n; u++)
		if(d[u]==0)
			push_back(&S1,u);
	
	int k=1, i;
	while(S1.size > 0){
		make_null_list(&S2);
		for(i=1; i<= S1.size; i++){
			int j = element_at(&S1, i);
			printf("%d ", j);			
			int v;
			for(v=1; v<=G->n; v++)
				if(G->A[j][v]!=0){
					d[v]--;
					if(d[v]==0)
						push_back(&S2, v);
				}
		}
		coppy_list(&S1,&S2);
		k++;
	}		
}

int main(){
	Graph G;
	int n, i,m, u, v, w, e;
//   	freopen("dothi.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	ranking(&G);
}


