#include <iostream>
#include <cassert>

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long int fibonacci_fast(int n) {
    long int *a = new long int[n+1];
    a[0]=0;
    a[1]=1;
	for(long int i=2;i<=n;i++)
		a[i]=a[i-1]+a[i-2];
    long int ans = a[n];
    delete a;
    return ans;
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
