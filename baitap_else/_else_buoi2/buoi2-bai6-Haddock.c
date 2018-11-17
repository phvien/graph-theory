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
	
	/* da cung
		G->A[x][y]+=1;
		G->A[y][x]+=1;
	*/
		
	//co huong
		G->A[x][y]=1;
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

/* Kiem tra chu trinh cua do thi CO HUONG */

// Bien ho tro

#define white 0
#define black 1
#define gray 2
#define MAX_VERTICES 100

int color[MAX_VERTICES];
int cycle;

// Duyet do thi bat dau tu dinh x
void dfs(Graph* G, int x){
	color[x]=gray;	
	List list = neighbors(G,x);
	int j;
	for(j=1; j<=list.size; j++){
		int y = element_at(&list,j);
		if(color[y]==gray){
			cycle+=1;
			return;
		}
		if(color[y]==white)
			dfs(G,y);
	}
	color[x]=black;
}

int contains_cycle(Graph* G){
	int j;
	for(j=1; j<=G->n; j++)
		color[j]=white;
	cycle=0;
	for(j=1; j<=G->n; j++)
		if(color[j]==white)
			dfs(G,j);
	return cycle;
}


int main(){
	Graph G;
	int n, m, v, u, x, y;
	FILE* file = fopen("dothi.txt","r");
	fscanf(file,"%d%d",&n,&m);
	init_graph(&G,n);
	for(x=1;x<=m;x++){
		fscanf(file,"%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	int kq=contains_cycle(&G);
	if(kq!=0)
		printf("NO");
	else
		printf("YES");
	return 0;
}

