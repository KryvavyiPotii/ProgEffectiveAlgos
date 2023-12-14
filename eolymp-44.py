n = int(input())
res = 0
while n > 1:
    a = 2 + n % 2
    b = 3 + n % 3
    if a < b:
        res += a
        n //= 2
    else:
        res += b
        n //= 3
print(res)


    
