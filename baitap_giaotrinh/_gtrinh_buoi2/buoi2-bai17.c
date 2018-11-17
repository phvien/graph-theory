#include <stdio.h>

#define MAX_VERTICES 100
typedef struct{
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
}Graph;

void init_graph(Graph* G, int n){
	int i,j;
	G->n=n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			G->A[i][j]=0;
}

void add_edge(Graph* G, int x, int y){
	/* vo huong
	G->A[x][y]=1;
	G->A[y][x]=1;
	*/
	
	// da cung
		G->A[x][y]+=1;
		G->A[y][x]+=1;
		
	/* co huong
		G->A[x][y]=1;
	*/
}

int adjacent(Graph* G, int x, int y){
	return G->A[x][y]!=0;
}

int degree(Graph* G, int x){
	/* don cung
	int y, deg=0;
	for(y=1;y<=G->n;y++)
		if(G->A[x][y]>0)
			deg++;
	return deg;
	*/
	
	// da cung
	int y, deg=0;
	for(y=1; y<=G->n;y++)
		deg+=G->A[x][y];
	return deg;
}

// CTDL Danh Sach

#define MAX_ELEMENTS 100

typedef int ElementType;

typedef struct{
	ElementType data[MAX_ELEMENTS];
	int size;
}List;

void make_null(List* L){
	L->size=0;
}

void push_back(List* L, ElementType x){
	L->data[L->size]=x;
	L->size++;	
}

ElementType element_at(List* L, int i){
	return L->data[i-1];
}

int count_list(List* L){
	return L->size;
}

List neighbors(Graph* G, int x){
	//Graph G;
	int y;
	List list;
	make_null(&list);
	for(y=1; y<=G->n;y++)
		if(adjacent(G,x,y))
			push_back(&list,y);
	return list;
}

#define WHITE -1
#define BLUE 0
#define RED 1
#define MAX_N 100
int color[MAX_N];
int conflict;

void colorize(Graph* G, int u, int c){
	if(color[u]==-1){
		color[u] = c;
		List list = neighbors(G, u);
		int j;
		for(j=1; j<=list.size; j++){
			int y = element_at(&list, j);
			colorize(G, y, !c);
		}
	}else if(color[u]!=c)
			conflict = 1;
}

int is_biggraph(Graph* G){
	int j;
	for(j=1; j<=G->n; j++)
		color[j]=-1;
	colorize(G, 1, 0);
	return !conflict;
}

int main(){
	Graph G;
	freopen("dothi.txt", "r", stdin);
	int n, m, u, v, i;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(i=1; i<=m; i++){
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	printf("%d", is_biggraph(&G));
}










