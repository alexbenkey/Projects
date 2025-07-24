d = open("data", "r")
height = 0
player_init = []
player = []
directions = [[-1,0],[0,1],[1,0],[0,-1]]
active_init = [directions[0][0], directions[0][1]]
active_val = 0
map_data = []
total = 0
next = [0, 0]

def has_duplicate_segments(array_of_pairs):
    seen_segments = set() 
    
    n = len(array_of_pairs)
    
    for segment_length in range(2, n // 2 + 1):
        for i in range(n - segment_length + 1):
            segment = tuple(array_of_pairs[i:i + segment_length])  
            if segment in seen_segments:
                print(f"found segment: ", segment)
                return(1)
            seen_segments.add(segment)
    print("no loop")
    return(0)

def out_of_bounds(pos, next):
    tmp1 = pos[0] + next[0]
    tmp2 = pos[1] + next[1]
    if tmp1 == -1 or tmp1 == height or tmp2 == -1 or tmp2 == width:
        return(1)
    return(0)

def block(pos, next):
    tmp1 = pos[0] + next[0]
    tmp2 = pos[1] + next[1]
    if map_data[tmp1][tmp2] == '#' or map_data[tmp1][tmp2] == '0':
        return(1)
    return(0)

def run_sim(map_data, player, active, directions, active_val):
    # print(f"Running simulation for: ", player[0], player[1])
    history = []
    while(0 <= player[0] < width and 0 <= player[1] < height):
        counter = 0
        if out_of_bounds(player, active):
            return (0)
        while block(player, active):
            active_val += 1
            counter += 1
            print("counter: ", counter)
            if active_val == 4:
                active_val = 0
            if counter == 4:
                return (1)
            active = directions[active_val]
        history_val = (player[0], player[1], active[0], active[1])
        player[0] += active[0]
        player[1] += active[1]
        if(history_val in history):
            return(1)
        history.append(history_val)
    return (0)

for line in d: 
    width = len(line)
    map_data.append(list(line.strip()))
    if '^' in line:
        player_init.append(height)
        player_init.append(line.find('^'))
    height += 1

reset = player_init

player.append(player_init[0])
player.append(player_init[1])

active = active_init

while(0 <= player[0] < height and 0 <= player[1] < width):
    map_data[player[0]][player[1]] = 'X'
    if out_of_bounds(player, active):
        break
    if block(player, active):
        active_val += 1
        if active_val == 4:
            active_val = 0
        active = directions[active_val]
    # history_val = (player[0], player[1])
    # history.append(history_val)
    player[0] += active[0]
    player[1] += active[1]

for row in map_data:
    print(row)

player[0] = player_init[0]
player[1] = player_init[1]

i = 0
j = 0
while i < height:
    while j < width:
        # print(f"i: ", i, "j: ", j)
        if (map_data[i][j] == "X"):
            map_data[i][j] = '0'
            player[0] = player_init[0]
            player[1] = player_init[1]
            active = active_init
            # print(f"i: {i}, j: {j}, map_data[i][j]: {map_data[i][j]}")
            if run_sim(map_data, player, active, directions, 0):
                for row in map_data:
                    print(row)
                print("hit")
                print("\n")
                total += 1
            map_data[i][j] = 'X'
        j += 1
    j = 0
    i += 1

for row in map_data:
    print(row)

print("height: ", height)
print("width: ", width)

print("total: ", total)