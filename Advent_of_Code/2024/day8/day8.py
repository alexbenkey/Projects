f = open("data", "r")
data = []
height = 0

def get_places(positions):
    hashes = []
    for j in range(len(positions)):
        for i in range(len(positions)):
            if (positions[j] != positions[i]):
                y_dif = (positions[i][0] - positions[j][0])
                x_dif = (positions[i][1] - positions[j][1])
                updated = [positions[j][0] - y_dif, positions[j][1] - x_dif]
                while (0 <= updated[0] < height and 0 <= updated[1] < width):
                    hashes.append(updated)
                    updated = [updated[0] - y_dif, updated[1] - x_dif]
    return(hashes)

def get_pos(val, data):
    positions = []
    y = 0
    for row in data:
        x = 0
        for unit in row:
            if unit == val:
                positions.append([y, x])
            x += 1
        y += 1
    print(positions)
    return(positions)

def find_unique(data):
    found = []
    for line in data:
        for char in line: 
            if (char != '.' and char not in found):
                found.append(char)
    return (found)

def find_hashes(data):
    total = 0
    for line in data:
        for char in line: 
            if (char == '#'):
                total += 1
    return (total)

def find_antennas(data, antennas):
    total = 0
    for ant in antennas:
        for line in data:
            for char in line: 
                if (char == ant):
                    total += 1
    return (total)

for line in f:
    height += 1
    l = []
    # print(line)
    for char in line.strip():
        l.append(char)
    data.append(l)
width = len(data[0])

positions = []
extra = []
uniques = find_unique(data)
for val in uniques:
    pos = get_pos(val, data)
    print("pos: ", pos)
    positions = get_places(pos)
    for place in  positions:
        if (0 <= place[0] < height and 0 <= place[1] < width):
            if data[place[0]][place[1]] == '.':
                print(data[place[0]][place[1]])
                data[place[0]][place[1]] = '#'
                print(place)
            else:
                extra.append(place)
for pos in extra:
    data[pos[0]][pos[1]] = '#'

total = find_hashes(data)
total += find_antennas(data, uniques)
print("hashes: ", total)

for row in data:
    print(row)
# print(data)
# print(find_unique(data))
# print(height, width)
# print(data)