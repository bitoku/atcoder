from collections import Counter

s = input()
counter = Counter(s)
if len(counter) != 2:
    print("No")
    exit()

for k, v in counter.items():
    if v != 2:
        print("No")
        exit()

print("Yes")