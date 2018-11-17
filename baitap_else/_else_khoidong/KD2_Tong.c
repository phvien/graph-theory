#include<stdio.h>

int add(int a, int b){
	int sum;
	sum = a+b;
	return sum;
}
int main(){
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d",add(a,b));
}
