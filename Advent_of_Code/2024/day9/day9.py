f = open("data", "r")

def get_size(mem, pos):
    # print("init pos: ", pos)
    val = mem[pos]
    size = 0
    while pos and mem[pos] == val:
        size += 1
        pos -= 1
    # print("size: ", size, "at position: ", pos)
    return (size)


def find_space(mem_array, length, max_pos): 
    pos = 0
    while(pos < max_pos):
        if (mem_array[pos] == '.'):
            start = pos
            size = 0
            while(pos < max_pos and mem_array[pos] == '.'):
                size += 1
                pos += 1
                if size >= length:
                    # print ("start position: ", start)
                    return(start)
        else:
            # print("current position: ", pos)
            pos += 1
    return (0)

file_free = 1
current = 0
mem = []
for line in f:
    for char in line:
        if file_free:
            file_free = 0
            for i in range(int(char)):
                mem.append(current)
            current += 1
        else:
            for i in range(int(char)):
                mem.append('.')
            file_free = 1
i = 0
j = 0
temp = 0
# print(mem)
pos = len(mem) - 1
while pos:
    print(pos)
    # print(mem)
    if mem[pos] != '.':
        val = mem[pos]
        # print("val: ", val)
        size = get_size(mem, pos)
        space = find_space(mem, size, pos)
        # print("space: ", space)
        if (space):
            while size and pos:
                mem[space] = val
                mem[pos] = '.'
                space += 1
                size -= 1
                pos -= 1
        else:
            pos -= size
    else: 
        pos -= 1



# while('.' in mem):
#     if mem[i] == '.':
#         while(mem[len(mem) - 1] == '.'):
#             mem.pop()
#         temp = mem.pop()
#         mem[i] = temp
#     i += 1
# print(mem)
# i = 0
total = 0
for val in mem:
    if (val != '.'):
        total += i * val
    i += 1
print(total)
