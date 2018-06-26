#include <iostream>

long long int gcd_euclid(long long int a, long long int b) {
	if(a<b){
		long long int tmp = a;
		a = b;
		b = tmp;
	}
	if(b==0)
		return a;	
	return gcd_euclid(b,a%b);
}

int main() {
  long long int a, b;
  std::cin >> a >> b;
  long long int ans = a*b;
  ans = ans/gcd_euclid(a,b);
  std::cout << ans << std::endl;
  return 0;
}
