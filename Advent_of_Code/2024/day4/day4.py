# directions = [[0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1], [-1, 0], [-1, 1]]


def in_range(x, y):
    if (0 <= x < height) and (0 <= y < width):
        return (1)
    return(0)

def find_diag_1(grid, x, y):
    vert = 1
    hor = 1
    if(in_range(x + vert, y + hor) and (grid[x + vert][y + hor] == "M")):
        vert *= -1
        hor *= -1
        if(in_range(x + vert, y + hor) and (grid[x + vert][y + hor] == "S")):
            return(1)
        else:
            vert *= -1
            hor *= -1
    elif(in_range(x + vert, y + hor) and (grid[x + vert][y + hor] == "S")):
        vert *= -1
        hor *= -1
        if(in_range(x + vert, y + hor) and (grid[x + vert][y + hor] == "M")):
            return(1)
    return(0)

def find_diag_2(grid, x, y):
    vert = 1
    hor = -1
    if(in_range(x + vert, y + hor) and (grid[x + vert][y + hor] == "M")):
        vert *= -1
        hor *= -1
        if(in_range(x + vert, y + hor) and (grid[x + vert][y + hor] == "S")):
            return(1)
        else:
            vert *= -1
            hor *= -1
    elif(in_range(x + vert, y + hor) and (grid[x + vert][y + hor] == "S")):
        vert *= -1
        hor *= -1
        if(in_range(x + vert, y + hor) and (grid[x + vert][y + hor] == "M")):
            return(1)
    return(0)

def find_words(grid, x, y, dir):
    if(in_range(x, y) and grid[x][y] == "M"):
        x+= dir[0]
        y+= dir[1]
        if(in_range(x, y) and grid[x][y] == "A"):
            x+= dir[0] 
            y+= dir[1]
            if(in_range(x, y) and grid[x][y] == "S"):
                return(1)
    return (0)

with open("data", "r") as data:
    lines = data.read().splitlines()
    grid = list(map(list, lines))

word = "XMAS"

total = 0
height = len(grid)
width = len(grid[0])
print(height)
print(width)

for i in range(height):
    for j in range(width):
        if (grid[i][j] == "A"):
            if(find_diag_1(grid, i, j) and find_diag_2(grid, i, j)):
                total += 1
                print(i, j)
print(total)