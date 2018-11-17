#include<stdio.h>

// Khai bao do thi Graph danh sach ke (dinh-dinh).
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

// CTDL Stack (Ngan xep)
#define MAX_ELEMENTS 100
typedef struct{
    int data[MAX_ELEMENTS];
    int size;
}Stack;

// Khoi tao ngan xep rong
void make_null_stack(Stack* S){
    S->size = 0;
}

// Them phan tu vao danh sach
void push(Stack* S, int x){
    S->data[S->size] = x;
    S->size++;
}

// Tra ve phan tu dau ngan xep
int top(Stack* S){
    return S->data[S->size-1];
}

// Loai bo phan tu dau ngan xep
void pop(Stack* S){
    S->size--;
}

// Kiem tra ngan xep rong
int empty(Stack* S){
    return S->size==0;
}
int  mark[MAX_VERTICES];
// Duyet do thi theo chieu sau
void depth_first_search(Graph* G, int n){
	Stack frontier;
	int i;
	make_null_stack(&frontier);
		
	push(&frontier, n);	// Cho dinh 1 vao stack
	
	while(!empty(&frontier)){	// Neu stack khac rong thi lay phan tu top gan cho x
		int x = top(&frontier);	
		pop(&frontier);
		if(mark[x] != 0)
			continue;
		printf("%d\n", x);
		mark[x]=1;
		List list = neighbors(G, x);		// Lay cac dinh ke cua x cho vao danh sach list
		for(i=1; i<=list.size; i++){		// Duyet dinh ke cua x trong list
			int y = element_at(&list, i);	// Lay phan tu tai vi tri i trong danh sach list
			push(&frontier, y);				// Cho dinh y vao stack
		}
	}
}


// Dem bo phan lien thong cua do thi
void count_graph(Graph* G){
	int i;
	for(i=1; i<=G->n; i++)
		if(mark[i]==1)
			continue;
		else 
			depth_first_search(G, i);
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
	
	count_graph(&G);
	return 0;
}

