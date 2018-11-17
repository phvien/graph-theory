#include<stdio.h>
#include <stdbool.h>

#define MAX 3
int list[MAX] = {5,3,4};

void swap(int a, int b){
	a = a+b;
	b = a-b;
	a = a-b;
//	printf("%d %d", a, b);
}

void bubbleSort(int a[], int n) {
   int temp;
   int i,j;
	
   bool swapped = false;       
   
   // lap qua tat ca cac so
   for(i = 0; i < n-1; i++) { 
      swapped = false;
      // vong lap thu hai
      for(j = 0; j < n-1-i; j++) {
         // kiem xa xem so ke tiep co nho hon so hien tai hay khong
         //   trao doi cac so. 
         //  (Muc dich: lam noi bot (bubble) so lon nhat) 
         if(a[j] > a[j+1]) {
            temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
            swapped = true;
         }
      }
      // neu khong can trao doi nua, tuc la 
      //   mang da duoc sap xep va thoat khoi vong lap. 
      if(!swapped) {
         break;
      }    
//      printf("Vong lap thu %d#: ",(i+1)); 
//      display();                     
   }
	
}

void display(){
   int i, n, a[n];	
   // Duyet qua tat ca phan tu
   for(i = 0; i < n; i++){
      printf("%d ",a[i]);
   }
   printf("\n");
}

int main(){
	int n, i, x, y;
	FILE* file = fopen("dothi.txt", "r");
	fscanf(file, "%d\n", &n);	
	printf("%d\n", n);
	int arr[n];
	if(n<=100){		
		for(i=0; i<n; i++){
			fscanf(file, "%d", &arr[i]);
			printf("%d ", arr[i]);												
		}
		printf("\n");
	}
	bubbleSort(arr, n);
	display();
		
}
					
		
			

