#include<stdio.h>

// Khai bao Stack
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



