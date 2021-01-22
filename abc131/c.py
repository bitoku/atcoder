a, b, c, d = list(map(int, input().split()))

def euclid(p, q):
    if p > q:
        p, q = q, p
    while q > 0:
        p, q = q, p % q
    return p

def lcm(p, q):
    return p * q // euclid(p, q)

c_a = (a-1) // c
c_b = b // c
d_a = (a-1) // d
d_b = b // d
cd_a = (a-1) // lcm(c, d)
cd_b = b // lcm(c, d)
# print(c_a, c_b, d_a, d_b, cd_a, cd_b)

print(b - a + 1 - ((c_b + d_b - cd_b) - (c_a + d_a - cd_a)))

