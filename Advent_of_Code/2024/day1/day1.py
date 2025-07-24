i = open("./data", "r")
list1 = []
list2 = []
total = 0

for line in i:
    values = line.split()
    list1.append(int(values[0]))
    list2.append(int(values[1]))

print(list1)
print(list2)
list1.sort()
list2.sort()
print("list 1 sorted: ")
print(list1)
print("\n\n\n")
print("list 2 sorted: ")
print(list2)
print("\n\n\n")
difs = [b - a for a, b in zip(list1, list2)]
print(difs)
for val in difs:
    if val < 0:
        val *= -1
    total += val

print("total: ")
print(total)

total = 0
# part2
for val in list1:
    total += (list2.count(val) * val)

print("total2: ")
print(total)