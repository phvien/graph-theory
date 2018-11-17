#include<stdio.h>

#define MAXN 100
#define NO_EDGE 0
#define INF 99999

//Queue

#define MAX_ELEMENTS 100 

typedef struct {  
	int data[MAX_ELEMENTS];  
	int front, rear; 
} Queue;
  
void make_null_queue(Queue* Q) {  
	Q->front = 0;  
	Q->rear = -1; 
}  

void enqueue(Queue* Q, int x) {  
	Q->rear++;  
	Q->data[Q->rear] = x; 
}  

int top(Queue* Q) {  
	return Q->data[Q->front]; 
}  

void dequeue(Queue* Q) {  
	Q->front++; 
}  

int empty(Queue* Q) {  
	return Q->front > Q->rear; 
} 

// cau truc do thi
typedef struct{
	int C[MAXN][MAXN];	// kha nang thong qua cung 
	int F[MAXN][MAXN];	// luong tren cung
	int n;
}Graph;

// cau truc nhan label
typedef struct{
	int dir; // =0 chua co nhan ; =1 cung thuan ; =-1 cung nghich
	int pre; // dinh truoc cua dinh dang xet
	int sigma; // luong tang cua luong
}Label;

// BIEN HO TRO 
Label labels[MAXN]; // luu nhan cac dinh

//khoi tao cac luong =0
void init_flow(Graph *G){
	int u,v;
	for(u=1;u<=G->n;u++)
		for(v=1;v<=G->n;v++)
			G->F[u][v]=0;
}

void init_graph(Graph*G,int n)
{
	G->n=n;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			G->C[i][j]=NO_EDGE;	
}

// lay gia tri nho nhat trong 2 so x,y
int min(int x,int y){
	return (x<y) ? x:y;
}

int FordFullkerson(Graph *G,int s,int t){
	int u,v;
	// khoi tao luong =0 voi moi cung tren do thi
	init_flow(G);
	int sum_flow=0;
	// khoi tao hang doi Q luu tru cac dinh de duyet
	Queue Q;
	// lap 
	do{
		// buoc 1 - xoa tat ca cac nhan =0
		for(u=1;u<=G->n;u++)
			labels[u].dir=0;
		
		// gan nhan cho S
		labels[s].dir=1; // gan nhan cho s =1 
		labels[s].pre=s; // default dinh truoc s la s
		labels[s].sigma = INF; // luong dua vao la vo cung INF
		// khoi tao Q rong
		make_null_queue(&Q);
		//dua s vao Q
		enqueue(&Q,s);
		int found=0;
		// lap gan nhan cho cac dinh
		int k=1;
		while(!empty(&Q))
		{
		//	printf("lan lap thu %d\n",k++);
			// lay 1 dinh trong Q ra la u
			int u=top(&Q); 
		//	printf("u=%d\nxoa u ra khoi Q\n",u);
			//xoa no ra khoi Q
			dequeue(&Q);
			for(v=1;v<=G->n;v++)
			{
				// xet gan nhan cho cung thuan hay cac dinh ke cua u
				if(labels[v].dir==0 && G->C[u][v]!=NO_EDGE && G->C[u][v]>G->F[u][v])
				{
		//			printf("cung thuan\n");
					labels[v].dir=1; // cung thuan
					labels[v].pre=u; // dinh ke truoc cua v la u
					labels[v].sigma=min(labels[u].sigma,G->C[u][v]-G->F[u][v]);
		//			printf("labels[%d].dir= %d\nlabel[%d].sigma=%d\n",v,labels[v].dir,v,labels[v].sigma);
					// dua v vao trong Q
		//			printf("dua %d vao Q\n",v);
					enqueue(&Q,v);
				}
				// xet gan nhan cho cung nghich hay cac dinh den u
				if(labels[v].dir==0 && G->C[v][u]!=NO_EDGE && G->F[v][u]>0)
				{
		//			printf("cung nghich\n");
					labels[v].dir = -1; // cung nghich
					labels[v].pre = u;  // dinh di den v la u
					labels[v].sigma=min(labels[u].sigma,G->F[u][v]);
		//			printf("labels[%d].dir= %d\nlabel[%d].sigma=%d\n",v,labels[v].dir,v,labels[v].sigma);
					// dua v vao Q
		//			printf("dua %d vao Q\n",v);
					enqueue(&Q,v); 
				}
				
			}
			// neu t duoc gan nhan =>
				// tim duoc duong tang luong, thoat vong lap
			if(labels[t].dir!=0)
			{
		//		printf("tim duoc dir t !=0\n");
				found=1;
				break;
			}
		}
		if(found==1)
		{
			// tang luong
			int x=t;
			int sigma= labels[t].sigma;
			sum_flow+=sigma; // tang them luong
			// kiem tra xem dinh do co phai la s khong
			while(x!=s)
			{
				int u=labels[x].pre; // lay dinh truoc cua x
		//		printf("Dinh truoc la: %d\n",u);
				if(labels[x].dir>0)
				{
					
					G->F[u][x] +=sigma; // tang luong
		//			printf("tang luong F[%d][%d] = %d\n",u,x,G->F[u][x]);
				}
				else
				{
					G->F[x][u] -=sigma;
		//			printf("Giam luong F[%d][%d] = %d\n",x,u,G->F[x][u]);
				}
				x=u; 
			}
		}
		else break; // thoat vong lap
		
			
	} while(1);
	return sum_flow;
}

int main(){
	Graph G;
	int n, m, u, v, e, c;
	freopen("dothi.txt", "r", stdin);
	Queue Q;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	
	for(e=0;e<m;e++)
	{
		scanf("%d%d%d",&u,&v,&c);
		G.C[u][v]=c;
	}
	
	int max_flow = FordFullkerson(&G,1,n);
	
	printf("Max flow: %d\n",max_flow);
		// in lat cat (X0,Y0)
	printf("X0: ");
	for(u=1;u<=n;u++)
		if(labels[u].dir!=0)
			printf("%d ",u);
	printf("\nY0: ");
	for(u=1;u<=n;u++)
		if(labels[u].dir==0)
			printf("%d ",u);
		
	return 0;
}

