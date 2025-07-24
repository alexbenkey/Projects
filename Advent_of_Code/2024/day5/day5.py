
f = open("data", "r")
g = open("data_lines", "r")
total = 0
values = []
temp = []

def convert_array(array):
    index = 0
    for val in array:
        array[index] = int(array[index])
        index += 1
    return array

def in_order(vals, array):
    bool = 0
    for val in vals:
        print(val[0], val[1])
        if array_in_order(array, val[0], val[1]) == 0:
            print("not in order")
            return (0)
    return (1)

def array_in_order(array, sub1, sub2):
    array = convert_array(array)
    if int(sub1) in array:
        index1 = array.index(int(sub1), 0, len(array))
    else:
        print(sub1, " not in array: ", array)
        return(1)
    if int(sub2) in array:
        index2 = array.index(int(sub2), 0, len(array))
    else:
        print(sub2, " not in array: ", array)
        return(1)
    if index1 < index2:
        print("array is in order")
        return(1)
    print("array not in order")
    return(0)

def substrings_in_order(s, sub1, sub2):
    index1 = s.find(sub1)
    index2 = s.find(sub2)
    if index1 == -1 or index2 == -1:
        return (1)
    elif index1 != -1 and index2 != -1 and index1 < index2:
        return(1)
    return(0)

def get_middle(ar):
    length = len(ar)
    val = int((length - 1) / 2)
    print(val)
    # print ("middle: ", ar[val])
    return (int(ar[val]))

def move_vals(array, val1, val2):
    # print("(move vals) array: ", array)
    # print("val1: ", val1)
    # print("array type: ", type(array))
    if val1 in array:
        pos1 = array.index(val1, 0, len(array))
    else:
        # print(val1, "(move_vals) not in array: ", array)
        pos1 = -1
    if val2 in array:
        pos2 = array.index(val2, 0, len(array))
    else:
        pos2 = -1
        # print(val2, "(move_vals) not in array: ", array)
    # pos2 = array.find(val2)
    # if pos2 == -1:
    #     return(1)
    if pos1 != -1 and pos2 != -1:
        if pos1 > pos2:
            value = array.pop(pos1)
            array.insert(pos2, value)
    return array

def reorder(array, values):
    index = 0
    while(in_order(values, array) == 0):
        index += 1
        for pair in values:
            array = move_vals(array, int(pair[0]), int(pair[1]))
    return (array)              

for line in f:
    temp = line.split("|")
    values.append((temp[0].strip(), temp[1].strip()))
for l in g:
    l.strip()
    for val in values:
        if substrings_in_order(l, val[0], val[1]) == 0:
            ll = []
            for v in l.split(","):
                ll.append(int(v))
            print(ll)
            sorted = reorder(ll, values)
            total += get_middle(sorted)
            break
print(total)