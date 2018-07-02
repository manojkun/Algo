import math
def sieve(n):
    if n<2:
        return
    composite = [1]*(n+1)
    primes = []
    for i in range(2,int(math.sqrt(n))+1):
        if composite[i]==1:
             for m in range(i*i,n+1,i):
                 composite[m]=0
    for i in range(2,n+1):
        if composite[i]==1:
            primes.append(i)
    print(primes)
    return

n = int(input("Please enter the Number: "))
sieve(n);
