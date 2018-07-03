#include<iostream>
using namespace std;
#define H 1000000007
void power(int a[2][2],int n);
void mul(int a[2][2],int b[2][2]);
long long int modmul(int a ,int b){
	 long long int k1 = a%H;
	 long long int k2 = b%H;
	 long long int k3 = (k1*k2)%H;
	 return k3;
}
long long int func(int a,int b,int n){
	if(n==0)
		return a;
	if(n==1)
		return b;
	int Fib[2][2] = {{0,1},{1,1}};
	power(Fib,n);
	long long int p1 = Fib[0][0]%H;
	long long int res=0;
	while(a>0){
		if(a%2==1)
			res = (res+p1)%H;
		p1 = (p1*2)%H;
		a/=2;
	}
	long long int p2 = Fib[0][1]%H;
	long long int res2=0;
	while(b>0){
		if(b%2==1)
			res2 = (res2+p2)%H;
		p2 = (p2*2)%H;
		b/=2;
	}
	if(p2<0)
		cout<<"p2\n";
	long long int ans = (res+res2)%H;
	return ans;
}

void power(int F[2][2],int n){
	if(n<=1)
		return;
	power(F,n/2);
	mul(F,F);
	int F2[2][2] = {{0,1},{1,1}}; 
	if(n%2!=0)
		mul(F,F2);
}
void mul(int A[2][2],int B[2][2]){
	long long int x = modmul(A[0][0],B[0][0]) + modmul(A[0][1],B[1][0]);
	if(x<0)
		cout<<"here\n";
	long long int y = modmul(A[0][0],B[0][1]) + modmul(A[0][1],B[1][1]);
	if(y<0)
		cout<<"y\n";
	long long int z = modmul(A[1][0],B[0][0]) + modmul(A[1][1],B[1][0]);
	if(z<0)
		cout<<"z\n";
	long long int w = modmul(A[1][0],B[0][1]) + modmul(A[1][1],B[1][1]);
	if(w<0)
		cout<<"w\n";
	A[0][0] = x%H;
	A[0][1] = y%H;
	A[1][0] = z%H;
	A[1][1] = w%H;
}
int main()
{
	int a,b,n,t;
	cin>>t;
	while(t--){
	cin>>a>>b>>n;
	long long int f = func(a,b,n);
	cout<<f<<endl;
	}
	return 0;
}
