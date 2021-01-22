s = input()

if len(s) == 1:
    print("Good")

before = s[0]
for a in s[1:]:
    if a == before:
        print("Bad")
        exit()
    before = a
print("Good")