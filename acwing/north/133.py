from math import factorial
n = int(input())
a = factorial(2*n);
b = factorial(n);
print(a//b//b//(n+1));