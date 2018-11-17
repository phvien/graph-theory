#include<stdio.h>

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

// Do Thi

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

List neighbors(Graph* G, int x){
	//Graph G;
	int y;
	List list;
	make_null(&list);
	for(y=1; y<=G->n; y++)
		if(adjacent(G,x,y))
			push_back(&list,y);
	return list;
}

// To mau

#define MAX_VERTICES 100

int color[MAX_VERTICES];
int fail;

void colorize(Graph* G, int x, int c){
	if(color[x]==-1){
		color[x]=c;
		List list = neighbors(G,x);
		int j;
		for(j=1; j<=list.size;j++){
			int y = element_at(&list,j);
			colorize(G,y,!c);
		}
	}
	else
		if(color[x]!=c)
			fail=1;
}

int is_bigraph(Graph* G){
	int j;
	for(j=1; j<=G->n; j++)
		color[j]=-1;
	fail=0;
	colorize(G,1,0);
	return !fail;
}

int main(){
	Graph G;
	int n, m, v, x, y;
	FILE* file = fopen("dothi.txt","r");
	fscanf(file,"%d%d",&n,&m);
	init_graph(&G,n);
	for(v=1;v<=m;v++){
		fscanf(file,"%d%d",&x,&y);
		add_edge(&G,x,y);
	}
	
	int kq = is_bigraph(&G);
	if(kq==1){
		for(v=1; v<=m; v++)
			if(color[v]==0)
				printf("%d ",v);
		printf("\n");		
		for(v=1; v<=m; v++)
			if(color[v]==1)
				printf("%d ",v);		
	}
	else
		printf("IMPOSSIBLE");
	return 0;
}


