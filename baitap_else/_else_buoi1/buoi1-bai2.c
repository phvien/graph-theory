#include<stdio.h>

#define MAX_VERTICES 100
#define MAX_EDGES 200

// Khai bao kieu cau truc 
typedef struct{
	int n, m; 						// n la dinh, m la cung
	int A[MAX_VERTICES][MAX_EDGES]; // dung mang luu tru dinh - cung
}Graph;

// Khoi tao do thi
void init_graph(Graph *G, int n, int m){
	int i, j;
	G->n=n;
	G->m=m;
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
		G->A[i][j]=0;
}

// Them cung e(x, y) vao do thi
void add_edge(Graph *G, int e, int x, int y){
	G->A[x][e]=1;
	G->A[y][e]=1;
}

// Kiem tra y co ke voi x khong
int adjacent(Graph *G, int x, int y){
	int e;
	for(e=1; e<=G->m; e++){
		if(G->A[x][e]==1 && G->A[y][e]==1)
			return 1;
	}	
	return 0;
}

//Tinh bac cua dinh x
int degree(Graph *G, int x){
	int e, deg=0;
	for(e=1; e<=G->m; e++)
		if(G->A[x][e]==1)
			deg++;
	return deg;
}

#define MAX_ELEMENTS 100
typedef int ElementType;

typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
}List;

// Tao danh sach rong
void make_null(List* L){
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



// Buoi1 - bai 2
// Tra ve danh sach dinh ke cua x
List neighbors(Graph* G, int x){
	int e, y; // e la cung. y la dinh
	List list;
	make_null(&list);
	for(y=1; y<=G->n; y++){	// duyet cac dinh		
		if (x==y) continue;	// neu 2 dinh bang nhau thi bo qua
		for(e=1; e<=G->m; e++)
			if(G->A[x][e]==1 && G->A[y][e]==1){		// kiem tra dinh ke
				push_back(&list, y);				// neu ke them dinh vao danh sach
			break;
		}			
	}		
	return list;
}

int main(){
	Graph G;
	List list;
	int n, m, e, u, v, y;
	FILE* file = fopen("dothi.txt", "r");
	fscanf(file, "%d%d", &n, &m);
	init_graph(&G, n, m);
	for(e=1; e<=m; e++){
		fscanf(file, "%d%d", &u, &v);
		add_edge(&G, e, u, v);
		adjacent(&G, u, v);
	}
	
// Bieu dien bang ma tran
//	for(u=1; u<=n; u++){
//		for(v=1; v<=m; v++)
//			printf("%d ", G.A[u][v]);
//		printf("\n");
//	}
//	printf("\n");
	
//	int i, j;
//	for(i=1; i<=n; i++){
//		List list = neighbors(&G, i);
////		printf("Dinh ke %d\n", v);
//		for(j=1; j<=list.size; j++)
//			printf("%d", element_at(&list, j));
//		printf("\n");
//	}	
	
	
	return 0;
}





