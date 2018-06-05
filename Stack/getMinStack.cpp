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

class BStack {
	public:
	Stack main;
	Stack min;
	
	BStack(){
	}

	void push(int ele)
	{
		if(min.arr[min.top] > ele || min.isEmpty() == 1)
			min.push(ele);
		main.push(ele);
	}

	int pop() {
		int ele = main.arr[main.top];
		if(min.arr[min.top] == ele)
			ele=min.pop();
		ele = main.pop();
		return ele;
	}

	int getMin() {
		return min.arr[min.top];
	}
};

int main()
{	int op=0,ele;
	BStack s;
	while(op!=4){
	cout<<"1.push 2.pop 3.min 4.exit\n";
	cin>>op;
	switch(op) {
		case 1:cout<<"enter element : ";
		       cin>>ele;
		       s.push(ele);
		       break;
		case 2:ele = s.pop();
		       cout<<"The element popped is "<<ele<<" \n";
		       break;
		case 3:ele = s.getMin();
		       cout<<"The Minimum is "<<ele<<endl;
		       break;
		case 4:cout<<"Exiting ..."<<endl;
		       break;
		}
	}
}


