import math
n = int(input("Please Enter a Number: "))
if n<=1:
    print("Not Applicable")
    exit()
for i in range(2,int(math.sqrt(n))):
    if n%i==0:
        print("Not Prime")
        exit()
print(n,"is Prime")
