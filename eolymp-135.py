from math import gcd

n = int(input())
s = [int(x) for x in input().split(" ")]
lcm = 1
for i in s:
    lcm *= i // gcd(i, lcm)
print(lcm)
