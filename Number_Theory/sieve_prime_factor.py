import math
def smallest_prime_factor(n):
    if n<2:
        return
    composite = [1]*(n+1)
    for i in range(2,n+1):
        if composite[i]==1:
             composite[i]=i
             for m in range(i*i,n+1,i):
                 if composite[m]==1:
                    composite[m]=i
    return composite

spf = smallest_prime_factor(10000);
q = int(input("Please enter number of queries: "))
while q!=0:
    n = int(input("Please enter the Number: "))
    PrimeFactors = []
    while n!=1:
        PrimeFactors.append(spf[n])
        n = int(n/spf[n])
    print(PrimeFactors)
    q-=1

