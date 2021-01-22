
def price():
    a, b = map(int, input().split())

    x = int(a / 0.08)

    if x * 8 < 100 * a:
        x += 1
    while 100*a <= x*8 < 100*a + 100:
        if 100*b <= x*10 < 100*b + 100:
            return x
        x += 1
    return -1

print(price())