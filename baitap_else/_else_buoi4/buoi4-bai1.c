#include<stdio.h>
#define MAX_N 100

// CTDL graph
typedef struct{
	int n;
	int A[MAX_N][MAX_N];
}Graph;

void init_graph(Graph* G, int n){
	int i, j;
	G->n = n;
	for(i=1; i<=G->n; i++)
		for(j=1 ;j<=G->n; j++)
			G->A[i][j]=0;
}

void add_edge(Graph* G, int x, int y){
	G->A[x][y]=1;
}

// CTDL danh sach
typedef int ElementType;
typedef struct{
	ElementType data[MAX_N];
	int size;
}List;

void make_null_list(List* L){
	L->size=0;
}

void push_back(List* L, ElementType x){
	L->data[L->size]=x;
	L->size++;
}

ElementType element_at(List* L, int i){
	return L->data[i-1];
}

void copy_list(List* s1, List* s2){
	make_null_list(s1);
	*s1 = *s2;
}

int rank[MAX_N];
void ranking(Graph* G){
	int d[MAX_N];
	int x, u;
	for(u=1; u<=G->n; u++)
		d[u]=0;
		
	for(x=1; x<=G->n; x++)
		for(u=1; u<=G->n; u++)
			if(G->A[x][u] != 0)
				d[u]++;
	List s1, s2;
	make_null_list(&s1);
	
	for(u=1; u<=G->n; u++)
		if(d[u]==0)
			push_back(&s1, u);
	
	int k=1, i;
	while(s1.size > 0){
		make_null_list(&s2);
		for(i=1; i<=s1.size; i++){
			int u = element_at(&s1, i);
			rank[u] = k;
			int v;
			for(v=1; v<=G->n; i++)
				if(G->A[u][v]!=0){
					d[u]--;
					if(d[v]==0)
						push_back(&s2, v);
				}
		}
		copy_list(&s1, &s2);
		k++;
	}
}

int main(){
	Graph G;
	int n, m, u, v, e;
	freopen("dothi.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(e=1; e<=m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	ranking(&G);
	int i;
	for(i=1; i<=n; i++)
		printf("%d", i);
}



