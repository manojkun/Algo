#include<iostream>
using namespace std;

class Stack {
	public:
	int top;
	int arr[20];
	Stack() {
	top = -1; 
	}
	int isFull() {
		return ( top == 19 );
	}
	int isEmpty() {
		return ( top == -1 );
	}
	void push(int ele) {
	       if (!isFull())
	       arr[++top] = ele;
	}
	int pop() {
		if (!isEmpty())
			return arr[top--];
		else
			return -9999;
	}	
};

int main() 
{
	Stack s;
	cout<<"Enter String : ";
	
}
