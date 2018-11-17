#include<stdio.h>
#define MAX 100
#define INF 9999999
typedef struct {
	int A[MAX][MAX];
	int n;
}Graph;
int rank[MAX];
int d[MAX];
typedef struct {
 int data[MAX];
 int size;
} List;
typedef struct {
 int data[MAX];
 int front, rear;
} Queue;
void make_null_queue(Queue* Q) {
 Q->front = 0;
 Q->rear = -1;
}
void push(Queue* Q, int x) {
 Q->rear++;
 Q->data[Q->rear] = x;
}
int top(Queue* Q) {
 return Q->data[Q->front];
}
void pop(Queue* Q) {
 Q->front++;
}
int empty(Queue* Q) {
 return Q->front > Q->rear;
}
void make_null_list(List* pL) {
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
	for(i=1;i<=n;i++){
		for (j=1;j<=n;j++)
			G->A[i][j]=0;
		}
}
void add_edge(Graph *G, int u, int v){
	G->A[u][v]=1;
}
int min(int a, int b){
	return a<b ?a :b;
}
int max(int a, int b){
	return a>b ?a :b;
}
void topo_sort(Graph* G, List* L){
	int d[MAX];
	int x, u;
	for (u=1;u<=G->n;u++)
		d[u]=0;
	for (u=1;u<=G->n;u++)
		for(x=1;x<=G->n;x++)
			if(G->A[u][x] != 0){
				d[x]++;
			}
	Queue Q;
	make_null_queue(&Q);
	for (u=1;u<=G->n;u++)
		if(d[u]==0){
			push(&Q,u);
		}
	int a;
	while(!empty(&Q)){
		a=top(&Q);
		pop(&Q);
		push_back(L,a);
		for(x=1;x<=G->n;x++)
			if(G->A[a][x]!=0){
				d[x]--;
				if(d[x]==0)
					push(&Q,x);		
			}
		}
}
int main(){
	Graph G;
	List L;
	int i, n, m, u, v, w, e,a;
	//freopen("test.txt", "r", stdin);
	scanf("%d", &n);
	init_graph(&G, n+2);	
	for (e = 1; e <= n; e++) {
		scanf("%d", &d[e]);
		do {
			scanf("%d",&v);
			if(v>0)
				add_edge(&G,v,e);
		}while(v>0);
	}
	for(e=1;e<=n;e++){
		int deg_neg=0;
		for(i=1;i<=n;i++)
			if(G.A[i][e]>0)
				deg_neg++;
		if(deg_neg==0)
			add_edge(&G,n+1,e);
	}
	for(e=1;e<=n;e++){
		int deg_pos=0;
		for(i=1;i<=n;i++)
			if(G.A[e][i]>0)
				deg_pos++;
			if(deg_pos==0)
				add_edge(&G,e,n+2);
	}
	topo_sort(&G,&L);
	int t[MAX];
	t[n+1]=0;
	for(e=2;e<=L.size;e++){
		u=element_at(&L,e);
		t[u]=-1;
		for(i=1;i<=G.n+2;i++)
			if(G.A[i][u]>0)
				t[u]=max(t[u],t[i]+d[i]);
	}
	int T[MAX];
	T[n+2]=t[n+2];
	for(e=L.size-1;e>=1;e--){
		u=element_at(&L,e);
		T[u]=INF;
		for(i=1;i<=G.n;i++)
			if(G.A[u][i]>0)
				T[u]=min(T[u],T[i]-d[u]);
	}
	for(e=1;e<=n+2;e++){
		if(t[e]==T[e])
			printf("%d\n",e);
	}
	return 0;
}
