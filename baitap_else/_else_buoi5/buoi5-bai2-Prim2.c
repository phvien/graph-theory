#include<stdio.h>

#define MAX_VESTICES 100
// CTDL Do Thi 
typedef struct{
	int n, m;
	int A[MAX_VESTICES][MAX_VESTICES];
}Graph;

// Khoi tao do thi voi n dinh.
void init_graph(Graph* G, int n){
	int u, v;
	G->n = n;
	for(u=0; u<n; u++)
		for(v=0; v<n; v++)
			G->A[u][v] = 0;
}

// Them cung vao do thi.
void add_edge(Graph* G, int u, int v, int w){
	G->A[u][v] = w;
	G->A[v][u] = w;
}

// CTDL Danh Sach
typedef int ElementType;
typedef struct{
	ElementType data[MAX_VESTICES];
	int size;
}List;

// Khoi tao danh sach rong.
void make_null_list(List* L){
	L->size = 0;
}

// Them phan tu vao danh sach.
void push_back(List* L, int i){
	L->data[L->size] = i;
	L->size++;
}

// Lay phan tu tai vi tri thu i.
ElementType element_at(List* L, int i){
	return L->data[i-1];
}

#define INFINITY 999
#define NO_EDGE 0
// Ham tra ve dinh v thuoc S gan voi u nhat.
int distanceFrom(int u, List* L, Graph* G){
	int min_dist = INFINITY;
	int min_v = -1;
	int i;
	for(i=1; i<=L->size; i++){
		int v = element_at(L, i);
		if(G->A[u][v] != NO_EDGE && min_dist > G->A[u][v]){
			min_dist = G->A[u][v];
			min_v = v;
		}
	}
	return min_v;
}


// Giai thuat chinh
int mark[MAX_VESTICES];
int Prim(Graph* G, Graph* T){
	int e, u, v;
	init_graph(T, G->m);
	// Khoi tao danh sach de luu phan tu.
	List L;
	make_null_list(&L);
	
	// Khoi tao cac dinh duoc danh dau = 0.
	for(u=0; u<G->n; u++)
		mark[u] = 0;
	
	// Cho phan tu dau tien vao danh sach de duyet.
	push_back(&L, 1);
	mark[1] = 1;
	
	int sum_w = 0;
	for(e=1; e<G->n; e++){
		int min_dist = INFINITY;
		int min_u, min_v;
		for(u=1; u<=G->n; u++)
			if(mark[u] == 0){
				int v = distanceFrom(u, &L, G);
				if(v != -1 && G->A[u][v] < min_dist){
					min_dist = G->A[u][v];
					min_u = u;
					min_v = v;
				}
			}
		// Them min_u vao danh sach.
		push_back(&L, min_u);
		mark[min_u] = 1;
		add_edge(T, min_u, min_v, min_dist);
		sum_w += min_dist;
	}
	return sum_w;
}

int main(){
	Graph G, T;
	int n, m, e, u, v, w;
	freopen("dothi.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(e=1; e<=m; e++){
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
//		printf("%d %d %d\n", u, v, w);
	}
	// In trong luong cay T 
	int i, j;
	int sum_w = Prim(&G, &T);
	printf("%d", sum_w);
	printf("\n%d", T.n);
	for(i=1; i<=T.n; i++){
		for(j=1; j<=T.n; j++)
			if(T.A[i][j]>0 && i<j)
				printf("%d %d %d\n", i, j, T.A[i][j]);
	}
		
	return 0;
}

