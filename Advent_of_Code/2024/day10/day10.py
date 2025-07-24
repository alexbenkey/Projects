f = open("data", "r")

paths = []

def is_in_bound(y, x, data):
    # print("height: ", len(data), "tested against: ", y)
    # print("width: ", len(data[0]), "tested against: ", x)
    if (0 <= y < len(data)):
        if (0 <= x < len(data[0])):
            return (1)
    # if (0 <= x < len(data[0])):
    #     return (1)
    return (0)

def return_paths(val, data, y, x, path):
    total = 0
    if (is_in_bound(y, x, data) == 0):
        return (0)
    if data[y][x] == val and val == 9:
        print("got to 9 at: ", y, " ", x)
        path.append((y, x))
        paths.append(path.copy())
        path.pop()
        return (1)
    # if data[y - 1][x] != (val + 1) and data[y + 1][x] != (val + 1) and data[y][x - 1] != (val + 1) and data[y][x + 1] != (val + 1):
    #     return (0)
    if is_in_bound((y - 1), x, data):
        if data[y - 1][x] == (val + 1):
            print("going up to: [", y - 1, "][", x, "]")
            path.append((y, x))
            return_paths((val + 1), data, (y - 1), x, path)
            path.pop()
    if is_in_bound((y + 1), x, data):
        if data[y + 1][x] == (val + 1):
            print("going down to: [", y + 1, "][", x, "]")
            path.append((y, x))
            return_paths((val + 1), data, (y + 1), x, path)
            path.pop()
    if is_in_bound(y, (x - 1), data):
        if data[y][x - 1] == (val + 1):
            print("going left to: [", y, "][", x - 1, "]")
            path.append((y, x))
            return_paths((val + 1), data, y, (x - 1), path)
            path.pop()
    if is_in_bound(y, (x + 1), data):
        if data[y][x + 1] == (val + 1):
            path.append((y, x))
            print("going right to: [", y, "][", x + 1, "]")
            return_paths((val + 1), data, y, (x + 1), path)
            path.pop()
    # return (total)

y = 0
x = 0

data = []
for line in f:
    # print(line) 
    row = []
    for char in line.strip():
        row.append(int(char))
    data.append(row)

total = 0
y = 0
x = 0
path = []
for line in data:
    for val in line:
        if val == 0:
            path = []
            return_paths(0, data, y, x, path)
            print("total: ", total, " pos[", y, "][]", x, "]")
        x += 1
    x = 0
    y += 1
# print(total)

for path in paths:
    print(path)
print (len(paths))

start_end = []

u_paths = []
for path in paths:
    s_e = path[0], path[-1]
    if (s_e not in start_end):
        start_end.append(s_e)

print(len(start_end))
