#include<iostream>
using namespace std;

int IsAttacked(int* board,int row,int col,int N){
//check if the position is attacked and returns 0 if attacked
//checking row left side
	for(int i=0;i<col;i++){
		if(board[row*N+i])
			return 0;
	}
	for(int i=row,j=col;j>=0;i--,j--)
		if(board[i*N+j])
			return 0;
	for(int i=row,j=col;j>=0;j--,i++)
		if(board[i*N+j])
			return 0;
	return 1;
 }


int Nqueen(int* board,int col,int N){
	if(col==N)
		return 1;
       	
	for(int i=0;i<N;i++){
		if(IsAttacked(board,i,col,N)){
			board[i*N+col]=1;
			if(Nqueen(board,col+1,N))
				return 1;
		board[i*N+col]=0;
		}
	}
	return 0;
}

int main(){
	
	//Taking input , size of Board
	int N;
	cout<<"Enter side of Square of Board: ";
	cin>>N;
	int* board = new int[N*N]();
	int k = Nqueen(board,0,N);
	if(k){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<board[i*N+j]<<" ";
		}
		cout<<"\n";
	}
	}
	else
		cout<<"Not possilble\n";

	return 0;
}
