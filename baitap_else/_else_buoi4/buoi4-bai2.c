#include <stdio.h>

#define MAX_VERTICES 100
typedef struct {
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
}Graph;
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
ElementType data[MAX_ELEMENTS];
int size;
} List;
/* Tao danh sach rong */
void make_null(List* L) {
L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
L->data[L->size+1] = x;
L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
ElementType element_at(List* L, int i) {
return L->data[i];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List* L) {
return L->size;
}
void copy_list(List *L1, List *L2){
	make_null(L1);
	int i;
	for (i = 1; i<= L2->size; i++){
		int u = element_at(L2, i);
		push_back(L1, u);
	}
	}

int init_graph(Graph *G, int n){
	int i, j;
	G->n = n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
		  G->A[i][j]=0;
}

void add_edge(Graph *G, int u, int v){
  G->A[v][u]=1;
}

int rank [MAX_VERTICES];
void ranking (Graph* G){
	int d[MAX_VERTICES];
	int x, u;
	for(u=1; u<= G->n; u++)
	 d[u]=0;
	for(x=1; x<=G->n; x++)
	    for (u =1; u<=G->n; u++)
	        if(G->A[x][u]!=0)
	         d[u]++;
	List S1, S2;
	make_null(&S1);
	for (u=1; u<=G->n; u++)
	 if(d[u]==0)
	 	push_back(&S1, u);
    int k = 1, i; 
    while (S1.size > 0){
    	make_null(&S2);
    	for (i =1; i<= S1.size; i++){
    	    u = element_at(&S1, i);
    		rank [u] = k;
    		int v;
    		for(v =1; v<=G->n; v++)
    			if (G->A[u][v]!=0){
    				d[v]--;
    				if (d[v]==0)
    					push_back(&S2, v);
    			}
        }
    copy_list(&S1, &S2);
	    k++;
    }
}
int main(){
	int m,n,e,u,v,i,sum;
	Graph G;
	scanf("%d%d", &n, &m);
	init_graph(&G,n);
	for (e = 1; e <= m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}

	ranking(&G);
	sum=0;
	for(e=1;e<=G.n;e++)
	{
		printf("%d\n",rank[e]);
	sum=sum+rank[e];
	}
	printf("%d",sum);
	return 0;
} 
