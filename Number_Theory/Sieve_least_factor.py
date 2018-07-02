import math
def sieve(n):
    if n<2:
        return
    composite = [1]*(n+1)
    PrimeFactors = []
    for i in range(2,n+1):
        if composite[i]==1:
             composite[i]=i
             for m in range(i*i,n+1,i):
                 if composite[m]==1:
                    composite[m]=i
    f=0
    for k in composite:
        print(f," ",k)
        f+=1
    return

n = int(input("Please enter the Number: "))
sieve(n);
