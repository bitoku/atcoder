n, a, b = map(int, input().split())
s = (n // (a + b))*a
s += min(n%(a+b), a)
print(s)