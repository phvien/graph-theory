#include <stdio.h>

int main() {
   int n,i,j, k;
   	scanf("%d", &n);
			/*
				   *
				  **
				 ***
				****
			*/
	/*
   for(i = 1; i <= n; i++) {		// Chay tu 1 den n 
      	for(j = 1; j <= n-i; j++){	// In khoang cach thu 1 den n-i
      		printf(" ");
	  	}
	  	for(k=1; k<=i; k++)			// In dau * thu i
	  		printf("*");
	  	printf("\n");
	}
	*/
	/*
			   *
			  ***
			 *****
			*******
	*/
	for(i=1; i<=n; i++){
		for(j=1; j<=2*n-1; j++)	{
			if((j>=n-i+1) && (j<=n+i-1))	// Neu trong khoang [a, b] in dau *
				printf("*");
			else 
				printf(" ");
		}
		printf("\n");
		
	}
	
	
	  return 0;
}

