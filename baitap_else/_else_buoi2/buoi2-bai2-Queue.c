#include<stdio.h>

// CTDL do thi
#define MAX_VERTICES 100
typedef struct{
	int n;                                  // n la dinh
	int A[MAX_VERTICES][MAX_VERTICES];	// mang A luu tru dinh - dinh
}Graph;

// Khoi tao do thi G co n dinh
void init_graph(Graph* G, int n){
	int i, j;
	G->n=n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			G->A[i][j]=0;
}

// Them cung e(x, y) vao do thi
void add_edge(Graph* G, int x, int y){
	G->A[x][y]=1;	// y ke voi x
	G->A[y][x]=1;	// x ke voi y
}

// Kiem tra y co ke voi x hay khong
int adjacent(Graph* G, int x, int y){
	return G->A[x][y]!=0;
}

// Tinh bac cua dinh x
int degree(Graph* G, int x){
	int i, deg=0;
	for(i=1; i<=G->n; i++)
		if(G->A[x][i]>0)
		deg++;
	return deg;
}

// Tinh bac truong hop da cung
int degree_second(Graph* G, int x){
	int i, deg=0;
	for(i=1; i<=G->n; i++)
		if(G->A[x][i]>0)
		deg += G->A[x][i];
	return deg;
}

// CTDL danh sach
#define MAX_ELEMENTS 100
typedef int ElementType;

typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
}List;

// Tao danh sach rong
void make_null_list(List* L){
	L->size=0;
}

// Them phan tu vao cuoi danh sach
void push_back(List* L, ElementType x){
	L->data[L->size]=x;
	L->size++;
}

// Lay phan tu tai vi tri i, phan tu bat dau tai vi tri 1
ElementType element_at(List* L, int i){
	return L->data[i-1];
}

// Tra ve so phan tu cua danh sach
int count_list(List* L){
	return L->size;
}

List neighbors(Graph* G, int x){
    int y;
    List list;
    make_null_list(&list);
    for(y=1; y<=G->n; y++)
        if(adjacent(G, x, y))
            push_back(&list, y);
    return list;
}

// Khai bao Queue (hang doi)
#define MAX_ELEMENTS 100
typedef struct{
	int front, rear;
	int data[MAX_ELEMENTS];
}Queue;

// Khoi tao ngan xep
void make_null_queue(Queue* Q){
	Q->front=0;
	Q->rear=-1;
}

// Them phan tu vao queue
void push(Queue* Q, int x){
	Q->rear++;
	Q->data[Q->rear]=x;
}

// Lay phan tu dau danh sach
int top(Queue* Q){
	return Q->data[Q->front];
}

// Loai bo phan tu dau danh sach
void pop(Queue* Q){
	Q->front++;
}

// Kiem tra ngan xep rong
int empty(Queue* Q){
	return Q->front > Q->rear;
}
int mark[MAX_VERTICES];
int parent[MAX_VERTICES];
// Duyet do thi theo chieu rong
void dreath_first_search(Graph* G, int n){
	Queue Q;
	make_null_queue(&Q);
	push(&Q, n);
	mark[n]=1;
	while(!empty(&Q)){	
		int x = top(&Q);
		pop(&Q);
		List list = neighbors(G, x);
		int i;
		for(i=1; i<=list.size; i++){
			int y = element_at(&list, i);
			if (mark[y] == 0) {                 
				mark[y] = 1;
				parent[y] = x; 
				push(&Q, y);
			}    
		}
	}
}

int main(){
	Graph G;
	int n, m, e, u, v;
	FILE* file = fopen("dothi.txt", "r");
	fscanf(file, "%d%d", &n, &m);
	init_graph(&G, n);
	for(e=1; e<=m; e++){
		fscanf(file, "%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	for(u=1; u<=n; u++){
		for(v=1; v<=n; v++)
			printf("%d ", G.A[u][v]);
		printf("\n");
	}
	printf("\n");
	int i;
	for(i=1; i<=G->n; i++){
		mark[i]=0;
			parent[i]=0;
	}
	for(i=1; i<=n; i++){
		dreath_first_search(&G, i);
	}
	for(i=1; i<=n; i++){
		printf("%d %d\n", i, parent[i]);
	}
	
	return 0;
}

