#include <iostream>

int gcd_euclid(int a, int b) {
	if(a<b){
		int tmp = a;
		a = b;
		b = tmp;
	}
	if(b==0)
		return a;	
	return gcd_euclid(b,a%b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_euclid(a, b) << std::endl;
  return 0;
}
