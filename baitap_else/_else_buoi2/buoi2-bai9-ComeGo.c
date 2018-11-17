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
		
	// co huong
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

// Stack

#define MAX_ELEMENTS 100

typedef struct{
	int data[MAX_ELEMENTS];
	int size;
}Stack;

void make_null_stack(Stack* S){
	S->size=0;
}

void push(Stack* S, int x){
	S->data[S->size]=x;
	S->size++;
}

int top(Stack* S){
	return S->data[S->size-1];
}

void pop(Stack* S){
	S->size--;
}

int empty(Stack* S){
	return S->size==0;
}

// Tinh lien thong cua do thi CO HUONG,  Tarjan

#define MAX_ELEMENTS 100

int num[MAX_ELEMENTS];
int min_num[MAX_ELEMENTS];
int on_stack[MAX_ELEMENTS];
int k;
Stack S;

int min(int a, int b){
	return a > b ? b : a;
}
int max(int a, int b){
	return a < b ? b : a;
}

int strong_connect(Graph* G, int x,int dem){
	num[x] = min_num[x] = k;
	k++;
	push(&S,x);
	on_stack[x]=1;
	
	List list = neighbors(G,x);
	int j;
	for(j=1; j<=list.size; j++){
		int y = element_at(&list,j);
		if(num[y]<0){
			dem = strong_connect(G,y,dem);
			min_num[x] = min(min_num[x],min_num[y]);
		}
		else if(on_stack[y])
			min_num[x] = min(min_num[x],min_num[y]);
	}
	//printf(" %d - min_num[%d] = %d \n",num[x],x,min_num[x]);
	
	if(num[x] == min_num[x]){
		//printf("%d la dinh khop.\n",x);
		int w;
		int maximum=0;
		do{
			w = top(&S);
			pop(&S);
			on_stack[w]=0;
			maximum++;
		}while(w!=x);
		dem = max(maximum,dem);
	}	
	return dem;
}
void duyet_do_thi(Graph* G, int n){
	int v;
	for(v=1; v<=G->n; v++){
		num[v]=-1;
		on_stack[v]=0;
	}
	k=1;
	int dem = 0;
	make_null_stack(&S);
	for(v=1; v<=G->n; v++)
		if(num[v]==-1)
			dem = strong_connect(G,v,dem);
	if(dem==n)
		printf("OKIE");
	else
		printf("NO");			
}

int main(){
	Graph G;
	int n, m, v, u, x, y;
	FILE* file = fopen("dothi.txt","r");
	fscanf(file,"%d%d",&n,&m);
	init_graph(&G,n);
	for(x=1;x<=m;x++){
		fscanf(file,"%d%d%d",&u,&v,&y);
		if(y==1)
			add_edge(&G,u,v);
		else{
			add_edge(&G,u,v);
			add_edge(&G,v,u);
		}
	}
	duyet_do_thi(&G,n);
	return 0;
}


