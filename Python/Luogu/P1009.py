def Factorial(n):
    res = 1
    for i in range(1,n+1):
        res = res * i
    return res
n = int(input())
sum = 0
for i in range(1,n+1):
    sum = sum + Factorial(i)
    pass
print(sum)
