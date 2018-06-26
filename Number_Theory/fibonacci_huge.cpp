#include <iostream>

long long int get_pisano_period(long long int m) {
    long long int previous = 0;
    long long int current  = 1;
    int count = 2;
    while (true) {
        long long int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
	if (previous == 0 && current == 1)
		return count-1;
	count++;	
    }
    std::cout<<"\n";
}

long long int fib(long long int k,long long int m){
	if(k<=1)
		return k;
	long long int p = 0;
	long long int c = 1;
	for(int i=0;i<k-1;i++){
		long long int tmp = p;
		p = c;
		c = (tmp+p)%m;
	}
	return c;
}

int main() {
    long long int n, m;
    std::cin >> n >> m;
    long long int pisano = get_pisano_period(m);
    //std::cout<<pisano<<" is pisano\n";
    long long int tmp = n % pisano;
    //std::cout<<"tmp is "<<tmp<<"\n";
    long long int ans = fib(tmp,m);
    std::cout<<ans<<"\n";
    return 0;
}
