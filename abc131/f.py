from collections import defaultdict

class Bag:
    def __init__(self):
        self.points = set()
        self.x = set()
        self.y = set()

    def __or__(self, other):
        self.points |= other.points
        self.x |= other.x
        self.y |= other.y
        return self

    def add_points(self, x, y):
        self.points.add((x, y))
        self.x.add(x)
        self.y.add(y)

bags = []
N = int(input())
for i in range(N):
    x, y = list(map(int, input().split()))
    used_bags = []
    new_bags = []
    for bag in bags:
        if x in bag.x or y in bag.y:
            used_bags.append(bag)
        else:
            new_bags.append(bag)
    initial_bag = Bag()
    for bag in used_bags:
        initial_bag |= bag
    initial_bag.add_points(x, y)
    new_bags.append(initial_bag)
    bags = new_bags

result = 0
for bag in bags:
    result += len(bag.x) * len(bag.y) - len(bag.points)
print(result)

