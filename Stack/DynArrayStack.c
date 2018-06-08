#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

struct Stack {
	int top;
	int capacity;
	int *array;
};

struct Stack *CreateStack() {
	struct Stack *S = malloc(sizeof(struct Stack));
	if(!S)
		return NULL;
	S->top = -1;
	S->capacity=1;
	S->array = malloc(S->capacity);
	if(!S->array)
		return NULL;
	return S;
}

int isFull(struct Stack *S) {
	return S->top == S->capacity -1 ;
}

int isEmpty(struct Stack *S) {
	return S->top == -1 ;
}

void Double(struct Stack *S) {
	S->capacity *= 2;
	S->array = realloc ( S->array , S->capacity * sizeof(int) );
}

void push(struct Stack *S, int data) {
	if ( isFull(S) )
		Double(S);
	S->array[++S->top] = data;
}

int Capacity(struct Stack *S) {
	return S->capacity;
}

int pop(struct Stack *S) {
	if ( isEmpty(S) ) 
		return INT_MIN;
	return S->array[S->top--];
}

void DeleteStack(struct Stack *S) {
	if(S)
		if(S->array)
			free(S->array);
		free(S);
}	

int main()
{
	printf("Which Operation would you like to perform\n");
	int op = 0,ele;
	struct Stack *st = CreateStack(); 
	while(op != 4) {
	printf("1.push 2.pop 3.capacity 4.Exit\n");
	scanf("%d",&op);
	switch(op) {
		case 1:
			printf("Enter element to push: ");
			scanf("%d",&ele);
			push(st,ele);
			printf("pushed\n");
			break;
		case 2:	
			ele = pop(st);
			if(ele == INT_MIN)
				printf("Stack Empty Can't Pop ...\n");
			else
				printf("Popped %d \n",ele);
			break;
		case 3:
			ele = Capacity(st);
			printf("The Capacity is %d \n",ele);
			break;
		case 4:	
			printf("exiting...\n");
			break;
		}
	}
}





	
