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
	for(y=1; y<=G->n;y++)
		if(adjacent(G,x,y))
			push_back(&list,y);
	return list;
}

// dem so thanh phan lien thong cua do thi

#define MAX_VERTICES 100

int mark[MAX_VERTICES];
int deg;
int traversal(Graph* G, int x){
	if(mark[x]==1)
		return;
	//printf("Duyet %d\n",x);
	mark[x]=1;
	List list = neighbors(G,x);
	int j;
	for(j=1; j<=list.size; j++){
		int y = element_at(&list,j);
			deg++;
		traversal(G,y);
	}
	return deg;
}

int count_connected_components(Graph* G){
	int j;
	for(j=1; j<=G->n; j++)
		mark[j]=0;
	int cnt=0;
	for(j=1; j<=G->n; j++)
		if(mark[j]==0){
			deg=0;
			traversal(G,j);
			cnt++;
			for(j=1; j<=cnt; j++)
				printf("%d -> %d\n", j, deg);
		}	
	return cnt;
}

int main(){
	Graph G;
	int n, m, v, u, i, y;
	FILE* file = fopen("dothi.txt","r");
	fscanf(file,"%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1;i<=m;i++){
		fscanf(file,"%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	count_connected_components(&G);
	return 0;
}



